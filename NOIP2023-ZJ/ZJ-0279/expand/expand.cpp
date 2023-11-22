#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
const ll N=500010,inf=0x3f3f3f3f3f3f3f3f;
ll C,n,m,Q,a[N],b[N],A[N],B[N],ans[N];//,aa[N],bb[N],c[N];
ll work1(){
	if(a[1]<=b[1])return 0;
	ll p1=1,p2=1,mnb=inf;
	for(;p2<=m;){
		while(b[p2]<a[p1]&&p2<=m)mnb=min(mnb,b[p2]),p2++;
		if(p2>m)break;
		ll mna=inf;
		while(p1<=n&&a[p1]<=b[p2])mna=min(mna,a[p1]),p1++;
		if(p1>n)return 0;
		if(mna<=mnb)return 0;
		p2++;
	}
	if(b[m]>=a[n])return 0;
	mnb=inf;ll mna=inf,p=0;
	for(ll i=m;i>=0;i--)
		if(!i||b[i]>a[n]){p=i;break;}
	for(ll i=p+1;i<=m;i++)mnb=min(mnb,b[i]);
	for(ll i=p1+1;i<=n;i++)mna=min(mna,a[i]);
	if(mna>mnb)return 1;
	ll mxb=b[m],mxa=a[n];
	for(ll i=n,cur=m;i>p1;i--){
		while(b[cur]>=a[i]&&cur>0)mxb=max(mxb,b[cur]),cur--;
		if(mxb>=mxa)return 0;
		if(!cur)return 0;
		mxa=max(mxa,a[i]);
	}
	return 1;
}
ll work2(){
	if(b[1]<=a[1])return 0;
	ll p1=1,p2=1,mnb=inf;
	for(;p2<=m;){
		while(a[p2]<b[p1]&&p2<=n)mnb=min(mnb,a[p2]),p2++;
		if(p2>n)break;
		ll mna=inf;
		while(p1<=m&&b[p1]<=a[p2])mna=min(mna,b[p1]),p1++;
		if(p1>m)return 0;
		if(mna<=mnb)return 0;
		p2++;
	}
	if(a[n]>=b[m])return 0;
	mnb=inf;ll mna=inf,p=0;
	for(ll i=n;i>=0;i--)
		if(!i||a[i]>b[m]){p=i;break;}
	for(ll i=p+1;i<=n;i++)mnb=min(mnb,a[i]);
	for(ll i=p1+1;i<=m;i++)mna=min(mna,b[i]);
	if(mna>mnb)return 1;
	ll mxb=a[n],mxa=b[m];
	for(ll i=m,cur=n;i>p1;i--){
		while(a[cur]>=b[i]&&cur>0)mxb=max(mxb,a[cur]),cur--;
		if(mxb>=mxa)return 0;
		if(!cur)return 0;
		mxa=max(mxa,b[i]);
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	C=read(),n=read(),m=read(),Q=read();
	for(ll i=1;i<=n;i++)A[i]=read();
	for(ll i=1;i<=m;i++)B[i]=read();
	for(ll i=1;i<=n;i++)a[i]=A[i];
	for(ll i=1;i<=m;i++)b[i]=B[i];
	ans[0]=max(work1(),work2());
	for(ll I=1;I<=Q;I++){
		for(ll i=1;i<=n;i++)a[i]=A[i];
		for(ll i=1;i<=m;i++)b[i]=B[i];
		ll kx=read(),ky=read();
		for(ll i=1,x,y;i<=kx;i++)x=read(),y=read(),a[x]=y;
		for(ll i=1,x,y;i<=ky;i++)x=read(),y=read(),b[x]=y;
		ans[I]=max(work1(),work2());
		reverse(a+1,a+n+1),reverse(b+1,b+m+1);
		ans[I]=max(ans[I],max(work1(),work2()));
	}
	for(ll i=0;i<=Q;i++)printf("%lld",ans[i]);
	puts("");
	return 0;
}
	// for(ll i=p1+1;i<=n;i++)if(a[i]<=b[m])return 0;
	// return 1;
	// for(ll i=p1+1;i<=m;i++)if(b[i]<=a[n])return 0;
	// return 1;
//		ll num=0;
		// for(ll i=1;i<=n;i++)c[++num]=a[i];
		// for(ll i=1;i<=m;i++)c[++num]=b[i];
		// sort(c+1,c+n+m+1);
		// for(ll i=1;i<=n;i++)aa[i]=lower_bound(c+1,c+n+m+1,a[i])-c;
		// for(ll i=1;i<=m;i++)bb[i]=lower_bound(c+1,c+n+m+1,b[i])-c;
		// for(ll i=1;i<=n;i++)printf("%lld ",aa[i]);puts("");
		// for(ll i=1;i<=n;i++)printf("%lld ",bb[i]);puts("");
/*
4 6 6 1
195982977 303897138 437154869 81559605 365511323 302808478
342942401 297976421 445071632 83871721 304067809 427239638
6 6
3 20666649
1 599175376
6 287382408
5 421035992
2 805423796
4 767604039
3 284182396
1 732011630
4 934948587
2 840870596
6 557335931
5 388591777
*/