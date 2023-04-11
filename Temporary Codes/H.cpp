#pragma GCC optimize("O3")
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

const int mxn=2e5+5;
ll dp[mxn];
ll tmp[mxn];
ll a[mxn];
ll pre[mxn];

int main() {_
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    for(int j=1;j<=m;j++){
        deque<int> q;
        q.push_back(0);
        for(int i=1;i<=n;i++){
            while(!q.empty() and dp[i]-pre[i]>=dp[q.back()]-pre[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            while(!q.empty() and pre[i]-pre[q.front()]>k){
                q.pop_front();
            }
            tmp[i]=tmp[i-1];
            if(!q.empty()){
                tmp[i]=max(tmp[i],dp[q.front()]+pre[i]-pre[q.front()]);
            }
        }
        for(int i=1;i<=n;i++){
            dp[i]=tmp[i];
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans;
    return 0;
}
//maybe its multiset not set
