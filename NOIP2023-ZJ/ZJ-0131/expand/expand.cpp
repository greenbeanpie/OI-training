#include<bits/stdc++.h>
#define rd read()
#define ll long long
#define ve vector<ll>
#define pa pair<ll,ll>
using namespace std;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,m,k,q,a[500005],b[500005],c[500005],d[500005];
void check(){
	if(c[n]>d[m]&&c[1]>d[1]){
		if(n>m){
			ll mac=-1,mid=1ll<<40;
			for(int i=1;i<=m;i++){
				mac=max(mac,c[i]);
				mid=min(mid,d[i]);
				if(c[i]<mid||d[i]>mac){
					printf("0");
					return;
				}
			}
			for(int i=m+1;i<=n;i++){
				if(c[i]<mid){
					printf("0");
					return;
				}
			}
			printf("1");
		}else{
			ll mac=-1,mid=1ll<<40;
			for(int i=1;i<=n;i++){
				mac=max(mac,c[i]);
				mid=min(mid,d[i]);
				if(c[i]<mid||d[i]>mac){
					printf("0");
					return;
				}
			}
			for(int i=n+1;i<=m;i++){
				if(d[i]>mac){
					printf("0");
					return;
				}
			}
			printf("1");
		}
	}else if(c[n]<d[m]&&c[1]<d[1]){
		if(n>m){
			ll mac=-1,mid=1ll<<40;
			for(int i=1;i<=m;i++){
				mac=max(mac,d[i]);
				mid=min(mid,c[i]);
				if(d[i]<mid||c[i]>mac){
					printf("0");
					return;
				}
			}
			for(int i=m+1;i<=n;i++){
				if(c[i]>mac){
					printf("0");
					return;
				}
			}
			printf("1");
		}else{
			ll mac=-1,mid=1ll<<40;
			for(int i=1;i<=n;i++){
				mac=max(mac,d[i]);
				mid=min(mid,c[i]);
				if(d[i]<mid||c[i]>mac){
					printf("0");
					return;
				}
			}
			for(int i=n+1;i<=m;i++){
				if(d[i]<mid){
					printf("0");
					return;
				}
			}
			printf("1");
		}
	}else printf("0");
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	rd;n=rd;m=rd;q=rd;
	for(int i=1;i<=n;i++)c[i]=a[i]=rd;
	for(int i=1;i<=m;i++)d[i]=b[i]=rd;
	check();
	while(q--){
		for(int i=1;i<=n;i++)c[i]=a[i];
		for(int j=1;j<=m;j++)d[j]=b[j];
		ll x=rd,y=rd;
		while(x--){
			ll p=rd,o=rd;
			c[p]=o;
		}
		while(y--){
			ll p=rd,o=rd;
			d[p]=o;
		}
		check();
	}
	return 0;
}
