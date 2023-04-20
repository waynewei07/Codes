//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include "factories.h"
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
vector<pair<int,ll>> g[mxn];
ll mn1[mxn],mn2[mxn];
bool visited[mxn];
int sz[mxn];
int n;

int dfs(int v,int p=-1){
    sz[v]=1;
    for(auto u:adj[v]){
        if(u.f==p or visited[u.f]) continue;
        sz[v]+=dfs(u.f,v);
    }
    return sz[v];
}

int find(int v,int mx,int p=-1){
    for(auto u:adj[v]){
        if(u.f==p or visited[u.f]) continue;
        if(sz[u.f]*2>mx) return find(u.f,mx,v);
    }
    return v;
}

void dfs2(int v,int pp,int p=-1,ll d=0){
    g[v].push_back({pp,d});
    for(auto u:adj[v]){
        if(u.f==p or visited[u.f]) continue;
        dfs2(u.f,pp,v,d+u.s);
    }
}

void centroid(int v=0){
    v=find(v,dfs(v));
    dfs2(v,v);
    visited[v]=true;
    for(auto u:adj[v]){
        if(visited[u.f]) continue;
        centroid(u.f);
    }
}

void Init(int N, int A[], int B[], int D[]) {
    n=N;
    for(int i=0;i<n;i++){
        int a=A[i];
        int b=B[i];
        int w=D[i];
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    centroid();
}

long long Query(int S, int X[], int T, int Y[]) {
    for(int i=0;i<S;i++){
        for(auto p:g[X[i]]){
            mn1[p.f]=mn2[p.f]=1e18;
        }
    }
    for(int i=0;i<T;i++){
        for(auto p:g[Y[i]]){
            mn1[p.f]=mn2[p.f]=1e18;
        }
    }
    for(int i=0;i<S;i++){
        for(auto p:g[X[i]]){
            mn1[p.f]=min(mn1[p.f],p.s);
        }
    }
    for(int i=0;i<T;i++){
        for(auto p:g[Y[i]]){
            mn2[p.f]=min(mn2[p.f],p.s);
        }
    }
    ll ans=1e18;
    for(int i=0;i<S;i++){
        for(auto p:g[X[i]]){
            ans=min(ans,mn1[p.f]+mn2[p.f]);
        }
    }
    for(int i=0;i<T;i++){
        for(auto p:g[Y[i]]){
            ans=min(ans,mn1[p.f]+mn2[p.f]);
        }
    }
    return ans;
}

/*int main() {_

    return 0;
}*/
//maybe its multiset not set
