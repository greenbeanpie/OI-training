#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=100010;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
struct node{
	int frm,to,tag,num;
}a[MAXN];
int c,t,n,m,ans=1e10;
int b[MAXN],d[MAXN];
bool flag;
inline void dfs(int tot){
	if(tot+1>n){
		for(int i=1;i<=n;i++)d[i]=b[i];
		for(int i=1;i<=m;i++){
			if(a[i].tag==1)d[a[i].num]=1;
			else if(a[i].tag==2)d[a[i].num]=2;
			else if(a[i].tag==3)d[a[i].num]=3;
			else if(a[i].tag==4)d[a[i].to]=d[a[i].frm];
			else if(a[i].tag==5){
				if(d[a[i].frm]==1)d[a[i].to]=2;
				else if(d[a[i].frm]==2)d[a[i].to]=1;
				else if(d[a[i].frm]==3)d[a[i].to]=3;
			}
		}
		flag=0;
		for(int i=1;i<=n;i++)if(b[i]!=d[i]){flag=1;break;}
		if(flag==0){
			int tot=0;
			for(int i=1;i<=n;i++)if(b[i]==3)tot++;
			ans=min(ans,tot);
		}
		return;
	}
	b[tot+1]=1;dfs(tot+1);
	b[tot+1]=2;dfs(tot+1);
	b[tot+1]=3;dfs(tot+1);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();t=read();
	char s;int x,y;
	while(t--){
		ans=1e10;
		n=read();m=read();
		if(c==1||c==2){
			for(int i=1;i<=n;i++)b[i]=d[i]=0;
			for(int i=1;i<=m;i++){
				cin>>s;
				if(s=='T')a[i].num=read(),a[i].tag=1;
				else if(s=='F')a[i].num=read(),a[i].tag=2;
				else if(s=='U')a[i].num=read(),a[i].tag=3;
				else if(s=='+')a[i].to=read(),a[i].frm=read(),a[i].tag=4;
				else if(s=='-')a[i].to=read(),a[i].frm=read(),a[i].tag=5;
			}
			dfs(0);
			printf("%lld\n",ans);
		}
		else if(c==3||c==4){
			ans=0;
			for(int i=1;i<=n;i++)b[i]=0;
			for(int i=1;i<=m;i++){
				cin>>s;x=read();
				if(s=='T')b[x]=1;
				else if(s=='F')b[x]=2;
				else if(s=='U')b[x]=3;
			}
			for(int i=1;i<=n;i++)if(b[i]==3)ans++;
			printf("%lld\n",ans);
		}
		else{
			ans=0;
			for(int i=1;i<=n;i++)b[i]=0;
			for(int i=1;i<=m;i++){
				cin>>s;
				if(s=='T')x=read(),b[x]=1;
				else if(s=='F')x=read(),b[x]=2;
				else if(s=='U')x=read(),b[x]=3;
				else if(s=='+'){
					x=read();y=read();
					b[x]=b[y];
				}
				else if(s=='-'){
					x=read();y=read();
					if(b[y]==0||b[y]==3)b[x]=b[y];
					else if(b[y]==1)b[x]=2;
					else if(b[y]==2)b[x]=1;
				}
			}
			for(int i=1;i<=n;i++)if(b[i]==3)ans++;
			printf("%lld\n",ans);
		}
	}
}