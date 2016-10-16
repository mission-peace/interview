#include<iostream>
#include<cstdlib>
using namespace std;

void getBiggestNumberfromArray(int arr[],int n,char ans[50])
{
	char temp[20];
	char XY[50],YX[50];
	char res[50];

	strcpy(res,itoa(arr[0],temp,10));
	strcpy(XY,temp);
	strcpy(YX,temp);

	for(int i=1 ; i<=n-1 ; i++)
	{
		itoa(arr[i],temp,10);

		strcat(XY,temp);
		strcpy(YX,strcat(temp,YX));

		if(strcmp(XY,YX) >= 0)
		{
			strcpy(res,XY);
			//swap()
		}
		else
			strcpy(res,YX);

		strcpy(XY,res);
		strcpy(YX,res);

		//cout<<endl<<res<<endl;
	}

	strcpy(ans,res);
	//ans = res;
}

int main()
{
	int arr[] = {1,34,3,98,9,76,45,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	char res[50] = " ";
	getBiggestNumberfromArray(arr,n,res);
	cout<<res;

	cin.get();
	cin.get();
	return 0;
}