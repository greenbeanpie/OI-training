#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e3+5;
int n,m;
char s1[N][N],s2[N][N];
ll c=131,h1[N][N],h2[N][N];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s1[i]+1),sort(s1[i]+1,s1[i]+1+m);
		copy(s1[i],s1[i]+1+m,s2[i]);
		reverse(s2[i]+1,s2[i]+1+m);
		for(int j=1;j<=m;j++)
			h1[i][j]=h1[i][j-1]*c+s1[i][j],
			h2[i][j]=h2[i][j-1]*c+s2[i][j];
	}
	for(int i=1;i<=n;i++){
		bool ok=1;
		for(int j=1;j<=n&&ok;j++) if(i!=j){
			int l=1,r=m,lcp=0;
			while(l<=r){
				int mid=(l+r)/2;
				if(h1[i][mid]==h2[j][mid]) lcp=mid,l=mid+1;
				else r=mid-1; 
			}
			ok&=lcp<m&&s1[i][lcp+1]<s2[j][lcp+1];
		}
		putchar(ok+'0');
	}
	puts("");
	return 0;
}
