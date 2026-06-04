#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main() {
    int c, n;
    cin >> c >> n;

    vector<int> red;
    vector<pair<int, int>> black;

    for (int i = 0; i < c; i++){
        int num;
        cin >> num;
        red.push_back(num);
    }

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        black.push_back({a, b});
    }

    sort(red.begin(), red.end());
    sort(black.begin(), black.end());

    priority_queue<int, vector<int>, greater<int>> tmp;
    int black_idx = 0;
    int cnt = 0;
    for (int i = 0; i < c; i++){
        while(black_idx < n && black[black_idx].first <= red[i]){
            tmp.push(black[black_idx].second);
            black_idx++;
        }

        while(!tmp.empty() && tmp.top() < red[i]){
            tmp.pop();
        }

        if (!tmp.empty()){
            cnt++;
            tmp.pop();
        }
    }
    cout << cnt;
    return 0;
}