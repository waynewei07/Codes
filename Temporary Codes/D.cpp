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
int sz[mxn];
vector<int> adj[mxn];
int n;

void dfs(int v,int p){
    sz[v]=1;
    bool tf=true;
    for(auto u:adj[v]){
        if(u==p) continue;
        dfs(u,v);
        if(sz[u]>n/2) tf=false;
        sz[v]+=sz[u];
    }
    if((n-sz[v])>n/2) tf=false;
    if(tf){
        cout<<v;
        exit(0);
    }
}

int main() {_
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    return 0;
}
//maybe its multiset not set
