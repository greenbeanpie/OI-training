#include<bits/stdc++.h>
using namespace std;

template<class T>inline void read(T&x){
	char last=' ',c;
	while(!isdigit(c=getchar()))last=c;
	x=c^48;
	while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+(c^48);
	if(last=='-')x=-x;
}

const int MAXN=1e5+7;
int n,m;
int c[MAXN];
int ans[MAXN<<1];
int f[MAXN<<1];

int sf(int x){
	return f[x]==x?x:f[x]=sf(f[x]);
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int Id,T;read(Id),read(T);
	while(T--){
		read(n),read(m);
		for(int i=1;i<=n;++i)c[i]=i+1;
		char op;
		for(int x,y;m--;){
			cin>>op;read(x);
			if(op=='T')c[x]=1;
			if(op=='F')c[x]=-1;
			if(op=='U')c[x]=0;
			if(op=='+'){
				read(y);
				c[x]=c[y];
			}
			if(op=='-'){
				read(y);
				c[x]=-c[y];
			}
		}
		for(int i=1;i<=n;++i)f[i]=i,f[n+i]=n+i,ans[i]=ans[n+i]=0x3f3f3f3f;
		for(int i=1;i<=n;++i){
			if(abs(c[i])<=1){
				ans[i]=c[i];
			}
			else{
				int v=abs(c[i])-1;
				if(c[i]>0){
					f[sf(v)]=sf(i);
					f[sf(n+v)]=sf(n+i);
				}
				else{
					f[sf(v)]=sf(n+i);
					f[sf(n+v)]=sf(i);
				}
			}
		}
		for(int i=1;i<=n;++i){
			if(ans[i]==0)ans[sf(i)]=ans[sf(n+i)]=0;
		}
		int anx=0;
		for(int i=1;i<=n;++i){
			if(sf(i)==sf(n+i))++anx;
			else anx+=ans[sf(i)]==0;
		}
		cout<<anx<<'\n';
	}
	return 0;
}
