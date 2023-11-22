#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using ULL=unsigned long long;
const int N=3009;
const ULL mod=11451419198102887ull;
ULL h1[N][N],h2[N][N];
char ch[N][N],c1[N][N],c2[N][N];
int n,m,ans[N];
inline bool check(int i,int j) {
	int l=0,r=m,res=0,mid;
	while(l<=r) {
		mid=l+r>>1;
		if(h1[i][mid]==h2[j][mid]) res=mid,l=mid+1;
		else r=mid-1;
	}
	if(res==m || c1[i][res+1]>c2[j][res+1])return true;
	return false;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%s",ch[i]+1);
		for(int j=1; j<=m; j++) c1[i][j]=c2[i][j]=ch[i][j];
		sort(c1[i]+1,c1[i]+1+m);
		sort(c2[i]+1,c2[i]+1+m,greater<char>());
		for(int j=1; j<=m; j++)
			h1[i][j]=h1[i][j-1]*mod+c1[i][j]-'a'+1,
			         h2[i][j]=h2[i][j-1]*mod+c2[i][j]-'a'+1;
	}
	for(int i=1; i<=n; i++) {
		int cf=1;
		for(int j=1; j<=n; j++) {
			if(i==j)continue;
			if(check(i,j)) {
				cf=0;
				break;
			}
		}
		ans[i]=cf;
	}
	for(int i=1; i<=n; i++) printf("%d",ans[i]);
	puts("");
	return 0;
}