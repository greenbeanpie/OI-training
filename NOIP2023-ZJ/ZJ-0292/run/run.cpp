#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum,n,m,k,d,c,t,i,j;
map<ll,ll> f[100005];
struct node{
	int x,y,z;
}u[100005];
inline bool cmp(node a,node b){
	return a.x<b.x;
}
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while ((ch<'0'||ch>'9')&&(ch!='-')) ch=getchar();
	if (ch=='-'){
		f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;	
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	t=read();
	
	for (;t>=1;t--){
		n=read();
		m=read();
		k=read();
		d=read();
		for (i=1;i<=m;i++) u[i].x=read(),u[i].y=read(),u[i].z=read();
		sort(u+1,u+1+m,cmp);
		for (i=1;i<=m;i++) f[i].clear();
		f[1][min(u[1].x,u[1].y)]=-d*min(u[1].x,u[1].y)+u[1].z+10000000000;
		f[1][0]=10000000000;
		for (i=2;i<=m;i++){
			f[i][0]=f[i-1][0];
			for (j=i-1;j>=1;j--)
				if (u[i].x-u[i].y+1<=u[j].x+1){
					for (auto kk : f[j] )
						if (kk.first!=0){
							if (kk.first+u[i].x-u[j].x<=k){
								f[i][kk.first+u[i].x-u[j].x]=max(f[i][kk.first+u[i].x-u[j].x],kk.second+u[i].z-d*(u[i].x-u[j].x));
//								if (i==m) printf("%lld %lld %lld %lld\n",kk.first+u[i].x-u[j].x,u[i].z,d*(u[i].x-u[j].x),kk.second);
							}
								
								
							f[i][0]=max(f[i][0],f[i-1][kk.first]);
						}
				}
				else if (j==i-1){
					for (auto kk : f[j] )
						f[i][0]=max(f[i][0],f[i-1][kk.first]);
					break;
				}
				else break;
			f[i][u[i].y]=f[j+1][0]-d*u[i].y+u[i].z;
		}
			
//		for (i=1;i<=m;i++){
//			for (auto kk : f[i]){
//				printf("%lld %lld\n",kk.first,f[i][kk.first]-10000000000);
//			}
//			printf("\n");
//		}
		sum=0;
		for (auto kk : f[m] )
			sum=max(sum,kk.second);
		printf("%lld\n",sum-10000000000);
	}
	return 0;
}
/*1 1
20 5 100 2
3 3 20
20 10 5
10 5 7
9 5 12
14 4 8


*/
