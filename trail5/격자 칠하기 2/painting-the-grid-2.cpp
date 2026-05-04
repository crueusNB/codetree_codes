#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int n;
int board[100][100];
bool visited[100][100];
queue<pair<int, int>> q;


void Initialize(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
}

bool canGo(int x, int y){
    if (x < 0 || y < 0 || x >= n || y >= n)
        return false;

    if (visited[x][y])
        return false;

    return true;
}

int bfs(int target){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int cnt = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int curr_x = x + dx[i];
            int curr_y = y + dy[i];
            if (canGo(curr_x, curr_y) && abs(board[x][y] - board[curr_x][curr_y]) <= target){
                visited[curr_x][curr_y] = true;
                cnt++;
                q.push({curr_x, curr_y});
            }
        }
    }

    return cnt;
}

bool check(int target){
    Initialize();

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visited[i][j] == false){
                q.push({i, j});
                visited[i][j] = true;
                int cnt = bfs(target);
                // 디버깅 부분
                //cout << "now Target : " << target << " cnt : " << cnt << '\n';
                if (cnt >= (n * n + 1) / 2){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // Please write your code here.
    int left = 0;
    int right = 1000000;
    int ans;

    while (left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}