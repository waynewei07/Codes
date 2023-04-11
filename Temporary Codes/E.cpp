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

const ll mxn=2e5+5;
ll a[mxn];
ll ans[mxn];
vector<pair<ll,ll>> st[mxn],en[mxn];
vector<ll> xs;
ll bit[2][mxn];
ll pre[mxn];

void update(ll id,ll pos,ll val){
    for(;pos<mxn;pos+=pos&(-pos)){
        bit[id][pos]+=val;
    }
}

ll query(ll id,ll pos){
    ll ans=0;
    for(;pos;pos-=(pos&-pos)){
        ans+=bit[id][pos];
    }
    return ans;
}

int main() {_
    ll n,q;
    cin>>n>>q;
    xs.push_back(-1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
        xs.push_back(a[i]);
    }
    sort(all(xs));
    xs.resize(unique(all(xs))-xs.begin());
    for(ll i=0;i<q;i++){
        ll l,r,k;
        cin>>l>>r>>k;
        st[l-1].push_back({i,k});
        en[r].push_back({i,k});
    }
    // k*(<=k的個數)-(<=k的和) + (>k的和)-k*(>k的個數) + (l~r的和) + k*(r-l+1) - k*(l~r有幾個=k)*2
    ll cur=0;
    for(ll i=1;i<=n;i++){
        cur+=a[i];
        ll pos=lower_bound(all(xs),a[i])-xs.begin();
        update(0,pos,1);
        update(1,pos,a[i]);
        for(auto v:st[i]){
            ll idk=upper_bound(all(xs),v.s)-xs.begin()-1;
            ll cnt1=query(0,idk);
            ll sum=query(1,idk);
            ans[v.f]=v.s*cnt1-sum;
            ans[v.f]+=(cur-sum)-v.s*(i-cnt1);
            ans[v.f]+=pre[i];
            ans[v.f]+=v.s*i;
            ans[v.f]=-1ll*ans[v.f];
            if(upper_bound(all(xs),v.s)-lower_bound(all(xs),v.s)==1){
                ans[v.f]+=2*(query(1,idk)-query(1,idk-1));
            }
        }
        for(auto v:en[i]){
            ll idk=upper_bound(all(xs),v.s)-xs.begin()-1;
            ll cnt1=query(0,idk);
            ll sum=query(1,idk);
            ans[v.f]+=v.s*cnt1-sum;
            ans[v.f]+=(cur-sum)-v.s*(i-cnt1);
            ans[v.f]+=pre[i];
            ans[v.f]+=v.s*i;
            if(upper_bound(all(xs),v.s)-lower_bound(all(xs),v.s)==1){
                ans[v.f]-=2*(query(1,idk)-query(1,idk-1));
            }
            //ans[v.f]+=v.s;
        }
    }
    for(ll i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
//maybe its multiset not set
