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

// Given a boolean expression, calculate the number of ways parenthesis can be applied on the string so that it evaluates to true.  
// s: nitik
// ans: 2 ( n | iti | k) -> 2 partitions

ll evalToTrue(string s, ll i, ll j, bool isTrue){
    if(i>j)
        return 0;
    
    ll ans=0;

    if(i==j){
        if(isTrue)
            return s[i]=='T';
        else
            return s[i]=='F';
    }

    for(ll k=i+1;k<=j-1;k=k+2){
        ll lt = evalToTrue(s,i,k-1,true);
        ll lf = evalToTrue(s,i,k-1,false);
        ll rt = evalToTrue(s,k+1,j,true);
        ll rf = evalToTrue(s,k+1,j,false);

        if(s[k]=='&'){
            if(isTrue){
                ans+=lt*rt;
            } else {
                ans+=(lt*rf)+(lf*rt)+(lf*rf);
            }
        } else if(s[k]=='|'){
            if(isTrue){
                ans+=(lt*rt)+(lt*rf)+(lf*rt);
            } else {
                ans+=lf*rf;
            }
        } else {
            if(isTrue){
                ans+=(lt*rf)+(lf*rt);
            } else {
                ans+=(lt*rt)+(lf*rf);
            }
        }
    }
    return ans;
}


int main(){
    FAST;
    ll i,j,k,n,m,t=1;
    string s;
    cin>>s;
    n = s.size();
    cout<<evalToTrue(s,0,n-1)<<endl;
    return 0;
}