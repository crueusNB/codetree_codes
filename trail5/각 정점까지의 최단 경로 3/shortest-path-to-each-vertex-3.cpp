#include <iostream>
#include <queue>
using namespace std;

int n, m;
int from[1000], to[1000], weight[1000];
int points[1002];
const int NOT_REACHED = -1;
queue<int> q;
int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
    }

    for (int i = 1; i <= n; i++){
        points[i] = NOT_REACHED;
    }
    
    q.push(1);
    points[1] = 0;

    while(!q.empty()){
        int p = q.front();
        q.pop();
        for (int i = 0; i < m; i++){
            if (from[i] == p){
                if (points[to[i]] == NOT_REACHED || points[to[i]] > points[from[i]] + weight[i]){
                    points[to[i]] = points[from[i]] + weight[i];
                    q.push(to[i]);
                }
            }
        }
    }

    // Please write your code here.
    for (int i = 2; i <= n; i++){
        cout << points[i] << '\n';
    }
    return 0;
}
