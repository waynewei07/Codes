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

const int mxn=1e3+5;
double p[mxn][mxn];
double pre[mxn],pre2[mxn];


int main() {_
    int n,k;
    cin>>n>>k;
    n--;
    p[0][0]=1;
    for(int i=1;i<=n;i++){
        p[i][0]=p[i-1][0]/2;
        for(int j=1;j<=n;j++){
            p[i][j]=(p[i-1][j-1]+p[i-1][j])/2;
        }
    }
    pre[0]=p[n][0];
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+p[n][i];
        pre2[i]=pre2[i-1]+p[n][i]*i;
    }
    double cur=0;
    while(k>0){
        int j=floor(cur+1e-9);
        double a=pre[j];
        double b=pre2[n]-pre2[j];
        int l=1,r=k;
        while(l<r){
            int mid=(l+r+1)/2;
            double ans=pow(a,mid)*cur+(pow(a,mid)-1)/(a-1)*b;
            if(floor(ans)==j){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        cur=pow(a,l)*cur+(pow(a,l)-1)/(a-1)*b;
        k-=l;
    }
    cout<<fixed<<setprecision(10)<<cur+1<<'\n';
    return 0;
}
//maybe its multiset not set

