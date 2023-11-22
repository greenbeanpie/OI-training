#include<bits/stdc++.h>
#define int long long
#define R read()

using namespace std;

int n,m,k,d,i,ans,C,T,X[100010],Y[100010],v[100010],c[100010];
int read(){
	int x=0,fl=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')fl=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*fl;
}
void pd(){
	int i,s=0;
	for(i=1;i<=n;i++)
		if(c[i])s=s-d;
	for(i=1;i<=n;i++)c[i]+=c[i-1];
	for(i=1;i<=m;i++)
		if(c[X[i]]-c[X[i]-Y[i]]==Y[i])s=s+v[i];
	ans=max(ans,s);
}
void sc(int t,int sk){
	if(t==n+1){
		pd();
		return;
	}
	if(sk+1<=k)c[t]=1,sc(t+1,sk+1);
	c[t]=0;
	sc(t+1,0);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	C=R;T=R;
	while(T--){
		n=R;m=R;k=R;d=R;
		for(i=1;i<=m;i++)X[i]=R,Y[i]=R,v[i]=R;
		if(C<=2){
			ans=-1e18;
			sc(1,0);
			cout<<ans<<"\n";
		}
		else if(C==17||C==18){
			ans=0;
			for(i=1;i<=m;i++)
				if(Y[i]<=k){
					int x=v[i]-Y[i]*d;
					if(x>0)ans+=x;
				}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
