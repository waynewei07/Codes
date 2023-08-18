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

void solve(){
    int m,k,a,b;
    cin>>m>>k>>b>>a;
    int t=m/k;
    int use=(b-(m%k))/k;
    b-=k*use;
    a+=use;
    int ans=0;
    ans+=max(0,t-a);
    ans+=max(0,m%k-b);
    cout<<ans<<'\n';
}

int main() {_
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
//maybe its multiset not set

