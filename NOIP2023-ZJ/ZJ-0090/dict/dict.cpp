#include<bits/stdc++.h>
using namespace std;
int n,m;
char ch[3005];
int ton[3005][35],rk[3005];
bool cmp(int a1,int a2){
	for(int i=25;i>=0;i--){
		if(ton[a1][i]!=ton[a2][i]) return ton[a1][i]<ton[a2][i];
	}
	return 0;
}
int solve(int x,int y){
	if(!y) return 1;
	int mn=-1,mx=-1;
	for(int i=0;i<26&&mn<0;i++) if(ton[x][i]) mn=i;
	for(int i=25;i>=0&&mx<0;i--) if(ton[y][i]) mx=i;
//	printf("%d %d\n",mn,mx);
	return mn<mx;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		for(int j=0;j<m;j++) ton[i][ch[j]-'a']++;
		rk[i]=i;
	}
	sort(rk+1,rk+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(i!=rk[1]) putchar(solve(i,rk[1])+'0');
		else putchar(solve(i,rk[2])+'0');
	}
	return 0;
}