#include<bits/stdc++.h>
#define siz(x) int((x).size())
#define all(x) std::begin(x),std::end(x)
#define fi first
#define se second
using namespace std;
constexpr int N=3007;
int n,m;
string s[N],mn[N],mx[N],pre[N],suf[N];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		mn[i]=s[i];
		sort(all(mn[i]));
		mx[i]=s[i];
		sort(all(mx[i]),greater<char>{});
	}
	pre[1]=mx[1];
	for(int i=2;i<=n;i++)pre[i]=min(pre[i-1],mx[i]);
	suf[n]=mx[n];
	for(int i=n-1;i>=1;i--)suf[i]=min(suf[i+1],mx[i]);
//	for(int i=1;i<=n;i++)cout<<pre[i]<<'\n';
//	for(int i=1;i<=n;i++)cout<<suf[i]<<'\n';
	for(int i=1;i<=n;i++){
		int ans=1;
		if(1<i&&pre[i-1]<=mn[i])ans=0;
		if(i<n&&suf[i+1]<=mn[i])ans=0;
//		cout<<pre[i-1]<<' '<<mn[i]<<' '<<suf[i+1]<<'\n';
		cout<<ans;
	}
	return 0;
}
