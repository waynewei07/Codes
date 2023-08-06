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
vector<pair<int,int>> adj[mxn];
map<pair<int,int>,int> init;
map<pair<int,int>,int> id;
map<pair<int,int>,int> ord;
int up[20][mxn];
int mx[20][mxn];
pair<int,int> rev[mxn];
int depth[mxn];

void dfs(int v,int p){
    up[0][v]=p;
    depth[v]=depth[p]+1;
    for(auto u:adj[v]){
        if(u.f==p) continue;
        mx[0][u.f]=u.s;
        dfs(u.f,v);
    }
}

int lca(int a,int b){
    int mxx=0;
    if(depth[a]<depth[b]) swap(a,b);
    int len=depth[a]-depth[b];
    for(int i=0;i<20;i++){
        if(len&(1<<i)){
            mxx=max(mxx,mx[i][a]);
            a=up[i][a];
        }
    }
    if(a==b) return mxx;
    for(int i=19;i>=0;i--){
        int ta=up[i][a];
        int tb=up[i][b];
        if(ta!=tb){
            mxx=max({mxx,mx[i][a],mx[i][b]});
            a=up[i][a];
            b=up[i][b];
        }
    }
    mxx=max(mxx,mx[0][a]);
    mxx=max(mxx,mx[0][b]);
    return mxx;
}

int main() {_
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edge;
    vector<pair<int,int>> mst;
    vector<pair<int,int>> other;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge.push_back({a,b});
        init[{a,b}]=i;
    }
    for(int i=0;i<n-1;i++){
        int k;
        cin>>k;
        k--;
        mst.push_back(edge[k]);
        init[edge[k]]=-1;
    }
    for(int i=0;i<m;i++){
        auto v=edge[i];
        if(init[v]!=-1){
            other.push_back(v);
        }
        init[v]=i;
    }
    sort(all(edge));
    for(int i=0;i<m;i++){
        id[edge[i]]=i;
        rev[i]=edge[i];
    }
    sort(all(mst));
    int cnt=0;
    for(auto v:mst){
        int a=v.f;
        int b=v.s;
        cnt++;
        ord[v]=cnt;
        adj[a].push_back({b,ord[v]});
        adj[b].push_back({a,ord[v]});
    }
    dfs(1,0);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            up[i][j]=up[i-1][up[i-1][j]];
            mx[i][j]=max(mx[i-1][j],mx[i-1][up[i-1][j]]);
        }
    }
    for(auto v:other){
        ord[v]=lca(v.f,v.s);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    priority_queue<int,vector<int>,greater<int>> pq2;
    for(auto v:other){
        pq.push({ord[v],id[v]});
    }
    vector<int> fin;
    for(int i=0;i<n-1;i++){
        auto v=mst[i];
        while(!pq2.empty() and pq2.top()<id[v]){
            fin.push_back(pq2.top());
            pq2.pop();
        }
        fin.push_back(id[v]);
        while(!pq.empty() and pq.top().f<=ord[v]){
            pq2.push(pq.top().s);
            pq.pop();
        }
    }
    while(!pq2.empty()){
        fin.push_back(pq2.top());
        pq2.pop();
    }
    for(auto v:fin){
        cout<<rev[v].f<<' '<<rev[v].s<<'\n';
    }
    return 0;
}
//maybe its multiset not set

