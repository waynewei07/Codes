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

void go(int l,int r,int tl,int tr){
	if(l>r)	return;
	int mid=(l+r)/2;
	priority_queue<int,vector<int>,greater<int>> pq;
	int len=0;
	ll sum=0;
	for(int i=mid;i>tr;i--){
		if(i!=mid){
            len++;
            if(i<st) len++;
		}
		pq.push(a[i]);
		sum+=a[i];
		while(!pq.empty() and (int)pq.size()>(d-len)){
			sum-=pq.top();
			pq.pop();
		}
	}
	int best=tr;
	for(int i=tr;i>=tl;i--){
		if(i!=mid){
            len++;
            if(i<st) len++;
		}
		pq.push(a[i]);
		sum+=a[i];
		while(!pq.empty() and (int)pq.size()>(d-len)){
			sum-=pq.top();
			pq.pop();
		}
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
	go(st,n-1,0,st);
	ll ans=dp[st];
	dp[st]=0;
	reverse(a,a+n);
	reverse(dp,dp+n);
	st=n-st-1;
	go(st,n-1,0,st);
	for(int i=0;i<n;i++){
		//cout<<dp[i]<<' ';
		ans=max(ans,dp[i]);
	}
    return ans;
}

signed main() {_
    auto S=clock();
	int q,qq,qqq;
	cin>>q>>qq>>qqq;
	int qqqq[q];
	for(int i=0;i<q;i++){
		cin>>qqqq[i];
	}
	cout<<findMaxAttraction(q,qq,qqq,qqqq);
    return 0;
}
//maybe its multiset not set
