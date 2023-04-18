//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const ll mxn=1e5+5;
vector<ll> adj[mxn];
vector<pair<ll,ll>> queries;
vector<pair<ll,ll>> g[mxn];
bool visited[mxn];
ll n=0;
ll cnt=0;
ll sz[mxn];
pair<ll,ll> fir[mxn],sec[mxn];

ll dfs(ll v,ll p=0){
    sz[v]=1;
    for(auto u:adj[v]){
        if(u==p or visited[u]) continue;
        sz[v]+=dfs(u,v);
    }
    return sz[v];
}

ll find(ll v,ll mx,ll p=0){
    for(auto u:adj[v]){
        if(u==p or visited[u]) continue;
        if(sz[u]*2>mx) return find(u,mx,v);
    }
    return v;
}

void dfs2(ll v,ll pp,ll p=0,ll d=0){
    g[v].push_back({pp,d});
    for(auto u:adj[v]){
        if(u==p or visited[u]) continue;
        dfs2(u,pp,v,d+1);
    }
}

void centroid(ll v){
    v=find(v,dfs(v));
    //cout<<v<<'\n';
    dfs2(v,v);
    visited[v]=true;
    for(auto u:adj[v]){
        if(!visited[u]) centroid(u);
    }
}

void sir(pair<ll,ll> p,ll v){
    if(v==fir[p.f].f){
        fir[p.f].s=max(fir[p.f].s,p.s);
    }
    else if(v==sec[p.f].f){
        sec[p.f].s=max(sec[p.f].s,p.s);
        if(sec[p.f].s>fir[p.f].s) swap(sec[p.f],fir[p.f]);
    }
    else{
        if(p.s>fir[p.f].s){
            sec[p.f]=fir[p.f];
            fir[p.f]={v,p.s};
        }
        else if(p.s>sec[p.f].s){
            sec[p.f]={v,p.s};
        }
    }
}

void update(ll v){
    int prv=-1;
    for(ll i=g[v].size()-1;i>=0;i--){
        sir(g[v][i],prv);
        prv=g[v][i].f;
    }
}

ll query(ll v){
    ll ans=0;
    int prv=-1;
    for(ll i=g[v].size()-1;i>=0;i--){
        if(g[v][i].f<=cnt){
            if(fir[g[v][i].f].f!=prv){
                ans=max(ans,g[v][i].s+fir[g[v][i].f].s);
            }
            else if(sec[g[v][i].f].f!=prv){
                ans=max(ans,g[v][i].s+sec[g[v][i].f].s);
            }
        }
        prv=g[v][i].f;
    }
    return ans;
}

int main() {_
    setIO("newbarn");
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++){
        char c;
        ll a;
        cin>>c>>a;
        if(c=='B'){
            n++;
            if(a!=-1){
                adj[a].push_back(n);
                adj[n].push_back(a);
            }
        }
        queries.push_back({(c=='B'?1:-1),a});
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]) centroid(i);
    }
    for(ll i=1;i<=n;i++){
        fir[i]=sec[i]={-1,-1e9};
    }
    for(auto v:queries){
        if(v.f==1){
            cnt++;
            update(cnt);
        }
        else{
            cout<<query(v.s)<<'\n';
        }
    }
    return 0;
}
//maybe its multiset not set
