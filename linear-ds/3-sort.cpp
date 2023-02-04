#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    cout << "\nArray \n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    sort(arr, arr + n, greater<int>());
    cout << "\nArray reverse\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}