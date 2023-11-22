#include<bits/stdc++.h>
using namespace std;
const int N=3100;
int n,m,p[N][26],mi=1,sum=1;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		char c[N];
		scanf("%s",c);
		for (int j=0;j<m;++j){
			++p[i][c[j]-'a'];
		}
		if (i>1){
			int f=0;	//equal
			for (int j=25;j>=0;--j){
				if (p[i][j]<p[mi][j]){
					f=1;
					break;
				}
				if (p[i][j]>p[mi][j]){
					f=2;
					break;
				}
			}
			if (f==1){
				mi=i;
				sum=1;
			}
			if (f==0){
				++sum;
			}
		}
	}
	for (int i=1;i<=n;++i){
		if (i==mi&&sum==1){
			printf("1");
			continue;
		}
		int f=0,j=0,k=25;
		while (j<=k){
			while (!p[i][j]&&j<25) ++j;
			while (!p[mi][k]&&k>0) --k;
			if (j<k){
				f=1;
				break;
			}
			++j;--k;
		}
		if (f==1) printf("1");
		else printf("0");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
