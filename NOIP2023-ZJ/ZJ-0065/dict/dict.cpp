#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char s[N][N];
bool cmp(char x,char y) {return x>y;}
int id=1;
int ans[N];
bool check(int x) {
	for(int i=1;i<=m;i++) {
		if(s[id][i]<s[x][i]) return true;
		if(s[id][i]>s[x][i]) return false;
	}
	return true;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		sort(s[i]+1,s[i]+m+1,cmp);
		if(i>1&&!check(i)) id=i;
	}
	ans[id]=1;
	for(int i=1;i<=n;i++) {
		if(i==id) continue;
		sort(s[i]+1,s[i]+m+1);
		if(!check(i)) ans[i]=1;
	}
	for(int i=1;i<=n;i++) {
		printf("%d",ans[i]);
	}
	return 0;
}
