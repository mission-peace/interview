// Problem: https://www.hackerrank.com/challenges/alternating-characters/problem
// Score: 20


#include <iostream>
#include <string>
using namespace std;


int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;


        char prev = '0';
        int ans = 0;

        for (char c: str){
            if (c == prev) {
                ans++;
            }
            prev = c;
        }

        cout << ans << '\n';
    }

    return 0;
}
