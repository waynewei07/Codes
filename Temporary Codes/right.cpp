#pragma GCC optimize("Ofast")
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

const int mxm=1005;
const int mod=1e9+7;

struct matrix{
    ll num[mxm][mxm];
    matrix(){
        for(int i=0;i<mxm;i++){
            for(int j=0;j<mxm;j++){
                num[i][j]=0;
            }
        }
    }
    void init(){
        for(int i=0;i<mxm;i++){
            num[i][i]=1;
        }
    }
    matrix operator*(matrix b){
        matrix c;
        for(int k=0;k<mxm;k++){
            for(int i=0;i<mxm;i++){
                for(int j=0;j<mxm;j++){
                    c.num[i][k]=(c.num[i][k]+num[i][j]*b.num[j][k]%mod)%mod;
                }
            }
        }
        return c;
    }
};

matrix fpow(matrix base,ll k){
    matrix ans;
    ans.init();
    while(k>0){
        if(k&1) ans=ans*base;
        base=base*base;
        k/=2;
    }
    return ans;
}

int main() {_
    ll n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    matrix base;
    for(int i=0;i<=m;i++){
        base.num[i][0]=1;
        for(int j=0;j<n;j++){
            if(i*2+a[j]<=m){
                base.num[i][i*2+a[j]]++;
            }
        }
    }
    matrix ans=fpow(base,k);
    ll sum=0;
    for(int i=0;i<=m;i++){
        sum=(sum+ans.num[0][i])%mod;
    }
    cout<<sum<<'\n';
    return 0;
}
//maybe its multiset not set
