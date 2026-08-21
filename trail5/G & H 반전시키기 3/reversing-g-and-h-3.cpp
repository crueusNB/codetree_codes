#include <iostream>
#include <string>
using namespace std;


int main() {
    int n;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;

    int cnt = 0;
    for (int i = 0; i < str1.length(); i++){
        if (str1[i] != str2[i]){
            cnt++;
            for (int j = 0; j < 4; j++){
                if (str1[j] != str2[j]){
                    str1[j] = str2[j];
                }
                else{
                    break;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}