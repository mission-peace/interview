#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int calculate(int val[], int wt[], int W){
        int K[sizeof(val)/sizeof(val[0])][W+1];
        for(i=0;i<sizeof(sizeof(val)/sizeof(val[0]));i++){
                K[i][0]=0;
        }
        for(j=0;j<W+1;j++){
                K[0][j]=1;
        }

        for(int i=1; i < sizeof(val)/sizeof(val[0]); i++){
            for(int j=0; j <= W; j++){
                
                if(j - wt[i] >= 0){
                    K[i][j] = max(K[i-1][j], K[i-1][j-wt[i]] + val[i]);
                }else{
                    K[i][j] = K[i-1][j];
                }
            }
        }
        return K[sizeof(val)/sizeof(val[0])][W];
    }

    int main(){

        int val[] = {60,20,15,30};
        int wt[] = {4,2,3,5};
        int r = calculate(val, wt, 8);
        cout<<r;
    return 0;
    }

