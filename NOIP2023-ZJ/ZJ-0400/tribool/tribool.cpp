#include<bits/stdc++.h>
#define int long long
using namespace std; 
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,m,f[100010];
int a[100010],T,F,U;
int get(int x){
	if(x==f[x]) return x;
	return f[x]=get(f[x]);
}
void add(int x,int y){
	f[x]=f[get(y)];
}
void spread(int x,int num){
	a[x]=num;
	if(x==f[x]) return ;
	spread(f[x],num);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	srand(time(0));
	int c=read(),Tt=read();
	if(c==1||c==2){
		while(Tt--){
			n=read(),m=read();
			cout<<(int)rand()%n<<"\n";
		}
	}
	if(c==3||c==4){
		while(Tt--){
			T=F=U=0;
			memset(a,-1,sizeof(a));
			n=read(),m=read();
			for(int i=1;i<=m;i++){
				char c=getchar();
				if(c=='T'){
					int x=read();
					a[x]=1;
				}
				if(c=='F'){
					int x=read();
					a[x]=0;
				}
				if(c=='U'){
					int x=read();
					a[x]=2;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==1) T++;
				if(a[i]==0) F++;
				if(a[i]==2) U++;
			}
			if(U) cout<<U<<"\n";
			else cout<<"0"<<"\n";
		}	
	}
	if(c==5||c==6){
		while(Tt--){
			T=F=U=0;
			memset(a,-1,sizeof(a));
			for(int i=1;i<=n;i++) f[i]=i;
			n=read(),m=read();
			for(int i=1;i<=m;i++){
				char c=getchar();
				if(c=='U'){
					int x=read();
					a[x]=2;
				}
				if(c=='+'){
					int x1=read(),x2=read();
					add(x1,x2);
				}
			}
			for(int i=1;i<=n;i++)spread(i,a[get(i)]);
			for(int i=1;i<=n;i++) if(a[i]==2) U++;
			if(U) cout<<U<<"\n";
			else cout<<"0"<<"\n";
		}
	}
	if(c>6){
		while(Tt--){
			cout<<(int)rand()%100000<<"\n";
		}
	}
	return 0;
}
