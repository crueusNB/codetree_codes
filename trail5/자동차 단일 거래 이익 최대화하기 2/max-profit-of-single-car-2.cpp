#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int n;
    cin >> n;

    int arr[100001];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int buy, sell;
    buy = sell = arr[0];
    int maxGap = 0;

    for (int i = 1; i < n; i++){
        if (arr[i] < buy){
            buy = arr[i];
            sell = arr[i];
        }
        else{
            sell = arr[i];
            maxGap = max(sell - buy, maxGap);
        }
    }
    cout << maxGap;
    return 0;
}