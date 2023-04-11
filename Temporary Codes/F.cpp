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
    ll n;
    cin>>n;
    ll cur=0;
    vector<int> vec(n,-1);
    int record=-1;
    for(int i=1;i<=10000;i++){
        if(i<10) cur=(cur*10%n+i)%n;
        else if(i<100) cur=(cur*100%n+i)%n;
        else if(i<1000) cur=(cur*1000%n+i)%n;
        else if(i<10000) cur=(cur*10000%n+i)%n;
        if(vec[cur]!=-1){
            record=i;
            break;
        }
        vec[cur]=i;
    }
    if(record==-1){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    int a=vec[cur];
    int b=record;
    for(int i=1;i<=a;i++){
        cout<<i;
    }
    cout<<' ';
    for(int i=1;i<=b;i++){
        cout<<i;
    }
    cout<<'\n';
}

int main() {_
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
//maybe its multiset not set
