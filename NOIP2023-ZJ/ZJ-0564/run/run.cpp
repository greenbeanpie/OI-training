#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int c,t;
int n,m,k,d;
struct node{
	ll l,r,w;
	bool flag=1;
} a[N];
int tot;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(!(c^'-')) f^=1;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^'0');c=getchar();}
	return (f?s:~(s-1));
}
bool cmp(node x,node y){
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
void solve(){
	memset(a,0,sizeof a);
	tot=0;
	n=read(),m=read(),k=read(),d=read();
	for(int i=1;i<=m;i++){
		int x,y,v;
		x=read(),y=read(),v=read();
		if(y-x+1>k) continue;
		a[++tot]={x,y,v-(y-x+1)*d};
	}
	sort(a+1,a+tot+1,cmp);
	int r=0;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].l>r) r=a[i].r,cnt+=a[i].w;
	}
	printf("%d\n",cnt);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	while(t--) solve();
	return 0;
}
