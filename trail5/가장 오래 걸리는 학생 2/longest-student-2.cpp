// n에서 모든 정점까지의 최단거리를 구하면 된다
// 이것도 양방향이니까 간선을 두개로 복제해서 실행
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M;
int i[100000], j[100000], d[100000];
const int INF = 2000000000;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> edges[200001];
int dist[100001];

int main() {
    cin >> N >> M;
    for (int k = 0; k < M; k++) {
        cin >> i[k] >> j[k] >> d[k];
        edges[i[k]].push_back({j[k],d[k]});
        edges[j[k]].push_back({i[k], d[k]});
    }

    for (int i = 0; i < N; i++){
        dist[i] = INF;
    }

    dist[N] = 0;
    pq.push({-0, N});
    // Please write your code here.

    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int min_index = pq.top().second;
        pq.pop();

        if (min_dist != dist[min_index])
            continue;

        for (int i = 0; i < edges[min_index].size(); i++){
            int target_dist, target_index;
            tie(target_index, target_dist) = edges[min_index][i];
            int new_dist = dist[min_index] + target_dist;
            if (new_dist < dist[target_index]){
                dist[target_index] = new_dist;
                pq.push({-new_dist, target_index});
            }
        }


    }


    // print
    int ans = 0;
    for (int i = 1; i < N; i++){
        ans = max(ans, dist[i]);
    }
    cout << ans << '\n';

    return 0;
}
