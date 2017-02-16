#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

/*
 *		Jumps the search loop by step = sqrt(n)
 *		Performs Linear Search on smaller region in which there is possibility of number.
 *		Time complexity O((sqrt(n)).... Better than Linear Search 
 */ 

template <typename T> int JumpSearch(T arr[],int n,T var){
	int step = (int)sqrt(n),prev=-step;
	for(int i=0;i<n;i=i+step){
		if(arr[i]==var)return i;
		if(arr[i]>var){
			break;
		}else
			prev += step;
	}
	for(int i=prev;i<prev+step;i++){
		if(arr[i] == var)return i;
	}
	return -1;
}

int main(){
	float arr[10] = {12.23,3.45,32.33,4.23,90.67,6.34,54.12,23.45,65.77,77.32};
	sort(arr,arr+10);
	float x;cin>>x;
	int index = JumpSearch(arr,10,x);
	if(index==-1){
		cout<<"Number not found"<<endl;
	}else{
		cout<<"Number found at index : "<<index<<endl;
	}
	fflush(stdin);
	getchar();
	return 0;
}