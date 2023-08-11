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
int x[mxn];
int y[mxn];
set<pair<ll,ll>> S[11];

struct DSU{
    vector<int> e;
    vector<vector<int>> belong;
    DSU(int n){
        e=vector<int>(n,-1);
        belong.resize(n);
        for(int i=0;i<n;i++){
            belong[i].push_back(i);
        }
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
        belong[a].insert(belong[a].end(),all(belong[b]));
        return true;
    }
};

int main() {_
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        S[y[i]].insert({x[i],i});
    }
    ll ans=0;
    DSU dsu(n);
    while(dsu.sz(0)!=n){
        vector<pair<ll,pair<ll,ll>>> vec;
        for(int i=0;i<n;i++){
            if(dsu.find(i)!=i) continue;
            vector<int> tmp=dsu.belong[i];
            for(auto v:tmp){
                S[y[v]].erase({x[v],v});
            }
            pair<ll,ll> mn={(ll)1e18,-1};
            for(auto v:tmp){
                for(int i=0;i<=10;i++){
                    if(S[i].empty()) continue;
                    pair<ll,ll> mnn={1e9,-1};
                    auto it=S[i].lower_bound({x[v],-1});
                    if(it!=S[i].end()){
                        mnn=min(mnn,{abs((*it).f-x[v]),(*it).s});
                    }
                    if(it!=S[i].begin()){
                        it--;
                        mnn=min(mnn,{abs(x[v]-(*it).f),(*it).s});
                    }
                    mn=min(mn,{mnn.f*mnn.f+1ll*(y[v]-i)*(y[v]-i),mnn.s});
                }
            }
            if(mn.s!=-1){
                vec.push_back({mn.f,{i,mn.s}});
            }
            for(auto v:tmp){
                S[y[v]].insert({x[v],v});
            }
        }
        sort(all(vec));
        for(auto v:vec){
            if(dsu.unite(v.s.f,v.s.s)){
                //cout<<v.s.f+1<<' '<<v.s.s+1<<' '<<v.f<<'\n';
                ans+=v.f;
            }
        }
        //cout<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}
//maybe its multiset not set

