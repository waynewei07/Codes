#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int depth[4000][4000];


int main() {_
	int n,m;
	cin>>n>>m;
	char num[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>num[i][j];
		}
	}
	deque<pair<int,int>> dq;
	dq.push_back({0,0});
	depth[0][0]=1;
	int ans=0;
	while(!dq.empty()){
		pair<int,int> temp=dq.front();
		int x=temp.f;
		int y=temp.s;
		dq.pop_front();
		ans=max(ans,depth[x][y]);
		for(int i=0;i<4;i++){
			if(0<=x+dx[i] && x+dx[i]<n && 0<=y+dy[i] && y+dy[i]<m && num[x+dx[i]][y+dy[i]]!='.' && depth[x+dx[i]][y+dy[i]]==0){
				if(num[x+dx[i]][y+dy[i]]==num[x][y]){
					depth[x+dx[i]][y+dy[i]]=depth[x][y];
					dq.push_front({x+dx[i],y+dy[i]});
				}
				else{
					depth[x+dx[i]][y+dy[i]]=depth[x][y]+1;
					dq.push_back({x+dx[i],y+dy[i]});
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//maybe its multiset not set
