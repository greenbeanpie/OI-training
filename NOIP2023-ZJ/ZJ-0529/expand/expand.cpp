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
int c,n,m,q,r=0;
int a[500001],b[500001],xx[500001],yy[500001];
bitset<500001>us,su;
void check() {
	r=0;bool tg;
	for(int i=1;i<=n;i++) {
		tg=0;
    	for(int j=i;j<=m;j++) {
    		us[j]=0;
    		if(a[i]>b[j] && (j<=r || us[j-1])) {
    			tg=1;
    			if(us[j-1] && j-1==r) r++;
    			us[j]=1;
			}
		}
		if(!tg) break;
	}
	if(r==m && tg) putchar(49);
	else {
		r=0;
		for(int i=1;i<=n;i++) {
			tg=0;
    		for(int j=i;j<=m;j++) {
    			us[j]=0;
    			if(a[i]<b[j] && (j<r || us[j-1])) {
    				tg=1;
    				if(us[j-1] && j-1==r) r++;
    				us[j]=1;
				}
			}
			if(!tg) {
				putchar(48);
				return ;
			}
		}
		if(r==m) putchar(49);
		else putchar(48);
	}
	return ;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
    c=read(),n=read(),m=read(),q=read();us[0]=1;
    for(int i=1;i<=n;i++) a[i]=xx[i]=read();
    for(int i=1;i<=m;i++) b[i]=yy[i]=read();
    check();
	while(q--) {
		int kx=read(),ky=read();
		for(int i=1;i<=n;i++) a[i]=xx[i];
		for(int i=1;i<=m;i++) b[i]=yy[i];
		for(int i=1;i<=kx;i++) {
			int p=read(),v=read();a[p]=v;
		}
		for(int i=1;i<=ky;i++) {
			int p=read(),v=read();b[p]=v;
		}
		check();
	}
    return 0;
}
