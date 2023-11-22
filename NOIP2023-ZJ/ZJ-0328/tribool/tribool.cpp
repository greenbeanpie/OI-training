#include <bits/stdc++.h>
#define int long long 
using namespace std;
/*
不算很难
考虑先正序跑一遍原序列
初始给每个位置赋值i，表示是正的
inf+1 T
inf+2 F
inf+3 U
然后就可以得到一个最终序列
如果最终结果下是有大于inf的，那么就必须要设为该值了
否则的话应该是其他东西连过去
可以考虑建扩展域并查集
<=n的表示确定这个值要选T
>n的表示要选F
如果T和F连一起了，那么就是要贡献一发
*/
const int N=1e5+5,inf=1e6;
int ID,T;
int n,m,a[N],f[N<<1];
char c;
int x,y;
int fd(int x){return f[x]==x?x:f[x]=fd(f[x]);}
inline void mg(int x,int y){
	x=fd(x),y=fd(y);
	if(x==y)return;
	f[x]=y;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>ID>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n*2;i++)f[i]=i;
		f[n*2+1]=n*2+1;
		for(int i=1;i<=n;i++)a[i]=i;
		for(int i=1;i<=m;i++){
			cin>>c;
			switch(c){
				case 'T':cin>>x;a[x]=inf;break;
				case 'F':cin>>x;a[x]=-inf;break;
				case 'U':cin>>x;a[x]=0;break;
				case '+':cin>>x>>y;a[x]=a[y];break;
				case '-':cin>>x>>y;a[x]=-a[y];break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)mg(i,n*2+1),mg(i+n,n*2+1);
			else if(a[i]!=inf and a[i]!=-inf){
				if(a[i]<0)mg(i,-a[i]+n),mg(i+n,-a[i]);
				else mg(i,a[i]),mg(i+n,a[i]+n);
			}
		}
		for(int i=1;i<=n;i++)if(fd(i)==fd(i+n))ans++;
		cout<<ans<<"\n";
	}
}
/*
2 1
10 10
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3
*/