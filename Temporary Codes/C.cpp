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

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void solve(){
    string str[5];
    for(int i=0;i<5;i++){
        for(int j=0;j<7;j++){
            cin>>str[i][j];
        }
    }
    string ans[5];
    for(int i=0;i<5;i++){
        for(int j=0;j<7;j++){
            ans[i][j]='0';
        }
    }
    for(int i=1;i<5;i++){
        for(int j=0;j<7;j++){
            if(str[i-1][j]=='1'){
                ans[i][j]='1';
                for(int k=0;k<4;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x>=0 and x<5 and y>=0 and y<7){
                        if(str[x][y]=='1') str[x][y]='0';
                        else str[x][y]='1';
                    }
                }
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<7;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}

int main() {_
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
//maybe its multiset not set
