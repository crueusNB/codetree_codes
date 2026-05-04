// 색칠된 칸중 하나에서 bfs를 떄렸을떄 다른 원래 칸이 방문처리 되어있지 않다면 불가능

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N;
int board[100][100];
int colored[100][100];
queue<pair<int, int>> q;
vector<pair<int,int>> vec;
bool visited[100][100];

void Initialize(){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            visited[i][j] = false;
        }
    }
}

bool canGo(int x, int y){
    if (x < 0 || y < 0 || x >= M || y >= N)
        return false;
    if (visited[x][y])
        return false;
    
    return true;
}


void bfs(int target){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int curr_x = x + dx[i];
            int curr_y = y + dy[i];

            if (canGo(curr_x, curr_y) && abs(board[x][y] - board[curr_x][curr_y]) <= target){
                q.push({curr_x, curr_y});
                visited[curr_x][curr_y] = true;
            }
        }
    }

}

bool check(int target){
    Initialize();
    q.push(vec[0]);
    visited[vec[0].first][vec[0].second] = true;
    bfs(target);

    for (int i = 1; i < vec.size(); i++){
        int x = vec[i].first;
        int y = vec[i].second;

        if (!visited[x][y])
            return false;
    }
    return true;
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> colored[i][j];
            if (colored[i][j] == 1){
                vec.push_back({i, j});
            }
        }
    }

    // Please write your code here.
    int left = 0;
    int right = 1000000000;
    int ans = 1000000000;
    while (left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    cout << ans;
    return 0;
}
