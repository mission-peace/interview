// Problem: https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
// Score: 35


#include <iostream>
#include <string>
#include <map>
using namespace std;


struct default_zero_int{
    int val = 0;
};


int main(){
    string str;
    cin >> str;

    map<char, default_zero_int> arr;

    for (char c: str){
        arr[c].val++;
    }

    map<char, default_zero_int> counts;

    for (auto el: arr){
        counts[el.second.val].val++;
    }

    if (counts.size() <= 1){
        cout << "YES";
    }
    else if (counts.size() > 2){
        cout << "NO";
    }
    else {
        auto el1 = *counts.begin();
        auto el2 = *(next(counts.begin(), 1));

        if (((el1.first == 1 && el1.second.val == 1) || (el2.first == 1 && el2.second.val == 1)) ||
        ((el1.second.val == 1 || el2.second.val == 1) && (abs(el1.first - el2.first) == 1))){
            cout << "YES";
        }
        else cout << "NO";
    }

    return 0;
}
