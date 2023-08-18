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

const int mxn=1e6+5;
const int mod=1e9+7;
ll pre[mxn],inv[mxn];

ll fpow(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int main() {_
    pre[0]=inv[0]=1;
    for(int i=1;i<mxn;i++){
        pre[i]=pre[i-1]*i%mod;
        inv[i]=fpow(pre[i],mod-2);
    }
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]/=2;
    }
    ll ans=1;
    for(int i=0;i<(n-1);i++){
        if(a[i]>=a[i+1]){
            ans=ans*pre[a[i]]%mod*inv[a[i+1]]%mod*inv[a[i]-a[i+1]]%mod;
        }
        else{
            ans=ans*pre[a[i+1]-1]%mod*inv[a[i]-1]%mod*inv[a[i+1]-a[i]]%mod;
        }
    }
    cout<<ans;
    return 0;
}
//maybe its multiset not set

