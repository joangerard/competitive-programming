#include <iostream>
#include <queue>
using namespace std;
 
// driver code
int main()
{
    int arr[6] = { 10, 2, 4, 8, 6, 9 };
 
    // defining priority queues
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq_min(arr, arr+6);
 
    // printing array
    cout << "Array: ";
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;
    // pushing array sequentially one by one
    for (int i = 0; i < 6; i++) {
        pq.push(arr[i]);
    }
 
    // printing priority queue max to min
    cout << "Priority Queue Max to Min: ";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    
    cout<<endl;

    // printing priority queue min to max
    cout << "Priority Queue Min de Max: ";
    while (!pq_min.empty()) {
        cout << pq_min.top() << ' ';
        pq_min.pop();
    }
 
    return 0;
}