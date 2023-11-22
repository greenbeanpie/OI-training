#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,cnt,vis[N],ans[N];
char s[N][N];
struct P{
	char s[N];
	int id,flag;
}now[N<<1];
bool cmp(P a,P b){
	for(int i=1;i<=m;i++)
		if(a.s[i]!=b.s[i])return a.s[i]<b.s[i];
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i]+1;
	for(int i=1;i<=n;i++){
		sort(s[i]+1,s[i]+m+1);
		++cnt;
		for(int j=1;j<=m;j++)now[cnt].s[j]=s[i][j];
		now[cnt].id=i,now[cnt].flag=1;
		++cnt;
		reverse(s[i]+1,s[i]+m+1);
		for(int j=1;j<=m;j++)now[cnt].s[j]=s[i][j];
		now[cnt].id=i,now[cnt].flag=0;
	}
	sort(now+1,now+cnt+1,cmp);
	for(int i=cnt;i;i--){
		if(now[i].flag==0)vis[now[i].id]=1;
		else {
			bool flag=1;
			for(int j=1;j<=n;j++){
				if(now[i].id==j)continue;
				if(!vis[j])flag=0;
			}
			ans[now[i].id]=flag;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i];
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
