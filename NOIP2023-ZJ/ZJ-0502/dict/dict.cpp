#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m;
char s[N][N];
char maxs[N][N],mins[N][N];
pair<string,int> keeps[N];
inline bool comp(char a[],string b){
	for(int i=0;i<m;++i)
		if(a[i]<b[i])return 1;
		else if(a[i]>b[i])return 0;
	return 0;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;++i){
		sort(s[i]+1,s[i]+m+1);
		for(int j=1;j<=m;++j)mins[i][j]=s[i][j];
		for(int j=m;j>=1;--j)maxs[i][j]=s[i][m-j+1];
		keeps[i]=make_pair(maxs[i]+1,i);
	}
	sort(keeps+1,keeps+n+1);
	for(int i=1;i<=n;++i){
		int flag=0;
		if(keeps[1].second==i){
			if(comp(mins[i]+1,keeps[2].first))flag=1;
		}else{
			if(comp(mins[i]+1,keeps[1].first))flag=1;
		}
		printf("%d",flag);
	}
	return 0;
}