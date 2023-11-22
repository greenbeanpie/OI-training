#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=3005;
ll n,m,w[maxn][maxn],minnum;
vector<ll> a[maxn],b[maxn],minn,mins;
bool operator <(vector<ll> a,vector<ll> b){
	ll n=min(a.size(),b.size());
	for(int i=0;i<n;i++){
		if(a[i]<b[i]) return 1;
		if(a[i]>b[i]) return 0;
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%lld%lld",&n,&m);getchar();
	for(int i=1;i<=n;getchar(),i++)
		for(int j=1;j<=m;j++) w[i][j]=getchar();
	for(int i=1;i<=n;i++){
		sort(w[i]+1,w[i]+m+1);
		for(int j=1;j<=m;j++) a[i].push_back(w[i][j]);
		for(int j=m;j>=1;j--) b[i].push_back(w[i][j]);
		if(minn.empty()||b[i]<minn) mins=minn,minn=b[i],minnum=0;
		if(b[i]==minn) minnum++;
	}
	for(int i=1;i<=n;i++)
		if(minnum==1&&minn<b[i]&&(mins.empty()||b[i]<mins)) mins=b[i];
	for(int i=1;i<=n;i++){
		if(a[i]<minn) printf("1");
		else if(minnum==1&&a[i]<mins&&b[i]==minn) printf("1");
		else printf("0");
	}
	printf("\n");
	return 0;
}
