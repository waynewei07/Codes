#include<bits/stdc++.h>
#include "race.h"
using namespace std;
#define ll long long
#define f first
#define s second
#define all(x) x,begin(),x.end()

const int mxn=2e5+5;
vector<pair<int,ll>> adj[mxn];
int depth[mxn];
ll len[mxn];
multiset<pair<ll,int>> S[mxn];
int ans=1e9;
ll k;

void dfs(int v,int p,int w=0){
    depth[v]=depth[p]+1;
    len[v]=len[p]+w;
    S[v].insert({len[v],depth[v]});
    for(auto u:adj[v]){
        if(u.f==p) continue;
        dfs(u.f,v,u.s);
        if(S[v].size()<S[u.f].size()){
            S[v].swap(S[u.f]);
        }
        for(auto &i:S[u.f]){
            ll target=k-i.f+2*len[v];
            auto it=S[v].lower_bound({target,0});
            if(it!=S[v].end() and (*it).f==target){
                ans=min(ans,i.s+(*it).s-2*depth[v]);
            }
        }
        for(auto &i:S[u.f]){
            S[v].insert(i);
        }
    }
}

int best_path(int N, int K, int H[][2], int L[])
{
    k=K;
    for(int i=0;i<N-1;i++){
        int a=H[i][0];
        int b=H[i][1];
        int w=L[i];
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dfs(0,0);
    return (ans==1e9?-1:ans);
}

/*int main(){
    int n,k;
    cin>>n>>k;
    int H[n-1][2];
    int L[n-1];
    for(int i=0;i<n-1;i++){
        cin>>H[i][0]>>H[i][1];
    }
    for(int i=0;i<n-1;i++){
        cin>>L[i];
    }
    cout<<best_path(n,k,H,L);
}*/

/*
11 12
0 1
0 2
2 3
3 4
4 5
0 6
6 7
6 8
8 9
8 10
3
4
5
4
6
3
2
5
6
7
*/
