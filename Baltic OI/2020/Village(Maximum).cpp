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

const int mxn=1e5+5;
int sz[mxn];
vector<int> adj[mxn];
int parent[mxn];
int depth[mxn];
int ord[mxn];
int ans[mxn];
int cnt=1;

int dfs(int v,int p=0){
    sz[v]=1;
    for(auto u:adj[v]){
        if(u==p) continue;
        sz[v]+=dfs(u,v);
    }
    return sz[v];
}

int find(int v,int mx,int p=0){
    for(auto u:adj[v]){
        if(u==p) continue;
        if(sz[u]*2>mx) return find(u,mx,v);
    }
    return v;
}

void dfs2(int v,int p,int d=1){
    ord[cnt++]=v;
    depth[v]=d;
    for(auto u:adj[v]){
        if(u==p) continue;
        dfs2(u,v,d+1);
    }
}

int main() {_
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int v=1;
    v=find(v,dfs(v));
    for(auto u:adj[v]){
        dfs2(u,v);
    }
    ll sum=0;
    ord[0]=v;
    for(int i=0;i<n;i++){
        int a=ord[i];
        int b=ord[(i+n/2)%n];
        ans[a]=b;
        sum+=depth[a]+depth[b];
    }
    cout<<sum<<'\n';
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
//maybe its multiset not set
