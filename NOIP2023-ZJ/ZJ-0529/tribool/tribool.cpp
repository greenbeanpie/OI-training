#include<bits/stdc++.h>
using namespace std;
long long read() {
    long long x;bool f;char ch;
    for(f=0;!isdigit(ch=getchar());f=ch=='-');
    for(x=ch-48;isdigit(ch=getchar());x=x*10+ch-48);
    return f?-x:x;
}
void print(long long x,char las) {
    if(!x) {
        putchar(48),putchar(las);
        return ;
    }
    if(x<0) putchar('-'),x=-x;
    int ls[48],s=0;
    while(x) ls[++s]=x%10,x/=10;
    while(s) putchar(ls[s--]+48);
    putchar(las);
    return ;
}
int c,t,n,m;
bitset<100001>tp;
int wc[100001],co[100001];
int fa[100001],f2[100001],size[100001],enm[100001];
int find(int x) {
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}
int fd(int x) {
	return f2[x]==x ? x : f2[x]=find(f2[x]);
}
void done() {
	n=read(),m=read();
	for(int i=1;i<=n;i++) enm[i]=0,tp[i]=0,wc[i]=fa[i]=f2[i]=i,size[i]=1,co[i]=0;
	for(int i=1;i<=m;i++) {
		char opt;cin>>opt;
		int x,y;
		if(opt=='-') {
			x=read(),y=read();
			if(co[y]) {
				co[x]=(co[y]==3 ? 3 : (co[y]==1 ? -1 : 1));
			}else {
				wc[x]=-1*wc[y];
			}
		}else if(opt=='+') {
			x=read(),y=read();
			if(co[y]) {
				co[x]=co[y];
			}else {
				wc[x]=wc[y];
			}
		}else {
			x=read();
			co[x]=(opt=='U' ? 3 : (opt=='T' ? 1 : -1));
		}
	}
//	puts("ssss");
	
	for(int i=1;i<=n;i++) {
		if(!co[i]) {
			int u=abs(wc[i]),v=i,uu,vv;
			uu=u,vv=v;
			u=find(u),v=find(v);
			if(u!=v && wc[i]>0) {
				if(find(enm[u])==find(v)) co[u]=3;
				fa[v]=u;
			}else if(u!=v && wc[i]<0) {
				int p=find(enm[u]);
				if(!p) enm[u]=v;
				if(p!=v) fa[v]=p;
				enm[u]=find(p);
			}else if(u==v && wc[i]<0) {
				co[i]=3;
			}
			uu=fd(uu),vv=fd(vv);
			if(u!=v) {
				f2[vv]=uu,size[uu]+=size[vv];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(!tp[find(i)]) {
		if(co[i]==3) ans+=size[find(i)];
		tp[find(i)]=1;
	}
	print(ans,'\n');
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),t=read();
	while(t--) done();
    return 0;
}
/*
1 1
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1

*/
