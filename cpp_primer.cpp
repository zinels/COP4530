#include <cstdlib>
#include <iostream>

using namespace std; //makes std available

// /* Program inputs two numbers x and y and outputs their sum */

// int main( ) {
//  int x, y;

//  cout << "Please enter two numbers: ";
//  cin >> x >> y; // input x and y

//  int sum = x + y; // compute their sum

//  cout << "Their sum is " << sum << endl;

//  return EXIT_SUCCESS; // terminate successfully
// }

//-------
// #include <iostream>
// #include <iomanip>
// #include <limits>
// using namespace std;

// int main() {
//     // Boolean and Character
//     bool flag = true;
//     char ch = 'A';
//     cout << "Boolean: " << flag << "\nChar: " << ch 
//          << " (ASCII: " << static_cast<int>(ch) << ")\n\n";//character encoding scheme

//     // Integer Types with Maximum Values
//     cout << "Integer Maximums:\n";
//     short s = 32767;
//     int i = 2147483647;
//     long long ll = 9223372036854775807LL;
//     // cout << "short: " << s << "\nint: " << i << "\nlong long: " << ll << "\n\n";

//     // Type Sizes
//     cout << "Sizes in bytes:\n"
//          << "short: " << sizeof(short) 
//          << ", int: " << sizeof(int)
//          << ", long long: " << sizeof(long long) << "\n\n";

//     // Floating Point with Different Precisions
//     cout << fixed << setprecision(10);
//     float f = 3.141592653589793;
//     double d = 3.141592653589793;
//     cout << "float: " << f << "\ndouble: " << d << "\n\n";

//     // Signed vs Unsigned
//     int si = -42;
//     unsigned int ui = 42;
//     cout << "signed: " << si << "\nunsigned: " << ui << "\n\n";

//     cout << "Size of signed int: " << sizeof(signed int) << " bytes\n";
//     cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes\n";

//     // Range Example (for int)
//     cout << "Int range: " 
//          << numeric_limits< unsigned int>::min() << " to "
//          << numeric_limits< unsigned int>::max() << "\n\n";

//     // Type Conversion
//     int num = 66;
//     char converted = static_cast<char>(num);
//     cout << "65 as char: " << converted << "\n";

//     return 0;
// }
// //----
// int x = 42;              // Regular variable
// int* ptr = &x;           // Pointer pointing to x
// cout << *ptr;            // Prints 42 (value at pointed address)
// cout << ptr;             // Prints memory address (e.g., 0x7fff5fbff7dc)
// *ptr = 100;             // Modifies x through the pointer
// cout << x;              // Prints 100
// //----

// #include <iostream>
// using namespace std;

// int main() {
//     // Create an array
//     int arr[] = {10, 20, 30, 40, 50};
//     int* ptr = arr;  // Points to first element
    
//     // 1. Pointer Arithmetic
//     cout << "Pointer Arithmetic:\n";
//     cout << "*ptr = " << *ptr << endl;       // 10
//     ptr++;                                   // Move to next element
//     cout << "*ptr = " << *ptr << endl;       // 20
//     ptr += 2;                                // Move 2 elements forward
//     cout << "*ptr = " << *ptr << endl;       // 40
    
//     // 2. Array Access
//     ptr = arr;  // Reset pointer to start
//     cout << "\nArray Access:\n";
//     cout << "ptr[2] = " << ptr[2] << endl;           // 30
//     cout << "*(ptr + 2) = " << *(ptr + 2) << endl;   // 30
    
//     // 3. Pointer Comparison
//     int* ptr1 = &arr[1];  // Points to second element
//     int* ptr2 = &arr[3];  // Points to fourth element
    
//     cout << "\nPointer Comparison:\n";
//     cout << "ptr1 < ptr2: " << (ptr1 < ptr2) << endl;          // true
//     cout << "Distance: " << (ptr2 - ptr1) << " elements" << endl;  // 2
    
//     return 0;
// }

// //----
// #include <iostream>
// using namespace std;

// int main() {
//     // 1. Null Pointers
//     int* nullPtr1 = nullptr;  // Modern C++ (preferred)
//     int* nullPtr2 = NULL;     // Old C++ style
//     if (nullPtr1 == nullptr) {
//         cout << "nullPtr1 is null\n";
//     }

//     // 2. Void Pointers
//     int num = 42;
//     void* voidPtr = &num;            // Can point to any type
//     int* intPtr = static_cast<int*>(voidPtr);  // Must cast before use
//     cout << "Value through void pointer: " << *intPtr << "\n";

//     // 3. Const Pointers
//     int value1 = 10, value2 = 20;

//     // Pointer to const (can't modify value)
//     const int* ptr1 = &value1;
//     // *ptr1 = 30;    // Error: can't modify value
//     ptr1 = &value2;   // OK: can change pointer

//     // Const pointer (can't modify pointer)
//     int* const ptr2 = &value1;
//     *ptr2 = 30;       // OK: can modify value
//     // ptr2 = &value2;  // Error: can't change pointer

//     // Const pointer to const (can't modify either)
//     const int* const ptr3 = &value1;
//     // *ptr3 = 30;      // Error: can't modify value
//     // ptr3 = &value2;  // Error: can't change pointer

//     cout << "Value1: " << value1 << "\n";
//     cout << "Value2: " << value2 << "\n";

//     return 0;
// }
// //-----
// #include <iostream>
// using namespace std;

// int main() {
//     // 1. Null Pointer Dereferencing
//     int* nullPtr = nullptr;
//     // BAD: *nullPtr = 42;    // Would cause crash
//     // GOOD: Check before use
//     if (nullPtr != nullptr) {
//         *nullPtr = 42;
//     }

