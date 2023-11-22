#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int f=1;
	int x=0;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar();};
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,m,q;
int a[500010],b[500010];
int c[500010],d[500010];
int f[2010][2010];
int check(){
	if(a[1]==b[1]||a[n]==b[m]) return 0;
	if((a[1]>b[1])!=(a[n]>b[m])) return 0;
	f[1][1]=1;
	for(int i=1;i<=n;++i){
		int re=(i==1?1:0);
		for(int j=(i==1?2:1);j<=m;++j){
			if((a[i]>b[j])==(a[1]>b[1])&&a[i]!=b[j]) f[i][j]=(f[i-1][j]|f[i][j-1]);else f[i][j]=0;
			re+=f[i][j];
		}
		if(re==0) return 0;
	}
	return f[n][m];
}

int check2(){
	if(a[1]==b[1]||a[n]==b[m]) return 0;
	if((a[1]>b[1])!=(a[n]>b[m])) return 0;
	int it=1;
	if(a[1]<b[1]){
		int pmx=b[1];
		for(int i=1;i<=n;++i){
			while(it<m&&(b[it+1]>a[i])==(b[1]>a[1])&&b[it+1]!=a[i]) pmx=max(pmx,b[++it]);
			if(a[i]>pmx) return 0;
		}
	}
	else{
		int pmn=b[1];
		for(int i=1;i<=n;++i){
			while(it<m&&(b[it+1]>a[i])==(b[1]>a[1])&&b[it+1]!=a[i]) pmn=min(pmn,b[++it]);
			if(a[i]<pmn) return 0;
		}
	}
	if(it!=m) return 0;
	reverse(a+1,a+n+1);reverse(b+1,b+m+1);
	it=1;
	if(a[1]<b[1]){
		int pmx=b[1];
		for(int i=1;i<=n;++i){
			while(it<m&&(b[it+1]>a[i])==(b[1]>a[1])&&b[it+1]!=a[i]) pmx=max(pmx,b[++it]);
			if(a[i]>pmx){
				reverse(a+1,a+n+1);reverse(b+1,b+m+1);
				return 0;
			}
		}
	}
	else{
		int pmn=b[1];
		for(int i=1;i<=n;++i){
			while(it<m&&(b[it+1]>a[i])==(b[1]>a[1])&&b[it+1]!=a[i]) pmn=min(pmn,b[++it]);
			if(a[i]<pmn){
				reverse(a+1,a+n+1);reverse(b+1,b+m+1);
				return 0;
			}
		}
	}
	reverse(a+1,a+n+1);reverse(b+1,b+m+1);
	return it==m;
}
int C;
int main(){
	// double st=clock();
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	// scanf("%d%d%d%d",&C,&n,&m,&q);
	C=read(),n=read(),m=read(),q=read();
	// cerr<<C<<"\n";
	// q=2;
	for(int i=1;i<=n;++i) a[i]=read();for(int i=1;i<=m;++i) b[i]=read();
	// for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	// for(int i=1;i<=m;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i) c[i]=a[i];
	for(int i=1;i<=m;++i) d[i]=b[i];
	printf("%d",(C>=8)?check2():check());
		// if(C<8) assert(check2()==check());
	for(int i=1;i<=q;++i){
		int kx=read(),ky=read();
		// scanf("%d%d",&kx,&ky);
		// cerr<<kx<<" "<<ky<<"\n";
		for(int j=1;j<=kx;++j){
			int p=read(),v=read();
			// scanf("%d%d",&p,&v);
			a[p]=v;
		}
		for(int j=1;j<=ky;++j){
			int p=read(),v=read();
			// scanf("%d%d",&p,&v);
			b[p]=v;
		}
		printf("%d",(C>=8)?check2():check());
		// if(C<8) assert(check2()==check());
		// printf("%d %d\n",check(),check2());
		// assert(check()==check2());
		for(int i=1;i<=n;++i) a[i]=c[i];
		for(int i=1;i<=m;++i) b[i]=d[i];
	}
		// cerr<<(clock()-st)/CLOCKS_PER_SEC<<"\n";
	// printf("\n%.5lf\n",(clock()-X)*1.0/CLOCKS_PER_SEC);
	return 0;
}