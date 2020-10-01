// Problem: https://www.hackerrank.com/challenges/abbr/problem
// Score: 40


#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    int q;
    cin >> q;

    for (int k = 0; k < q; k++){
        string s1, s2;
        cin >> s1 >> s2;

        vector<vector<bool>> dp (s2.size() + 1, vector<bool> (s1.size() + 1, false));

        dp[0][0] = true;

        for (int i = 1; i < s2.size() + 1; i++){
            dp[i][0] = false;
        }

        for (int i = 1; i < s1.size() + 1; i++){
            dp[0][i] = (islower(s1[i - 1])) && (dp[0][i - 1] == true);
        }

        for (int i = 1; i < s2.size() + 1; i++){
            for (int j = 1; j < s1.size() + 1; j++){
                if (islower(s1[j-1])){
                    dp[i][j] = (dp[i - 1][j - 1] && s2[i - 1] == toupper(s1[j - 1])) || dp[i][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && s2[i - 1] == s1[j - 1];
                }

            }
        }

        if (dp[s2.size()][s1.size()]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}


