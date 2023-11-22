#include<bits/stdc++.h>
using namespace std;
int n,m,i,flag,j;
char a[3010][3010],b[3010][3010];
bool pd(int x,int y){
	int i;
	for(i=1;i<=m;i++){
		if(a[x][i]<b[y][i])return 1;
		if(a[x][i]>b[y][i])return 0;
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i]+1;
		sort(a[i]+1,a[i]+1+m);
		for(j=1;j<=m;j++)b[i][j]=a[i][m-j+1];
	}
	for(i=1;i<=n;i++){
		flag=1;
		for(j=1;j<=n;j++){
			if(j==i)continue;
			if(!pd(i,j)){
				flag=0;
				break;
			}
		}
		cout<<flag;
	}
	return 0;
}