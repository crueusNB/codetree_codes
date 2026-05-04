#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int T_max;
int d[10000];

bool check(int num){
    vector<int> vec(num);
    for (int i = 0; i < num; i++){
        vec[i] = d[i];
    }

    // 여기서 시간초과 날거같은데
    for (int i = num; i < N; i++){
        int minIdx = 0;
        for (int j = 1; j < num; j++){
            if (vec[j] < vec[minIdx]){
                minIdx = j;
            }
        }

        vec[minIdx] += d[i];
    }

    for (int i = 0; i < num; i++){
        if (vec[i] > T_max){
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> T_max;

    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }

    sort(d, d + N);
    reverse(d, d + N);

    // Please write your code here.
    int left = 1;
    int right = N;
    int ans = N;

    while (left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }
    cout << ans;
    return 0;
}
