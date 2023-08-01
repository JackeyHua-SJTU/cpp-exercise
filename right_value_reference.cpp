#include<iostream>
#include<string>

using namespace std;

// # Move Semantics #

void reference(string& str) {
    cout << "left" << endl;
}
void reference(string&& str) {
    cout << "right" << endl;
}

class demo {
    public:
        int* p;

        demo() = default;

        demo(demo& d) {
            this->p = new int(*d.p);
            cout << "Calling copy constructor." << endl;
        }
        // called when right value is used
        // Essencially, it is like value copy, but special treatment for pointer.
        demo(demo&& d) {
            this->p = d.p;
            // in case in the current instance, the pointer will be a dangeling pointer 
            d.p = nullptr;
            cout << "Calling move constructor." << endl;
        }

        ~demo() {delete p;}

};

demo retRight(bool flag) {
    demo a, b;
    if (flag) return a;
    else return b;
}


int main() {
    string str1 = "string,";
    // str2 is another name for "string,"(the right value), but it is actually left value.
    string&& str2 = move(str1);
    cout << 1 << " " << str2 << endl;
    reference(str2); // left

    str2 += str1;
    cout << 2 << " " << str2 << endl;

    demo obj = retRight(false);
    cout << obj.p << endl;
    cout << *obj.p << endl;

    return 0;
}