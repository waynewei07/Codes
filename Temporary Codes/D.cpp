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
int sz[mxn];
int depth[mxn];
int tp[mxn];
int parent[mxn];
int st[mxn];
int segtree[mxn*4];
int lazy[mxn*4];
int cnt=0;
int n,q;

void push(int v){
    segtree[v*2]+=lazy[v];
    segtree[v*2+1]+=lazy[v];
    lazy[v*2]+=lazy[v];
    lazy[v*2+1]+=lazy[v];
    lazy[v]=0;
}

void update(int tl,int tr,int val,int l=1,int r=n,int v=1){
    if(r<tl or tr<l){
        return;
    }
    if(tl<=l and r<=tr){
        segtree[v]+=val;
        lazy[v]+=val;
        return;
    }
    push(v);
    int mid=(l+r)/2;
    update(tl,min(mid,tr),val,l,mid,v*2);
    update(max(mid+1,tl),tr,val,mid+1,r,v*2+1);
    segtree[v]=segtree[v*2]+segtree[v*2+1];
}

int query(int pos,int l=1,int r=n,int v=1){
    if(l==r){
        return segtree[v];
    }
    push(v);
    int mid=(l+r)/2;
    if(pos<=mid) return query(pos,l,mid,v*2);
    return query(pos,mid+1,r,v*2+1);
}

void dfs(int v,int p){
    parent[v]=p;
    depth[v]=depth[p]+1;
    sz[v]=1;
    for(auto u:adj[v]){
        if(u==p) continue;
        dfs(u,v);
        sz[v]+=sz[u];
    }
}

void hld(int v,int p,int top){
    tp[v]=top;
    st[v]=++cnt;
    int mx=-1;
    int hc=-1;
    for(auto u:adj[v]){
        if(u==p) continue;
        if(sz[u]>mx){
            mx=sz[u];
            hc=u;
        }
    }
    if(hc!=-1) hld(hc,v,top);
    for(auto u:adj[v]){
        if(u==p or u==hc) continue;
        hld(u,v,u);
    }
}

void upd(int a,int b){
    while(tp[a]!=tp[b]){
        if(depth[tp[a]]<depth[tp[b]]) swap(a,b);
        update(st[tp[a]],st[a],1);
        a=parent[tp[a]];
    }
    if(depth[a]<depth[b]) swap(a,b);
    update(st[b],st[a],1);
    update(st[b],st[b],-1);
}

int main() {_
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    hld(1,0,1);
    for(int i=0;i<q;i++){
        char c;
        cin>>c;
        int a,b;
        cin>>a>>b;
        if(c=='P'){
            upd(a,b);
        }
        else{
            if(depth[a]<depth[b]) swap(a,b);
            cout<<query(st[a])<<'\n';
        }
    }
    return 0;
}
//maybe its multiset not set
