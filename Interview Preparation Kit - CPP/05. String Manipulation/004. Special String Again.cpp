// Problem: https://www.hackerrank.com/challenges/special-palindrome-again/problem
// Score: 40


#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<pair<char, int>> arr;
    arr.push_back(make_pair(str[0], 0));

    for (char c: str){
        if (c == arr.back().first){
            arr.back().second++;
        }
        else {
            arr.push_back(make_pair(c, 1));
        }
    }

    int ans = 0;
    for (int i = 0; i < arr.size(); i++){
        ans += (arr[i].second + 1) * arr[i].second / 2;
        if ((i != 0) && (i != arr.size() - 1) && (arr[i].second == 1) && (arr[i - 1].first == arr[i + 1].first)){
            ans += min(arr[i - 1].second, arr[i + 1].second);
        }
    }

    cout << ans;
    return 0;
}
