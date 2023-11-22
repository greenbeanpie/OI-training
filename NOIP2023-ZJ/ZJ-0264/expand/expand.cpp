#include <bits/stdc++.h>
using namespace std;
const int N=3005;
const int M=500005;
int c,n,m,q,kx,ky,px[M],py[M],vx[M],vy[M],a[M],b[M],x[M],y[M];
bool st,f[N][N];
int rd(){
	int x=0,w=0;
	char ch=getchar();
	while (!isdigit(ch)){
		if (ch=='-') w=1;
		ch=getchar();
	}
	while (isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return w?-x:x;
}
void solve(){
	st=x[1]<y[1];
	if (x[1]==y[1]||x[n]==y[m]||((x[n]<y[m])^st)){
		putchar('0');
		return;
	}
	if (n<=2000&&m<=2000){
		f[0][0]=1;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
			if (x[i]<y[j]&&st||x[i]>y[j]&&!st)
			f[i][j]=f[i-1][j-1]||f[i-1][j]||f[i][j-1];
			else f[i][j]=0;
		putchar('0'+f[n][m]);
		return;
	}
	int j=1;
	for (int i=1;i<=n;++i){
		if (j<=m&&(x[i]<y[j]&&st||x[i]>y[j]&&!st))
		while (j<=m&&(x[i]<y[j]&&st||x[i]>y[j]&&!st)) j++;
		else{
			while (j>=1&&!(x[i]<y[j]&&st||x[i]>y[j]&&!st)) j--;
			if (j<1){
				putchar('0');
				return;
			}
			j++;
		}
	}
	putchar('0'+(j>m));
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=rd(),n=rd(),m=rd(),q=rd();
	for (int i=1;i<=n;++i) x[i]=rd();
	for (int i=1;i<=m;++i) y[i]=rd();
	solve();
	while (q--){
		kx=rd(),ky=rd();
		for (int i=1;i<=kx;++i){
			px[i]=rd(),vx[i]=rd();
			swap(x[px[i]],vx[i]);
		}
		for (int i=1;i<=ky;++i){
			py[i]=rd(),vy[i]=rd();
			swap(y[py[i]],vy[i]);
		}
		solve();
		for (int i=1;i<=kx;++i)x[px[i]]=vx[i];
		for (int i=1;i<=ky;++i)y[py[i]]=vy[i];
	}
	return 0;
}
