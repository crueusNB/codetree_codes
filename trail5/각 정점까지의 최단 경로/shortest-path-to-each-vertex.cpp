#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
int from[300000], to[300000], weight[300000];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> edges[20001];
int dist[20001];
const int INF = 10000000;

int main() {
    cin >> n >> m;
    cin >> k;

    for (int i = 1; i <= n; i++){
        dist[i] = INF;
    }
    dist[k] = 0;
    // 앞 가중치 , 뒤 정점 번호
    pq.push({-0, k});

    // 무방향 그래프라서 두개로 복제할까
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        edges[from[i]].push_back({to[i], weight[i]});
        edges[to[i]].push_back({from[i], weight[i]});
    }

    // Please write your code here.
    while (!pq.empty()){
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();

        min_dist = -min_dist;

        if (min_dist != dist[min_index]){
            continue;
        }

        for (int j = 0; j < edges[min_index].size(); j++){
            int target_index, target_dist;
            tie (target_index, target_dist) = edges[min_index][j];

            int new_dist = dist[min_index] + target_dist;
            if (dist[target_index] > new_dist){
                dist[target_index] = new_dist;
                pq.push({-new_dist, target_index});
            }
        }
    }



    //
    for (int i = 1; i <= n; i++){
        if (dist[i] == INF)
            dist[i] = -1;
        cout << dist[i] << '\n';
    }

    return 0;
}
