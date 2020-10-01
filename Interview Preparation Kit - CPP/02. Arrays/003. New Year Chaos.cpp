// Problem: https://www.hackerrank.com/challenges/new-year-chaos/problem
//  Score: 40

#include <iostream>
#include <vector>
using namespace std;


bool check_sorted(vector<int> & arr){
    bool ans = true;
    for (int i = 0; i < arr.size() - 1; i++){
        if (arr[i] > arr[i + 1]){
            ans = false;
        }
    }
    return ans;
}


int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> arr;

        for (int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }

        int ans = 0;

        for (int j = 0; j < 2; j++){
            for (int k = arr.size() - 1; k > 0; k--){
                if (arr[k] < arr[k - 1]){
                    swap(arr[k], arr[k - 1]);
                    ans++;
                }
            }
        }

        if (check_sorted(arr)){
            cout << ans << endl;
        }
        else {
            cout << "Too chaotic" << endl;
        }

    }

    return 0;
}
