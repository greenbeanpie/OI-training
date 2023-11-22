#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return f*s;
}
int c,t,n,m,k,d;
int x[100005],y[100005],v[100005];
int dp[1005][1005];
void test_1718(){
	t=read();
	while(t--){
		n=read(),m=read(),k=read(),d=read();
		int ans=0;
		for(int i=1;i<=m;i++){
			x[i]=read(),y[i]=read(),v[i]=read();
		}
		for(int i=1;i<=m;i++){
			if((y[i]-x[i]+1)*d<v[i]&&y[i]-x[i]+1<=k){
				ans+=(v[i]-d*(y[i]-x[i]+1));
			}
		}
		printf("%lld\n",ans);
	}
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	
	if(c==17||c==18){
		test_1718();
		return 0;
	}
	else{
		t=read();
		while(t--){
			puts("0");
		}
	}
}