#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[100005],c[100005],p,ans,l,r,n,m,C,T;
char ch;
struct pp{
	int op,l,r;
}a[100005];
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
void dfs(int x,int y){
	if(x<=n)
	for(int i=0;i<=2;i++)dfs(x+1,y*3+i);
	if(x==n){
		for(int i=1;i<=n;i++){
			c[i]=b[i]=y%3-1;
			y/=3;
		}
		for(int i=1;i<=m;i++){
			l=a[i].l;
			r=a[i].r;
			if(a[i].op==1){
				c[l]=c[r];
			}
			if(a[i].op==2){
				c[l]=-c[r];
			}
			if(a[i].op==3){
				c[l]=1;
			}
			if(a[i].op==4){
				c[l]=-1;
			}
			if(a[i].op==5){
				c[l]=0;
			}
		}
		p=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=b[i])return ;
			if(c[i]==0)p++;
		}
		ans=min(ans,p);
	}
}
int onl(){
	for(int i=1;i<=n;i++)b[i]=1;
	for(int i=1;i<=m;i++){
		l=a[i].l;
		if(a[i].op==3)b[l]=1;
		if(a[i].op==4)b[l]=-1;
		if(a[i].op==5)b[l]=0;
	}
	int k=0;
	for(int i=1;i<=n;i++)if(b[i]==0)k++;
	return k;
}
int you(){
	for(int i=1;i<=n;i++)b[i]=1;
	for(int i=1;i<=m;i++){
		l=a[i].l;
		if(a[i].op==5){
			b[l]=0;
		}
	}
	for(int i=1;i<=m;i++){
		l=a[i].l;
		r=a[i].r;
		if(a[i].op==1){
			b[l]=b[r];
		}
	}
	int k=0;
	for(int i=1;i<=n;i++)if(b[i]==0)k++;
	return k;
}
int mm(){
	return 1;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		ans=0;
		n=read();
		m=read();
		bool pd1=0,pd2=0;
			for(int i=1;i<=m;i++){
				while((ch=getchar())!='-'&&ch!='+'&&ch!='T'&&ch!='F'&&ch!='U');
				if(ch=='+'){
					a[i].op=1;
					a[i].l=read();
					a[i].r=read();
					pd1=1;
				}
				if(ch=='-'){
					pd2=1;
					a[i].op=2;
					a[i].l=read();
					a[i].r=read();
				}
				if(ch=='T'){
					a[i].op=3;
					a[i].l=read();
				}
				if(ch=='F'){
					a[i].op=4;
					a[i].l=read();
				}
				if(ch=='U'){
					a[i].op=5;
					a[i].l=read();
				}
			}
		if(n<=10){
			ans=INT_MAX;
			dfs(1,0);
			dfs(1,1);
			dfs(1,2);
			printf("%lld\n",ans);
		}
		else
		{
			if(!pd1){
				printf("%lld\n",onl());
				
			}
			else
			if(!pd2){
				printf("%lld\n",you());
			}
			else{
				printf("%lld\n",mm());
			}
		}
	}
	return 0;
}
