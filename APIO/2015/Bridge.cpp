#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

multiset<ll> st,en;
ll lsum=0,rsum=0;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
	return a.f+a.s<b.f+b.s;
}

void insert(ll v){
	ll mid=(st.size()?*st.rbegin():1e9+1);
	if(v<=mid){
		st.insert(v);
		lsum+=v;
	}
	else{
		en.insert(v);
		rsum+=v;
	}
	while(st.size()>en.size()+1){
		lsum-=*st.rbegin();
		rsum+=*st.rbegin();
		en.insert(*st.rbegin());
		st.erase(st.find(*st.rbegin()));
	}
	while(en.size()>st.size()){
		lsum+=*en.begin();
		rsum-=*en.begin();
		st.insert(*en.begin());
		en.erase(en.find(*en.begin()));
	}
}

int main() {_
	ll k,n;
	cin>>k>>n;
	ll ans=0;
	vector<pair<ll,ll>> num;
	for(ll i=0;i<n;i++){
		char a,b;
		ll s,t;
		cin>>a>>s>>b>>t;
		if(a==b) ans+=abs(s-t);
		else num.push_back({s,t});
	}
	sort(num.begin(),num.end(),compare);
	vector<ll> pre(num.size()+1,0);
	for(ll i=0;i<num.size();i++){
		insert(num[i].f);
		insert(num[i].s);
		pre[i+1]=rsum-lsum;
	}
	ll ans2=pre[num.size()];
	if(k==2){
		st.clear();
		en.clear();
		lsum=0;
		rsum=0;
		for(ll i=num.size();i>=1;i--){
			insert(num[i-1].f);
			insert(num[i-1].s);
			ans2=min(ans2,rsum-lsum+pre[i-1]);
			/*or(auto v=st.begin();v!=st.end();v++){
				cout<<*v<<' ';
			}
			cout<<'\n';
			for(auto v=en.begin();v!=en.end();v++){
				cout<<*v<<' ';
			}
			cout<<'\n';*/
		}
	}
	cout<<ans+ans2+num.size();
	return 0;
}
//maybe its multiset not set
