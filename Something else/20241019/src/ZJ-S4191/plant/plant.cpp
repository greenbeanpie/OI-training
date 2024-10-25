#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn];
int n,k;
int lesscnt(int x){
	return upper_bound(c+1,c+n+1,x)-c-1;
}
bool check(int x){
	int res=0;
	for(int i=1;i<=n;++i)
		res+=lesscnt((x-a[i])/b[i]);
	return res>=k;
}
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) scanf("%lld",a+i);
	for(int i=1;i<=n;++i) scanf("%lld",b+i);
	for(int i=1;i<=n;++i) scanf("%lld",c+i);
	scanf("%lld",&k);
	sort(c+1,c+n+1);
	int L=0,R=1.5e18,MID;
	while(L<R){
		MID=(L+R)>>1;
		if(check(MID)) R=MID;
		else L=MID+1;
	}
	printf("%lld",R);
} 
