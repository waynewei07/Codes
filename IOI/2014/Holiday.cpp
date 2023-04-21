#pragma GCC optimize("O3","unroll-loops")
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

const int mxn=1e5+5;
int n;
ll dp[mxn];
int a[mxn];
int d;
int st;
int L,R;
multiset<ll> S;
multiset<ll> T;
ll sum=0;
int len=0;

void init(){
    L=0,R=n-1;
    len=-1;
    sum=0;
    S.clear();
    T.clear();
    for(int i=0;i<n;i++){
        len++;
        if(i<st) len++;
        sum+=a[i];
        S.insert(a[i]);
    }
    while(!S.empty() and (int)S.size()>d-len){
        sum-=*S.begin();
        T.insert(*S.begin());
        S.erase(S.begin());
    }
}

void sir(int l,int r){
    while(L>l){
        L--;
        len++;
        if(L<st) len++;
        sum+=a[L];
        S.insert(a[L]);
        while(!S.empty() and (int)S.size()>d-len){
            sum-=*S.begin();
            T.insert(*S.begin());
            S.erase(S.begin());
        }
    }
    while(R<r){
        R++;
        len++;
        if(R<st) len++;
        sum+=a[R];
        S.insert(a[R]);
        while(!S.empty() and (int)S.size()>d-len){
            sum-=*S.begin();
            T.insert(*S.begin());
            S.erase(S.begin());
        }
    }
    while(L<l){
        len--;
        if(L<st) len--;
        if(S.find(a[L])!=S.end()){
            S.erase(S.find(a[L]));
            sum-=a[L];
        }
        else if(T.find(a[L])!=T.end()){
            T.erase(T.find(a[L]));
        }
        while(!T.empty() and (int)S.size()<d-len){
            sum+=*T.rbegin();
            S.insert(*T.rbegin());
            T.erase(prev(T.end()));
        }
        L++;
    }
    while(R>r){
        len--;
        if(R<st) len--;
        if(S.find(a[R])!=S.end()){
            S.erase(S.find(a[R]));
            sum-=a[R];
        }
        else if(T.find(a[R])!=T.end()){
            T.erase(T.find(a[R]));
        }
        while(!T.empty() and (int)S.size()<d-len){
            sum+=*T.rbegin();
            S.insert(*T.rbegin());
            T.erase(prev(T.end()));
        }
        R--;
    }
}

void go(int l,int r,int tl,int tr){
	if(l>r)	return;
	int mid=(l+r)/2;
	int best=tr;
	for(int i=tr;i>=tl;i--){
		sir(i,mid);
		if(sum>dp[mid]){
			dp[mid]=sum;
			best=i;
		}
	}
	go(l,mid-1,tl,best);
	go(mid+1,r,best,tr);
}

long long findMaxAttraction(int N, int start, int D, int attraction[]) {
	d=D;
	n=N;
	st=start;
	for(int i=0;i<n;i++){
		a[i]=attraction[i];
	}
	init();
	go(st,n-1,0,st);
	ll ans=dp[st];
	dp[st]=0;
	reverse(a,a+n);
	reverse(dp,dp+n);
	st=n-st-1;
	init();
	go(st,n-1,0,st);
	for(int i=0;i<n;i++){
		//cout<<dp[i]<<' ';
		ans=max(ans,dp[i]);
	}
    return ans;
}

/*signed main() {_
    auto S=clock();
	int q,qq,qqq;
	cin>>q>>qq>>qqq;
	int qqqq[q];
	for(int i=0;i<q;i++){
		cin>>qqqq[i];
	}
	cout<<findMaxAttraction(q,qq,qqq,qqqq);
    return 0;
}*/
//maybe its multiset not set
