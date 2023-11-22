#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=5e5+50;
int c,n,m,q;
int x[MAXN],y[MAXN],a[MAXN],b[MAXN];
void copy(){
	for(int i=1;i<=n;++i)
		a[i]=x[i];
	for(int i=1;i<=m;++i)
		b[i]=y[i];
}
void excopy(){
	for(int i=1;i<=n;++i)
		b[i]=x[i];
	for(int i=1;i<=m;++i)
		a[i]=y[i];
}
int taila[MAXN],tailb[MAXN];
bool check(){
	int i=1,j=1;
	if(a[1]>=b[1]) return false;
	if(a[n]>=b[m]) return false;
	int cnta=0,cntb=0;
	memset(taila,0,sizeof(taila));
	memset(tailb,0,sizeof(tailb));
	for(i=1;i<n;++i)
		if(a[i]>a[i+1]) taila[++cnta]=i;
	taila[++cnta]=n;
	for(j=1;j<m;++j)
		if(b[j]>b[j+1]) tailb[++cntb]=j;
	tailb[++cntb]=m;
	
	j=1;
	int last;
	for(i=1;i<=cnta;++i){
		for(last=j;j<=cntb;++j) if(b[tailb[j]]>a[taila[i]]) break;
		if(j==cntb+1) break;
		for(int k=tailb[last];k<=tailb[j];++k){
			if(a[taila[i-1]+1]>=b[k]) return false;
		}
	}
	if(i==cnta+1){
		for(int k=tailb[j];k<=m;++k){
			if(a[n]>=b[k]) return false;
		}
	}else if(j==cntb+1){
		for(int k=taila[i];k<=n;++k){
			if(a[k]>=b[m]) return false;
		}
	}
	return true;
}
bool excheck(){
	int i=1,j=1;
	if(b[1]>=a[1]) return false;
	if(b[m]>=a[n]) return false;
	int cnta=0,cntb=0;
	memset(taila,0,sizeof(taila));
	memset(tailb,0,sizeof(tailb));
	for(i=1;i<m;++i)
		if(b[i]>b[i+1]) tailb[++cntb]=i;
	tailb[++cntb]=m;
	for(j=1;j<n;++j)
		if(a[j]>a[j+1]) taila[++cnta]=j;
	taila[++cnta]=n;
	
	j=1;
	int last=0;
	for(i=1;i<=cntb;++i){
		for(last=j;j<=cnta;++j) if(a[taila[j]]>b[tailb[i]]) break;
		if(j==cnta+1) break;
		for(int k=taila[last];k<=taila[j];++k){
			if(b[tailb[i-1]+1]>=a[k]) return false;
		}
	}
//	cout<<"ok:"<<a[m]<<" "<<b[n]<<endl;
	if(i==cntb+1){
		for(int k=taila[j];k<=n;++k){
			if(b[m]>=a[k]) return false;
		}
	}else if(j==cnta+1){
		for(int k=tailb[i];k<=m;++k){
			if(b[k]>=a[n]) return false;
		}
	}
	return true;
}
bool solve(){
	return check()|excheck();
//	return excheck();
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
//	srand(time(0));
	scanf("%d %d %d %d",&c,&n,&m,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",x+i),a[i]=x[i];
	for(int i=1;i<=m;++i)
		scanf("%d",y+i),b[i]=y[i];
	printf("%d",solve());
	int kx,ky,p,v;
	for(int i=1;i<=q;++i){
		copy();
		scanf("%d %d",&kx,&ky);
		for(int j=1;j<=kx;++j){
			scanf("%d %d",&p,&v);
			a[p]=v;
		}
		for(int j=1;j<=ky;++j){
			scanf("%d %d",&p,&v);
			b[p]=v;
		}
		printf("%d",solve());
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}