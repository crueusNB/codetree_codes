#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

    int sum = 0;
    int time = 0;
    priority_queue<int, vector<int>, greater<int>> scores;

    for (int i = 0; i < n; i++){
        if (vec[i].first > time){
            scores.push(vec[i].second);
            time++;
        }
        else{
            if (!scores.empty() && scores.top() < vec[i].second){
                scores.pop();
                scores.push(vec[i].second);
            }
        }
    }

    while (!scores.empty()){
        sum += scores.top();
        scores.pop();
    }

    cout << sum;


    return 0;
}