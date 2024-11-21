//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {_
    setIO("landscape");
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    vector<int> a(n),b(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum+=b[i];
        b[i]-=a[i];
    }
    deque<pair<int,int>> L,R;
    for(int i=1;i<=sum;i++){
        R.push_back({x,0});
        L.push_front({-y,0});
    }
    ll val=0;
    for(int i=0;i<n;i++){
        if(b[i]>0){
            for(int j=0;j<b[i];j++){
                auto v=R.front();
                R.pop_front();
                v.f=min(x,v.f+z*(i-v.s));
                v.s=i;
                val+=v.f;
                L.push_back(v);
            }
        }
        else{
            for(int j=0;j<-b[i];j++){
                auto v=L.back();
                L.pop_back();
                v.f=max(-y,v.f-z*(i-v.s));
                v.s=i;
                val-=v.f;
                R.push_front(v);
            }
        }
    }
    cout<<val<<'\n';
    return 0;
}
//maybe its multiset not set
//yeeorz
//diaoborz
