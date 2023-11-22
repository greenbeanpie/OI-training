#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+5;
int a[N],b[N];
signed main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,m) scanf("%lld",&b[i]);
	while(q--) {
		int k1,k2;
		scanf("%lld%lld",&k1,&k2);
		For(i,1,k1) {
			int k,x;
			scanf("%lld%lld",&k,&x);
			a[k]=x;
		}
		For(i,1,k2) {
			int k,x;
			scanf("%lld%lld",&k,&x);
			b[k]=x;
		}
		if(n==1&&m==1) if(a[1]!=b[1]) printf("1"); else printf("0");
		if(n<=2&&m<=2) {
			if(n==1&&m==2) if((b[1]-a[1])*(b[2]-a[1])) printf("1"); else putchar('0');
			if(n==2&&m==1) if((b[1]-a[1])*(b[1]-a[2])) printf("1"); else putchar('0');
			if(n==2&&m==2) if((b[2]-a[2])*(b[1]-a[1])) printf("1"); else putchar('0');
		}
	}
	return 0;
}
/*
1 1
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
*/
