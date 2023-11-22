#include<bits/stdc++.h>
using namespace std;
int a[3550][30];//3331=mx1,3332=mx2,3333=mn1,3334=mn2
int n,m;
int lw(int x,int y){
	for(int i=25;i>=0;i--){
		if(a[x][i]<a[y][i])return 1;
		if(a[x][i]>a[y][i])return 0;
	}
	return 1;
}
bool cmp(int x,int y){
	int i=0,j=25;
	while(!a[x][i])++i;
	while(!a[y][j])--j;
	return i<j;
}
void gv(int x,int y){
	for(int i=0;i<=25;i++)
		a[y][i]=a[x][i];
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	char c;
	c=getchar();
	a[3331][25]=m;a[3332][25]=m;
	for(int i=1;i<=n;i++){
		while(!isalpha(c))c=getchar();
		while(isalpha(c)){
			++a[i][c-'a'];
			c=getchar();
		}
	}
	for(int i=1;i<=n;i++){
		if(lw(i,3331)){
			gv(3331,3332);
			gv(i,3331);
		}
		else if(lw(i,3332))
			gv(i,3332);
	}
	for(int i=1;i<=n;i++){
		if(!cmp(i,3331)){
			printf("0");
		}
		else printf("1");
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<=25;j++){
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}
	for(int j=0;j<=25;j++)cout<<a[3331][j]<<' ';cout<<endl;
	for(int j=0;j<=25;j++)cout<<a[3332][j]<<' ';cout<<endl;
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
