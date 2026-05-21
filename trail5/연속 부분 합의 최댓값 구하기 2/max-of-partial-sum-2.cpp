#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[100001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum = -99999;
    int maxSum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        maxSum = max(sum, maxSum);

        if (sum < 0)
            sum = 0;
    }
    cout << maxSum;
    return 0;
}