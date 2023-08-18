#pragma GCC optimize("O3")
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

const int mxn=20;
int nxt[1<<mxn];
bool dp[mxn*3][1<<mxn];
int pre[mxn*3];
int t,n;
int cnt=1;
int ord[1<<mxn];

int trans(string str){
    int ans=0;
    for(int i=0;i<n;i++){
        int a=str[i]-'0';
        ans|=(a<<(n-1-i));
    }
    return ans;
}

void p(int val){
    for(int i=n-1;i>=0;i--){
        if(val&(1<<i)) cout<<1;
        else cout<<0;
    }
}

int main() {_
    cin>>t>>n;
    for(int i=0;i<(1<<n);i++){
        int val=i;
        int a=val&1;
        val>>=1;
        val|=(a<<(n-1));
        nxt[val]=i;
    }
    vector<int> vec;
    for(int i=0;i<(1<<n);i++){
        if(ord[i]>0) continue;
        vec.push_back(i);
        ord[i]=cnt;
        int val=nxt[i];
        while(val!=i){
            ord[val]=cnt;
            val=nxt[val];
        }
        cnt++;
    }
    int bit=0;
    for(int i=1;i<n*3;i++){
        pre[i]=pre[i-1];
        pre[i]^=(1<<bit);
        bit++;
        bit%=n;
    }
    dp[0][0]=true;
    for(int i=1;i<n*3;i++){
        int cur=pre[i];
        for(auto mask:vec){
            for(int j=0;j<n;j++){
                dp[i][mask]|=dp[i-1][mask^cur];
                cur=nxt[cur];
            }
            int val=nxt[mask];
            while(val!=mask){
                dp[i][val]=dp[i][mask];
                val=nxt[val];
            }
        }
    }
    for(int i=0;i<t;i++){
        string a,b;
        cin>>a>>b;
        int L=trans(a);
        int S=trans(b);
        for(int j=0;j<3*n;j++){
            if(dp[j][L]){
                cout<<j<<'\n';
                break;
            }
            L^=S;
            L=nxt[L];
        }
    }
    return 0;
}
//maybe its multiset not set

