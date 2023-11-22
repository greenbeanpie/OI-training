#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,k,d,dui,dd[100005],f[100005],ans,l;
struct pp{
	int a,b,c,d;
}a[100005],b[100005];
bool cmp(pp x,pp y){
	if(x.a<y.a)return 1;
	return 0;
}
bool cmp1(int x,int y){
	if(x<y)return 1;
	return 0;
}
bool cmp2(pp x,pp y){
	if(x.a-x.b<y.a-y.b )return 1;
	return 0;
}
inline int read(){
	int p=0,flag=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')
	if(ch=='-')flag=-1;
	p=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
	p=p*10+ch-'0';
	return flag*p;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		n=read();
		m=read();
		k=read();
		d=read();
		l=-1;
		ans=0;
		for(int i=1;i<=m;i++){
			a[i].a=read();
			a[i].b=read();
			a[i].c=read()-a[i].b*d;
			a[i].c=max(a[i].c,(long long )0);
			a[i].d=i;
			b[i]=a[i];
		}
		f[0]=0;
		b[0].a=-1;
		b[0].b=0;
		b[0].c=0;
		b[0].d=0;
		a[0]=b[0];
		ans=0;
		l=-1;
		dui=0;
		sort(a+1,a+m+1,cmp2);
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;i++){
			while(b[l+1].a<a[i].a-a[i].b){
				l++;
				dui++;
				dd[dui]=f[b[l].d];
				pop_heap(dd+1,dd+dui+1,cmp1);
			}
			f[a[i].d]=dd[1]+a[i].c;
			ans=max(ans,f[a[i].d]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
