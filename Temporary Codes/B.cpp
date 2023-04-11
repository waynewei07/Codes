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

const int mxn=5e5+5;
vector<pair<int,int>> adj[mxn];
int c[mxn];
bool visited[mxn];
int n,m;

bool dfs(int v,int k){
    visited[v]=true;
    for(auto u:adj[v]){
        if(u.s<=k) continue;
        if(visited[u.f]){
            if(c[u.f]==c[v]) return false;
            continue;
        }
        c[u.f]=1-c[v];
        if(dfs(u.f,k)==false) return false;
    }
    return true;
}

bool check(int mid){
    for(int i=1;i<=n;i++){
        c[i]=0;
        visited[i]=false;
    }
    for(int i=1;i<=n;i++){
        if(!dfs(i,mid)) return false;
    }
    return true;
}

int main() {_
    cin>>n>>m;
    int mx=1;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mx=max(mx,c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l;
    return 0;
}
//maybe its multiset not set
