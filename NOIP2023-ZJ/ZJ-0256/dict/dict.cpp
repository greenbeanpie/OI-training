#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m;
int sum[N][30];
bool cmp(int x,int y){
	return x>y;
}
bool check(int x,int y){
	int i,j,s1,s2;
	for(i=0;i<26;i++) if(sum[x][i]){
		s1=i;break;
	}
	for(i=25;i>=0;i--) if(sum[y][i]){
		s2=i;break;
	}
	if(s1<s2) return 1;
	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			char c;
			cin>>c;
			sum[i][c-'a']++;
		}
	}
	for(i=1;i<=n;i++){
		int f=1;
		for(j=1;j<=n;j++){
			if(i==j) continue;
			f=f&check(i,j);
			if(!f) break;
		}cout<<f;
	}
}
