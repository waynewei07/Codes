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
vector<int> adj[mxn];
int deg[mxn];
bool out[mxn];
bool visited[mxn];
int mx=1;

struct DSU{
    vector<int> e;
    DSU(int n){
        e=vector<int> (n,-1);
    }
    int find(int x){
        return (e[x]<0?x:e[x]=find(e[x]));
    }
    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        if(e[a]>e[b]) swap(a,b);
        e[a]+=e[b];
        e[b]=a;
        mx=max(mx,-e[a]);
        return true;
    }
};

int main() {_
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    set<pair<int,int>> S;
    for(int i=0;i<n;i++){
        S.insert({deg[i],i});
    }
    ll ans=0;
    int up=ceil(sqrt((double)(2*m)))+1;
    vector<int> vec[up];
    for(int i=1;i<=up;i++){
        while(!S.empty() and (*S.begin()).f<i){
            auto v=*S.begin();
            S.erase(S.begin());
            out[v.s]=true;
            vec[i-1].push_back(v.s);
            for(auto u:adj[v.s]){
                if(out[u]) continue;
                S.erase(S.find({deg[u],u}));
                deg[u]--;
                S.insert({deg[u],u});
            }
        }
    }
    DSU dsu(n);
    for(int i=0;i<n;i++){
        if(out[i]) continue;
        for(auto u:adj[i]){
            if(!out[u]) dsu.unite(i,u);
        }
    }
    for(int i=up-1;i>=0;i--){
        for(auto v:vec[i]){
            out[v]=false;
            for(auto u:adj[v]){
                if(!out[u]) dsu.unite(v,u);
            }
        }
        ans=max(ans,1ll*i*mx);
    }
    cout<<ans<<'\n';
    return 0;
}
//maybe its multiset not set

