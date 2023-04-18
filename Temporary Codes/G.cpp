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

const int mxn=2e5+5;
vector<int> adj[mxn];
bool visited[mxn];
int sz[mxn];
int n,k;
int cnt[mxn];
ll ans=0;

int dfs(int v,int p=0){
    sz[v]=1;
    for(auto u:adj[v]){
        if(u==p or visited[u]) continue;
        sz[v]+=dfs(u,v);
    }
    return sz[v];
}

void dfs2(int v,int p,int pp,int d=0){
    g[v].push_back({pp,d});
    for(auto u:adj[v]){
        if(u==p or visited[u]) continue;
        dfs2(u,v,pp,d+1);
    }
}

int find(int v,int mx,int p=0){
    for(auto u:adj[v]){
        if(u==p or visited[u]) continue;
        if(sz[u]*2>mx) return find(u,mx,v);
    }
    return v;
}

void centroid(int v=1){
    v=find(v,dfs(v));
    dfs2(v,0,v);
    visited[v]=true;
    for(auto u:adj[v]){
        if(!visited[u]) centroid(u);
    }
}

int main() {_
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    centroid();
    cout<<ans;
    return 0;
}
//maybe its multiset not set
