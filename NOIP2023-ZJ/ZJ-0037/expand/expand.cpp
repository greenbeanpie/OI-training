#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int inf_int=numeric_limits<int>::max()/2;
constexpr int max_n=1000000;
int a[max_n+1],b[max_n+1],tmp[max_n+1];
bool solvey(const int mna,const int mxb){
	int i=2,nowa=a[1],j=2,nowb=b[1];
	if(nowa==mna||nowb==mxb)
		return 1;
	while(1){
		if(a[i]>=nowb&&b[j]<=nowa){
			if(a[i]<b[j]){
				if(a[i]<nowa){
					nowa=a[i];
					if(nowa==mna)
						return 1;
				}
				if(b[j]>nowb){
					nowb=b[j];
					if(nowb==mxb)
						return 1;
				}
				++i,++j;
				continue;
			}
			return 0;
		}
		for(; a[i]<nowb; ++i){
			if(a[i]<nowa){
				nowa=a[i];
				if(nowa==mna)
					return 1;
			}
		}
		for(; b[j]>nowa; ++j){
			if(b[j]>nowb){
				nowb=b[j];
				if(nowb==mxb)
					return 1;
			}
		}
	}
}
void solvex(const int n,const int m){
	int mna=a[1],mxa=a[1],mnb=b[1],mxb=b[1];
	for(int i=2; i<=n; ++i)
		if(a[i]>mxa)
			mxa=a[i];
		else
			if(a[i]<mna)
				mna=a[i];
	for(int i=2; i<=m; ++i)
		if(b[i]>mxb)
			mxb=b[i];
		else
			if(b[i]<mnb)
				mnb=b[i];
	if(mxa>=mxb||mna>=mnb){
		putchar('0');
		return;
	}
	if(solvey(mna,mxb)){
		reverse(a+1,a+n+1);
		reverse(b+1,b+m+1);
		if(solvey(mna,mxb)){
			putchar('1');
			return;
		}
	}
	putchar('0');
}
void solve(const int n,const int m){
	// for(int i=1; i<=n; ++i)
	// 	fprintf(stderr,"a %d: %d\n",i,a[i]);
	// for(int i=1; i<=m; ++i)
	// 	fprintf(stderr,"b %d: %d\n",i,b[i]);
	if(ll(a[1]-b[1])*(a[n]-b[m])<=0){
		putchar('0');
		return;
	}
	if(a[1]>b[1]){
		memcpy(tmp,a+1,n<<2);
		memcpy(a+1,b+1,m<<2);
		memcpy(b+1,tmp,n<<2);
		solvex(m,n);
	}
	else
		solvex(n,m);
}
int c[max_n+1],d[max_n+1];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int n,m,q;
	scanf("%*d%d%d%d",&n,&m,&q);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	for(int i=1; i<=m; ++i)
		scanf("%d",b+i);
	memcpy(c+1,a+1,n<<2);
	memcpy(d+1,b+1,m<<2);
	solve(n,m);
	for(int i=1,k,kx,p,v; i<=q; ++i){
		memcpy(a+1,c+1,n<<2);
		memcpy(b+1,d+1,m<<2);
		for(scanf("%d%d",&k,&kx); k; --k,a[p]=v)
			scanf("%d%d",&p,&v);
		for(k=kx; k; --k,b[p]=v)
			scanf("%d%d",&p,&v);
		solve(n,m);
	}
	putchar('\n');
	return 0;
}