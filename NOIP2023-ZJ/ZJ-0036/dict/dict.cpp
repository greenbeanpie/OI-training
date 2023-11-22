//T#YMS@4
//Y@T2L32#
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3003;
const int P=131;
const int Mod1=1e9+7,Mod2=1e9+9;

int n,m;
char S[N];
int a[N][N];
int h1[N][N],h2[N][N];

int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%s",S+1);
		for(int j=1;j<=m;j++) a[i][j]=S[j]-'a'+1;
		sort(a[i]+1,a[i]+1+m,greater<int>());
		for(int j=1;j<=m;j++) h1[i][j]=(1ll*h1[i][j-1]*P%Mod1+a[i][j])%Mod1,h2[i][j]=(1ll*h2[i][j-1]*P%Mod2+a[i][j])%Mod2;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) a[0][j]=a[i][j];
		sort(a[0]+1,a[0]+1+m);
		for(int j=1;j<=m;j++) h1[0][j]=(1ll*h1[0][j-1]*P%Mod1+a[0][j])%Mod1,h2[0][j]=(1ll*h2[0][j-1]*P%Mod2+a[0][j])%Mod2;
		bool flag=1;
		for(int j=1;j<=n;j++) {
			if(i==j) continue;
			int L=1,R=m,mid,res=0;
			while(L<=R) {
				mid=L+R>>1;
				if(h1[0][mid]==h1[j][mid] && h2[0][mid]==h2[j][mid]) res=mid,L=mid+1;
				else R=mid-1;
			}
			if(a[0][res+1]>=a[j][res+1]) {
				flag=0;
				break;
			}
		}
		printf("%d",flag);
	}
	return 0;
}
//8:55
