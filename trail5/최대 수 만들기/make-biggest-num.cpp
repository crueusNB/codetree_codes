#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<string> vec;

bool compare(string a, string b){
    string tmp1 = a + b;
    string tmp2 = b + a;

    if (stod(tmp1) > stod(tmp2))
        return true;
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n ; i++){
        string str;
        cin >> str;
        vec.push_back(str);
    }

    sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < n; i++){
        cout << vec[i];
    }
    return 0;
}