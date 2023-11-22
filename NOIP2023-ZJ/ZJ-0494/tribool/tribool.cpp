#include<bits/stdc++.h>
using namespace std;
#define re register
#define inl inline
#define rep(i,l,r) for(re int i=l;i<=r;i++)
#define N 100005
mt19937_64 rnd(time(0));
template <typename T> inl T read(){
	T ret=0;bool p=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') p=0;c=getchar();}
	while(isdigit(c)){ret=(ret<<3)+(ret<<1)+(c-'0');c=getchar();}
	if(p) return ret;
	else return ~(ret-1);
}
template <typename T> inl void write(T x){
	static int sta[50];int top=0;
	if(x<0){putchar('-');x=~(x-1);}
	while(x){sta[++top]=x%10;x/=10;}
	if(top==0) sta[++top]=0;
	while(top){putchar(sta[top--]+'0');}
	putchar('\n');
	return;
}
void fre(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
}
int p[3]={-1,0,1};
int a[N],b[N],c,t,n,m;
int origin[N];
struct node{
	char opt,x,y;
}nod[N];
int main(){
	fre();
	c=read<int>();t=read<int>();
	if(c==1||c==2){
		n=read<int>();m=read<int>();int am=n;
		for(re int i=1;i<=m;i++){
			cin>>nod[i].opt;
			if(nod[i].opt=='+'||nod[i].opt=='-') cin>>nod[i].x>>nod[i].y;
			else cin>>nod[i].x;
		}
		for(int i=1;i<=10000;i++){
			for(int j=1;j=n;j++){
				a[j]=p[rnd()%3];
			}
			rep(j,1,n) b[j]=a[j];
			for(int j=1;j<=m;j++){
				if(nod[i].opt=='-') b[nod[i].x]=-b[nod[i].y];
				else if(nod[i].opt=='+') b[nod[i].x]=b[nod[i].y];
				else if(nod[i].opt=='U') b[nod[i].x]=0;
				else if(nod[i].opt=='T') b[nod[i].x]=1;
				else if(nod[i].opt=='F') b[nod[i].x]=-1;
			}
			bool flag=0;int cnt=0;
			rep(j,1,n){
				if(b[j]!=a[j]){
					flag=0;break;
				}
			}
			if(flag){
				rep(j,1,n){
					if(a[j]==0) cnt++;
				}
			}
			am=min(am,cnt);
		}
		write(am);
		return 0;
	}
	if(c==3||c==4){
		while(t--){
			n=read<int>();m=read<int>();
			for(re int i=1;i<=n;i++) a[i]=1;
			char opt;int x,y,cnt=0;
			rep(i,1,m){
				cin>>opt>>x;
				if(opt=='U') a[x]=0;
				if(opt=='F') a[x]=-1;
				if(opt=='T') a[x]=1;
			}
			rep(i,1,n){
				if(a[i]==0) cnt++;
			}
			write(cnt);
		}
		return 0;
	}
	
	if(c==5||c==6){
		while(t--){
			n=read<int>();m=read<int>();
			rep(i,1,n) a[i]=1;
			char opt;int x,y,cnt=0;
			rep(i,1,m){
				cin>>opt;
				if(opt=='U'){
					x=read<int>();a[x]=0;
				}
				if(opt=='+'){
					x=read<int>();y=read<int>();a[x]=a[y];
				}
			}
			rep(i,1,n){
				if(a[i]==0) cnt++;
			}
			write(cnt);
		}
		return 0;
	}
	if(c==7||c==8){
		while(t--){
			n=read<int>();m=read<int>();
			char opt;int x,y,cnt0=0;
			rep(i,1,m){
				cin>>opt>>x>>y;
				if(opt=='-') cnt0++;
			}
			if(cnt0%2==1){
				write(n);
			}
			else write(0);
		}
	}
	
	return 0;
}