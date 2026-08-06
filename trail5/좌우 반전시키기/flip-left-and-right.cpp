#include <iostream>
using namespace std;

int n;
int arr[102];

void change(int num){
    arr[num - 1] = arr[num - 1] == 0 ? 1 : 0;
    arr[num] = arr[num] == 0 ? 1 : 0;
    arr[num + 1] = arr[num + 1] == 0 ? 1 : 0;
}

int main() {
    // Please write your code here.
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    for (int i = 1; i < n; i++){
        if (arr[i - 1] == 0){
            change(i);
            cnt++;
        }
    }
    if (arr[n - 1] == 0)
        cnt = -1;
    
    cout << cnt;
    return 0;
}