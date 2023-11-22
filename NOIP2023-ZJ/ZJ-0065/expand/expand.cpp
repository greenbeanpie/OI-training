#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,INF=2e9;
int n,m;
int a[N],b[N];
int a_[N],b_[N];

int c[N<<1];
int tot;
void init() {
	cout<<"==============\n";
	for(int i=1;i<=n;i++) c[i]=a[i];
	for(int i=1;i<=m;i++) c[i+n]=b[i];
	sort(c+1,c+n+m+1);
	tot=unique(c+1,c+n+m+1)-c-1;
	for(int i=1;i<=n;i++) {
		a[i]=lower_bound(c+1,c+tot+1,a[i])-c;
		cout<<a[i]<<" ";
	}
	puts("");
	for(int i=1;i<=m;i++) {
		b[i]=lower_bound(c+1,c+tot+1,b[i])-c;
		cout<<b[i]<<" ";
	}
	puts("");
	return;
}

bool checka1(int pos) {
	int p=1,mx=a[1];
	for(int i=2;i<pos;i++) {
		if(a[i]>b[p]) {
			mx=max(mx,a[i]);
			continue;
		}
		else {
			int mx2=b[p],_=p;
			while(p<=m&&a[i]<=b[p]) p++,mx2=max(mx2,b[p]);
			if(p==m+1||mx<=mx2) return false;
			mx=a[i];
		}
	}
	int _=p;
	p=m,mx=a[n];
	for(int i=n-1;i>pos;i--) {
		if(a[i]>b[p]) {
			mx=max(mx,a[i]);
			continue;
		}
		else {
			int mx2=b[p];
			while(p>=1&&a[i]<=b[p]) p--,mx2=max(mx2,b[p]);
			if(p==0||mx<=mx2) return false;
			mx=a[i];
		}
	}
	if(p>=_) return true;
	return false;
}
bool checkb2(int pos) {
	int p=1,mn=b[1];
	for(int i=2;i<pos;i++) {
		if(b[i]<a[p]) {
			mn=min(mn,b[i]);
			continue;
		}
		else {
			int mn2=a[p];
			while(p<=n&&b[i]>=a[p]) p++,mn2=min(mn2,a[p]);
			if(p==n+1||mn>=mn2) return false;
			mn=b[i];
		}
	}
	int _=p;
	p=n,mn=b[m];
	for(int i=n-1;i>pos;i--) {
		if(b[i]<a[p]) {
			mn=min(mn,b[i]);
			continue;
		}
		else {
			int mn2=a[p];
			while(p>=1&&b[i]>=a[p]) p--,mn2=min(mn2,a[p]);
			if(p==0||mn>=mn2) return false;
			mn=b[i];
		}
	}
	if(p>=_) return true;
	return false;
}
int f[2005][2005];
void atri() {
	int fg=a[1]>b[1];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			f[i][j]=0;
			if((a[i]>b[j])!=fg) continue;
			if(i==1&&j==1) f[i][j]=1;
			if(i>1) f[i][j]|=f[i-1][j];
			if(j>1) f[i][j]|=f[i][j-1];
			if(i>1&&j>1) f[i][j]|=f[i-1][j-1];
		}
	}
	printf("%d",f[n][m]);
	return;
}
void Ginka() {
//	init();
	if(a[1]==b[1]||a[n]==b[m]) {putchar('0');return;}
	int fg=(a[1]>b[1])^(a[n]>b[m]);
	if(fg) {putchar('0');return;}
	if(n<=2000&&m<=2000) {
		atri();
		return;
	}
	if(a[1]<b[1]) {
		for(int i=1;i<=max(n,m);i++) swap(a[i],b[i]);
		swap(n,m);
	}
	
	int mn1=INF,mx1=-INF,posa1=1,posa2=1;
	for(int i=1;i<=n;i++) {
		if(a[i]<mn1) mn1=a[i],posa1=i;
		if(a[i]>mx1) mx1=a[i],posa2=i;
	}
	
	int mn2=INF,mx2=-INF,posb1=1,posb2=1;
	for(int i=1;i<=m;i++) {
		if(b[i]<mn2) mn2=b[i],posb1=i;
		if(b[i]>mx2) mx2=b[i],posb2=i;
	}
	if(mn1<=mn2||mx1<=mx2) {putchar('0');return;}
	
	if(checka1(posa2)) {putchar('1');return;}
	if(checkb2(posb1)) {putchar('1');return;}
	
	putchar('0');
	return;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int Komeji,Koishi;
	scanf("%d%d%d%d",&Komeji,&n,&m,&Koishi);
	for(int i=1;i<=n;i++) scanf("%d",&a_[i]),a[i]=a_[i];
	for(int i=1;i<=m;i++) scanf("%d",&b_[i]),b[i]=b_[i];
	Ginka();
	while(Koishi--) {
		int k1,k2;scanf("%d%d",&k1,&k2);
		for(int i=1;i<=n;i++) a[i]=a_[i];
		for(int i=1;i<=m;i++) b[i]=b_[i];
		while(k1--) {
			int p,vl;scanf("%d%d",&p,&vl);
			a[p]=vl;
		}
		while(k2--) {
			int p,vl;scanf("%d%d",&p,&vl);
			b[p]=vl;
		}
		Ginka();
	}
	return 0;
}
