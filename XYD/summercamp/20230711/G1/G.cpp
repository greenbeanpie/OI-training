#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[2000][10000];
//bool vis[2000][2000];
void fz(int x,int y,int m)
{
	if(m==1)
	{
		a[x][y]='/';
		a[x][y+1]='\\';
		a[x+1][y-1]='/';
		a[x+1][y]='_';
		a[x+1][y+1]='_';
		a[x+1][y+2]='\\';
		return;
	}
	int k=1<<(m-1),g=1<<(m-1);
	fz(x,y,m-1);
	fz(x+g,y-k,m-1);
	fz(x+g,y+k,m-1);
	return;
}
int main()
{
	scanf("%d",&n);
	 m=1<<n;
	 for(int i=0;i<=m;i++)
	 	for(int j=1;j<=2*m;j++)
	 		a[i][j]=' ';
	 fz(1,m,n);
	 for(int i=1;i<=m;i++){
	 	for(int j=1;j<=2*m;j++)
	 		printf("%c",a[i][j]);
	 	printf("\n");
	 }
	 
}