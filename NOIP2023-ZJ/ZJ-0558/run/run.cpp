#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define MAXM 1000005
#define int long long
int n,m,k,d,g,ans=0xcfcfcfcfcfcfcfcf;
int testid,T,sum[MAXN];
struct Node{
	int x,y,v;
}node[MAXM];
inline bool cmp(Node x,Node y){return x.x<y.x;}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&testid,&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=0;i<m;i++) scanf("%lld%lld%lld",&node[i].x,&node[i].y,&node[i].v);
		sort(node,node+m,cmp);
		ans=0xcfcfcfcfcfcfcfcf;
		g=0;
		memset(sum,0xcf,sizeof(sum));
		sum[0]=0;
		for(int i=1;i<=n;i++){//days
			int mx=0xcfcfcfcfcfcfcfcf;
			for(int i=0;i<=k;i++) mx=max(mx,sum[i]);
			for(int j=k;j>0;j--) sum[j]=sum[j-1]-d;
			sum[0]=mx;
			while(node[g].x==i&&g<m){
				for(int j=node[g].y;j<=k;j++){
					sum[j]=max(sum[j],sum[j]+node[g].v);
				}
				g++;
			}
		}
		for(int i=0;i<=k;i++) ans=max(ans,sum[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
//11:10 Ϊʲô�����Զ�ȴ�Ҫ�� ����1Сʱ�˼����� 
//11:31 ˭���뵽28-29��λ�û������ܽ�����Ⱑ 
