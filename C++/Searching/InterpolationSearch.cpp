#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

/*
 *    Improved varaint of Binary Search.
 *    Performs Search in  O(log(log(n)))... 
 *	  Requires Array in sorted form.	
 */
 
template <typename T> int InterpolationSearch(T arr[],int n,T var){
	int start = 0,end = n-1;
	while(start<=end && var>=arr[start] && var<=arr[end]){
		int pos = start + (((double)(var-arr[start])*(end-start))/(arr[end]-arr[start]));
		if(arr[pos] == var)return pos;
		if(arr[pos]<var){
			start = pos+1;
		}else{
			start = pos-1;
		}
	}
	return -1;
}

int main(){
	float arr[10] = {12.23,3.45,32.33,4.23,90.67,6.34,54.12,23.45,65.77,77.32};
	sort(arr,arr+10);
	float x;cin>>x;
	int index = InterpolationSearch(arr,10,x);
	if(index==-1){
		cout<<"Number not found"<<endl;
	}else{
		cout<<"Number found at index : "<<index<<endl;
	}
	fflush(stdin);
	getchar();
	return 0;
}