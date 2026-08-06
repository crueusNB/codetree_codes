#include <iostream>
#include <string>
using namespace std;

int n;
string a;
string b;

void change(int num){
    for (int i = 0; i < num; i++){
        a[i] = a[i] == 'G' ? 'H' : 'G';
    }
}

int main() {
    cin >> n;
    cin >> a >> b;

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--){
        if (a[i] != b[i]){
            change(i);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}