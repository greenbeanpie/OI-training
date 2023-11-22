#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll ans,f[1010][1010],ma,k,d,pl,pr,i,t,n,m,C,T;
struct node{
	ll x,y,z;
}a[100010];
ll read(){
	ll p=0,o=1;
	char ch=getchar();
	while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(ch>='0' && ch<='9') p=(p<<1)+(p<<3)+ch-48,ch=getchar();
	return o*p;
}
bool cmp(node a,node b){return a.x<b.x || a.x==b.x && a.y<b.y;}
int ef(int x){
	int l=1,r=m,mid,bao=m+1;
	while(l<=r){
		mid=l+r>>1;
		if(a[mid].x>=x) r=mid-1,bao=mid;
		else l=mid+1;
	}
	return bao;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	C=read(); T=read();
	while(T--){
		n=read(); m=read(); k=read(); d=read();
		for(i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
		sort(a+1,a+1+m,cmp);
		for(i=1;i<=m;i++) a[i].z+=a[i-1].z;
		//f[wei][day]
		for(i=1;i<=n;i++){
			pl=ef(i); pr=pl; ma=0;
			for(t=0;t<=min(i-1,k);t++) ma=max(ma,f[i-1][t]);
			f[i][0]=ma;
			for(t=1;t<=min(i,k);t++){
				f[i][t]=f[i-1][t-1]-d;
				while(a[pr].x==i && a[pr].y<=t) pr++;
				f[i][t]+=a[pr-1].z-a[pl-1].z;
			}
		}
		ans=0;
		for(i=0;i<=min(n,k);i++) ans=max(ans,f[n][i]);
		cout<<ans<<"\n";
	}
	return 0;
}