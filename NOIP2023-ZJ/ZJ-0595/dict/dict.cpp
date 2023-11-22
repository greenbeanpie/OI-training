#include<bits/stdc++.h>
using namespace std;
int n,l,a[3002][30];char c[3002];
struct q{
	int a,b=-1,c,d;
}b[3002];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
	 scanf("%s",c);
	 for(int j=0;j<l;j++)a[i][c[j]-'a']++;
	}
//	for(int i=1;i<=n;i++){
//	 for(int j=0;j<26;j++){
//	  printf("%d  ",a[i][j]);
//	 }
//	 printf("\n");
//	}
	for(int i=1;i<=n;i++){
	 bool f=0;
	 for(int j=0;j<26;j++){
	  if(a[i][j]!=0){
	   if(f==0)f=1,b[i].a=j,b[i].c=a[i][j];
	   else b[i].b=j,b[i].d=a[i][j];
	  }
	 }
	 if(b[i].b==-1)b[i].b=b[i].a,b[i].d=b[i].c;
	}
//	for(int i=1;i<=n;i++)
//	 printf("%d %d %d %d\n",b[i].a,b[i].b,b[i].c,b[i].d);
	memset(c,'1',sizeof(c));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	 if(i!=j&&(b[i].a>b[j].b||b[i].a==b[j].b&&b[i].c>=b[j].d)){
	  c[i]='0';
	  break;
	 }
	for(int i=1;i<=n;i++)printf("%c",c[i]);
	return 0;
}/*4 7
abandon
bananaa
baannaa
notnotn
*/