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

const int mxn=18;
ll dp[1<<mxn][mxn];
ll ans[1<<mxn];
bool ok[mxn][mxn];
int n;

int main() {_
    cin>>n;
    for(int i=0;i<n;i++){
        bool tf=true;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            x--;
            if(tf) ok[i][x]=true;
            if(x==i) tf=false;
        }
        dp[1<<i][i]=1;
    }
    ans[0]=1;
    for(int i=0;i<n;i++){
        for(int S=(1<<i);S<(1<<(i+1));S++){
            for(int last=0;last<=i;last++){
                for(int k=0;k<i;k++){
                    if(!(S&(1<<k)) and ok[last][k]){
                        dp[S^(1<<k)][k]+=dp[S][last];
                    }
                }
                if(ok[last][i]) ans[S]+=dp[S][last];
            }
            for(int j=i+1;j<n;j++){
                dp[S^(1<<j)][j]+=ans[S];
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int S=0;
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            if(c=='H') S+=(1<<j);
        }
        cout<<ans[S]*ans[((1<<n)-1)^S]<<'\n';
    }
    return 0;
}
//maybe its multiset not set
/*
5
1 2 3 4 5
3 4 5 2 1
4 5 3 2 1
3 4 5 2 1
3 4 5 2 1
*/
