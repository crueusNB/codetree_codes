#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[100][100];
bool visited[100][100];

void Initialize(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
}

void bfs(int target){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});
    int firstValue = board[0][0];

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int curr_x = x + dx[i];
            int curr_y = y + dy[i];

            if (curr_x < 0 || curr_y < 0 || curr_x >= n || curr_y >= m)
                continue;
            if (visited[curr_x][curr_y])
                continue;
            
            if (abs(board[curr_x][curr_y] - firstValue) <= target){
                q.push({curr_x, curr_y});
                visited[curr_x][curr_y] = true;
            }
        }
    }
}

// target이 들어오면 그에대해 grid에서 bfs해주고 가능하면 true리턴
bool check(int target){
    Initialize();
    bfs(target);

    return visited[n - 1][m - 1];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // Please write your code here.
    // mid 는 높이차
    int left = 0;
    int right = 500;
    int ans;
    while (left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            right = mid - 1;
            ans = mid;
        }
        else{
            left = mid + 1;
        }
    }

    cout << ans;
    return 0;
}
