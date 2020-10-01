// Problem: https://www.hackerrank.com/challenges/ctci-ransom-note/problem
// Score: 25

#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(){
    int m, n;
    cin >> m >> n;

    map<string, int> magazine;

    for (int i = 0; i < m; i++) {
        string word;
        cin >> word;

        if (magazine.find(word) == magazine.end()){
            magazine[word] = 1;
        }
        else {
            magazine[word]++;
        }
    }


    bool ans = true;
    for (int i = 0; i < n; i++){
        string word;
        cin >> word;

        if (magazine.find(word) == magazine.end() || magazine[word] == 0){
            ans = false;
            break;
        }
        else {
            magazine[word]--;
        }
    }


    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
