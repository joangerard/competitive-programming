// BOTTOM-UP DP FIBONACCI
#include <iostream>

using namespace std;
long memo[10000001];

long fibo(long n) {
    if (n<= 2) return 1;
    memo[1] = 1;
    memo[2] = 1;
    for (int i=3; i<= n; i++) {
        memo[i] = memo[i-1] + memo[i-2];
    }

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