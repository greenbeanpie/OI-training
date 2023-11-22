#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=2e6;
int dp1[3][N];
struct node{
	int y,v;
}ch[N];
vector<int>q[N];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int id=read(),T=read();
//	if(id<=7){
		while(T--){
			memset(dp1,-0x3f,sizeof(dp1));
			int n=read(),m=read(),k=read(),d=read();
			for(int i=1;i<=n;i++) q[i].clear();
			for(int i=1;i<=m;i++){
				int x=read();ch[i].y=read(),ch[i].v=read();
				q[x].push_back(i);
			}
			int ans=0;
			dp1[0][0]=0;
			for(int i=1;i<=n;i++){
				for(int t=0;t<=k;t++) dp1[i%2][t]=-1e17;
				for(int t=0;t<=k;t++){
					dp1[i%2][0]=max(dp1[i%2][0],dp1[(i-1)%2][t]);
					if(t>0) dp1[i%2][t]=max(dp1[i%2][t],dp1[(i-1)%2][t-1]-d);
					for(int tz:q[i]){
						if(t>=ch[tz].y) dp1[i%2][t]+=ch[tz].v;
					}
					ans=max(ans,dp1[i%2][t]);
				}
				for(int tz:q[i]){
					if(0>=ch[tz].y) dp1[i%2][0]+=ch[tz].v;
				}
				ans=max(ans,dp1[i%2][0]);
			}
			printf("%lld\n",ans);
		}	
//	}
	return 0;
}