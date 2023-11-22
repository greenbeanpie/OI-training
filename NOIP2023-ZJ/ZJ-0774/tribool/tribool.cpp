#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,ans;
struct _dat{
	int v,x,y;
}a[maxn];
int c1[15];
int c[maxn];
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
bool check1(){
	int d[15];
	for(int i=1;i<=n;++i)d[i]=c1[i];
	for(int i=1;i<=m;++i){
		if(a[i].v==1)d[a[i].x]=d[a[i].y];
		if(a[i].v==2)d[a[i].x]=-d[a[i].y];
		if(a[i].v==3)d[a[i].x]=1;
		if(a[i].v==4)d[a[i].x]=-1;
		if(a[i].v==5)d[a[i].x]=0;
	}
	bool flag=1;
	for(int i=1;i<=n;++i){
		if(d[i]!=c1[i]){
			flag=0;
			break;
		}
	}
	return flag;
}
void dfs1(int x,int sum){
	if(ans==0)return ;
	if(x==n+1){
		if(check1())ans=min(ans,sum);
		return ;
	}
	for(int i=-1;i<2;++i){
		c1[x]=i;
		dfs1(x+1,sum+(i==0));
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int id,t;
	id=read();t=read();
	while(t--){
		n=read();m=read();ans=0;
		for(int i=1;i<=m;++i){
			char ch=getchar();
			while(ch!='+'&&ch!='-'&&ch!='F'&&ch!='T'&&ch!='U')ch=getchar();
			if(ch=='+'){
				a[i].v=1;
			}
			if(ch=='-')a[i].v=2;
			if(ch=='T')a[i].v=3;
			if(ch=='F')a[i].v=4;
			if(ch=='U')a[i].v=5;
			a[i].x=read();if(a[i].v<3)a[i].y=read();
		}
		if(id<=2){
			ans=n;
			dfs1(0,0);
			printf("%d\n",ans);
			continue;
		}
		if(id==3||id==4){
			ans=0;
			for(int i=1;i<=n;++i)c[i]=-1;
			for(int i=1;i<=m;++i){
				if(a[i].v==5)c[a[i].x]=0;
				if(a[i].v==3)c[a[i].x]=1;
				if(a[i].v==4)c[a[i].x]=-1;
			}
			for(int i=1;i<=n;++i)ans+=(c[i]==0);
			printf("%d\n",ans);
			continue;
		}
		if(id==5||id==6){
			ans=0;
			for(int i=1;i<=n;++i)c[i]=-1;
			for(int kkk=1;kkk<=m;++kkk)
			for(int i=1;i<=m;++i){
				if(a[i].v==5){
					c[a[i].x]=0;
				}
				if(a[i].v==1){
					c[a[i].x]=c[a[i].y];
				}
			}
			
			for(int i=1;i<=n;++i)ans+=(c[i]==0);
			printf("%d\n",ans);
			continue;
		}
	}
	return 0;
}
