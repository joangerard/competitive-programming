#include <iostream>
#include <set>

using namespace std;
 
void print( set<char, greater<char>> b) {
    set<char, greater<char> >::iterator itr;
    for (itr = b.begin(); itr != b.end(); itr++) {
        cout << *itr << " ";
    }
    cout<<endl;
}
int main()
{
    // ASCENDING
    set<char> a;
    a.insert('A');
    a.insert('Z');
    a.insert('G');
    a.insert('C');
    a.insert('B');
    a.insert('H');
    a.insert('A');
    a.insert('D');
    a.insert('G'); // duplicate
    cout<<"ASC: "  ;
    for (auto& str : a) {
        cout << str << ' ';
    }

    cout << '\n';

    // DESCENDING
    set<char, greater<char>> b;
    b.insert('A');
    b.insert('Z');
    b.insert('G');
    b.insert('C');
    b.insert('B');
    b.insert('H');
    b.insert('A');
    b.insert('D');
    b.insert('G'); // duplicate

    cout<<"DESC: "  ;
    for (auto& str : b) {
        cout<< str<< ' ';
    }

    // PRINT SET
    set<char, greater<char> >::iterator itr;
    cout << "\nThe set b is : \n";
    print(b);

    // DELETE LAST 3
    b.erase(b.find('C'), b.end());
    print(b);

    // SEARCH ELEMENT:
    cout<<*a.lower_bound('C')<<endl;
    cout<<*a.upper_bound('C')<<endl;

    // SWAP ELEMENTS BETWEEN SETS:
    // Take any two sets
    set<int> set1{ 1, 2, 3, 4 };
    set<int> set2{ 5, 6, 7, 8 };
  
    // Swap elements of sets
    set1.swap(set2);
  
    // Print the first set
    cout << "set1 = ";
    for (auto it = set1.begin();
         it != set1.end(); ++it)
        cout << ' ' << *it;
  
    // Print the second set
    cout << endl
         << "set2 = ";
    for (auto it = set2.begin();
         it != set2.end(); ++it)
        cout << ' ' << *it;
    return 0;
}