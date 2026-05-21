#include <iostream>
#include <queue>
using namespace std;

int n;

int main() {
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    long long sum = 0;
    while(pq.size() != 1){
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();

        sum += num1 + num2;
        pq.push(num1 + num2);
    }
    cout << sum;
    
    
    
    return 0;
}