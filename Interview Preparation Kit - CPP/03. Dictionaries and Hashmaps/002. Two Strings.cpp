// Problem: https://www.hackerrank.com/challenges/two-strings/problem
// Score: 25


#include <iostream>
#include <set>
#include <string>
using namespace std;


int main(){
    int p;
    cin >> p;

    for (int i = 0; i < p; i++){
        string s1, s2;
        cin >> s1 >> s2;

        set<char> letters;

        for (char c: s1){
            letters.insert(c);
        }

        bool ans = false;
        for (char c: s2){
            if (letters.find(c) != letters.end()){
                ans = true;
                break;
            }
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
