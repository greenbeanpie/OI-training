#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
const ll N=200010;
ll C,Tst,n,m,f[N],v[N],p[N],op[N],deg[N],ans,a[N];
ll get(ll x){return x==f[x]?x:f[x]=get(f[x]);}
ll nOt(ll x){return x==2?2:1-x;}
ll head[N],nxt[N<<1],ver[N<<1],tot,edge[N<<1];
void add(ll x,ll y,ll z){
	ver[++tot]=y,edge[tot]=z,nxt[tot]=head[x],head[x]=tot;
}
ll oP(ll x){return x<=n?x+n:x-n;}
queue<ll> Q;
void work(){
	n=read(),m=read(),ans=tot=0;
	memset(head,0,sizeof(head));
	for(ll i=1;i<=n*2;i++)f[i]=i,v[i]=0;
	for(ll i=1;i<=n*2;i++)p[i]=i,op[i]=1,a[i]=3,deg[i]=0;
	for(ll I=1,x,y;I<=m;I++){
		char o[2];scanf("%s",o);
		if(o[0]=='+'){
			x=read(),y=read();
			if(a[p[y]]==3)p[x]=p[y],op[x]=op[y];
			else a[x]=a[y];
		}
		else if(o[0]=='-'){
			x=read(),y=read();
			if(a[p[y]]==3)p[x]=p[y],op[x]=op[y]^1;
			else a[x]=nOt(a[y]);
		}
		else{
			if(o[0]=='T')x=read(),a[x]=1;
			if(o[0]=='F')x=read(),a[x]=0;
			if(o[0]=='U')x=read(),a[x]=2;
		}
	}
	for(ll i=1;i<=n;i++)
		if(p[i]!=i&&a[i]==3)add(p[i],i,op[i]);
	while(Q.size())Q.pop();
	for(ll i=1;i<=n;i++)if(a[i]<3)Q.push(i);
	while(Q.size()){
		ll x=Q.front();Q.pop();
		if(a[x]==3)continue;
		for(ll i=head[x];i;i=nxt[i]){
			ll y=ver[i],z=edge[i];
			if(z)a[y]=a[x];else a[y]=nOt(a[x]);
			Q.push(y);
		}
	}
	for(ll i=1;i<=n;i++){
		if(a[i]<3)continue;
		ll x=i,y;
		if(op[i])y=p[x];else y=p[x]+n;
		ll X=get(x),Y=get(y);if(X!=Y)f[X]=Y;
		x=oP(x),y=oP(y),X=get(x),Y=get(y);
		if(X!=Y)f[X]=Y;
	}
	for(ll i=1;i<=n;i++){
		if(a[i]<3)continue;
		ll x=i,y=i+n;
		ll X=get(x),Y=get(y);
		if(X==Y)v[X]=v[Y]=1;
	}
	for(ll i=1;i<=n;i++){
		if(a[i]<3){ans+=a[i]==2;continue;}
		ll I=get(i);ans+=v[I];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	C=read(),Tst=read();
	while(Tst--)work();
	return 0;
}
	// for(ll i=1;i<=n;i++)printf("%lld ",p[i]);puts("");
	// for(ll i=1;i<=n;i++)printf("%lld ",op[i]);puts("");
		// assert(a[p[i]]==3);
		// if(a[p[i]]<3){printf("i=%lld p[i]=%lld\n",i,p[i]);continue;}
	// }puts("===============");
	// for(ll i=1;i<=n;i++)printf("%lld ",f[i]);puts("");
	// for(ll i=1;i<=n;i++)printf("%lld ",f[i+n]);puts("");
/*
1 1
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
*/