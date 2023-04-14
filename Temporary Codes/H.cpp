#pragma GCC optimize("O4")
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

int n;
vector<pair<int,int>> vec;

int check(int x,int y){
    int a1=0,a2=0,a3=0,a4=0;
    for(int i=0;i<n;i++){
        if(vec[i].f>x and vec[i].s>y) a1++;
        else if(vec[i].f>x and vec[i].s<y) a2++;
        else if(vec[i].f<x and vec[i].s>y) a3++;
        else a4++;
    }
    return max({a1,a2,a3,a4});
}

int f(int v){
    //cout<<v<<'\n';
    int l=0,r=5e5+5;
    while(l<r){
        //cout<<l<<' '<<r<<'\n';
        if(l==r-1){
            if(check(v*2,r*2)<=check(v*2,l*2)){
                l++;
            }
            else{
                r--;
            }
            continue;
        }
        int tl=(l+r)/2;
        int tr=(tl+r)/2;
        if(tl==r-1){
            if(check(v*2,r*2)>=check(v*2,l*2)){
                r=tl;
            }
            else{
                l=tl;
            }
            continue;
        }
        if(check(v*2,tr*2)>=check(v*2,tl*2)){
            r=tr;
        }
        else{
            l=tl;
        }
    }
    return check(v*2,l*2);
}

int main() {_
    setIO("balancing");
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    int l=0,r=5e5+5;
    while(l<r){
        if(l==r-1){
            if(f(r)<=f(l)){
                l++;
            }
            else{
                r--;
            }
            continue;
        }
        int tl=(l+r)/2;
        int tr=(tl+r)/2;
        if(tl==r-1){
            if(f(r)>=f(l)){
                r=tl;
            }
            else{
                l=tl;
            }
            continue;
        }
        if(f(tr)>=f(tl)){
            r=tr;
        }
        else{
            l=tl;
        }
    }
    //cout<<l*2<<'\n';
    cout<<f(l);
    return 0;
}
//maybe its multiset not set
