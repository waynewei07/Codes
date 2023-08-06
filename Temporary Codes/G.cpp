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

ll sum1[1<<23],sum2[1<<23];

ll chmax1(ll a,ll b){
    return ((sum1[a]>sum1[b])?a:b);
}

ll chmax2(ll a,ll b){
    return ((sum2[a]>sum2[b])?a:b);
}

int main() {_
    ll n,m,k;
    cin>>n>>m>>k;
    ll n1=k/2;
    ll n2=k-n1;
    ll A[n];
    for(ll i=0;i<n;i++){
        cin>>A[i];
        A[i]--;
    }
    vector<ll> aa(n1,(1<<n1)-1),ab(n1,(1<<n2)-1),bb(n2,(1<<n2)-1);
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        a=A[a];
        b=A[b];
        if(a==b) continue;
        if(a>b) swap(a,b);
        if(a<n1){
            if(b<n1){
                if(aa[a]&(1<<b)) aa[a]^=(1<<b);
                if(aa[b]&(1<<a)) aa[b]^=(1<<a);
            }
            else{
                if(ab[a]&(1<<(b-n1))) ab[a]^=(1<<(b-n1));
            }
        }
        else{
            if(bb[a-n1]&(1<<(b-n1))) bb[a-n1]^=(1<<(b-n1));
            if(bb[b-n1]&(1<<(a-n1))) bb[b-n1]^=(1<<(a-n1));
        }
    }
    for(ll i=0;i<n1;i++){
        aa[i]^=(1<<i);
    }
    for(ll i=0;i<n2;i++){
        bb[i]^=(1<<i);
    }
    /*for(ll i=0;i<n1;i++){
        cout<<i<<'\n';
        for(ll j=0;j<n1;j++){
            if(aa[i]&(1<<j)){
                cout<<j<<' ';
            }
        }
        cout<<'\n';
    }
    for(ll i=0;i<n2;i++){
        cout<<i<<'\n';
        for(ll j=0;j<n2;j++){
            if(bb[i]&(1<<j)){
                cout<<j<<' ';
            }
        }
        cout<<'\n';
    }
    for(ll i=0;i<n1;i++){
        cout<<i<<'\n';
        for(ll j=0;j<n2;j++){
            if(ab[i]&(1<<j)){
                //cout<<j<<' ';
            }
        }
        //cout<<'\n';
    }*/
    vector<ll> c1(n1),c2(n2);
    for(ll i=0;i<n1;i++){
        cin>>c1[i];
    }
    for(ll i=0;i<n2;i++){
        cin>>c2[i];
    }
    //cout<<'\n';
    for(ll s=1;s<(1<<n1);s++){
        for(ll i=0;i<n1;i++){
            if(s&(1<<i)){
                sum1[s]+=c1[i];
            }
        }
    }
    for(ll s=1;s<(1<<n2);s++){
        for(ll i=0;i<n2;i++){
            if(s&(1<<i)){
                sum2[s]+=c2[i];
            }
        }
    }
    vector<ll> dp1(1<<n1),dp2(1<<n2);
    for(ll s=1;s<(1<<n1);s++){
        for(ll i=0;i<n1;i++){
            if(s&(1<<i)){
                //cout<<i<<' ';
                dp1[s]=chmax1(dp1[s],dp1[s^(1<<i)]);
                dp1[s]=chmax1(dp1[s],dp1[(s^(1<<i))&(aa[i])]|(1<<i));
            }
        }
        //cout<<'\n';
        //cout<<dp1[s]<<'\n';
    }
    for(ll s=1;s<(1<<n2);s++){
        for(ll i=0;i<n2;i++){
            if(s&(1<<i)){
                //cout<<i<<' ';
                dp2[s]=chmax2(dp2[s],dp2[s^(1<<i)]);
                dp2[s]=chmax2(dp2[s],dp2[(s^(1<<i))&(bb[i])]|(1<<i));
            }
        }
        //cout<<'\n';
        //cout<<dp2[s]<<'\n';
    }
    ll ans=0;
    for(ll s=0;s<(1<<n1);s++){
        ll neibor=(1<<n2)-1;
        for(ll i=0;i<n1;i++){
            if(s&(1<<i)){
                neibor&=ab[i];
            }
        }
        ans=max(ans,sum1[dp1[s]]+sum2[dp2[neibor]]);
    }
    cout<<ans<<'\n';
    return 0;
}
//maybe its multiset not set

