#pragma GCC optimize("O4")
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

const int mod=487634879;
const int mxn=4e4+5;
int dp[mxn];

int main() {_
    int n,m;
    cin>>n>>m;
    // dp[i][j]=dp[i-1][j]*j+dp[i-1][j-1]*(m-(j-1))
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp[j]=(1ll*dp[j]*j%mod+1ll*dp[j-1]*(m-(j-1))%mod);
            if(dp[j]>=mod) dp[j]-=mod;
        }
        dp[0]=0;
    }
    cout<<dp[m];
    return 0;
}
//maybe its multiset not set
