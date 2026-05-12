#include <iostream>
#include <queue>
#include <cmath>
using namespace std;


// 문제를 대충 읽으면 안됨 굉장히 굉장히 망해버렸다 지금
// 거쳐가는곳의 최대높이와 최소높이 차의 최솟값이네
// 
int n, m;
int board[100][100];
bool visited[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void Initialize(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
    visited[0][0] = true;
}

bool canGo(int x, int y){
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    if (visited[x][y])
        return false;

    return true;
}

// 인자로 좌표랑 최대 최소가 들어가야하겠죠? 그리고 target범위까지
// 이걸 bool 리턴하게 할까요
bool dfs(int x, int y, int maxNum, int minNum, int target){
    if (x == n - 1 && y == m - 1)
        return true;
        
    maxNum = max(maxNum, board[x][y]);
    minNum = min(minNum, board[x][y]);

    for (int i = 0; i < 4; i++){
        int curr_x = x + dx[i];
        int curr_y = y + dy[i];

        if (canGo(curr_x, curr_y) && abs(maxNum - board[curr_x][curr_y]) <= target
        && abs(minNum - board[curr_x][curr_y]) <= target){
            visited[curr_x][curr_y] = true;
            if (dfs(curr_x, curr_y, maxNum, minNum, target)){
                return true;
            }
            visited[curr_x][curr_y] = false;
        }
    }
    return false;
}

// target이 들어오면 그에대해 grid에서 bfs해주고 가능하면 true리턴
bool check(int target){
    Initialize();


    return dfs(0, 0, board[0][0], board[0][0], target);
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
        cout << "target : " << mid;
        if (check(mid)){
            cout << " true" << '\n';
            right = mid - 1;
            ans = mid;
        }
        else{
            cout << " false" << '\n';
            left = mid + 1;
        }
    }

    cout << ans;
    return 0;
}
