#include<bits/stdc++.h>
#define o1 x[1]!=y[1]&&x[1]!=y[2]&&!((x[1]<y[1])^(x[1]<y[2]))
#define o2 x[1]!=y[1]&&x[2]!=y[1]&&!((x[1]<y[1])^(x[2]<y[1]))
#define two x[1]!=y[1]&&x[2]!=y[2]&&!((x[1]<y[1])^(x[2]<y[2]))
using namespace std;
const int N=500010;
int c,n,m,q,x[N],y[N];
pair<int,int> A[N],B[N];
bool st1[N],st2[N];
struct node{
	int a,b;
	bool operator<(const node&A)const{
		int t=min(a,b),T=min(A.a,A.b);
		return t^T?t<T:max(a,b)<max(A.a,A.b);
	}
}seg[40010];
void calc(){
//	puts("start");
//	return;
	memset(st1,0,n+1);
	memset(st2,0,m+1);
//	for(int i=1;i<=n;++i)cout<<x[i]<<' ';
//	cout<<'\n';
//	for(int i=1;i<=n;++i)cout<<y[i]<<' ';
//	cout<<'\n';
	if(x[1]==y[1]||x[n]==y[m]||(x[1]<y[1])^(x[n]<y[m])){
		
		putchar('0');
	}
	else{
		int cur=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(x[i]!=y[j]&&!((x[1]<y[1])^(x[i]<y[j])))
					seg[++cur]={i,j};
		sort(seg+1,seg+1+cur);
//		for(int i=1;i<=cur;++i)cout<<seg[i].a<<' '<<seg[i].b<<'\n';
		node lst={-1,-1};
		for(int i=1;i<=cur;++i){
			if(seg[i].a>=lst.a&&seg[i].b>=lst.b){
//				cout<<"choose "<<seg[i].a<<' '<<seg[i].b<<'\n';
				lst=seg[i];
				st1[lst.a]=st2[lst.b]=1;
			}
		}
		for(int i=2;i<n;++i)
			if(!st1[i]||!st2[i]){
				putchar('0');
				return;
			}
		putchar('1');
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%d",x+i);
	for(int i=1;i<=m;++i)scanf("%d",y+i);
	if(c==1)putchar(x[1]!=y[1]?'1':'0');
	else if(c==2){
		if(n==1)putchar(o1?'1':'0');
		else if(m==1)putchar(o2?'1':'0');
		else putchar(two?'1':'0');
	}
	else if(c<=5)calc();
	for(int i=1;i<=q;++i){
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;++j){
			int a,b;
			scanf("%d%d",&a,&b);
			A[j]={a,x[a]};
			x[a]=b;
		}
		for(int j=1;j<=ky;++j){
			int a,b;
			scanf("%d%d",&a,&b);
			B[j]={a,y[a]};
			y[a]=b;
		}
		if(c==1)putchar(x[1]!=y[1]?'1':'0');
		else if(c==2){
			if(n==1)putchar(o1?'1':'0');
			else if(m==1)putchar(o2?'1':'0');
			else putchar(two?'1':'0');
		}
		else if(c<=5)calc();
		for(int j=1;j<=kx;++j)x[A[j].first]=A[j].second;
		for(int j=1;j<=ky;++j)y[B[j].first]=B[j].second;
	}
//	cout<<"Hit";
	if(c>5)for(int i=1;i<=q+1;++i)putchar('0');
	return 0;
}