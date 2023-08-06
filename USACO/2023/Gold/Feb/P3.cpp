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

const int mxn=305;
const int mod=1e9+7;
int a[mxn];
int n;
ll A,B;
ll cnt[mxn][mxn];
string str;
ll dp[mxn][20][20][3]; // 0/1/2 under/equal/over

void reset(){
    for(int i=0;i<mxn;i++){
        for(int j=0;j<20;j++){
            for(int k=0;k<20;k++){
                for(int m=0;m<3;m++){
                    dp[i][j][k][m]=0;
                }
            }
        }
    }
}

ll chadd(ll a,ll b){
    ll ans=(a+b)%mod;
    if(ans<0) ans+=mod;
    return ans;
}

void solve(int L,int add){
    for(int j=L;j<n;j++){
        for(int i=0;i<(int)str.length();i++){
            int con=1;
            int digit=str[i]-'0';
            if(a[j]<digit) con=0;
            else if(a[j]>digit) con=2;
            dp[j][i][i][con]=2;
            //cout<<j<<' '<<i<<' '<<i<<' '<<con<<' '<<dp[j][i][i][con]<<'\n';
        }
    }
    for(int i=L+1;i<n;i++){
        for(int l=0;l<(int)str.length();l++){
            for(int r=l;r<(int)str.length();r++){
                for(int m=0;m<3;m++){
                    dp[i][l][r][m]=chadd(dp[i][l][r][m],dp[i-1][l][r][m]);
                }
                if(l==r){
                    for(int m=0;m<3;m++){
                        //cout<<i<<' '<<l<<' '<<r<<' '<<m<<' '<<dp[i][l][r][m]<<'\n';
                    }
                    continue;
                }
                int con=1;
                int digit=str[r]-'0';
                if(a[i]<digit) con=0;
                else if(a[i]>digit) con=2;
                dp[i][l][r][2]=chadd(dp[i][l][r][2],dp[i-1][l][r-1][2]);
                dp[i][l][r][0]=chadd(dp[i][l][r][0],dp[i-1][l][r-1][0]);
                dp[i][l][r][con]=chadd(dp[i][l][r][con],dp[i-1][l][r-1][1]);

                con=1;
                digit=str[l]-'0';
                if(a[i]<digit) con=0;
                else if(a[i]>digit) con=2;
                if(con==1){
                    dp[i][l][r][0]=chadd(dp[i][l][r][0],dp[i-1][l+1][r][0]);
                    dp[i][l][r][1]=chadd(dp[i][l][r][1],dp[i-1][l+1][r][1]);
                    dp[i][l][r][2]=chadd(dp[i][l][r][2],dp[i-1][l+1][r][2]);
                }
                else{
                    dp[i][l][r][con]=chadd(dp[i][l][r][con],dp[i-1][l+1][r][0]);
                    dp[i][l][r][con]=chadd(dp[i][l][r][con],dp[i-1][l+1][r][1]);
                    dp[i][l][r][con]=chadd(dp[i][l][r][con],dp[i-1][l+1][r][2]);
                }
                for(int m=0;m<3;m++){
                    //cout<<i<<' '<<l<<' '<<r<<' '<<m<<' '<<dp[i][l][r][m]<<'\n';
                }
            }
        }
    }
    for(int i=L;i<n;i++){
        cnt[L][i]=chadd(cnt[L][i],(dp[i][0][(int)str.length()-1][0]+dp[i][0][(int)str.length()-1][1])%mod*add);
        for(int l=1;l<(int)str.length();l++){
            cnt[L][i]=chadd(cnt[L][i],(dp[i][l][(int)str.length()-1][0]+dp[i][l][(int)str.length()-1][1]+dp[i][l][(int)str.length()-1][2])%mod*add);
        }
    }

}

int main() {_
    cin>>n>>A>>B;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    str=to_string(B);
    for(int i=0;i<n;i++){
        reset();
        //cout<<i<<'\n';
        solve(i,1);
    }
    str=to_string(A-1);
    for(int i=0;i<n;i++){
        reset();
        //cout<<i<<'\n';
        solve(i,-1);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<cnt[a-1][b-1]<<'\n';
    }
    return 0;
}
//maybe its multiset not set

