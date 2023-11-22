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
int n,m;
int mii[3001],il[3001],xr[3001],mxx[3001],vis[26],vt[26];
string s[3001],pp="";
bitset<3001>pre,erp;
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	if(n==1) {
		putchar(49);
		cin>>s[1];
		return 0;
	}
//	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) {
		cin>>s[i];
		for(int j=0;j<26;j++) vis[j]=vt[j]=-1;
		mxx[i]=0,xr[i]=0,il[i]=0,mii[i]=0;
		for(int j=m-1;~j;j--) {
			for(int k=0;k<s[i][j]-'a';k++) if(vis[k]!=-1) {
				il[i]=j,mii[i]=vis[k];break;
			}
			for(int k=25;k>s[i][j]-'a';k--) if(vt[k]!=-1) {
				xr[i]=j;mxx[i]=vt[k];break;
			}
			if(vis[s[i][j]-'a']==-1) vis[s[i][j]-'a']=j;
			if(vt[s[i][j]-'a']==-1) vt[s[i][j]-'a']=j;
		}
		swap(s[i][il[i]],s[i][mii[i]]);
		if(pp>s[i]) pre[i]=1;
		else pre[i]=0;
//		cout<<s[i]<<"   ";
		swap(s[i][il[i]],s[i][mii[i]]);
		swap(s[i][xr[i]],s[i][mxx[i]]);
		if(pp>s[i] || pp=="") pp=s[i];
//		cout<<s[i]<<"   "<<pp<<'\n';
		swap(s[i][xr[i]],s[i][mxx[i]]);
	}
	pp="";
	for(int i=n;i>=1;i--) {
		swap(s[i][il[i]],s[i][mii[i]]);
		if(pp>s[i]) erp[i]=1;
		else erp[i]=0;
		swap(s[i][il[i]],s[i][mii[i]]);
		swap(s[i][xr[i]],s[i][mxx[i]]);
		if(pp>s[i] || pp=="") pp=s[i];
		swap(s[i][xr[i]],s[i][mxx[i]]);
	}
	pre[1]=erp[n]=1;
	for(int i=1;i<=n;i++) if(pre[i] && erp[i]) putchar(49);
	else putchar(48);
    return 0;
}
/*
15 2
zx
qn
wn
nd
pl
pd
vm
ff
mh
ql
zi
yv
md
ji
oc
000101010000101

*/
