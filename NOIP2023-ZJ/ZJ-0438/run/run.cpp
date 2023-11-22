#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e4+9;
int c,T;
int n,m,k,d;
struct node{
	int x,y;
	ll v;
}a[N];
bool cmp(node a,node b){
	return a.x<b.x;
}
ll f[N][N];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		memset(f,0,sizeof(f));
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for (int i=1;i<=m;i++){
			scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].v);
		}
		sort(a+1,a+1+m,cmp);
		//for (int i=1;i<=m;i++) cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].v<<endl;
		int tot=1;
		ll maxn=0;
		for (int i=1;i<=n;i++){
			ll max1=0;
			for (int j=0;j<=min(k,i);j++){
				if (j!=0) f[i][j]=f[i-1][j-1]-d;else f[i][j]=maxn;
				max1=max(f[i][j],max1);
			}
			while(tot<=m&&a[tot].x<i) tot++;
			while(tot<=m&&a[tot].x==i){
				for (int j=a[tot].y;j<=min(i,k);j++)
					f[i][j]+=a[tot].v,max1=max(f[i][j],max1);
				tot++;
			}
			/*for (int j=0;j<=min(k,i);j++)
				cout<<i<<' '<<j<<' '<<f[i][j]<<endl;*/
			maxn=max1;
		}
		printf("%lld\n",maxn);
	}
	
	return 0;
}
