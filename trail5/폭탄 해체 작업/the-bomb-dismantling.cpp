#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> vec;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++){
        int score, time;
        cin >> score >> time;
        vec.push_back({time, score});
    }

    sort(vec.begin(), vec.end());

    int firstT = vec[0].first;
    int sum = vec[0].second;

    for (int i = 1; i < n; i++){
        if (firstT == vec[i].first){
            sum -= vec[i - 1].second;
        }
        sum += vec[i].second;
        firstT = vec[i].first;
    }


    cout << sum;

    return 0;
}