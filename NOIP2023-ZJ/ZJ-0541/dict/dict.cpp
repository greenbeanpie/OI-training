#include <bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int String[N][27];
bool exist[N][27];
int ans[N],n,m;
char read[N];
int main()
{
 freopen("dict.in","r",stdin);
 freopen("dict.out","w",stdout);
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
 	scanf("%s",read);
 	for(int j=0;j<m;j++)
 		String[i][read[j]-'a'+1]++;
 }
 if(n==1)
 {
 	printf("1\n");
 	return 0;
 }
 for(int i=1;i<=n;i++)
 	for(int j=26;j>=1;j--)
 		exist[i][j]|=String[i][j+1],exist[i][j]|=exist[i][j+1];
 for(int i=1;i<=n;i++)
 {
 	int Min=26;	ans[i]=1;
 	for(Min=1;Min<=26;Min++)
 		if(String[i][Min])	break;
	for(int j=1;j<=n;j++)
		if(i!=j&&exist[j][Min]==false)	ans[i]=0,j=1e9;
 }
 for(int i=1;i<=n;i++)	printf("%d",ans[i]);
 printf("\n");
 return 0;
}