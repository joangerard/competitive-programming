#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> stack;
    stack.push(1);// The values pushed in the stack should be of the same data which is written during declaration of stack
    stack.push(2);
    stack.push(6);
    stack.push(3);
   
    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }
}
