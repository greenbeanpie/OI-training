#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>void read(T &x){x=0;char ch;bool f=0;while(!isdigit(ch=getchar())) f|=ch=='-';while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();x=f?-x:x;}
template<typename T1,typename ...T2>void read(T1 &x,T2& ...y){read(x);read(y...);}
int c,n,m,q,k1,k2;
int v,xx;
int x[500],y[500];
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read(c,n,m,q);
	if(n==1){
		while(q--){
		putchar('1');
	}return 0;
	}
	else{
		for(int i=1;i<=n;i++)read(x[i]);
		for(int i=1;i<=m;i++)read(y[i]);
		if((x[1]>y[1]&&x[n]>y[m])||((x[1]<y[1]&&x[n]<y[m])))putchar('1');
		else putchar('0');
		while(q--){
			read(k1,k2);
			while(k1--){
				read(v);read(xx);x[v]=xx;
			}
			while(k2--){
				read(v);read(xx);y[v]=xx;
			}
			if((x[1]>y[1]&&x[n]>y[m])||((x[1]<y[1]&&x[n]<y[m])))putchar('1');
			else putchar('0');
		}
		
	}
	return 0;
}

