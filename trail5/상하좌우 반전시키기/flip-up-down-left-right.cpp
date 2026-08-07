#include <iostream>
using namespace std;

int grid[103][103];
int n;

void change(int x, int y){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    grid[x][y] = grid[x][y] == 0 ? 1 : 0;
    for (int i = 0; i < 4; i++){
        grid[x + dx[i]][y + dy[i]] = grid[x + dx[i]][y + dy[i]] == 0 ? 1 : 0;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (grid[i - 1][j] == 0){
                change(i, j);
                cnt++;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (grid[n][i] == 0){
            cnt = -1;
            break;
        }
    }
    cout << cnt;
    return 0;
}