#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int c,t;
namespace Sub1{
	int n,m;
	int co[40],keepc[40],ans;
	struct operate{char ch;int u,v;}o[40];
	inline void dfs(int cnt){
		if(cnt>n){
			for(int i=1;i<=m;++i){
				if(o[i].ch=='+')keepc[o[i].v]=keepc[o[i].u];
				else if(o[i].ch=='-'){
					if(keepc[o[i].u]==1)keepc[o[i].v]=2;
					else if(keepc[o[i].u]==2)keepc[o[i].v]=1;
					else if(keepc[o[i].u]==3)keepc[o[i].v]=3;
				}else{
					if(o[i].ch=='T')keepc[o[i].v]=1;
					else if(o[i].ch=='F')keepc[o[i].v]=2;
					else if(o[i].ch=='U')keepc[o[i].v]=3;
				}
			}
			int tot=0;bool flag=1;
			for(int i=1;i<=n;++i){
				if(co[i]!=keepc[i]){flag=0;break;}
				if(co[i]==3)++tot;
			}
			if(flag)ans=min(ans,tot);
			else{
				for(int i=1;i<=n;++i)keepc[i]=co[i];
			}
			return;
		}
		for(int i=1;i<=3;++i){
			co[cnt]=i;
			keepc[cnt]=i;
			dfs(cnt+1);
		}
	}
	signed work(){
		while(t--){
			scanf("%d %d ",&n,&m);
			for(int i=1;i<=m;++i){
				cin>>o[i].ch;
				if(o[i].ch=='+'||o[i].ch=='-')cin>>o[i].v>>o[i].u;
				else cin>>o[i].v;
			}
			ans=114514;
			dfs(1);
			printf("%d\n",ans);
		}
		return 0;
	}
}
namespace Sub2{
	int n,m,cnt;
	bool co[100010];
	signed work(){
		while(t--){
			cnt=0;
			scanf("%d %d ",&n,&m);
			memset(co,0,sizeof co);
			for(int i=1;i<=m;++i){
				char ch;int u;
				scanf("%c %d ",&ch,&u);
				if(ch=='T'||ch=='F')co[u]=0;
				else co[u]=1;
			}
			for(int i=1;i<=n;++i)if(co[i]==1)++cnt;
			printf("%d\n",cnt);
		}
		return 0;
	}
}
namespace Sub3{
	int n,m,co[100010],cnt;
	signed work(){
		while(t--){
			cnt=0;
			memset(co,0,sizeof co);
			scanf("%d %d ",&n,&m);
			for(int i=1;i<=m;++i){
				char ch;int u,v;
				scanf("%c %d ",&ch,&u);
				if(ch=='T'||ch=='F')co[u]=0;
				else if(ch=='U')co[u]=1;
				else{
					scanf("%d ",&v);
					co[u]=co[v];
				}
			}
			for(int i=1;i<=n;++i)if(co[i]==1)++cnt;
			printf("%d\n",cnt);
		}
		return 0;
	}
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d ",&c,&t);
	if(c<=2)Sub1::work();
	else if(c<=4)Sub2::work();
	else if(c<=6)Sub3::work();
	return 0;
}