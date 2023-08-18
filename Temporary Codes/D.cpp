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

const int mxn=105;
const int B=105*105;
int dp[mxn][mxn*mxn*2];

void solve(){
    string str;
    cin>>str;
    int n=(int)str.length();
    int a=0,b=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(str[i]=='0' and str[j]=='1') a++;
            else if(str[i]=='1' and str[j]=='0') b++;
        }
    }
    /*int goal=(a+b)/2;
    vector<vector<int>> vec;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=i+1;j<n;j++){
            if(str[i]=='0' and str[j]=='1') tmp.push_back(-(j-i));
            else if(str[i]=='1' and str[j]=='0') tmp.push_back((j-i));
        }
        if(!tmp.empty()) vec.push_back(tmp);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[B]=0;
    for(auto vv:vec){
        //cout<<v<<' ';
        if(vv[0]>0){
            for(int i=mxn*mxn*2-1;i>=vv[0];i--){
                for(auto v:vv){
                    if(i>=v) dp[i]=min(dp[i],dp[i-v]+1);
                }
            }
        }
        else{
            for(int i=0;i-vv[0]<mxn*mxn*2;i++){
                for(auto v:vv){
                    if(i-v<mxn*mxn*2) dp[i]=min(dp[i],dp[i-v]+1);
                }
            }
        }
    }*/
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=n;i++) dp[i][B]=0;
    for(int i=1;i<=n;i++){
        if(str[i-1]!='1') continue;
        for(int j=n;j>=1;j--){
            for(int k=0;k<mxn*mxn*2;k++){
                dp[j][k]=0x3f3f3f3f;
            }
            int val=j-i;
            if(val>=0){
                for(int k=mxn*mxn*2-1;k>=val;k--){
                    dp[j][k]=min(dp[j][k],dp[j-1][k-val]+(str[j-1]=='0'));
                }
            }
            else{
                for(int k=0;k-val<mxn*mxn*2;k++){
                    dp[j][k]=min(dp[j][k],dp[j-1][k-val]+(str[j-1]=='0'));
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=0;k<mxn*mxn*2;k++){
                dp[j][k]=min(dp[j][k],dp[j-1][k]);
            }
        }
    }
    //cout<<'\n';
    //cout<<b-a<<'\n';
    int mn=1e9;
    for(int j=1;j<=n;j++){
        cout<<dp[j][B+(b-a)/2]<<'\n';
        mn=min(mn,dp[j][B+(b-a)/2]);
    }
    cout<<mn<<'\n';
}

int main() {_
    int t;
    t=1;
    while(t--) solve();
    return 0;
}
//maybe its multiset not set

