#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

/*
 *   Time complexity : O(log(n))
 */
 
template <typename T> int BinarySearch(T arr[],int n,float var){
	int start = 0,end = n-1;
	while(start <= end){
		int mid = (end+start)/2;
		if(arr[mid] == var){
			return mid;
		}
		else if(arr[mid] < var){
			start = mid + 1;
		}else{
			end = mid - 1;
		}
	}
	return -1;
}

int main(){
	float arr[10] = {12.23,3.45,32.33,4.23,90.67,6.34,54.12,23.45,65.77,77.32};
	sort(arr,arr+10);
	float x;cin>>x;
	int index = BinarySearch(arr,10,x);
	if(index==-1){
		cout<<"Number not found"<<endl;
	}else{
		cout<<"Number found at index : "<<index<<endl;
	}
	fflush(stdin);
	getchar();
	return 0;
}