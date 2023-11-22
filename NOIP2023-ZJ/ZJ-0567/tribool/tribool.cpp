#include<bits/stdc++.h>
using namespace std;
const int MaxM=1e5+50;
struct node{
	int type,x,y;
}op[MaxM];
vector<int> E[MaxM];
int nd[MaxM],vis[MaxM];
int n,m,x,y,c,t,ans,V;
char ch,C;
void read(int &num){
	num=0;
	while((C=getchar())!=' ' && C!='\n')
		num=(num<<3)+(num<<1)+(C^48);
	return;
}
void dfs(int pos,int type,int v){
	if(vis[pos]>0)
		return;
	if(vis[pos]<0){
		if(op[pos].type==1)
			V=-3-v;
		else
			V=v;
		if(V!=vis[pos])
			vis[pos]=2;
		else
			vis[pos]=1;
		return;
	}
	if(op[pos].type==1)
		vis[pos]=-3-v;
	else
		vis[pos]=v;
	if(!op[pos].type){
		if(type)
			nd[op[pos].x]=op[pos].y;
		vis[pos]=op[pos].y;
		return;
	}
	int l=0,r=E[op[pos].y].size()-1,Y=op[pos].y;
	if(r<0){
		vis[pos]=1;
		return;
	}
	while(l<r){
		int mid=(l+r+1)>>1;
		if(E[Y][mid]<pos)
			l=mid;
		else
			r=mid-1;
	}
	if(E[Y][l]>pos)
		l=E[Y].size()-1;
	dfs(E[Y][l],(l==(int)(E[Y].size()-1)),vis[pos]);
	vis[pos]=vis[E[Y][l]];
	if(op[pos].type==1)
		vis[pos]=4-vis[pos];
	if(type)
		nd[op[pos].x]=vis[pos];
	return;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	read(c);read(t);
	while(t--){
		read(n);read(m);
		for(int i=1;i<n+1;i++){
			E[i].clear();
			nd[i]=0;
		}
		ans=0;
		for(int i=1;i<m+1;i++){
			vis[i]=0;
			ch=getchar();
			getchar();
			if(ch=='-' || ch=='+'){
				read(x);read(y);
				E[x].push_back(i);
				op[i].x=x;op[i].y=y;
				op[i].type=(ch=='-')?1:2;
			}else{
				read(x);
				if(ch=='T')
					y=1;
				else
				if(ch=='U')
					y=2;
				else
				if(ch=='F')
					y=3;
				E[x].push_back(i);
				op[i].x=x;op[i].y=y;op[i].type=0;
			}
		}
		for(int i=1;i<n+1;i++)
			if(!nd[i] && E[i].size())
				dfs(E[i][E[i].size()-1],1,-1);
		for(int i=1;i<n+1;i++)
			if(nd[i]==2)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}