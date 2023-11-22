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
const ll N=3005,M=3005;
//==========================================================================================
ll n,m,ans=0,x,y,l,r,s,z;
char ch[N];
ll a[N],b[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ll i,j;
	read(n); read(m);
	fr(i,1,n){
		scanf("%s",ch+1);
		ll fst=inf,lst=0;
		fr(j,1,m) Max(lst,ch[j]-'a') , Min(fst,ch[j]-'a');
		a[i]=lst; b[i]=fst;
	}
	fr(i,1,n){
		bool t=true;
		fr(j,1,n){
			if (i==j) continue;
			if (b[i]>=a[j]) t=false;
		}
		if (t) putchar('1');
		else putchar('0');
	}
	return 0;
}