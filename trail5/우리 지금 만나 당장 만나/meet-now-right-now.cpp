#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int n;
int x[100000];
int v[100000];

pair<int, double> check(int target){
    double maxT = double(abs(target - x[0])) / v[0];
    int max_idx = 0;

    for (int i = 1; i < n; i++){
        double goingTime = double(abs(target - x[i])) / v[i];
        if (goingTime > maxT){
            maxT = goingTime;
            max_idx = i;
        }
    }
    // cout << "target: " << target << " idx값: " << max_idx << " 시간: " << maxT << '\n';
    return {x[max_idx], maxT};
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Please write your code here.
    int left = 1;
    int right = 1000000000;
    double ans = 1000000000;

    while(left <= right){
        int mid = (left + right) / 2;
        // 최대일때의 위치, 시간
        pair<int, double> tmp = check(mid);

        if (tmp.first < mid){
            right = mid - 1;
            ans = min(ans, tmp.second);
        }
        else{
            left = mid + 1;
            ans = min(ans, tmp.second);
        }
    }

    cout << fixed << setprecision(4) << ans;
    return 0;
}
