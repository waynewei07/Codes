/*
|||||||||||||||
||
||
||
||
||
*/
#pragma GCC optimize("O3")
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
vector<int> sccadj[mxn];
map<pair<int,int>,int> mp;
vector<int> st;
int order[mxn],low[mxn];
int depth[mxn];
int val[mxn];
vector<bool> visited(mxn,false);
int scc[mxn];
int sccnt=0;
int cnt=1;
vector<pair<int,int>> bridge;
vector<pair<int,int>> edges;

void dfs(int v,int p){
    order[v]=low[v]=cnt;
    cnt++;
    st.push_back(v);
    for(auto u:adj[v]){
        if(u==p and mp[{u,v}]==1) continue;
        if(order[u]){
            low[v]=min(low[v],order[u]);
        }
        else{
            dfs(u,v);
            low[v]=min(low[v],low[u]);
            if(low[u]==order[u]){
                bridge.push_back({v,u});
                sccnt++;
                while(st.back()!=u){
                    scc[st.back()]=sccnt;
                    st.pop_back();
                }
                scc[st.back()]=sccnt;
                st.pop_back();
            }
        }
    }
    if(p==-1){
        sccnt++;
        while(st.size()){
            scc[st.back()]=sccnt;
            st.pop_back();
        }
    }
}

void dfs2(int v,int p){
    visited[v]=true;
    if(p!=-1) depth[v]=depth[p]+1;
    for(auto u:sccadj[v]){
        if(u==p or visited[u]) continue;
        dfs2(u,v);
        val[v]+=val[u];
    }
}

int main() {_
    //setIO("wayne");
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
        adj[a].push_back(b);
        adj[b].push_back(a);
        mp[{a,b}]++;
        mp[{b,a}]++;
    }
    for(int i=1;i<=n;i++){
        if(!scc[i]){
            dfs(i,-1);
        }
        //cout<<scc[i]<<' ';
    }
    for(int i=0;i<m;i++){
        if(scc[edges[i].f]!=scc[edges[i].s]){
            sccadj[scc[edges[i].f]].push_back(scc[edges[i].s]);
            sccadj[scc[edges[i].s]].push_back(scc[edges[i].f]);
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        val[scc[a]]++;
        val[scc[b]]--;
    }
    for(int i=1;i<=sccnt;i++){
        if(!visited[i]){
            dfs2(i,-1);
        }
    }
    for(auto v:edges){
        if(scc[v.f]==scc[v.s]){
            cout<<'B';
        }
        else{
            if(depth[scc[v.f]]>depth[scc[v.s]]){
                if(val[scc[v.f]]==0){
                    cout<<'B';
                }
                else if(val[scc[v.f]]>0){
                    cout<<'R';
                }
                else{
                    cout<<'L';
                }
            }
            else{
                if(val[scc[v.s]]==0){
                    cout<<'B';
                }
                else if(val[scc[v.s]]>0){
                    cout<<'L';
                }
                else{
                    cout<<'R';
                }
            }
        }
    }
    return 0;
}
//maybe its multiset not set
