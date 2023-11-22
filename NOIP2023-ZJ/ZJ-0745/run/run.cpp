//      Author:WangJingze      //
//      Deep Dark Fantasy      //
#include<bits/stdc++.h>
#define re register
#define il inline
#define u32 int
#define u64 long long
#define ll long long
#define int long long 
using namespace std;
const int MAXN=1e5+10;
u32 c,t;
u32 n,m,k,d;
ll mx=0;
struct node{
	int x,y,v;
}a[MAXN];

signed main(){
freopen("run.in","r",stdin);
freopen("run.out","w",stdout);
scanf("%lld%lld",&c,&t);while(t--){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	mx=0;
	for(re u32 i=0;i<m;++i) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
	for(re u32 i=0;i<m;++i){
		if(a[i].x<=a[i].y&&a[i].v-a[i].y*d>0){
			mx+=a[i].v-a[i].y*d;
		}
	}
	printf("%lld\n",mx);
		
}return 0;}
/*


Expect: 0pts
//freopen("run2.in","r",stdin);
//freopen("run.out","w",stdout);



*/

