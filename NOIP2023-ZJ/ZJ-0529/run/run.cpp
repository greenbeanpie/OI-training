#include<bits/stdc++.h>
using namespace std;//bu ru yuan shen yi tuo gou shi
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
int c,t,n,m,k,d,as[100001];
struct node {
	int x,y,v;
	inline bool operator<(const node&ls) const {
		return x!=ls.x ? x<ls.x : y<ls.y;
	}
}nd[100001];
int f[201][201];
void done() {
	n=read(),m=read(),k=read(),d=read();
	for(int i=0;i<=200;i++) for(int j=0;j<=200;j++) f[i][j]=-0x3f3f3f3f;
	f[0][0]=0;
	for(int i=1;i<=m;i++) nd[i].x=read(),nd[i].y=read(),nd[i].v=read();
	sort(nd+1,nd+m+1);
	int ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) f[i][0]=max(f[i][0],f[i-1][j-1]);
		for(int j=1;j<=i;j++) {
			int p=0;
			for(int l=1;l<=m;l++) {
				if(nd[l].x>i) break;
				if(nd[l].y==j) p+=nd[l].v;
			}
			f[i][j]=max(f[i][j],f[i][j-1]-d+p);
			ans=max(ans,f[i][j]);
		}
	}
	print(ans,'\n');
	return ;
}
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	while(t--) done();
    return 0;
}
