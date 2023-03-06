// kadane's algorithm to find maximum range sum query in O(n)
#include <iostream>

using namespace std;


int main() {
    int n = 10, A[] = { 4, -5, 4, 8, -3, 4, -5, 2, -10, 1 }; // a sample array A
    int sum = 0, ans = 0; // important, ans must be initialized to 0
    for (int i = 0; i < n; i++) { // linear scan, O(n)
        sum += A[i]; // we greedily extend this running sum
        ans = max(ans, sum); // we keep the maximum RSQ overall
        if (sum < 0) sum = 0; // but we reset the running sum
    } // if it ever dips below 0
    printf("Max 1D Range Sum = %d\n", ans);
}