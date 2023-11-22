#include<bits/stdc++.h>
#define ll long long
#define N 3005
using namespace std;
int n,m;
struct Dict{
	char wd[N];
	int id;
	bool f;
}dc[N<<1];
inline bool cmp(Dict x,Dict y){
	for(int i=1;i<=m;i++)
		if(x.wd[i]!=y.wd[i]) return x.wd[i]<y.wd[i];
	if(y.id-x.id==n) return 1;
	if(x.id-y.id==n) return 0;
	if(x.f&&!y.f) return 1;
	if(y.f&&!x.f) return 0;
	return 1;
}
int ans[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",dc[i].wd+1);
		sort(dc[i].wd+1,dc[i].wd+m+1);
		dc[i].f=0; dc[i].id=i;
		for(int j=1;j<=m;j++)
			dc[i+n].wd[j]=dc[i].wd[m-j+1];
		dc[i+n].f=1; dc[i+n].id=i+n;
	}
	sort(dc+1,dc+n*2+1,cmp);
	int cnt=0;
	for(int i=1;i<=n*2;i++){
		if(dc[i].f) cnt++;
		else{
			if(cnt==0) ans[dc[i].id]=1;
			else ans[dc[i].id]=0;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d",ans[i]);
	return 0;
}