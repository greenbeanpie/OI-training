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
const ll N=100005;
//==========================================================================================
struct rlt{
	ll op;
	ll pos,v;
};
struct edge{ ll x,y,v; };
ll qt,n,m,ans=0,x,y,l,r,s,z;
rlt a[N];
ll cnt=0,head[N]; edge e[2*N];
ll f[N];
ll get_opt(){
	char ch=getchar();
	while ( ! ( ch=='T' || ch=='F' || ch=='U' || ch=='+' || ch=='-' ) ) ch=getchar();
	if (ch=='T') return 1;
	if (ch=='F') return 2;
	if (ch=='U') return 3;
	if (ch=='+') return 4;
	if (ch=='-') return 5;
}
void addedge(ll x,ll y,ll v){
	cnt++;
	e[cnt].x=head[x];
	e[cnt].y=y;
	e[cnt].v=v;
	head[x]=cnt;
}
inline ll con(ll x,ll y){
	if (x==2) return x;
	else return x^y;
}
void dfs(ll x,ll c){
	if (f[x]!=3 && f[x]!=c) c=2;
	f[x]=c;
	ll i; ll go;
	for (i=head[x]; i; i=e[i].x){
		go=e[i].y;
		if (con(c,e[i].v)!=f[go]) dfs(go,con(c,e[i].v));
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ll i,j;
	read(qt); read(qt);
	while (qt--){
		read(n); read(m);
		fr(i,1,n){
			a[i].op=1;
			a[i].pos=i;
			a[i].v=0;
		}
		fr(i,1,m){
			ll op;
			op=get_opt();
			if (1<=op && op<=3){
				read(x);
				a[x].op=0;
				a[x].v=op-1;
			}
			else {
				op-=4;
				read(x); read(y);
				if (a[y].op==0){
					a[x].op=0;
					a[x].v=con(a[y].v,op);
				}
				else {
					a[x].op=1;
					a[x].pos=a[y].pos;
					a[x].v=a[y].v^op;
				}
			}
		}
//		fr(i,1,n){
//			if (a[i].op==0) printf("a [ %lld ] = %lld\n")
//		}
		cnt=0;
		fr(i,1,n) head[i]=0,f[i]=3;
		fr(i,1,n){
			if (a[i].op==0) f[i]=a[i].v;
			else {
				addedge(i,a[i].pos,a[i].v);
				addedge(a[i].pos,i,a[i].v);
			}
		}
		fr(i,1,n)
			if (f[i]!=3) dfs(i,f[i]);
		fr(i,1,n) if (f[i]==3) dfs(i,0);
		ans=0;
		fr(i,1,n) 
			if (f[i]==2) ans++;
		write(ans); putchar('\n');
	}
	return 0;
}