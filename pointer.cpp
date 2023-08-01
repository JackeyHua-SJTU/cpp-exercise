#include<iostream>
#include<memory>

using namespace std;

struct A {int a;};

int main() {
    // shared_ptr can track how many pointers point to itself, when the number is 0, it will be deleted automatically.
    // make_shared is like new, creating a shared pointer.
    auto p1 = make_shared<int>(10);
    *p1 += 1;
    // use_count() return the number of pointers pointing to the source pointer.
    cout << "p1 has " << p1.use_count() << " copies.\n";
    // p1.get() returns the initial pointer.
    auto p2 = p1.get();
    cout << "Now there is " << p1.use_count() << " copies.\n";
    // reset() deletes the current pointer.
    p1.reset();
    cout << "Now there is " << p1.use_count() << " copies.\n";

    // unique_ptr only allows one pointer.
    auto p3 = make_unique<int>(10);

    auto p5 = make_shared<A>();
    // p4 will NOT add to the number that points to what p5 points to.
    // address is passed to p4.
    weak_ptr<A> p4 = p5;
    // p4.expired() will return true if the stuff it points to is deleted.
    // p4.lock() will return a shared_ptr to what it points to.

    // p6 is a shared_ptr pointing to what p5 points to.
    auto p6 = p4.lock();
    cout << "p5 has " << p5.use_count() << " copies.\n";
    p5.reset();
    p6.reset();
    // p4 is now expired, because all pointers pointing to p5 has been expired.
    cout << p4.expired();
    return 0;
}