#include<bits/stdc++.h>
using namespace std;
char w[3100][3100];
int t[3100],tt[3100];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",w[i]+1);
	for(int i=1;i<=n;i++)t[i]=0,tt[i]=100;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)t[i]=max(t[i],w[i][j]-'a'),tt[i]=min(tt[i],w[i][j]-'a');
	for(int i=1;i<=n;i++){
		int ans=1;
		for(int j=1;j<=n;j++){
			if(j!=i&&tt[i]>=t[j]){
				ans=0;
				break;
			}
		}
		printf("%d",ans);
	}
	return 0;
}