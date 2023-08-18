//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct DSU{
    vector<int> e;
    DSU(int n){
        e=vector<int>(n,-1);
    }
    int sz(int x){
        return -e[find(x)];
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
        return true;
    }
};

signed main() {_
    int n,m;
    cin>>n>>m;
    vector<vector<int>> aa(n,vector<int>(n,0));
    //memset(a,0,sizeof(a));
    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int w;
        cin>>w;
        for(int i=a-1;i<=b-1;i++){
            for(int j=c-1;j<=d-1;j++){
                aa[i][j]+=w;
                aa[j][i]+=w;
            }
        }
    }
    vector<pair<int,pair<int,int>>> vec;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            vec.push_back({aa[i][j],{i,j}});
        }
    }
    sort(all(vec));
    ll ans=0;
    DSU dsu(n);
    for(auto v:vec){
        if(dsu.unite(v.s.f,v.s.s)) ans+=v.f;
    }
    cout<<ans;
    return 0;
}
//maybe its multiset not set

