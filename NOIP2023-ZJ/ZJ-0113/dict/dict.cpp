#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,m;
char s[N][N],minc[N],maxc[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		minc[i]='z',maxc[i]='a';
		for(int j=1;j<=m;j++){
			minc[i]=min(minc[i],s[i][j]);
			maxc[i]=max(maxc[i],s[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(maxc[j]<=minc[i])
				{flag=false;break;}
		}
		cout<<flag;
	}
	return 0;
}
