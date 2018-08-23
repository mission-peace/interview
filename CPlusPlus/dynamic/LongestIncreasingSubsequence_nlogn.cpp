#include <iostream>
#include <cstdio>
using namespace std;

/**
 * Date 18/08/2015
 * @author Tushar Roy
 * Original code is in Java
 * https://github.com/mission-peace/interview/blob/master/src/com/interview/array/LongestIncreasingSubSequenceOlogNMethod.java
 * Code in Cpp by @azam58
 *
 * Given an array, find longest increasing subsequence in nlogn time complexity
 *
 * References
 * http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 * http://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/
 */
 
const int num = 1e6 + 5;
int a[num], t[num], r[num];


int binary_search( int p, int q, int g ){ // range is [p,q], key is g, using global arrays
	int low = p, high = q, mid ;
	while ( low <= high ){
		mid = (high + low)>>1;
// this can overflow. So, consider mid =  low + (high - low) / 2;
//		printf("%d %d %d %d\n", low, mid, high, t[mid]);

		if ( a[ t[mid] ] <= g) // instead of a[mid], we are now checking a[ t[mid] ].  And a[ t[mid] ] <= g searches for ceil.
			low = mid + 1;
		else
			high = mid - 1;
	}
	
	if ( a[ t[mid] ] < g ) mid++;
	return mid;
}


void recursion_print(int r[], int i){
	if (r[i] == -1 ) return ;
	recursion_print( r, r[i] );
	printf("%d ", a[ r[i] ]);
}

int main ()
{
//	freopen("test.txt","r",stdin);
// Our sample array is 3 4 -1 5 8 2 3 12 7 9 10

	int n, j, len = 0 ; cin >> n ;
	
	for ( int i = 0 ; i < n ; i++ ) scanf("%d", a + i);
	for ( int i = 0 ; i < n ; i++ ) r[i] = -1;
	
	t[0] = 0;
	
	for ( int i = 1 ; i < n ; i++ ){
		j = binary_search( 0, len, a[i]); // this always returns ceil index.
		if ( j > len ){
			len++;
		}
		if ( j > 0 ){
			r[i] = t[j-1];
		} // else r[i] remains -1
		t[j] = i;
	}
	for ( int i = 0 ; i < n ; i++ ){
		printf ("%d ", r[i] );
	}
	cout << endl;

	cout << " length of LIS is ->    "<< len + 1 <<endl;
	
	printf("%d ", a[ t[len] ]);
	for ( int i = t[len]; r[i] != -1 ; i = r[i] ) printf("%d ", a[ r[i] ]);
	cout <<   endl;
	
	recursion_print( r, t[len]);
	printf("%d ", a[ t[len] ]);
	cout <<   endl;

//	fclose(stdin);
    return 0;
}
