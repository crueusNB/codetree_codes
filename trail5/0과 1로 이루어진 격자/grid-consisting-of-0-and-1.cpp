#include <iostream>
using namespace std;


int n;
int grid[11][11];

void change(int x, int y){
    for (int i = x; i >= 0; i--){
        for (int j = y; j >= 0; j--){
            grid[i][j] = grid[i][j] == 0 ? 1 : 0;
        }
    }
}

void print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        for (int j = 0; j < n; j++){
            grid[i][j] = str[j] == '0' ? 0 : 1;
        }
    }

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            if(grid[i][j] == 1){
                change(i, j);
                cnt++;
            }
        }
    }


    cout << cnt;

    return 0;
}