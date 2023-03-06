// TOP-DOWN DP GRID TRAVELER
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, long long int> memo;

long long int gridTravelerDp(int m, int n) {
    //m=3, n=2 => key=3,2 //m=2, n=3 => key=3,2
    string key = to_string(max(m,n)) +","+ to_string(min(m,n)); 

    if (memo.find(key) != memo.end()) {return memo[key];}
    if (m==1 && n ==1) return 1;
    if (m==0 || n == 0) return 0;

    memo[key] = gridTravelerDp(m-1, n)+gridTravelerDp(m, n-1);

    return memo[key];
}

int main() {
    cout<<gridTravelerDp(1,1)<<endl;
    cout<<gridTravelerDp(3,2)<<endl;
    cout<<gridTravelerDp(3,3)<<endl;
    cout<<gridTravelerDp(5,5)<<endl;
    cout<<gridTravelerDp(18,18)<<endl;
}