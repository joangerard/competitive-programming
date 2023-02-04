#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    queue<int> s;

    s.push(3);
    s.push(6);
    s.push(4);
    s.push(2);

    while (!s.empty()) {
        cout << s.front() << " " ;
        s.pop();
    }

    cout << endl;
    return 0;
}