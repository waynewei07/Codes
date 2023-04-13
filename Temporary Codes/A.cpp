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

const int mxn=1e5+5;
vector<int> adj[mxn];
int n,q;


int main() {_
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<q;i++){
        char c;
        cin>>c;
        int a,b;
        cin>>a>>b;
        if(c=='P'){
            upd(a,b);
        }
        else{

        }
    }
    return 0;
}
//maybe its multiset not set
