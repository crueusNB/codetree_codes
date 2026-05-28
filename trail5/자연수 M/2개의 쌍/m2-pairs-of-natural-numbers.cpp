/*
    {정수, 개수} 이렇게 쌍으로 저장하고 이걸 정렬을 때리면 일단 메로리는 초과하지 않음
    이제 여기서 점점 중앙쪽으로 가면서 값계산및 비교를 해주면 되겠죠?
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++){
        int cnt;
        int num;
        cin >> cnt >> num;
        for (int j = 0; j < cnt ; j++){
            vec.push_back({num, cnt});
        }
    }
    sort(vec.begin(), vec.end());

    int maxNum = 0;
    int left_idx = 0;
    int right_idx = n - 1;

    while (left_idx <= right_idx){
        int& left = vec[left_idx].second;
        int& right = vec[right_idx].second;

        if (left == right){
            left = right = 0;
            maxNum = max(maxNum, vec[left_idx].first + vec[right_idx].first);
            left_idx++;
            right_idx--;
        }
        else if (left > right){
            left -= right;
            right = 0;
            maxNum = max(maxNum, vec[left_idx].first + vec[right_idx].first);
            right_idx--;
        }
        else{
            right -= left;
            left = 0;
            maxNum = max(maxNum, vec[left_idx].first + vec[right_idx].first);
            left_idx++;
        }
    }
    cout << maxNum;
    return 0;
}