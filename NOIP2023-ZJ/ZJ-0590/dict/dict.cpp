#include<bits/stdc++.h>
using namespace std;
int n,l,a[3105][35];char c[3105][3105];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		scanf("%s",c[i]);
		for(int j=0;j<l;j++)
			a[i][c[i][j]-96]++;
	}
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int p=1,q=26;
			for(;!a[i][p];p++);
			for(;!a[j][q];q--);
			if(p>=q){
				flag=1;
				printf("0");
				break;
			}
		}
		if(!flag)printf("1");
	}
	return 0;
}