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
vector<int> xs,ys;
vector<int> xx;
vector<int> yy;

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
    int l=0,r=yy.size()-1;
    while(l<r){
        //cout<<l<<' '<<r<<'\n';
        if(l==r-1){
            if(check(v,yy[r])<=check(v,yy[l])){
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
            if(check(v,yy[r])>=check(v,yy[l])){
                r=tl;
            }
            else{
                l=tl;
            }
            continue;
        }
        if(check(v,yy[tr])>=check(v,yy[tl])){
            r=tr;
        }
        else{
            l=tl;
        }
    }
    return check(v,yy[l]);
}

int main() {_
    setIO("balancing");
    cin>>n;
    xs.push_back(-5);
    xs.push_back(1e6+5);
    ys.push_back(-5);
    ys.push_back(1e6+5);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
        xs.push_back(x);
        ys.push_back(y);
    }
    sort(all(xs));
    sort(all(ys));
    xs.resize(unique(all(xs))-xs.begin());
    ys.resize(unique(all(ys))-ys.begin());
    for(int i=0;i<xs.size()-1;i++){
        xx.push_back((xs[i]+xs[i+1])/2);
    }
    for(int i=0;i<ys.size()-1;i++){
        yy.push_back((ys[i]+ys[i+1])/2);
    }
    int l=0,r=xx.size()-1;
    while(l<r){
        if(l==r-1){
            if(f(xx[r])<=f(xx[l])){
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
            if(f(xx[r])>=f(xx[l])){
                r=tl;
            }
            else{
                l=tl;
            }
            continue;
        }
        if(f(xx[tr])>=f(xx[tl])){
            r=tr;
        }
        else{
            l=tl;
        }
    }
    //cout<<l*2<<'\n';
    cout<<f(xx[l]);
    return 0;
}
//maybe its multiset not set
