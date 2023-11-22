#include<bits/stdc++.h>
using namespace std;
const int N =3010;
int cnt[N][27],n,m,mv[N],mx[N];
char str[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>str;
		for(int j=0;j<m;j++) cnt[i][str[j]-'a'+1]++;
		for(int j=1;j<=26;j++) if(cnt[i][j]>0){
			mv[i]=j;
			break;
		}
		for(int j=26;j>=1;j--) if(cnt[i][j]>0){
			mx[i]=j;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		bool suc=true;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(mx[j]<=mv[i]) suc=false;
		}
		if(suc) cout<<1;
		else cout<<0;
	}
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn

*/