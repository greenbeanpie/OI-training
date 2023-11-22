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
//==========================================================================================
struct infor{ ll l,r,v; };
ll qt,n,m,k,d,ans=0,x,y,l,r,s,z;
struct Sub1{
	ll g[1005];
	ll u,v,f[2][1005];
	struct Val{ ll x,v; };
	vector<Val> c[1005];
	void main(){
		ll i,j;
		while (qt--){
			read(n); read(m); read(k); read(d);
			fr(i,1,n) c[i].clear();
			fr(i,1,m){
				read(x); read(y); read(z);
				Val p;
				p.x=y; p.v=z;
				c[x].push_back(p);
			}
			u=0; v=1;
			memset(f,-0x3f,sizeof(f));
			f[0][0]=0;
			fr(i,1,n){
				memset(f[v],-0x3f,sizeof(f[v]));
				fr(j,0,k) Max(f[v][j+1],f[u][j]-d);
				fr(j,0,k) Max(f[v][0],f[u][j]);
				memset(g,0,sizeof(g));
				for (j=0; j<c[i].size(); j++) g[c[i][j].x]+=c[i][j].v;
				fr(j,1,n) g[j]+=g[j-1];
				fr(j,0,n) f[v][j]+=g[j];
				swap(u,v);
			}
			ans=0;
			fr(i,0,k) Max(ans,f[u][i]);
			write(ans); putchar('\n');
		}
	}
}sub1;
struct Sub2{
	ll cnt=0,p[2005];
	infor a[1005];
	ll v[2005][2005];
	ll f[2005];
	ll find_r(ll x){//max <=
		ll l,r,mid;
		l=1; r=cnt;
		while (l<=r){
			mid=(l+r)>>1;
			if (p[mid]<=x) l=mid+1;
			else r=mid-1;
		}
		return r;
	}
	ll find_l(ll x){//min >=
		ll l,r,mid;
		l=1; r=cnt;
		while (l<=r){
			mid=(l+r)>>1;
			if (p[mid]>=x) r=mid-1;
			else l=mid+1;
		}
		return l;
	}
	ll V(ll l,ll r){ return v[l][r]-(p[r]-p[l]+1)*d; }
	void main(){
		ll i,j;
		while (qt--){
			read(n); read(m); read(k); read(d);
			fr(i,1,m){
				read(x); read(y); read(z);
				a[i].l=x-y+1; a[i].r=x;
				a[i].v=z;
			}
			cnt=0;
			fr(i,1,m){
				p[++cnt]=a[i].l;
				p[++cnt]=a[i].r;
			}
			sort(p+1,p+1+cnt);
			ll len=1;
			fr(i,2,cnt)
				if (p[i]!=p[len]) p[++len]=p[i];
			cnt=len;
			memset(v,0,sizeof(v));
			fr(i,1,m){
				x=find_l(a[i].l); y=find_l(a[i].r);
				v[x][y]+=a[i].v;
			}
			rfr(i,cnt,0)
				fr(j,0,cnt)
					v[i][j]+=v[i+1][j]+v[i][j-1]-v[i+1][j-1];
			p[0]=-inf;
			memset(f,0,sizeof(f));
			ans=0;
			fr(i,0,cnt){
				Max(ans,f[i]);
				Max(f[i+1],f[i]);
				if (p[cnt]<p[i]+2) continue;
				ll l=inf;
				if (p[i+2]>=p[i]+2) l=i+2;
				if (p[i+1]>=p[i]+2) l=i+1;
				fr(j,l,cnt){
					if (p[l]+k-1<p[j]) break;
					Max( f[j] , f[i] + V(l,j) );
				}
				if (l==cnt) continue;
				l++;
				fr(j,l,cnt){
					if (p[l]+k-1<p[j]) break;
					Max( f[j] , f[i] + V(l,j) );
				}
			}
			write(ans); putchar('\n');
		}
		return ;
	}
}sub2;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ll id;
	read(id); read(qt);
	if (id<=9){
		sub1.main();
		return 0;
	}
	if (id==10 || id==11 || id==15 || id==16){
		sub2.main();
		return 0;
	}
	return 0;
}