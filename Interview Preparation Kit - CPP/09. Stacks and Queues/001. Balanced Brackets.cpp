// Problem: https://www.hackerrank.com/challenges/balanced-brackets/problem
// Score: 25


#include <iostream>
#include <vector>
using namespace std;


int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        string str;
        cin >> str;
        vector<char> brackets;

        bool ans = true;

        for (char c: str){
            if (c == ')' || c == ']' || c == '}'){
                if  ((!brackets.empty()) && (
                        (c == ')' && brackets.back() == '(') ||
                        (c == ']' && brackets.back() == '[') ||
                        (c == '}' && brackets.back() == '{'))){
                    brackets.pop_back();
                }
                else {
                    ans = false;
                    break;
                }
            }
            else brackets.push_back(c);
        }

        if (ans && brackets.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}

