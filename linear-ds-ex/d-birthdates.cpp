#include <iostream>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;

class Person
{
    public: 
        string name;
        int birthdate;
};

struct LessThanByAge
{
  bool operator()(const Person& lhs, const Person& rhs) const
  {
    return lhs.birthdate < rhs.birthdate;
  }
};

struct GreatThanByAge
{
  bool operator()(const Person& lhs, const Person& rhs) const
  {
    return lhs.birthdate > rhs.birthdate;
  }
};

int main()
{
    char name[15];
    unsigned int n, d, m, y;
     // defining priority queues
    priority_queue<Person, vector<Person>, LessThanByAge> pq_younger;
    priority_queue<Person, vector<Person>, GreatThanByAge> pq_older;

    cin>>n;

    for (unsigned int i = 0; i < n; i++)
    {
        scanf("%s %u %u %u", name, &d, &m, &y);
        Person p = Person();
        p.name = name;
        p.birthdate = y*10000+m*100+d;
        pq_younger.push(p);
        pq_older.push(p);
    }

    cout<<pq_younger.top().name<<endl<<pq_older.top().name<<endl;
}