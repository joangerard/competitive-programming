#include <iostream>
#include <unordered_map>

using namespace std;
 
int main()
{
    // Create a hash table
    unordered_map<string, int> ages;

    // Insert some values into the hash table
    ages["Mario"] = 20; //O(1)
    ages["Alicia"] = 25; //O(1)
    ages["Pedro"] = 30; //O(1)

    // Get an iterator pointing to the first element
    unordered_map<string, int>::iterator it = ages.begin();

    // Iterate through the unordered_map and print the elements
    while (it != ages.end()) // O(n)
    {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        ++it;
    }

    cout<<"empy?: "<<ages.empty()<<endl;
    cout<<"size?: "<<ages.size()<<endl;
    cout<<"alicia's age:"<<ages.at("Alicia")<<endl; //O(1)
    cout<<"alicia's age:"<<ages["Alicia"]<<endl; //O(1)
    bool found = false;
    found = ages.find("Alicia") != ages.end(); //O(1)
    cout<<"found alicia?: "<<found<<endl;
    
    ages.erase("Alicia"); //O(1)
    found = ages.find("Alicia") != ages.end();
    cout<<"found alicia after erase?: "<<found<<endl;

    return 0;
}