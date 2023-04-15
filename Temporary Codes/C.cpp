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

random_device seed;
mt19937 rng(seed());

int main() {_
    cout<<1000<<'\n';
    for(int i=0;i<1000;i++){
        cout<<abs((int)rng())<<' ';
    }
    return 0;
}
//maybe its multiset not set
