#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,i,j,p,mi[N],ma[N];
char s[3005][3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(i=1;i<=n;i++){
		mi[i]='z';ma[i]='a';
		for(j=1;j<=m;j++)ma[i]=max(ma[i],int(s[i][j])),mi[i]=min(mi[i],int(s[i][j]));
	}
	for(i=1;i<=n;i++){
		p=1;
		for(j=1;j<=n;j++)
			if(i!=j&&mi[i]>=ma[j]){p=0;break;}
		printf("%d",p);
	}
	return 0;
}
