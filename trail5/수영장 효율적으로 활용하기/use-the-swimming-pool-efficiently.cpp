#include <iostream>

using namespace std;

int n, m;
int T[100000];

bool check(long long target){
    int arr[100001];
    for (int i = 0; i < m; i++){
        arr[i] = 0;
    }
    int lane = 0;
    for (int i = 0; i < n; i++){
        if (lane >= m)
            return false;

        if (arr[lane] + T[i] <= target){
            arr[lane] += T[i];
        }
        else{
            lane++;
            i--;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }


    long long left = 1;
    long long right = 2000000000;
    long long ans;

    while (left <= right){
        long long mid = (left + right) / 2;
//        cout << "target : " << mid;
        if (check(mid)){
 //           cout << " T\n";
            right = mid - 1;
            ans = mid;
        }
        else{
            left = mid + 1;
//            cout << " F\n";
        }
    }

    cout << ans;
    
    return 0;
}
