#pragma GCC optimize("O4")
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
vector<int>adj[mxn];
int sz[mxn];
vector<int> tmp(mxn,0);

void dfs0(int v,int p=0){
    sz[v]=1;
    for(auto u:adj[v]){
        if(u==p) continue;
        dfs0(u,v);
        sz[v]+=sz[u];
    }
}

bool dfs(int k,int v=1,int p=0){
    for(auto u:adj[v]){
        if(u==p) continue;
        if(!dfs(k,u,v)) return false;
    }
    vector<int> vec;
    for(auto u:adj[v]){
        if(u==p or (sz[u]%k)==0) continue;
        tmp[sz[u]%k]++;
        if(tmp[sz[u]%k]==1) vec.push_back(sz[u]%k);
    }
    int cnt=0;
    for(auto v:vec){
        int u=k-v;
        if(u==v){
            tmp[v]%=2;
        }
        else{
            int mn=min(tmp[v],tmp[u]);
            tmp[v]-=mn;
            tmp[u]-=mn;
        }
        cnt+=tmp[v];
    }
    for(auto v:vec){
        tmp[v]=0;
    }
    return (cnt<=1);
}

int main() {_
    setIO("deleg");
    auto st=clock();
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> d;
    for(int i=1;i*i<=n-1;i++){
        if((n-1)%i==0){
            d.push_back(i);
            if(i!=((n-1)/i)) d.push_back((n-1)/i);
        }
    }
    sort(all(d));
    //reverse(all(d));
    dfs0(1);
    vector<bool> ans(n,false);
    for(auto v:d){
        if((double)(clock()-st)/CLOCKS_PER_SEC>1.9) break;
        bool tf=true;
        for(int i=v;i<=(n-1);i+=v){
            if(ans[i]){
                ans[v]=true;
                tf=false;
                break;
            }
        }
        if(tf) ans[v]=dfs(v);
    }
    for(int i=1;i<=n-1;i++){
        cout<<ans[i];
    }
    return 0;
}
//maybe its multiset not set

