#include <bits/stdc++.h>
#define N 3114
using namespace std;
string dc[N];
int n,m,t[26][N],mn[N],mx[N],vis[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){cin>>dc[i];}
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j){
			t[dc[i][j]-'a'][i]++;
		}
		for(int j=0;j<26;++j){
			if(t[j][i]!=0){
				mn[i]=j;
				break;
			}
		}
		for(int j=25;j>=0;--j){
			if(t[j][i]!=0){
				mx[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i)vis[i]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			if(mn[i]>mx[j])vis[i]=0;
			if(mn[i]<mx[j])continue;
			if(mn[i]==mx[j])vis[i]=0;
			if(vis[i]==0)break;
		}
	}
	for(int i=1;i<=n;++i){
		cout<<vis[i];
	}
	return 0;
	
}