#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
#define fr(i,l,r) for (i=(l); i<=(r); i++)
#define rfr(i,l,r) for (i=(l); i>=(r); i--)
inline void Max(ll &x,ll y){ x=max(x,y); }
inline void Min(ll &x,ll y){ x=min(x,y); }
template<typename T>inline void read(T &n){
	n=0; T w=1; char ch=getchar();
	while (!isdigit(ch) && ch!=EOF){
		if (ch=='-') w=-1;
		ch=getchar();
	}
	while (isdigit(ch) && ch!=EOF){
		n=(n<<3)+(n<<1)+(ch&15);
		ch=getchar();
	}
	n*=w;
}
template<typename T>inline void write(T x){
	if (x==0){
		putchar('0');
		return ;
	}
	T tmp;
	if (x<0){
		putchar('-');
		x=-x;
	}
	tmp=x;
	long long cnt=0;
	char F[45];
	while (tmp>0){
		F[++cnt]=tmp%10+48;
		tmp/=10;
	}
	while (cnt>0) putchar(F[cnt--]);
}
const ll N=2005;
//==========================================================================================
ll n,m,q,ans=0,x,y,l,r,s,z;
ll a[N],b[N],c[N],d[N];
bool f[N][N];
void solve(){
	ll i,j;
	if (a[1]==b[1]){
		putchar('0');
		return ;
	}
	if (a[1]>b[1]){
		memset(f,false,sizeof(f));
		f[1][1]=1;
		fr(i,1,n){
			fr(j,1,m){
				if (!f[i][j]) continue;
				if (j<m && a[i]>b[j+1]) f[i][j+1]=true;
				if (i<n && a[i+1]>b[j]) f[i+1][j]=true;
			}
		}
	}
	else {
		memset(f,false,sizeof(f));
		f[1][1]=1;
		fr(i,1,n){
			fr(j,1,m){
				if (!f[i][j]) continue;
				if (j<m && a[i]<b[j+1]) f[i][j+1]=true;
				if (i<n && a[i+1]<b[j]) f[i+1][j]=true;
			}
		}
	}
	if (f[n][m]) putchar('1');
	else putchar('0');
}
struct Luan{
	ll a[500005],b[500005],c[500005],d[500005];
	bool f[2005][2005];
void solve(ll n,ll m){
	Min(n,2000);
	Min(m,2000);
	ll i,j;
//	printf("n = %lld , m = %lld\n",n,m);
	if (a[1]==b[1]){
		putchar('0');
		return ;
	}
	if (a[1]>b[1]){
		memset(f,false,sizeof(f));
		f[1][1]=1;
		fr(i,1,n){
			fr(j,1,m){
				if (!f[i][j]) continue;
				if (j<m && a[i]>b[j+1]) f[i][j+1]=true;
				if (i<n && a[i+1]>b[j]) f[i+1][j]=true;
			}
		}
	}
	else {
		memset(f,false,sizeof(f));
		f[1][1]=1;
		fr(i,1,n){
			fr(j,1,m){
				if (!f[i][j]) continue;
				if (j<m && a[i]<b[j+1]) f[i][j+1]=true;
				if (i<n && a[i+1]<b[j]) f[i+1][j]=true;
			}
		}
	}
	bool t=false;
	fr(i,1,m) 
		t|=f[n][i];
	if (t) putchar('1');
	else putchar('0');
}
	void main(){
//		printf("n = %lld\n",n);
		ll i,j;
		fr(i,1,n) read(a[i]),c[i]=a[i];
		fr(i,1,m) read(b[i]),d[i]=b[i];
		solve(n,m);
		while (q--){
			ll kx,ky;
			read(kx); read(ky);
			fr(i,1,n) a[i]=c[i];
			fr(i,1,m) b[i]=d[i];
			fr(i,1,kx){
				read(x); read(y);
				a[x]=y;
			}
			fr(i,1,ky){
				read(x); read(y);
				b[x]=y;
			}
			solve(n,m);
		}
	}
}luan;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ll i,j;
	ll id;
	read(id); read(n); read(m); read(q);
	if (n>2100){
		luan.main();
		return 0;
	}
	fr(i,1,n) read(a[i]),c[i]=a[i];
	fr(i,1,m) read(b[i]),d[i]=b[i];
	solve();
	while (q--){
		ll kx,ky;
		read(kx); read(ky);
		fr(i,1,n) a[i]=c[i];
		fr(i,1,m) b[i]=d[i];
		fr(i,1,kx){
			read(x); read(y);
			a[x]=y;
		}
		fr(i,1,ky){
			read(x); read(y);
			b[x]=y;
		}
		solve();
	}
	return 0;
}