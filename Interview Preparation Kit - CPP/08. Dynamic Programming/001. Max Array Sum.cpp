// Problem: https://www.hackerrank.com/challenges/max-array-sum/problem
// Score: 20


#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++){
        dp[i] = max(max(dp[i-2] + arr[i], dp[i - 1]), arr[i]);
    }

    cout << dp[n - 1];

    return 0;
}
