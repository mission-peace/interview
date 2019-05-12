#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::max;

//This method will maximize the price of items in the knapsack problem

int bottomUpDp(vector<int>& weight,vector<int>& price, int max_wt){
    int items = weight.size();
    vector<vector<int>> sack(items+1,vector<int>(max_wt));
    for(int i=0; i<items+1; i++){
        for(int j=0; j<=max_wt; j++){
            if(i==0 || j==0){
                sack[i][j] = 0;
                continue;
            }
            if(j-weight[i-1] >= 0){
                sack[i][j] = max(sack[i-1][j], sack[i-1][j-weight[i-1]] + price[i-1]);
            }
            else{
               sack[i][j] = sack[i-1][j];
            }
        }
    }
    return sack[items][max_wt];
}

int main(){
    vector<int> weight{2,3,4,5};
    vector<int> price{1,2,5,6};
    int max_wt = 8;
    int max_price = bottomUpDp(weight,price,max_wt);
    cout << "Maximum price : " << max_price;
    return 0;
}
