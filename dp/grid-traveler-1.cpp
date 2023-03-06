// NORMAL GRID TRAVELER
#include <iostream>

using namespace std;

long gridTraveler(int m, int n) {
    if (m==1 && n ==1) return 1;
    if (m==0 || n == 0) return 0;

    return gridTraveler(m-1, n)+gridTraveler(m, n-1);
}

int main() {
    cout<<gridTraveler(3,2)<<endl;
    cout<<gridTraveler(3,3)<<endl;
    cout<<gridTraveler(5,5)<<endl;
    cout<<gridTraveler(18,18)<<endl;
}