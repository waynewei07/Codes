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

const int mxn=3e5+5;
int bit[2][mxn];
int n;

void update(int id,int pos,int val){
    for(;pos<=n;pos+=(pos&-pos)){
        bit[id][pos]+=val;
    }
}

int query(int id,int pos){
    int ans=0;
    for(;pos;pos-=(pos&-pos)){
        ans+=bit[id][pos];
    }
    return ans;
}

void solve(){
    cin>>n;
    fill(bit[0],bit[0]+n+1,0);
    fill(bit[1],bit[1]+n+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int val=query(1,x);
        int val2=query(0,x);
        //cout<<val<<' '<<val2<<'\n';
        if(val==0 and val2!=0){
            ans++;
            update(1,x,1);
        }
        update(0,x,1);
    }
    cout<<ans<<'\n';
}

int main() {_
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
//maybe its multiset not set

