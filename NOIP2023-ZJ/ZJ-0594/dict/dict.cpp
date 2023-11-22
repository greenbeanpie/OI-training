#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int n,m;
int a[maxn][maxn];
int p[maxn][maxn],c[maxn][maxn];
inline bool cmpp(int x,int y) { return x<y; }
inline bool cmpc(int x,int y) { return x>y; }
inline bool check(int i) {
	for(register int j=1;j<=n;j++) {
		if(i==j) continue;
		bool flag=false;
		for(register int k=1;k<=m&&flag==false;k++) {
			if(p[i][k]<c[j][k]) flag=true;
			else return false;
		}
	}
	return true;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(register int i=1;i<=n;i++) {
		for(register int j=1;j<=m;j++) {
			char x;
			cin>>x;
			a[i][j]=x-'a'+1;
		}
	}
	if(n==1) for(register int i=1;i<=n;i++) cout<<'1';
	if(n<=26&&m==1) {
		int maxz=1000,maxi;
		for(register int i=1;i<=n;i++) if(maxz>a[i][1]) maxz=a[i][1],maxi=i;
		for(register int i=1;i<=n;i++) {
			if(maxi==i) cout<<'1';
			else cout<<'0';
		} 
		return 0;
	}
	for(register int i=1;i<=n;i++) {
		sort(a[i]+1,a[i]+m+1,cmpp);
		for(register int j=1;j<=m;j++) p[i][j]=a[i][j];
		sort(a[i]+1,a[i]+m+1,cmpc);
		for(register int j=1;j<=m;j++) c[i][j]=a[i][j];
	}
	for(register int i=1;i<=n;i++) {
		bool flag=true;
		if(check(i)) cout<<'1';
		else cout<<'0';
	}
	return 0;
}
