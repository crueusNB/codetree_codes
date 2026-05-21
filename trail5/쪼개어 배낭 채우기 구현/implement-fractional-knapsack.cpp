#include <iostream>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int n, m;
vector<tuple<double, int, int>> vec;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int w, v;
        cin >> w >> v;
        double perV = double(v) / w;
        vec.push_back(make_tuple(perV, w, v));
    }
    sort(vec.rbegin(), vec.rend());

    int weightSum = 0;
    double sum = 0;
    for (int i = 0; i < vec.size(); i++){
        double perV;
        int w, v;
        tie(perV, w, v) = vec[i];
        if (weightSum + w <= m){
            weightSum += w;
            sum += v;
        }
        else{
            sum += perV * (m - weightSum);
            break;
        }
    }
    cout << fixed << setprecision(3) << sum;
    return 0;
}