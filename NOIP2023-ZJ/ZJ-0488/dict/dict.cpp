#include<bits/stdc++.h>
using namespace std;
const int N=3010;
char a[N][N];
int b[N][N];
int c[N][N];
bool flag;
bool f;
int n,m;
int tmp(int a,int b){
	return a>b;
}
bool bijiao(int a[],int b[],int n){
	for(int i=1;i<=n;i++){
		if(a[i]==b[i])continue;
		else if(a[i]<b[i])return 1;
		else return 0;
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			b[i][j]=int(a[i][j]);
			c[i][j]=int(a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		sort(b[i]+1,b[i]+1+m);
		sort(c[i]+1,c[i]+1+m,tmp);
	}
	for(int i=1;i<=n;i++){
		flag=1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(bijiao(b[i],c[j],m)==0){
				flag=0;
				break;
			}
		}
		if(flag==0)printf("0");
		else printf("1");
	}
}