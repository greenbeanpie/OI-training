#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#define ll long long
#define gc() getchar()
#define maxn 105
#define mo 1000000007
using namespace std;

inline ll read(){
	ll a=0;int f=0;char p=gc();
	while(!isdigit(p)){f|=p=='-';p=gc();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=gc();}
	return f?-a:a;
}
int n;

struct ahaha{
	ll a[maxn][maxn];     //一定要用long long存矩阵，否则在过程中会爆掉
	ahaha(){
		memset(a,0,sizeof a);
	}
	inline void build(){     //建造单位矩阵
		for(int i=1;i<=n;++i)a[i][i]=1;
	}
}a;
ahaha operator *(const ahaha &x,const ahaha &y){     //重载运算符
	ahaha z;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mo)%mo;
	return z;
}

ll k;
inline void init(){
	n=read();k=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a.a[i][j]=read();
}

int main(){
	init();
  #ifndef ONLINE_JUDGE
    freopen("P3390_1.in","r",stdin);
  #endif
	ahaha ans;ans.build();
	do{
		if(k&1)ans=ans*a;
		a=a*a;k>>=1;
	}while(k);
	for(int i=1;i<=n;putchar('\n'),++i)
		for(int j=1;j<=n;++j)
			printf("%d ",ans.a[i][j]);
	return 0;
}