// Problem: https://www.hackerrank.com/challenges/largest-rectangle/problem
// Score: 50


#include <iostream>
#include <vector>
using namespace std;


void update_ans(long long int & ans, int i, vector<int> & positions, vector<int> & heights){
    long long int square;
    square = heights.back() * (i - positions.back());
    ans = max(ans, square);
    heights.pop_back();
    positions.pop_back();
}


int main (){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> positions;
    vector<int> heights;

    long long int ans = 0;

    for (int i = 0; i < n; i++){
        if (heights.empty() || arr[i] > heights.back()){
            heights.push_back(arr[i]);
            positions.push_back(i);
        }

        else if (arr[i] < heights.back()){
            int last_position = positions.back();

            while (!heights.empty() && heights.back() > arr[i]){
                last_position = positions.back();
                update_ans(ans, i, positions, heights);
            }
            positions.push_back(last_position);
            heights.push_back(arr[i]);
        }
    }

    while (!heights.empty()){
        update_ans(ans, n, positions, heights);
    }

    cout << ans;

    return 0;
}
