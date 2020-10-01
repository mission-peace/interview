// Problem: https://www.hackerrank.com/challenges/crush/problem
// Score: 60


#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    vector<long long int> arr(n, 0);

    for (int i = 0; i < m; i++){
        int start, finish, value;
        cin >> start >> finish >> value;
        arr[start - 1] += value;
        arr[finish] -= value;
    }

    long long int ans = 0;
    long long int current = 0;

    for (int value: arr){
        current += value;
        if (current > ans){
            ans = current;
        }
    }

    cout << ans;

    return 0;
}
