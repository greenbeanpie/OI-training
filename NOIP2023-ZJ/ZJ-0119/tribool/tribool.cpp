#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int t,opt,n,m,flg=0,ans[N];
char o;
vector<int>e[N];
struct val{
	int op,x,c;
	val inv(){
		val t=*this;
		if(op)t.op*=-1;
		else t.c=t.c>1?2:-t.c;
		return t;
	}
};
val v[N];
void dfs1(int x){
	if(flg)
		return;
	int t=x>n?x-n:x+n,inv=-ans[x];
	if(ans[t]&&ans[t]!=inv)
		return void(flg=1);
	ans[t]=inv;
	for(int y:e[x])
		if(ans[y]&&ans[y]!=ans[x])
			return void(flg=1);
		else if(!ans[y])
			ans[y]=ans[x],dfs1(y);
	for(int y:e[t])
		if(ans[y]&&ans[y]!=ans[t])
			return void(flg=1);
		else if(!ans[y])
			ans[y]=ans[t],dfs1(y);
}
void dfs2(int x){
	int t=x>n?x-n:x+n;
	ans[x]=ans[t]=2;
	for(int y:e[x])
		if(ans[y]!=2)
			dfs2(y);
	for(int y:e[t])
		if(ans[y]!=2)
			dfs2(y);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	for(cin>>opt>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			v[i].op=1,v[i].x=i,v[i].c=0;
		for(int i=1;i<=2*n;i++)
			ans[i]=0,e[i].clear();
		for(int i=1,x,y;i<=m;i++){
			switch(cin>>o>>x,o){
				case'T':{
					v[x].op=v[x].x=0,v[x].c=1;
					break;
				}
				case'F':{
					v[x].op=v[x].x=0,v[x].c=-1;
					break;
				}
				case'U':{
					v[x].op=v[x].x=0,v[x].c=2;
					break;
				}
				case'+':{
					cin>>y,v[x]=v[y];
					break;
				}
				case'-':{
					cin>>y,v[x]=v[y].inv();
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(v[i].op){
				int j=v[i].x+(v[i].op<0?n:0);
				e[i].push_back(j);
				e[j].push_back(i);
			}else ans[i]=v[i].c,
				ans[i+n]=v[i].inv().c;
		for(int i=1;i<=n;i++)
			if(!ans[i]){
				ans[i]=1,flg=0,dfs1(i);
				if(flg)dfs2(i);
			}
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=ans[i]>1;
		cout<<cnt<<"\n";
	}
}
