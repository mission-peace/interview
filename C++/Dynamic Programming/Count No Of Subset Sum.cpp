// WOOF!!
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define str string
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<ll,vector<ll>,greater<ll> > 
#define maxQueue priority_queue<ll,vector<ll>,less<ll> > 
#define deb1(x) cout<<#x<<" : "<<x<<endl;
#define deb2(x,y) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" : "<<x<<"   "<<#y<<" : "<<y<<"  "<<#z<<" : "<<z<<endl;
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);
#define RANDOM srand(time(NULL));
#define MOD 1000000007
#define NAX 1000005
#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN
#define MAX_NUM 200001

// n=3 sum=2
// 1 1 2
// 2 ({1,1}, {2})

ll countSubsetSum(vector<ll>a, ll sum){
	ll n=a.size();
	ll dp[n+1][sum+1];
	memset(dp,0,sizeof dp);

    // If we want sum as 0, then we can always find a subset with no values, null set.
	for(int i=0;i<=n;i++)
		dp[i][0]=1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(a[i-1]>j){       // current element is already greater than the sum we are trying to get. So, we cannot include the current element in our answer 
				dp[i][j]=dp[i-1][j];
			} else {            // we have two choices, either include the current element in our answer, or discard it. If we include the current element, 
                                //  then we check for the remaining elements and sum excluding the value of the current element added
				dp[i][j]=dp[i-1][j] + dp[i-1][j-a[i-1]];
			}
		}
	}
	return dp[n][sum];
}


int main(){
    FAST;
    ll i,j,k,n,m,t=1;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++){
    	cin>>a[i];
    }
    ll sum;
    cin>>sum;
    cout<<countSubsetSum(a,sum)<<endl;
    return 0;
}