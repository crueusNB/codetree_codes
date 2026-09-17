#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int from[100000], to[100000], weight[100000];
int A, B;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> edges[1001];
int path[1001];
int dist[1001];
const int INF = 2000000000;

int main() {
    cin >> n >> m;

    // 양방향이에용
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        edges[from[i]].push_back({to[i], weight[i]});
        edges[to[i]].push_back({from[i], weight[i]});
    }

    cin >> A >> B;

    for (int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    dist[B] = 0;
    pq.push({-0, B});

    // Please write your code here.
    while(!pq.empty()){
        int min_dist, min_index;
        min_dist = -pq.top().first;
        min_index = pq.top().second;
        pq.pop();

        if (min_dist != dist[min_index])
            continue;

        for (int i = 0; i < edges[min_index].size(); i++){
            int target_index, target_dist;
            target_index = edges[min_index][i].first;
            target_dist = edges[min_index][i].second;

            if (dist[target_index] > dist[min_index] + target_dist){
                path[target_index] = min_index;
                dist[target_index] = dist[min_index] + target_dist;
                pq.push({-dist[target_index], target_index});
            }
        }
    }

    vector<int> ans;
    int x = A;
    ans.push_back(x);
    while (x != B){
        x = path[x];
        ans.push_back(x);
    }

    cout << dist[A] << '\n';
    for (int a : ans){
        cout << a << ' ';
    }
    
    return 0;
}
