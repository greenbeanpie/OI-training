#include<bits/stdc++.h>
using namespace std;
int C,T,n,m,k;
long long d,ans_1;
void solve1(){
	while (T--){
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		ans_1=0;
		int la=0;
		long long ltmp=0;
		for (int i=1;i<=m;++i){
			int x,y;
			long long v;
			scanf("%d%d%lld",&x,&y,&v);
			int l=x-y+1;
			if (y>k||l<1) continue;
			long long tmp=v-(long long)y*d;
			if (l>la+1){
				if (tmp>0) ans_1+=tmp;
			}
			else{
				if (tmp>ltmp){
					if (ltmp>0) ans_1-=ltmp;
					if (tmp>0) ans_1+=tmp;
				} 
			}
			la=x-y+1;
			ltmp=tmp;
		}
		printf("%lld\n",ans_1);
	}
}
int f[20];
long long ans;
struct node{
	int x,y;
	long long v;
}a[110];
void work(int sum){
	long long res=-d*(long long)sum;
	for (int i=1;i<=m;++i){
		if (f[a[i].x]>=a[i].y) res+=a[i].v;
	}
	ans=max(ans,res);
}
void dfs(int x,int sum){
	if (x==n+1){
		work(sum);
		return;
	}
	dfs(x+1,sum);
	if (f[x-1]<k){
		f[x]=f[x-1]+1;
		dfs(x+1,sum+1);
		f[x]=0;
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&C,&T);
	if (C<=4){
		while (T--){
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			ans=0;
			memset(f,0,sizeof(f));
			for (int i=1;i<=m;++i){
				scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].v);
			}
			dfs(1,0);
			printf("%lld\n",ans);
		}
	}
	else solve1();
	fclose(stdin);fclose(stdout);
	return 0;
}
