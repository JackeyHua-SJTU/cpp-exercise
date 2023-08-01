#include<iostream>

using namespace std;

// @note Inline Function
// Suppose an inline function f, in the COMPILE stage, all f in program will be replaced by the body of f.
// Tradeoff between speed and space. Hence, very tiny body (<10 loc), defined before used.
// All functions declared and defined inside a class are INLINE. If defined outside, we should explicitly add inline in declaration or definition.

class demo1 {
    private:
        int x;
        double y;
        int *arr;
        static int cnt;
        const int c;

    public:
        // there is no this pointer in static function
        // can only have access to static var/func 
        static int returnCnt() {return cnt;}
        
        // #1 use the default constructor
        demo1() = default;

        // #5 this pointer in class
        // all the functions belonging to this class has "this" pointer pointing to it implicitly.

        //#7 const variable can only be initialized in the list "c(0)"
        demo1(int p1, double p2) : c(0) {
            this->x = p1;
            this->y = p2;
            arr = new int[x];
            cnt++;
            cout << "this is the " << cnt << "th instances of demo1." << endl;
        }

        // #5 static variable is shared by all the class instances.
        // It MUST be instantiated outside the class.
        // static int cnt;

        auto getX () {return x;}
        auto getY() {return y;}
        // const demo1 * const this
        auto getC() const {cout << this->x; return c;}

        // @note #4 friend function and class
        // Friend can have access to private and protected variables inside a class.
        // When defined outside a class, there is no need to add the namespace like demo1::testFriend.
        // Because friend DOES NOT belong to this class !!!
        friend void testFriend(demo1 d);
        
        // #2 shallow copy constructor
        // copy the value of the parameter
        // Fatal when there is a pointer. It may cause the same place on the heap to be deleted for more times.

        // @note when using == for basic types, it will compare the value. When used for others (such as pointers), it will compare the address.
        /*
        demo1(demo1& d) {
            x = d.getX();
            y = d.getY();
            arr = d.arr;
            cout << "Check whether the address is the same. (arr == d.arr) -> " << (arr == d.arr) << endl;
            // point to the same place
        }
        */

        // #2 deep copy constructor
        // address the problem of pointer

        // #6 Value, Reference and Pointer
        // 1. Value and Pointer are about the same, allocating space on stack and copy the value of the parameter.
        // For pointer, the value is the address it points to.
        // Changes on the parameter itself will not change the real one outside function.
        // Namely foo(*p) {int var; p = &var;} The real p outside foo is still the same. But if we change *p, it will make a change.
        // 2. Reference is just giving variable another name. It copies the address to the newly-allocated stack space.
        // All operations on the reference will be directly changed on the variable.
        // To reference, there is no counterpart for *p, that is the main difference between ref and pointer.
        // In terms of large objects, if we pass by value, the process of copying takes great time, so pass by ref!

        // #7 In copy constructor, the constant variable can only be initialized by using the list like "c(d.c)".
        demo1(demo1& d) : c(d.c) {
            this->x = d.getX();
            this->y = d.getY();
            this->arr = new int [this->x];
            for (int i = 0; i < x; i ++) {
                cout << "Deep copying, current array size is " << this->x << ".\n";
                arr[x] = d.arr[x];
                cout << "Check whether the address is the same. (arr == d.arr) -> " << (arr == d.arr) << endl;
            }
        }
        
        ~demo1() {delete[] arr;}

};

// @note #3 mode and inherit
// when a variable is defined protected in a class, it is no different from private but can be accessed by derived class.
// In terms of inheritance, it refers to the mode of parent class in the current class.
// public inherit : [public, protected, private] --> [public, protected, private]
// protected inherit : [public, protected, private] --> [protected, protected, private]
// private inherit : [public, protected, private] --> [private, private, private]

class demo2 : protected demo1 {
    public:
        demo2() = default;
};


// When instantiated outside a class, the variable must add the namespace. Namely, demo1:: .
// Better initialize in global area, because for private static, it can only be initialized here.
// public static variable can be given new value in main()
int demo1::cnt = 0;

int main() {
    // #1 when initializing using the default constructor, do not use @example demo1 var();
    demo1 var(1, 2.0);
    cout << var.getX() << ' ' << var.getY() << endl;
    demo1 var2 = var;
    cout << var2.getX() << " " << var2.getY() << " " << var2.getC() << endl;
    // #2 when copy constructor will be called?
    //      1. when we use an instance to create another.
    //      2. as the parameter of a function
    //      3. as the return value of a function
    testFriend(var);
    cout << demo1::returnCnt();
    return 0;
}

// #4 Friend function.
// no need to add demo1::
void testFriend(demo1 d) {
    cout << "Current x is " << d.x << ", Current y is " << d.y << ".\n";
}


// @note #7 About const, namely read only
// 1. const int *p == const int (*p), which means *p should not be changed.
// 2. int * const p == int * (const p), which means the address p points to should not be changed.
// 3. const int * const p, neither the value nor the address can be changed.
// 4. const& as return value, is pretty similar to 3. & implied that when created, the address cannot be changed. const makes sure that value can not be changed.
// 5. const function inside a class. foo() const {}. This pointer inside it is 3rd type. It can only read variables.