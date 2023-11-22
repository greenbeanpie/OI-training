#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define MP make_pair
#define pii pair<int,int>
using namespace std;
constexpr int N=3005;
int n,m,cnt[30],p[N<<1];
bool flg[N],ans[N];
vector<pii> a[N<<1];
string ch;
bool check(int x,int y){
	for(int i=0;i<min((int)a[x].size(),(int)a[y].size());i++)
		if(a[x][i]!=a[y][i])return 0;
	return 1;
}
bool cmp(int x,int y){
	int siz1=(int)a[x].size(),siz2=(int)a[y].size();
	for(int i=0;i<min(siz1,siz2);i++){
		if(a[x][i].fi>a[y][i].fi)return 1;
		if(a[x][i].fi<a[y][i].fi)return 0;
		if(a[x][i].se<a[y][i].se){
			if(a[x][i+1].fi>a[y][i].fi)return 1;
			else return 0;
		}
		else{
			if(a[y][i+1].fi>a[x][i].fi)return 0;
			else return 1;
		}
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<m;j++)cnt[int(ch[j]-'a')]++;
		for(int j=0;j<26;j++)
			if(cnt[j])a[i].pb(MP(j,cnt[j]));
		for(int j=25;j>=0;j--)
			if(cnt[j])a[i+n].pb(MP(j,cnt[j]));
		p[i]=i,p[i+n]=i+n;
	}
	sort(p+1,p+n*2+1,cmp);
	for(int i=1,j,now=0;i<=n*2;i=j+1){
		for(j=i;j<n*2&&check(p[j+1],p[i]);j++);
		for(int k=i;k<=j;k++)
			if(p[k]<=n&&now-flg[p[k]]==n-1)ans[p[k]]=1;
		for(int k=i;k<=j;k++)
			if(p[k]>n)flg[p[k]-n]=1,now++;
	}
	for(int i=1;i<=n;i++)cout<<ans[i];
	cout<<'\n';
	return 0;
}