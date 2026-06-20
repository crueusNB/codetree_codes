#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int,int> b){
    if (a.second < b.second) return true;
    if (a.second == b.second && a.first < b.first) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        vec.push_back({s, e});
    }

    sort(vec.begin(), vec.end(), compare);

    int end_time = vec[0].second;
    int cnt = 0;
    for (int i = 1; i < n; i++){
        if (vec[i].first >= end_time){
            end_time = vec[i].first;
        }
        else{
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}