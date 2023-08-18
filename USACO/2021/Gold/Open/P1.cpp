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
int a[mxn];
int pos[mxn];
int bit[mxn];
bool used[mxn];

void update(int pos,int val){
    for(;pos<mxn;pos+=(pos&-pos)){
        bit[pos]+=val;
    }
}

int query(int pos){
    int ans=0;
    for(;pos;pos-=(pos&-pos)){
        ans+=bit[pos];
    }
    return ans;
}

ll go(int l,int r){
    if(l==r) return 0;
    int mid=(l+r)/2;
    queue<pair<int,int>> q;
    for(int i=mid;i>=l;i--){
        if(pos[a[i]]==0){
            pos[a[i]]=i;
            update(i,1);
            q.push({i,-1});
        }
    }
    ll ans=0;
    for(int i=mid+1;i<=r;i++){
        if(used[a[i]]) continue;
        used[a[i]]=true;
        if(pos[a[i]]!=0){
            update(pos[a[i]],-1);
            q.push({pos[a[i]],1});
        }
        int fin=max(pos[a[i]]+1,l);
        ans+=query(mid)-query(fin-1);
    }
    for(int i=l;i<=r;i++){
        pos[a[i]]=0;
        used[a[i]]=false;
    }
    while(!q.empty()){
        update(q.front().f,q.front().s);
        q.pop();
    }
    ans+=go(l,mid);
    ans+=go(mid+1,r);
    return ans;
}

int main() {_
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<go(1,n);
    return 0;
}
//maybe its multiset not set

