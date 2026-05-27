#include <iostream>
using namespace std;

int n;
bool card[100001];  // all is F

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        card[num] = true;
    }
    
    int A_cnt = 0;
    int B_cnt = 0;

    for (int i = 1; i <= 2 * n ; i++){
        if (card[i]){
            B_cnt++;
        }
        else if (B_cnt > A_cnt){
            A_cnt++;
        }
    }
    cout << A_cnt;

    return 0;
}