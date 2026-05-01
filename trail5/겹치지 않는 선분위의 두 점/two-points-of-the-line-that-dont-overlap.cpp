#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<pair<long long, long long>> lines;

bool check(long long num){
    long long prevP = lines[0].first;
    int cnt = 1;

    for (int i = 0; i < m; i++){
        long long nextP = max(prevP + num, lines[i].first);
        // 다음 point 위치가 lines[i].sec 범위안이면 
        while(nextP <= lines[i].second){
            cnt++;
            prevP = nextP;
            if (cnt >= n) return true;
            nextP = prevP + num;
        }
    }

    if (cnt >= n)
        return true;
    return false;
}

// target을 넘지 않는 a를 찾고 해당 b값까지 안에 있는지 확인 있으면 그곳에 점찍는거죠?
// 이거 쌍으로 설정해두고 sort해줘야함
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        long long a, b;
        cin >> a >> b;
        lines.push_back({a, b});
    }
    // 작동완
    sort(lines.begin(), lines.end());

    long long left = 1;
    long long right = 1000000000000000000;
    long long ans = 0;
    while (left <= right){
        long long mid = (left + right) / 2;
        if (check(mid)){
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << ans;

}