#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int left = 0;
    int right = n - 1;
    int cnt = 0;

    while(a != b){
        while(a[left] == b[left]){
            left++;
            if (left > right){
                break;
            }
        }

        while(a[right] == b[right]){
            right--;
            if (left > right)
                break;
        }

        for (int i = left; i <= right; i++){
            if (a[i] == 'G'){
                a[i] = 'H';
            }
            else{
                a[i] = 'G';
            }
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}