// Problem: https://www.hackerrank.com/challenges/minimum-swaps-2/problem
// Score: 40


#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp - 1);
    }

    int i = 0;
    int ans = 0;
    while (i < n){
        if (arr[i] != i){
            swap(arr[i], arr[arr[i]]);
            ans++;
        }
        else{
            i++;
        }
    }

    cout << ans;

    return 0;
}
