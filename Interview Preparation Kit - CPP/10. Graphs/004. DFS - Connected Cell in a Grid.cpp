// Problem: https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem
// Score: 45


#include <iostream>
#include <vector>
using namespace std;


void count_nodes(vector<vector <int>> const & arr, vector<vector <bool>> & visited, int i, int j, int & count){
    if (visited[i][j]) return;

    visited[i][j] = true;
    if (arr[i][j] == 0) return;
    if (i != 0) count_nodes(arr, visited, i - 1, j, count);
    if (i != 0 && j != 0) count_nodes(arr, visited, i - 1, j - 1, count);
    if (i != 0 && j != arr[0].size() - 1) count_nodes(arr, visited, i - 1, j + 1, count);
    if (j != 0) count_nodes(arr, visited, i, j - 1, count);
    if (j != arr[0].size() - 1) count_nodes(arr, visited, i, j + 1, count);
    if (i != arr.size() - 1) count_nodes(arr, visited, i + 1, j, count);
    if (i != arr.size() - 1 && j != 0) count_nodes(arr, visited, i + 1, j - 1, count);
    if (i != arr.size() - 1 && j != arr[0].size() - 1) count_nodes(arr, visited, i + 1, j + 1, count);
    count++;
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector <int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector <bool>> visited(n, vector<bool>(m, false));


    int ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int count = 0;
            count_nodes(arr, visited, i, j, count);
            if (count > ans){
                ans = count;
            }
        }
    }

    cout << ans;

    return 0;
}
