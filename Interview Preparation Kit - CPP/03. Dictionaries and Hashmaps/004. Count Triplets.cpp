// Problem: https://www.hackerrank.com/challenges/count-triplets-1/problem
// Score: 25


#include <iostream>
#include <map>
using namespace std;


struct custom_int{
    long long int value = 0;
};


int main(){
    int n, r;
    cin >> n >> r;
    map<long long int, custom_int> arr2;
    map<long long int, custom_int> arr3;

    long long int ans = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        ans += arr3[tmp].value;
        arr3[tmp * r].value += arr2[tmp].value;
        arr2[tmp * r].value++;
    }

    cout << ans;

    return 0;
}
