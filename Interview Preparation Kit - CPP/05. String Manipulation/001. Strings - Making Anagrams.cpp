// Problem: https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
// Score: 25


#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s1, s2;
    cin >> s1 >> s2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    int i = 0;
    int j = 0;
    int ans = 0;
    while (i < s1.size() || j < s2.size()){
        if (i >= s1.size()){
            j++;
            ans++;
        }
        else if (j >= s2.size()){
            i++;
            ans++;
        }
        else if (s1[i] == s2[j]){
            i++;
            j++;
        }
        else if (s1[i] < s2[j]){
            ans++;
            i++;
        }
        else if (s2[j] < s1[i]){
            ans++;
            j++;
        }
    }

    cout << ans;

    return 0;
}
