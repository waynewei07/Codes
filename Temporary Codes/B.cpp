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
pair<int,int> num[mxn];
int C[mxn];
int pos[mxn];
vector<int> vals[mxn];
int n,m;

bool check(int mid){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<mid;i++){
        for(auto v:vals[i]){
            pq.push(v);
        }
    }
    int cur=-1;
    for(int i=mid;i<=m;i++){
        for(auto v:vals[i]){
            pq.push(v);
        }
        while(!pq.empty() and pq.top()<cur) pq.pop();
        if(pq.empty()) return false;
        cur=pq.top();
        pq.pop();
    }
    return true;
}

int main() {_
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i].f>>num[i].s;
    }
    for(int i=1;i<=m;i++){
        cin>>C[i];
    }
    sort(C+1,C+m+1);
    for(int i=1;i<=n;i++){
        pos[i]=lower_bound(C+1,C+m+1,num[i].f)-C;
        vals[pos[i]].push_back(num[i].s);
    }
    int l=1,r=m+1;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<m+1-l;
    return 0;
}
//maybe its multiset not set
