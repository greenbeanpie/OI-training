#include<bits/stdc++.h>
#define ri int
using namespace std;
string s[3005];int n,m,pr[3005],nx[3005],mx[3005],mn[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ri i=1;i<=n;++i){
		cin>>s[i];mx[i]=-1;mn[i]=100;
		for(ri j=0;j<m;++j)mx[i]=max(mx[i],s[i][j]-'a'),mn[i]=min(mn[i],s[i][j]-'a');
	}
	pr[0]=nx[n+1]=100;
	for(ri i=1;i<=n;++i)pr[i]=min(pr[i-1],mx[i]);
	for(ri i=n;i;--i)nx[i]=min(nx[i+1],mx[i]);
	for(ri i=1;i<=n;++i)if(mn[i]<pr[i-1]&&mn[i]<nx[i+1])printf("1");else printf("0");
	return 0;
}
