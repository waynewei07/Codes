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

struct line{
    ll a,b;
    ll operator()(const ll x){
        return a*x+b;
    }
};

const int mxn=1e5+5;
const int mxk=205;
ll A[mxn];
ll pre[mxn];
ll dp[mxn];
line li[mxn];
int prv[mxn][mxk];

bool check(int a,int b,int c){
    line l1=li[a];
    line l2=li[b];
    line l3=li[c];
    return (l2.b-l3.b)*(l2.a-l1.a)<=(l1.b-l2.b)*(l3.a-l2.a);
}

int main() {_
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        pre[i]=pre[i-1]+A[i];
    }
    for(int m=1;m<=k;m++){
        deque<int> dq;
        li[m]={pre[m],dp[m]-pre[m]*pre[m]};
        dq.push_back(m);
        for(int i=m+1;i<=n;i++){
            while(dq.size()>1 and li[dq[0]](pre[i])<li[dq[1]](pre[i])){
                dq.pop_front();
            }
            prv[i][m]=dq[0];
            li[i]={pre[i],dp[i]-pre[i]*pre[i]};
            dp[i]=li[dq[0]](pre[i]);
            while(dq.size()>1 and check(dq[dq.size()-2],dq.back(),i)){
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    cout<<dp[n]<<'\n';
    int cur=n;
    vector<int> output;
    for(int i=k;i>=1;i--){
        cur=prv[cur][i];
        output.push_back(cur);
    }
    reverse(all(output));
    for(auto v:output){
        cout<<v<<' ';
    }
    return 0;
}
//maybe its multiset not set
