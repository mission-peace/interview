// Problem: https://www.hackerrank.com/challenges/repeated-string/problem
// Score: 20


#include <iostream>
#include <string>

using namespace std;


long long count(string const & str){
    long long ans = 0;
    for (const char & c: str){
        ans += c == 'a';
    }
    return ans;
}


int main(){
    string str;
    cin >> str;

    long long n;
    cin >> n;

    long long ans = 0;
    ans = n / str.size() * count(str) + count(str.substr(0, n % str.size()));

    cout << ans;
    return 0;
}
