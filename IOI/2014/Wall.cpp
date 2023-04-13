/*
希望全國賽不要墊底
*/
#pragma GCC optimize("O4,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
#include <wall.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mxh=0x3f3f3f3f;

const int mxn=2e6+5;
pair<int,int> segtree[8000080];

void push(int v){
    segtree[v*2].f=max(segtree[v*2].f,segtree[v].f);
    segtree[v*2].s=min(segtree[v*2].s,segtree[v].s);
    segtree[v*2].f=min(segtree[v*2].f,segtree[v].s);
    segtree[v*2].s=max(segtree[v*2].s,segtree[v].f);
    segtree[v*2+1].f=max(segtree[v*2+1].f,segtree[v].f);
    segtree[v*2+1].s=min(segtree[v*2+1].s,segtree[v].s);
    segtree[v*2+1].f=min(segtree[v*2+1].f,segtree[v].s);
    segtree[v*2+1].s=max(segtree[v*2+1].s,segtree[v].f);
    segtree[v].f=0;
    segtree[v].s=mxh;
}

void update(int type,int tl,int tr,int h,int l,int r,int v=1){
    if(tl>tr){
        return;
    }
    if(tl<=l and r<=tr){
        if(type==1){
        	segtree[v].f=max(segtree[v].f,h);
        	segtree[v].s=max(segtree[v].s,h);
        }
        else{
        	segtree[v].s=min(segtree[v].s,h);
        	segtree[v].f=min(segtree[v].f,h);
        }
        return;
    }
    push(v);
    int mid=(l+r)/2;
    update(type,tl,min(mid,tr),h,l,mid,v*2);
    update(type,max(mid+1,tl),tr,h,mid+1,r,v*2+1);
}

ll query(int pos,int l,int r,int v=1){
    if(l==r){
        return min(segtree[v].f,segtree[v].s);
    }
    push(v);
    int mid=(l+r)/2;
    if(pos<=mid) return query(pos,l,mid,v*2);
    else return query(pos,mid+1,r,v*2+1);
}

void buildWall(int n,int k,int op[],int l[],int r[],int h[], int final[]){
for(int i=0;i<k;i++){
        update(op[i],l[i],r[i],h[i],0,n-1);
    }
    for(int i=0;i<n;i++){
        final[i]=query(i,0,n-1);
    }
}

/*int main() {_
    //setIO("wayne");
	int op[6]={1,2,2,1,1,2};
	int l[6]={1,4,3,0,2,6};
	int r[6]={8,9,6,5,2,7};
	int h[6]={4,1,5,3,5,0};
	int final[10];
    buildWall(n,k,op,l,r,h,final);
    for(int i=0;i<n;i++){
        cout<<final[i]<<' ';
    }
    return 0;
}*/
//maybe its multiset not set
