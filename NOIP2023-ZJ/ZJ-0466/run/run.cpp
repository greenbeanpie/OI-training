#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int p=0,o=1;char po=getchar();
	while(!(po>='0'&&po<='9')){if(po=='-')o=-1;po=getchar();}
	while(po>='0'&&po<='9'){p=p*10+po-'0';po=getchar();}
	return p*o;
}
struct data{
	int q,w,e;
}g[100005];
int pl,lp,a,s,d,f;
bool h[100005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	pl=read();lp=read();
	if(pl>14)return 0;
	while(lp--){
		a=read(),s=read(),d=read(),f=read();
		int ans=0;memset(h,0,sizeof(h));
		for(int i=1;i<=s;i++){
			g[i].q=read(),g[i].w=read(),g[i].e=read();
			for(int j=g[i].q-g[i].w+1;j<=g[i].q;j++)
			h[j]=true;
			ans+=g[i].e;
		}
		for(int i=1;i<=a;i++)if(h[i])ans-=f;
		printf("%d",ans);
	}
	return 0;
}