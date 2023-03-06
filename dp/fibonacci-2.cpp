// TOP-DOWN DP FIBONACCI
#include <iostream>

using namespace std;
long memo[10000001];

long fibo(long n) {
    if (memo[n] != -1) return memo[n];
    long val = -1;
    if (n == 1 || n==2) {
        val = 1;
    }
    else {
        val = fibo(n-1) + fibo(n-2);
    } 
    memo[n] = val;
    return memo[n];
}

int main() {
    memset(memo, -1, sizeof memo);
    cout<<fibo(1)<<endl;
    cout<<fibo(3)<<endl;
    cout<<fibo(6)<<endl;
    cout<<fibo(10)<<endl;
    cout<<fibo(60)<<endl;
    cout<<fibo(10000000)<<endl;
}