// Problem: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
// Score: 20


#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    int element;
    vector<int> arr;

    while (cin >> element){
        arr.push_back(element);
    }

    int ans = 0;
    int position = 0;

    while (position < n - 1){
        position ++;
        if (position + 1 <= n - 1 && arr[position + 1] != 1){
            position ++;
        }
        ans ++;
    }

    cout << ans;

    return 0;
}
