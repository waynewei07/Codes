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
    string str;
    cin>>str;
    int n=(int)str.length();
    string a,b;
    for(int i=0;i<n;i++){
        a+='(';
    }
    for(int i=0;i<n;i++){
        a+=')';
    }
    for(int i=0;i<n;i++){
        b+="()";
    }
    bool tf=true;
    for(int i=0;i+n-1<2*n;i++){
        if(a.substr(i,n)==str){
            tf=false;
            break;
        }
    }
    if(tf){
        cout<<"YES"<<'\n';
        cout<<a<<'\n';
        return;
    }
    tf=true;
    for(int i=0;i+n-1<2*n;i++){
        if(b.substr(i,n)==str){
            tf=false;
            break;
        }
    }
    if(tf){
        cout<<"YES"<<'\n';
        cout<<b<<'\n';
        return;
    }
    else{
        cout<<"NO"<<'\n';
        return;
    }
}

int main() {_
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
//maybe its multiset not set

