// Problem: https://www.hackerrank.com/challenges/angry-children/problem
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

    sort(arr.begin(), arr.end());

    int ans = arr[k - 1] - arr[0];
    for (int i = 0; i < arr.size() - k + 1; i++){
        int tmp = arr[k - 1 + i] - arr[i];
        if (tmp < ans) ans = tmp;
    }

    cout << ans;
    return 0;
}
