#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++){
        int cnt;
        int num;
        cin >> cnt >> num;
        for (int j = 0; j < cnt ; j++){
            vec.push_back(num);
        }
    }
    sort(vec.begin(), vec.end());
    int maxNum = 0;
    for (int i = 0; i < vec.size() / 2; i++){
        int sum = vec[i] + vec[n - i - 1];
        maxNum = max(sum, maxNum);
    }
    cout << maxNum;

    return 0;
}