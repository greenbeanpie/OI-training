#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(!(c^'-')) f^=1;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^'0');c=getchar();}
	return (f?s:~(s-1));
}
//const int N=1e3+10;
const int N=5e5+10;
int x[N],y[N],a[N],b[N],p1[N],p2[N],v1[N],v2[N],bx[N],by[N];
int c,n,m,q;
multiset<int> q1,q2;
bool check(){
	if(*q1.begin()<*q2.begin()||x[1]<=y[1]||x[n]<=y[m]) return 0;
	//if(*q1.end()>*q2.end()||x[1]>=y[1]||x[n]>=y[m]) return 0;
	else return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) x[i]=read(),q1.insert(x[i]);
	for(int i=1;i<=m;i++) y[i]=read(),q2.insert(y[i]);
	if(check()) printf("%d",1);
	else printf("%d",0);
	while(q--){
		int kx,ky;
		kx=read(),ky=read();
		for(int i=1;i<=kx;i++){
			int p,v;
			p=read(),v=read();
			p1[i]=p;v1[i]=v,bx[i]=x[p];
			q1.erase(q1.find(x[p]));
			q1.insert(v);
			x[p]=v;
		}
		for(int i=1;i<=ky;i++){
			int p,v;
			p=read(),v=read();
			p2[i]=p;v2[i]=v,by[i]=y[p];
			q2.erase(q2.find(y[p]));
			q2.insert(v);
			y[p]=v;
		}
		if(check()) printf("%d",1);
		else printf("%d",0);
		for(int i=1;i<=kx;i++){
			q1.erase(q1.find(v1[i]));
			q1.insert(bx[i]);
			x[p1[i]]=bx[i];
		}
		for(int i=1;i<=ky;i++){
			q2.erase(q2.find(v2[i]));
			q2.insert(by[i]);
			y[p2[i]]=by[i];
		}
	}
	return 0;
}