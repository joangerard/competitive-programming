#include <iostream>
#include <vector>
using namespace std;

/*********
 * lower_bound returns the position of the element NOT LESS than the given one
 * upper_bound returns the position of the element GREATER than the given one
 ********/
  
int main()
{
    // initializing vector of integers
    // for single occurrence
    vector<int> arr1 = { 10, 15, 20, 25, 30, 35 };
  
    // initializing vector of integers
    // for multiple occurrences
    vector<int> arr2 = { 10, 15, 20, 20, 20, 30, 35 };
  
    // initializing vector of integers
    // for no occurrence
    vector<int> arr3 = { 10, 15, 25, 30, 35 };
  
    // using lower_bound() to check if 20 exists
    // single occurrence
    // prints 2
    cout << "The position of 20 using lower_bound "
            " (in single occurrence case) : ";
    cout << lower_bound(arr1.begin(), arr1.end(), 20)
                - arr1.begin();
  
    cout << endl;
  
    // using lower_bound() to check if 20 exists
    // multiple occurrence
    // prints 2
    cout << "The position of 20 using lower_bound "
            "(in multiple occurrence case) : ";
    cout << lower_bound(arr2.begin(), arr2.end(), 20)
                - arr2.begin();

    cout << endl;

    // using upper_bound() to check if 20 exists
    // multiple occurrence
    // prints 4 because 30 is the next bigger element after 20
    cout << "The position of 20 using upper_bound "
            "(in multiple occurrence case) : ";
    cout << upper_bound(arr2.begin(), arr2.end(), 20)
                - arr2.begin() - 1;
  
    cout << endl;
  
    // using lower_bound() to check if 20 exists
    // no occurrence
    // prints 2 ( index of next higher)
    cout << "The position of 20 using lower_bound "
            "(in no occurrence case) : ";
    cout << lower_bound(arr3.begin(), arr3.end(), 20)
                - arr3.begin();
  
    cout << endl;
}