// Problem: https://www.hackerrank.com/challenges/candies/problem
// Score: 50


#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> up (n, 1);
    vector<int> down (n, 1);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++){
        if (arr[i] > arr[i - 1]){
            up[i] = up[i - 1] + 1;
        }

        if (arr[n - i - 1] > arr[n - i]){
            down[n - i - 1] = down[n - i] + 1;
        }
    }

    long long int ans = 0;
    for (int i = 0; i < n; i++){
        ans += max(up[i], down[i]);
    }

    cout << ans;

    return 0;
}
