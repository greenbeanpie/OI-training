//Y@T2L32#
#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char s[N],mn[N],mx[N],mnx='z'+1,mnx2='z'+1;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		mx[i]=0,mn[i]='z'+1;
		for(int j=1;j<=m;j++)
			mx[i]=max(mx[i],s[j]),mn[i]=min(mn[i],s[j]);
		if(mx[i]<mnx)mnx2=mnx,mnx=mx[i];
		else if(mx[i]<mnx2)mnx2=mx[i];
		mnx=min(mnx,mx[i]);
		//printf("%c %c\n",mn[i],mx[i]);
	}
	for(int i=1;i<=n;i++)
		printf("%d",mn[i]<mnx||(mx[i]==mnx&&mn[i]<mnx2));
	printf("\n");
	return 0;
}