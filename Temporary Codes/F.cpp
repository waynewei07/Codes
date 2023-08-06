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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=*max_element(all(a));
    int mn=*min_element(all(a));
    int mxpos=max_element(all(a))-a.begin();
    int mnpos=min_element(all(a))-a.begin();
    set<pair<int,int>> S;
    for(int i=0;i<n;i++){
        S.insert({a[i],i});
    }
    int ans=0;
    vector<pair<int,int>> vec;
    if(abs(mx)>=abs(mn)){
        for(int i=1;i<n;i++){
            while(a[i]<a[i-1]){
                auto it=S.lower_bound({a[i-1]-a[i],-1});
                if(it==S.end()) it--;
                vec.push_back({i,(*it).s});
                int val=(*it).f;
                S.erase({a[i],i});
                a[i]+=val;
                S.insert({a[i],i});
                ans++;
            }
        }
        cout<<ans<<'\n';
        for(auto v:vec){
            cout<<v.f+1<<' '<<v.s+1<<'\n';
        }
    }
    else{
        for(int i=n-2;i>=0;i--){
            while(a[i]>a[i+1]){
                auto it=S.upper_bound({a[i+1]-a[i],n});
                if(it!=S.begin()) it--;
                vec.push_back({i,(*it).s});
                int val=(*it).f;
                S.erase({a[i],i});
                a[i]+=val;
                S.insert({a[i],i});
                ans++;
            }
        }
        cout<<ans<<'\n';
        for(auto v:vec){
            cout<<v.f+1<<' '<<v.s+1<<'\n';
        }
    }
}

int main() {_
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
//maybe its multiset not set

