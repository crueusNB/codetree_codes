#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x1[100000], x2[100000];
vector<pair<int, int>> lines;

// 
bool check(int num){
    int prevP = lines[0].first;
    for (int i = 1; i < n; i++){
        if (prevP + num > lines[i].second){
            return false;
        }

        prevP = max(prevP + num, lines[i].first);
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        lines.push_back({x1[i], x2[i]});
    }
    sort(lines.begin(), lines.end());
    // Please write your code here.
    int left = 1;
    int right = 1000000000;
    int ans = 0;
    while (left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
