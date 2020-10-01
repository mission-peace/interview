// Problem: https://www.hackerrank.com/challenges/greedy-florist/problem
// Score: 35


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr;

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.rbegin(), arr.rend());

    int ans = 0;
    int mult = 0;
    for (int i = 0; i < n; i++){
        if (i % k == 0) mult++;
        ans += arr[i] * mult;
    }

    cout << ans;

    return 0;
}
