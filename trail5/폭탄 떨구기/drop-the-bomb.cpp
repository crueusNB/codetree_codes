// R을 선택 -> 첫 점에서 r만큼 떨어진 위치에 폭탄시작 -> 다음 점에서 r만큼 ..
// 뒤에 점이 남아있으면 false
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int x[50000];

bool check(int target){
    // 폭발 횟수
    int cnt = 1;
    // 시작폭발의 끝값
    int curr = x[0] + 2 * target;

    for (int i = 1; i < n; i++){
        if (x[i] <= curr)
            continue;

        if (cnt > k)
            return false;

        curr = x[i] + 2 * target;
        cnt++;
    }

    if (cnt <= k)
        return true;
    return false;    


}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    // Please write your code here.
    int left = 1;
    int right = 500000000;
    int ans = 500000000;
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
