#include<bits/stdc++.h>
using namespace std;
const int maxn =1e5+5;
int id,t,n,m,k,d;
long long ans;
struct _dat{
	int x,y,v;
}a[maxn];
int c1[20];
long long dp[2][1005][1005];
long long f[1005][1005];
inline int read(){
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+c-'0';
		c=getchar();
	}
	return res*f;
}
long long calc(){
	long long res=0;
	for(int i=1;i<=m;++i){
		bool flag=1;
		for(int j=a[i].x-a[i].y+1;j<=a[i].x;++j){
			if(!c1[j]){
				flag=0;
				break;
			}
		}
		if(flag)res+=a[i].v;
		
	}
	for(int i=1;i<=n;++i){
		if(c1[i])res-=d;
	}
	return res;
}
void dfs1(int x,int lx){
	if(lx>k)return ;
	if(x==n+1){
		ans=max(ans,calc());
//		ans=max(ans,sum);
		return ;
	}
	for(int i=0;i<2;++i){
		c1[x]=i;
		dfs1(x+1,lx+(i==1));
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	id=read();t=read();
	while(t--){
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)f[i][j]=dp[0][i][j]=dp[1][i][j]=0;
		ans=0;
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=m;++i){
			a[i].x=read();a[i].y=read();a[i].v=read();
			a[i].y=a[i].x-a[i].y+1;
			if(id<=9){
				f[a[i].x][a[i].y]=a[i].v;
				
			}
		}
		if(id<=2){
			dfs1(1,0);
		}
		else if(id<=9){
			ans=0;
			
			for(int i=1;i<=n;++i)
				for(int j=1;j<=min(i,k);++j)f[i][j]+=f[i][j-1];
			
			for(int i=1;i<=n;++i){
				for(int j=0;j<=min(i,k);++j){
					if(j==0){
						for(int kk=0;kk<=i;++kk)dp[i&1][j][kk]=dp[(i-1)&1][j][kk];
						
					}
					else 
					for(int kk=0;kk<=i;++kk){
						dp[i&1][j][kk+1]=dp[(i-1)&1][j-1][kk]+f[i][j];
						ans=max(ans,dp[i&1][j][kk+1]-(kk+1)*d);
					}
					
				}
				
				
			}
			
			
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
//dp i,j dao i lian pao j de max
