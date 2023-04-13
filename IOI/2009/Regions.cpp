#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n,r,q;
const int mxn=2e5+5;
const int mxr=25005;
const int k=37;
vector<int> adj[mxn];
int region[mxn];
int st[mxn],en[mxn];
vector<int> regioncnt[mxr];
vector<int> regiontimer[mxr];
map<int,vector<int>> ans_big;
int timer=1;

void euler_tour(int v){
	st[v]=timer;
	regiontimer[region[v]].push_back(timer);
	timer++;
	for(auto u:adj[v]){
		euler_tour(u);
	}
	en[v]=timer-1;
}

void precal(int h){
	vector<int> temp(n+2,0);
	for(auto v:regioncnt[h]){
		temp[st[v]]++;
		temp[en[v]+1]--;
	}
	ans_big[h].resize(r+1);
	for(int i=1;i<=n;i++){
		temp[i]+=temp[i-1];
	}
	for(int i=1;i<=n;i++){
		ans_big[h][region[i]]+=temp[st[i]];
	}
}

int cal_small(int r1,int r2){
	int ans=0;
	for(auto v:regioncnt[r1]){
		ans+=upper_bound(regiontimer[r2].begin(),regiontimer[r2].end(),en[v])-lower_bound(regiontimer[r2].begin(),regiontimer[r2].end(),st[v]);
	}
	return ans;
}

void query_big(int r1,int r2){
	cout<<ans_big[r1][r2]<<'\n'<<flush;
}

void query_small(int r1,int r2){
	cout<<cal_small(r1,r2)<<'\n'<<flush;
}

int main() {_
	//setIO("wayne");
	cin>>n>>r>>q;
	cin>>region[1];
	regioncnt[region[1]].push_back(1);
	for(int i=2;i<=n;i++){
		int s,h;
		cin>>s>>h;
		adj[s].push_back(i);
		region[i]=h;
		regioncnt[h].push_back(i);
	}
	euler_tour(1);
	for(int i=1;i<=r;i++){
		if(regioncnt[i].size()>=k){
			precal(i);
		}
	}
	for(int i=0;i<q;i++){
		int r1,r2;
		cin>>r1>>r2;
		if(regioncnt[r1].size()>=k){
			query_big(r1,r2);
		}
		else{
			query_small(r1,r2);
		}
	}
	return 0;
}
//maybe its multiset not set
