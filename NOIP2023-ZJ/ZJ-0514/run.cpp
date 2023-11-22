#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define Min(x,y) x<y?x:y;
#define Max(x,y) x>y?x:y;
using namespace std;
const int N=1e5+5,M=1005,INF=1e9+5;//need to be bigger
int c,t,cnt;
int n,m,k;
ll d,f1[M][M],f0[M],ans,s[N],cmax[N];
struct node{
	int l,r;
	ll v;
}chal[N];
bool cmp(node x,node y){
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
void init(){
	cnt=0;ans=0;
	memset(f0,128,sizeof(f0));
	memset(f1,128,sizeof(f1));
	memset(cmax,128,sizeof(cmax));
	s[0]=0;
	f0[0]=f1[0][0]=0;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	int x,y;ll v;
	ll mi;
	while(t--){
		init();
		
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;++i){
			scanf("%d%d%lld",&x,&y,&v);
			if(y>x||y>k) continue;
			chal[++cnt]=(node){x-y+1,x,v};
		}
		
		sort(chal+1,chal+cnt+1,cmp);
		
		/*printf("\n\n");
		for(int i=1;i<=cnt;++i)
			printf("%d %d %d\n",chal[i].l,chal[i].r,chal[i].v);*/
		
		for(int i=1;i<=cnt;++i)
			s[i]=s[i-1]+chal[i].v;
		
		for(int i=1;i<=cnt;++i){
			f0[i]=f0[i-1];
			if(i>=2) f0[i]=Max(f0[i],cmax[i-1]);
			int mini=INF;
			for(int j=i;j>=1;--j){//done j~i works in a row.
				mini=Min(mini,chal[j].l);
				mi=(ll)(chal[i].r-mini+1ll);
				if(mi>k) break;
				mi*=d;
				f1[i][j]=Max(f1[i][j],f0[j-1]+s[i]-s[j-1]-mi);
				cmax[i]=Max(cmax[i],f1[i][j]);
			}
		}
		
		/*for(int i=1;i<=cnt;++i)
			printf("%d ",f0[i]);
		printf("\n\n");
		for(int i=1;i<=cnt;++i){
			for(int j=1;j<=cnt;++j){
				printf("%d ",f1[i][j]);
			}
			printf("\n");
		}*/
		
		ans=f0[cnt];
		ans=Max(ans,cmax[cnt]);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1 1
5 6 5 2
5 4 3
9 5 3
7 5 2
9 1 100
8 1 6
7 5 5
*/