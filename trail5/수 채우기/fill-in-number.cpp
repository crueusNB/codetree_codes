#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    
    int cnt = 0;
    cnt += n / 5;
    
    int res = n % 5;

    if (res % 2 == 0){
        cnt += res / 2;
    }
    else{
        if (n == res){
            cnt = -1;
        }
        else{
            res += 5;
            cnt--;
            cnt += res / 2;
        }
    }
    cout << cnt;

    return 0;
}