// Problem: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
// Score: 50


#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


int main(){
    int n;
    cin >> n;
    for (int t = 0; t < n; t++){
        string str;
        cin >> str;

        map<string, int> lib;

        for (int i = 1; i < str.size(); i++){
            for (int j = 0; j < str.size() - i + 1; j++){
                string tmp = str.substr(j, i);
                sort(tmp.begin(), tmp.end());

                if (lib.find(tmp) != lib.end()){
                    lib[tmp]++;
                }
                else {
                    lib[tmp] = 1;
                }

            }
        }

        int ans = 0;
        for (auto const & el: lib){
            ans += el.second * (el.second - 1) / 2;
        }

        cout << ans << endl;
    }

    return 0;
}