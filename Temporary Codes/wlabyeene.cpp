//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb push_back
#define vi vector<int>
#define vp vector<pii>
#define vvi vector<vi>
const int sz=1e5+5;
int to[sz];
int num[sz];
int find(int x){
    return (to[x]==x?x:to[x]=find(to[x]));
}
void un(int a,int b){
    a=find(a);
    b=find(b);
    if(num[a]>num[b]){
        swap(a,b);
    }num[b]+=num[a];
    to[a]=b;
}
bool operator <(pii a,pii b){
    if(a.F==b.F)return a.S<b.S;
    return a.F<b.F;
}
signed main() {_
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        to[i]=i;
        num[i]=1;
    }
    vp edge;
    edge.pb({-1,-1});
    vp ll;
    vp rr;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge.pb({a,b});
    }
    vector<bool>check(m+1,0);
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        check[x]=1;
        ll.pb(edge[x]);
    }for(int i=1;i<=m;i++){
        if(!check[i])rr.pb(edge[i]);
    }
    sort(all(ll));
    sort(all(rr));
    int lp=0,rp=0;
    vp ans;
    while(lp<n-1 or rp<m-n+1){
        if(lp<n-1 and (rp>=m-n+1 or ll[lp]<rr[rp] or (find(rr[rp].F)!=find(rr[rp].S)))){
            un(ll[lp].F,ll[lp].S);
            ans.pb(ll[lp++]);
        }else ans.pb(rr[rp++]);
    }
    for(auto i:ans){
        cout<<i.F<<' '<<i.S<<'\n';
    }
    return 0;
}
//maybe its multiset not set

