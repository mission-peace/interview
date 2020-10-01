// Problem: https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
// Score: 20


#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, d;

    cin >> n;
    cin >> d;

    vector<int> arr;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    for (int i = 0; i < n; i++){
        cout << arr[(i + d) % n] << " ";
    }

    return 0;
}
