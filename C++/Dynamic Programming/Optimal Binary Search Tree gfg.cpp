/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|     ( website: himanshu010.github.io/Portfolio_website )  |
|                                                           |
|                                                           |
*-----------------------------------------------------------*
*/
#include<bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
using namespace std;

void findMinConfig(vi keys, vi value, int n) {
    vector<vector<P>>dp(n, vector<P>(n));
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = {value[i], i};
    }
    int cur = 1;
    while (cur <= n) {
        int start = 0;
        int end = start + cur;

        while (end < n) {
            int total = 0;
            int mn = INT_MAX;
            int root = start;
            for (int i = start; i <= end; ++i)
            {
                total += value[i];
                if (i == start) {
                    mn = min(mn, dp[i + 1][end].F);
                    if (mn == dp[i + 1][end].F) {
                        root = i;
                    }

                }
                else if (i == end) {
                    mn = min(mn, dp[start][i - 1].F);
                    if (mn == dp[start][end - 1].F) {
                        root = i;
                    }
                }
                else {
                    mn = min(mn, dp[start][i - 1].F + dp[i + 1][end].F);
                    if (mn == dp[start][i - 1].F + dp[i + 1][end].F) {
                        root = i;
                    }
                }
            }
            dp[start][end].F = total + mn;
            dp[start][end].S = root;
            start = start + 1;
            end = end + 1;
        }
        cur++;

    }

    for (auto x : dp) {
        for (auto y : x) {
            cout << y.F << ',' << y.S << ' ';
        }
        cout << endl;
    }

    cout << dp[0][n - 1].F << endl;
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> keys(n), value(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> keys[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> value[i];
    }

    findMinConfig(keys, value, n);

}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}