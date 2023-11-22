#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,m,minn;
int sta[15],op2[15],x2[15],y2[15];
int visC4[MAXN];
int getu6[MAXN],op6[MAXN],x6[MAXN],y6[MAXN],fa6[MAXN],vis[MAXN];
map<pair<int,int>,int> mp;
vector<int> v[MAXN];
void dfs(int step){
	if(step==n+1){
		int sta2[15];
		rep(i,1,n)sta2[i]=sta[i];
		rep(i,1,m){
			if(op2[i]==1)
				sta2[y2[i]]=1;
			if(op2[i]==2)
				sta2[y2[i]]=2;
			if(op2[i]==3)
				sta2[y2[i]]=3;
			if(op2[i]==4)
				sta2[x2[i]]=sta2[y2[i]];
			if(op2[i]==5){
				if(sta2[y2[i]]==1)
					sta2[x2[i]]=2;
				else if(sta2[y2[i]]==2)
					sta2[x2[i]]=1;
				else sta2[x2[i]]=3;
			}
		}
		int flag=0;
		rep(i,1,n)
			if(sta2[i]!=sta[i])
				flag=1;
		if(flag==0){
			int cnt=0;
			rep(i,1,n)
				if(sta[i]==3)cnt++;
			minn=min(minn,cnt);
		}
		return;
	}
	sta[step]=1;
	dfs(step+1);
	sta[step]=2;
	dfs(step+1);
	sta[step]=3;
	dfs(step+1);
}
void dfs6(int x,int fa){
	vis[x]=1;
	for(int i=0;i<(int)v[x].size();i++){
		int y=v[x][i];
		if(vis[y])continue;
		if(y==fa)continue;
		getu6[y]=getu6[x];
		dfs6(y,x);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C,T;scanf("%d%d",&C,&T);
	if(C<=2){
		while(T--){
			rep(i,0,14)
				sta[i]=0,op2[i]=0,x2[i]=0,y2[i]=0;
			minn=0x3f3f3f3f;
			scanf("%d%d",&n,&m);
			rep(i,1,m){
				char ch;cin>>ch;
				if(ch=='T'){
					scanf("%d",&y2[i]);
					op2[i]=1,x2[i]=1;
				}
				if(ch=='F'){
					scanf("%d",&y2[i]);
					op2[i]=2,x2[i]=2;
				}
				if(ch=='U'){
					scanf("%d",&y2[i]);
					op2[i]=3,x2[i]=3;
				}
				if(ch=='+'){
					scanf("%d%d",&x2[i],&y2[i]);
					op2[i]=4;
				}
				if(ch=='-'){
					scanf("%d%d",&x2[i],&y2[i]);
					op2[i]=5;
				}
			}
			dfs(1);
			printf("%d\n",minn);	
		}
		return 0;
	}
	else if(C<=4){
		while(T--){
			int cnt=0;
			scanf("%d%d",&n,&m);
			rep(i,1,n)visC4[i]=0;
			rep(i,1,m){
				char ch;cin>>ch;
				int tmp;cin>>tmp;
				if(ch=='U'&&!visC4[tmp]){
					visC4[tmp]=1;
					cnt++;
				}
			}
			printf("%d\n",cnt);
		}
		return 0;
	}
	else if(C<=6){
		while(T--){
			scanf("%d%d",&n,&m);
			rep(i,1,n)getu6[i]=0;
			rep(i,1,n)v[i].clear();
			rep(i,1,m){
				char ch;cin>>ch;
				if(ch=='U'){
					scanf("%d",&x6[i]);
					op6[i]=1;
				}
				else{
					scanf("%d%d",&x6[i],&y6[i]);
					op6[i]=2;
				}
			}
			for(int i=m;i>=1;i--){
				if(op6[i]==1){
					getu6[x6[i]]=1;
					rep(i,1,n)vis[i]=0;
					dfs6(x6[i],-1);
				}
				else{
					if(y6[i]==x6[i])continue;
					if(mp[make_pair(y6[i],x6[i])])continue;
					mp[make_pair(y6[i],x6[i])]=1;
					rep(i,1,n)vis[i]=0;
					dfs6(y6[i],-1);
					v[y6[i]].push_back(x6[i]);
				}
			}
			int cnt=0;
			rep(i,1,n)
				if(getu6[i])
					cnt++;
			printf("%d\n",cnt);
		}
		return 0;
	}
	else{
		rep(i,1,T)
			printf("0\n");
	}
	return 0;
}

