// Problem: https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem
// Score: 35


#include <iostream>
#include <map>
using namespace std;


int main(){
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++){
        int money, n;
        cin >> money >> n;
        map<int, int> arr;

        for (int j = 0; j < n; j++){
            int c;
            cin >> c;

            if (arr.find(c) == arr.end()){
                arr[money - c] = j + 1;
            }
            else{
                cout << arr[c] << " " << j + 1 << '\n';
            }
        }
    }
    return 0;
}
