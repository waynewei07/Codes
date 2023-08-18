//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int mod=1e9+7;
const int mxn=1005;
ll dp[mxn][mxn];
ll pre[mxn][mxn];

int main() {_
    int n;
    cin>>n;
    // dp[i][j]= dp[i-1][0]+~dp[i-1][h-j]
    for(int i=0;i<mxn;i++){
        fill(pre[i],pre[i]+mxn,1);
    }
    for(int i=0;i<n;i++){
        int h;
        cin>>h;
        memset(dp,0,sizeof(dp));
        for(int j=0;j<=h;j++){
            for(int k=j;k<=h;k++){
                dp[j][k]=pre[j][j+h-k];
                /*if(j>0) dp[j][k]-=pre[j][j-1];
                dp[j][k]%=mod;
                if(dp[j][k]<0) dp[j][k]+=mod;*/
            }
        }
        for(int j=0;j<mxn;j++){
            pre[j][0]=dp[j][0];
            for(int k=1;k<mxn;k++){
                pre[j][k]=(pre[j][k-1]+dp[j][k])%mod;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<mxn;i++){
        //cout<<dp[i][i]<<' ';
        ans=(ans+dp[i][i])%mod;
    }
    if(n&1) cout<<ans<<'\n';
    else cout<<dp[0][0]<<'\n';
    return 0;
}
//maybe its multiset not set

