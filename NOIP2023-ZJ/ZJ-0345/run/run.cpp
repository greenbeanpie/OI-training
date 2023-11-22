#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,k,d,ans;
struct RP{
	int x,y,z;
	bool operator<(const RP&plasplas)const{return y<plasplas.y;}
}a[100005];
int read(){
	int ret=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
#undef int
int main(){
#define int long long
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	while(q--){
		n=read(),m=read(),k=read(),d=read();ans=0;
		for(int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
		sort(a+1,a+1+m);
		int cnt=0;
		for(int i=1;i<=m;i++){
			if(a[i].y>a[i].x) continue;
		}
		printf("%lld\n",ans);
	}
//	printf("\n%lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
