#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	int x,y,v;
	bool operator<(const node &a)const{
		if(x-y==a.x-a.y){
			if(x==a.x)return v>a.v;
			return x<a.x;
		}return x-y<a.x-a.y;
	}
};
multiset<node>clg;
int n,m,k,d;
LL mx=-INT_MAX;
void dfs(int now,int eng,int stps){
	auto pos=clg.begin();
	for(node p=*pos;pos!=clg.end();pos++,p=*pos){
		int dis=p.x-p.y+1;
		if(dis<now)continue;
		if(dis==now&&stps){
			int nstps=stps+p.y-1;
			if(nstps>k)continue;
			int neng=eng-d*(p.y-1)+p.v;
			mx=max(mx,(LL)neng);
			dfs(p.x,neng,nstps);
			continue;
		}
		if(dis==now+1){
			int nstps=stps+p.y;
			if(nstps>k)continue;
			int neng=eng-d*p.y+p.v;
			mx=max(mx,(LL)neng);
			dfs(p.x,neng,nstps);
			continue;
		}
		int nstps=p.y;
		if(nstps>k)continue;
		int neng=eng-d*p.y+p.v;
		mx=max(mx,(LL)neng);
		dfs(p.x,neng,nstps);
	}
	auto end=clg.end();
	node ed=*end;
	if(now<ed.x-1)dfs(now+1,eng,0);
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		clg.clear(),mx=-INT_MAX;
		scanf("%d %d %d %d",&n,&m,&k,&d);
		for(int i=1;i<=m;++i){
			int x,y,v;
			scanf("%d %d %d",&x,&y,&v);
			clg.insert((node){x,y,v});
		}
		dfs(0,0,0);
		printf("%d\n",mx);
	}
	return 0;
}


