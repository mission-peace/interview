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

// Q: Find the maximum number of ways to make a change from the infinite supply of coins

// n=3 sum=5
// coins[]: 1 2 3
// Ans: 5

ll coinChangeMaxNoOfWays(vector<ll>coins, ll sum){
	ll n=coins.size();
	ll dp[n+1][sum+1];
	memset(dp,0,sizeof dp);

    // If sum is zero, then we have just one way of making the change, include nothing in our answer set
    for(int i=0;i<=n;i++)
        dp[i][0]=1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(coins[i-1]>j){       // current element is already greater than the sum we are trying to get. So, we cannot include the current element in our answer 
				dp[i][j]=dp[i-1][j];
			} else {            // we add both the choices, the first choice is to include the current coin in our answer set, 
                                // and the other choice is to discard the current coin 
				dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
			}
		}
	}
	return dp[n][sum];
}


int main(){
    FAST;
    ll i,j,k,n,m,t=1;
    cin>>n;
    vector<ll>coins(n);
    for(i=0;i<n;i++){
    	cin>>coins[i];
    }
    ll sum;
    cin>>sum;
    cout<<coinChangeMaxNoOfWays(coins,sum)<<endl;
    return 0;
}