#include <iostream>
#include <algorithm>
using namespace std;

int N, M, C;
int t[100000];

bool check(int target){
    int cnt = 1;
    int curr = t[0] + target;
    int take_cnt = 1;

    for (int i = 1; i < N; i++){
        if (cnt > M)
            return false;
        // 만약 탄사람이 C명이 되면 다음버스를 타야함
        if (take_cnt == C){
            cnt++;
            take_cnt = 1;
            curr = t[i] + target;
            continue;
        }

        // 범위안에 있으면
        if (t[i] <= curr){
            take_cnt++;
        }
        else{
            // 범위 밖이면 새로운 버스를 배정
            cnt++;
            take_cnt = 1;
            curr = t[i] + target;
        }
    }

    if (cnt <= M)
        return true;
    return false;
}

int main() {
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    sort(t, t + N);
    // Please write your code here.
    int left = 1;
    int right = 1000000000;
    // target은 걸리는 최대시간
    int ans;
    while (left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    cout << ans;
    return 0;
}
