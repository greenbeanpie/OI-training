#include<bits/stdc++.h>
using namespace std;
#define ll int
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
const ll N=3010;
ll n,m,a[N][N],mx[N][N],mn[N][N],ans[N];
char s[N][N];
bool cmp(ll x,ll y){return x>y;}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)a[i][j]=s[i][j]-'a';
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)mn[i][j]=mx[i][j]=a[i][j];
	for(ll i=1;i<=n;i++)sort(mn[i]+1,mn[i]+m+1);
	for(ll i=1;i<=n;i++)sort(mx[i]+1,mx[i]+m+1,cmp);
	for(ll i=1;i<=n;i++){
		ll cur=1;
		for(ll j=1;j<=n;j++){
			if(i==j)continue;
			if(mn[i][1]>=mx[j][1]){cur=0;break;}
		}
		ans[i]=cur;
	}
	for(ll i=1;i<=n;i++)printf("%d",ans[i]);
	puts("");return 0;
}