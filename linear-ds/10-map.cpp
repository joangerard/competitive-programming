#include <iostream>
#include <map>

using namespace std;
 
int main()
{
    // Create a map of strings to integers
    map<string, int> ages;

    // Insert some values into the map
    ages["Mario"] = 20; //O(log n)
    ages["Alicia"] = 25; //O(log n)
    ages["Pedro"] = 30; //O(log n)

    // Get an iterator pointing to the first element in the map
    map<string, int>::iterator it = ages.begin();

    // Iterate through the map and print the elements
    while (it != ages.end()) // O(n)
    {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        ++it;
    }

    cout<<"empy?: "<<ages.empty()<<endl;
    cout<<"size?: "<<ages.size()<<endl;
    cout<<"alicia's age:"<<ages.at("Alicia")<<endl; //O(log n)
    cout<<"alicia's age:"<<ages["Alicia"]<<endl; //O(log n)
    bool found = false;
    found = ages.find("Alicia") != ages.end(); //O(log n)
    cout<<"found alicia?: "<<found<<endl;
    
    ages.erase("Alicia"); //O(log n)
    found = ages.find("Alicia") != ages.end();
    cout<<"found alicia after erase?: "<<found<<endl;

    return 0;
}