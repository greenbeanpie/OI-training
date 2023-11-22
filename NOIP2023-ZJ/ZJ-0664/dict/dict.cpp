#include<bits/stdc++.h>
#define rr register
#define N 3005
using namespace std;
int read(){
	rr int num=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9') num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return f*num;
}
int n,m;
struct dd{
	char s[N];
	int sum[30],id,l,r;
}a[N];
bool cmp(dd x,dd y){
	for(rr int i=26;i;--i)
		if(x.sum[i]==y.sum[i]) continue;
		else return x.sum[i]>y.sum[i];
	return 1;
}
bool v[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(rr int i=1;i<=n;++i){
		a[i].id=i;
		a[i].l=26;;
		for(rr int j=1;j<=m;++j){
			a[i].s[j]=getchar();
			while(a[i].s[j]<'a'||a[i].s[j]>'z') a[i].s[j]=getchar();
			a[i].sum[a[i].s[j]-'a'+1]++;
			a[i].l=min(a[i].l,a[i].s[j]-'a'+1);
			a[i].r=max(a[i].r,a[i].s[j]-'a'+1);
		}
	}
	sort(a+1,a+1+n,cmp);
//	for(rr int i=1;i<=n;++i){
//		cout<<a[i].id<<' ';
//		for(rr int j=1;j<=26;++j) cout<<a[i].sum[j]<<' ';
//		cout<<endl;
//	}
	for(rr int i=1;i<n;++i){
		rr int L=a[i].l,R=a[n].r;
		if(L==R){
			if(a[i].sum[L]>a[i].sum[R]) v[a[i].id]=1;
		}else
		if(L<R) v[a[i].id]=1;
	}
	v[a[n].id]=1;
	for(rr int i=1;i<=n;++i) printf("%d",v[i]);
	return 0;
}
