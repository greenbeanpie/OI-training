#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
inline int read(){
	int f=1,w=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')	f=-1;
		c=getchar();
	}
	while(c>='0'&& c<='9'){
		w=(w<<1)+(w<<3)+(c^48);
		c=getchar();
	}
	return f*w;
}
int c,n,m,q;
int a[N],b[N];
int tmpa[N],tmpb[N];
namespace sub1{
	void calc(){
		if(tmpa[1]==tmpb[1])	cout<<0;
		else	cout<<1;
	}
	void work(){
		calc();
		while(q--){
			int k,kk;
			k=read();
			kk=read();
			for(int i=1;i<=n;i++){
				tmpa[i]=a[i];
			}
			for(int i=1;i<=m;i++){
				tmpb[i]=b[i];
			}
			for(int i=1;i<=k;i++){
				int x,y;
				x=read();
				y=read();
				tmpa[x]=y;
			}
			for(int i=1;i<=kk;i++){
				int x,y;
				x=read();
				y=read();
				tmpb[x]=y;
			}
			calc();
		}
	}
}
namespace sub2{
	void calc(){
		if(tmpa[1]>tmpb[1]){
			if(tmpa[n]>tmpb[n])	cout<<1;
			else	cout<<0;
		}else if(tmpa[1]<tmpb[1]){
			if(tmpa[n]<tmpb[n])	cout<<1;
			else	cout<<0;
		}else{
			cout<<0;
		}
	}
	void work(){
		calc();
		while(q--){
			int k,kk;
			k=read();
			kk=read();
			for(int i=1;i<=n;i++){
				tmpa[i]=a[i];
			}
			for(int i=1;i<=m;i++){
				tmpb[i]=b[i];
			}
			for(int i=1;i<=k;i++){
				int x,y;
				x=read();
				y=read();
				tmpa[x]=y;
			}
			for(int i=1;i<=kk;i++){
				int x,y;
				x=read();
				y=read();
				tmpb[x]=y;
			}
			calc();
		}
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		tmpa[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
		tmpb[i]=b[i];
	}
	if(c==1){
		sub1::work();
		return 0;
	}
	if(c==2){
		sub2::work();
		return 0;
	}
	sub2::work();
	return 0;
}