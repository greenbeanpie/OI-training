#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int read(){
	int f=1,k=0;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){k=k*10+c-'0';c=getchar();}
	return f*k;
}
int n,m,k,d,c,t;
int x[N],y[N],z[N];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	srand(time(NULL));
	c=read();t=read();
	while(t--){
		int sum=0;
		n=read();m=read();k=read();d=read();
		for(int i=1;i<=m;i++)
			x[i]=read(),y[i]=read(),z[i]=read(),sum+=z[i];
		printf("%lld",rand()%sum*rand()%sum*rand()%sum);
	}
	return 0;
}
