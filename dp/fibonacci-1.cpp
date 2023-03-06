// NORMAL FIBONACCI
#include <iostream>

using namespace std;
// 1, 1, 2, 3, 5, 8, 13, 21, 34...
// 1  2  3  4  5  6
long fibo(long n) {
    if (n == 1 || n==2) return 1;
    else return fibo(n-1) + fibo(n-2);
}

int main() {
    cout<<fibo(1)<<endl;
    cout<<fibo(3)<<endl;
    cout<<fibo(6)<<endl;
    cout<<fibo(10)<<endl;
    cout<<fibo(60)<<endl;
}