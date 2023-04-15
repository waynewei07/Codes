//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pdd pair<long double,long double>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {_
    int n;
    cin>>n;
    vector<pdd> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].f>>vec[i].s;
    }
    multiset<pdd> S;
    long double d=1e10;
    sort(all(vec));
    int j=0;
    for(int i=0;i<n;i++){
        while((vec[i].f-vec[j].f)>=d){
            S.erase(S.find({vec[j].s,vec[j].f}));
            j++;
        }
        auto it=S.lower_bound({vec[i].s-d,-1e9-1});
        auto bound=S.upper_bound({vec[i].s+d,1e9+1});
        for(;it!=bound;it++){
            pdd tmp=*it;
            //cout<<vec[i].f<<' '<<vec[i].s<<' '<<tmp.f<<' '<<tmp.s<<'\n';
            d=min(d,sqrt((tmp.s-vec[i].f)*(tmp.s-vec[i].f)+(tmp.f-vec[i].s)*(tmp.f-vec[i].s)));
        }
        S.insert({vec[i].s,vec[i].f});
    }
    long double ans=d*d+1e-5;
    cout<<(ll)(ans);
    return 0;
}
//maybe its multiset not set
