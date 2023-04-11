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

int main() {_
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    ll b[n+1];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }
    ll c[k+1];
    c[0]=0;
    for(ll i=1;i<=k;i++){
        cin>>c[i];
    }
    sort(c+1,c+k+1);
    ll ans=0;
    for(ll i=1;i<=k;i++){
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll sum=0;
        for(ll j=c[i-1]+1;j<=c[i];j++){
            sum+=a[j];
            sum-=b[j];
            if(b[j]>0) pq.push(b[j]);
            while(sum<0){
                ll v=pq.top();
                pq.pop();
                if(sum+v>0){
                    pq.push(v+sum);
                    sum=0;
                }else sum+=v;
            }
        }
        ans+=(ll)pq.size();
        if(sum>0){
            cout<<-1;
            return 0;
        }
        //cout<<ans<<' ';
    }
    cout<<ans;
    return 0;
}
//maybe its multiset not set
