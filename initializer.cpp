#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// @link https://stackoverflow.com/questions/14414832/why-use-initializer-list-instead-of-vector-in-parameters
// The difference between vector and initializer_list.
// 1. Initializer_list in included in vector, so that we can use {} to initialize a vector.
// 2. Initializer_list allows you to use {} to create a list anywhere you want.

class Foo {
    private:
        vector<int> bar;
    
    public:
        // Initializer list for initialization, only 1 parameter (the initializer_list)
        // Can use either = or ({}) or {} (uniform initialization) to initialize
        Foo(initializer_list<int> list) {
            for (auto i : list) {
                bar.emplace_back(i);
            }
        }
        // More than 2 parameters, test the way to initialize.
        // Use ({}, ...) to initialize
        // Do not use = to initialize
        Foo(initializer_list<int> list, int n) {
            for (auto i : list) bar.push_back(i);
            cout << "In Initializer, n is " << n << "\n";
        }

        void display() {
            for (auto i : bar) cout << i << "\t";
        }

        // Initializer list as parameter
        void demo(initializer_list<int> list) {
            for (auto i : list) bar.emplace_back(i);
            cout << "\n";
            for (auto i : bar) cout << i << '\t';
        }

};

int main() {
    Foo f1 = {1,2,3,4,5};
    // Same as 
    Foo f2 ({1,2,3,4,5}, 5);
    f1.display();
    // output 1 2 3 4 5
    f2.demo({6,7,8,9,10});
    return 0;
}