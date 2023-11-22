#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define ll long long
using namespace std;
char s[3005][3005];
int n,m;
int tmp[3005],ch[9000005][30],mn[9000005];
int cnt=1;
void ins(){
	int u=1;
	For(i,1,m){
		if(!ch[u][tmp[i]]) ch[u][tmp[i]]=++cnt,mn[u]=min(mn[u],tmp[i]);
		u=ch[u][tmp[i]];
	}
}
bool query(){
	int u=1;
	For(i,1,m){
		//cout<<u<<" "<<mn[u]<<" "<<tmp[i]<<endl;
		if(mn[u]<tmp[i]) return 0;
		u=ch[u][tmp[i]];
	} return 1;
}
bool cmp(int a,int b){
	return a>b;
}
const int M=30;
void solve(){
	For(i,0,9000000) mn[i]=M;
	 cin>>n>>m;
	For(i,1,n) cin>>s[i]+1;
	For(i,1,n){
		For(j,1,m) tmp[j]=s[i][j]-'a';
		sort(tmp+1,tmp+m+1,cmp);
		ins();
	}
	For(i,1,n){
		For(j,1,m) tmp[j]=s[i][j]-'a';
		sort(tmp+1,tmp+m+1);
		cout<<query();
	}
}
signed main(){
	freopen("dict.in","r",stdin); freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	solve();
	return 0;
}