#include<bits/stdc++.h>
using namespace std;
struct node{long long x,y,v;}a[100010];
long long C,T,n,m,k,d,f[1010][1010],s[1010][1010],ans;
bool cmp(node x,node y){return (x.x!=y.x?x.x<y.x:x.y<y.y);}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>m>>k>>d,memset(f,128,sizeof(f)),memset(s,0,sizeof(s)),ans=0x8000000000000000;
		for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].v;
		if(C==17||C==18){
			ans=0;
			for(int i=1;i<=m;i++)if(a[i].y<=k&&a[i].v-a[i].y*d>0)ans+=a[i].v-a[i].y*d;
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++)if(a[i].x==a[i-1].x)a[i].v+=a[i-1].v;
		for(int i=1,j=1;i<=n;i++)while(a[j].x==i&&j<=m){
			for(int kk=a[j].y;kk<=(a[j].x==a[j+1].x&&j<=m?a[j+1].y-1:k);kk++)s[i][kk]=a[j].v;
			j++;
		}
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=k;j++)f[i][0]=max(f[i][0],f[i-1][j]);
			for(int j=1;j<=k;j++)f[i][j]=f[i-1][j-1]-d+s[i][j];
		}
		for(int i=0;i<=k;i++)ans=max(ans,f[n][i]);
		cout<<ans<<"\n";
	}
	return 0;
}