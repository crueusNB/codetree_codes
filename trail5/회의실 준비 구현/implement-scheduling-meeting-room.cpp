#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int ,int>> vec;
bool compare(pair<int, int> a, pair<int, int> b){
    if (a.second < b.second)
        return true;
    if (a.second == b.second){
        if (a.first < b.first){
            return true;
        }
    }
    return false;

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        vec.push_back({s, e});
    }

    sort(vec.begin(), vec.end(), compare);

    int cnt = 1;
    int endT = vec[0].second;
    for (int i = 1; i < vec.size(); i++){
        if (vec[i].first >= endT){
            cnt++;
            endT = vec[i].second;
        }
    }
    cout << cnt;
    return 0;
}