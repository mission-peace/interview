#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
vector <int> A;
A.push_back(1); A.push_back(2);  A.push_back(3); 
int n = A.size();
   int count = 0; 
   for(int i=n-1;i>=0;i--){
       if(A[i]==9) count++;
       else break;
   }
   if(count == n){
       cout<<"1 ";
       for(int i=1;i<=n;i++) cout<<"0 ";
   }
   else{
       int l = n-count-1;
       int flag = 0;
       for(int i=0;i<l;i++) if(A[i]!=0 || (flag!=0 && A[i]==0)) {flag = 1;cout<<A[i]<<" ";} else if(A[i]==0 && flag == 0);
       cout<<A[l] + 1<<" ";
       for(int i=1;i<=count;i++) cout<<"0 ";
   }
   return 0;
   }
