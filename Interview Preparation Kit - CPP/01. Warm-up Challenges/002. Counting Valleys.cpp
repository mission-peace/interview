// Problem: https://www.hackerrank.com/challenges/counting-valleys/problem
// Score: 15

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    int ans = 0;

    int current_level = 0;

    for (char c: str){
        if (c == 'D') {
            if (current_level == 0){
                ans++;
            }

            current_level--;
        }

        else if (c == 'U') current_level++;
    }

    cout << ans;

    return 0;
}
