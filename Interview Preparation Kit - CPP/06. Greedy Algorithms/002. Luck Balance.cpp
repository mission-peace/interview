// Problem: https://www.hackerrank.com/challenges/luck-balance/problem
// Score: 20


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    int n, k;
    cin >> n >> k;

    int ans = 0;
    vector <int> arr;

    for (int i = 0; i < n; i++){
        int l, t;
        cin >> l >> t;

        if (t == 0) ans += l;
        else arr.push_back(l);
    }

    sort(arr.rbegin(), arr.rend());

    for (int i = 0; i < arr.size(); i++){
        if (i < k) ans += arr[i];
        else ans -= arr[i];
    }

    cout << ans;

    return 0;
}
