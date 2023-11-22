#include<bits/stdc++.h>
using namespace std;
int n,m,mn;
char a[3005][3005],c[3005];
bool fl;
bool check(int x){
	for(int i=1;i<=m;i++){
		if(a[x][m-i+1]<c[i])return 1;
		if(a[x][m-i+1]>c[i])return 0;
	}
	return 0;
}
int check2(int x){
	for(int i=1;i<=m;i++){
		if(a[x][i]<c[i])return 1;
		if(a[x][i]>c[i])return 0;
	}
	return 0;
}
int chk(int x){
	for(int i=1;i<=n;i++)
		if(i!=x){
			fl=0;
			for(int j=1;j<=m;j++){
				if(a[x][j]<a[i][m-j+1]){fl=1;break;}
				if(a[x][j]>a[i][m-j+1])return 0;
			}
			if(!fl)return 0;
		}
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m,mn=1;
	for(int i=1;i<=n;i++)
		cin>>a[i]+1,sort(a[i]+1,a[i]+m+1);
	for(int i=1;i<=m;i++)c[i]=a[1][m-i+1];
	for(int i=2;i<=n;i++)
		if(check(i)){
			for(int j=1;j<=m;j++)c[j]=a[i][m-j+1];
			mn=i;
		}
	for(int i=1;i<=n;i++){
		if(mn==i)cout<<chk(i);
		else cout<<check2(i);
	}
}