//     // 2. Uninitialized Pointer
//     int* uninitPtr;          // BAD: undefined behavior
//     // GOOD: Initialize pointers
//     int* initPtr = nullptr;  // or point to valid memory
    
//     // 3. Memory Leaks
//     // BAD: Memory leak
//     int* leakyPtr = new int(42);
//     leakyPtr = new int(73);  // Original memory lost
    
//     // GOOD: Proper cleanup
//     int* goodPtr = new int(42);
//     delete goodPtr;          // Clean up
//     goodPtr = nullptr;       // Prevent dangling pointer
    

//     return 0;
// }

// //---
// #include <iostream>
// using namespace std;

// int main() {
//     // if-else
//     int x = 10;
//     if (x > 5) {
//         cout << "x is greater than 5\n";
//     } else if (x < 5) {
//         cout << "x is less than 5\n";
//     } else {
//         cout << "x is equal to 5\n";
//     }

//     // Ternary operator (shorthand if-else)
//     string result = (x > 5) ? "greater" : "less or equal";
//     cout << "x is " << result << " than 5\n";

//     // for loop
//     cout << "\nFor loop: ";
//     for(int i = 0; i < 3; i++) {
//         cout << i << " ";
//     }

//     // while loop
//     cout << "\nWhile loop: ";
//     int j = 0;
//     while(j < 3) {
//         cout << j << " ";
//         j++;
//     }

//     // do-while loop
//     cout << "\nDo-while loop: ";
//     int k = 0;
//     do {
//         cout << k << " ";
//         k++;
//     } while(k < 3);

//     // for-each loop (C++11)
//     cout << "\nFor-each loop: ";
//     int array[] = {1, 2, 3};
//     for(int num : array) {
//         cout << num << " ";
//     }

//     return 0;
// }
///-----
// Basic structure definition
// struct Student {
//     string name;
//     int age;
//     double gpa;
    
//     // Member function
//     void printInfo() {
//         cout << name << ", Age: " << age 
//              << ", GPA: " << gpa << endl;
//     }
// };

// struct Course {
//     string code;
//     Student enrolled[30];
//     int count;
// };

// int main()
// {
// Student student1;
// student1.name = "John";
// student1.age = 20;
// student1.gpa = 3.8;

// student1.printInfo();
// // Course crs1;
// // crs1.enrolled[0].name= "Simpson";


// }
//---
#include <iostream>
#include <string>
using namespace std;

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

class Passenger {
public:
    // Constructors
    Passenger();  // default constructor
    Passenger(const string& nm, MealType mp, const string& ffn = "NONE");
    Passenger(const Passenger& pass);  // copy constructor
    bool getIsFreqFlyer() const { return isFreqFlyer; }
    // Destructor
    ~Passenger() {}

private:
    string name;
    MealType mealPref;
    bool isFreqFlyer;
    string freqFlyerNo;
};

// Initialize using member initialization list
Passenger::Passenger() 
    : name("--NO NAME--"),
      mealPref(NO_PREF),
      isFreqFlyer(false),
      freqFlyerNo("NONE") 
{}

Passenger::Passenger(const string& nm, MealType mp, const string& ffn)
    : name(nm),
      mealPref(mp),
      isFreqFlyer(ffn != "NONE"),
      freqFlyerNo(ffn)
{}

Passenger::Passenger(const Passenger& pass)
    : name(pass.name),
      mealPref(pass.mealPref),
      isFreqFlyer(pass.isFreqFlyer),
      freqFlyerNo(pass.freqFlyerNo)
{}

  

int main() {
    // Default constructor
    Passenger p1;

    // Parameterized constructor
    Passenger p2("John Smith", VEGETARIAN, "293145");

    // Parameterized constructor with default ffn
    Passenger p3("Pocahontas", REGULAR);

    // Copy constructor
    Passenger p4(p3);

    // Copy constructor (alternative syntax)
    Passenger p5 = p2;

    // Dynamic allocation
    Passenger* pp1 = new Passenger();

    // Dynamic allocation with parameters
    Passenger* pp2 = new Passenger("JoeBlow", NO_PREF);
    cout<<p3.getIsFreqFlyer()<<endl;

    // Clean up dynamic memory
    delete pp1;
    delete pp2;

    return 0;
}

//---
// #include <iostream>
// #include <string>
// using namespace std;

// enum MealPref { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

// class Passenger {
// public:
//     string name;
//     MealPref mealPref;
//     bool isFreqFlyer;
//     string freqFlyerNo;
    
//     Passenger(string n = "", MealPref mp = NO_PREF, 
//              bool isFF = false, string ffn = "") 
//         : name(n), mealPref(mp), isFreqFlyer(isFF), freqFlyerNo(ffn) {}
// };

// // print an int
// void print(int x) {
//     cout << x;
// }

// // print a Passenger
// void print(const Passenger& pass) {
//     cout << pass.name << " " << pass.mealPref;
//     if (pass.isFreqFlyer) {
//         cout << " " << pass.freqFlyerNo;
//     }
// }

// bool operator==(const Passenger& x, const Passenger& y) {
//     return x.name == y.name
//         && x.mealPref == y.mealPref
//         && x.isFreqFlyer == y.isFreqFlyer
//         && x.freqFlyerNo == y.freqFlyerNo;
// }

// int main() {
//     Passenger p1("John Smith", VEGETARIAN, true, "1234A");
//     Passenger p2("Jane Doe", REGULAR);
    
//     cout << "Passenger 1: ";
//     print(p1);
//     cout << "\nPassenger 2: ";
//     print(p2);
    
//     Passenger p3("John Smith", VEGETARIAN, true, "1234A");
//     cout << "\nPassengers 1 and 3 are " 
//          << (p1 == p3 ? "equal" : "not equal") << endl;
    
//     return 0;
// }
