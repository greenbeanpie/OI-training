#include<bits/stdc++.h>
using namespace std;
char a[3005][3005];
int n,m;
bool com(int x,int y){
	if(x<1)return 1;
	if(x>=1){
		if(a[x][m]<a[y][m])return 0;
		else return com(x-1,y);
	}
}
bool com1(int p,int q){
	if(p<1)return 1;
	if(p==q)return com(p-1,q);
	if(p>=1){
		if(a[q][1]==a[q][2]){
			if(a[p][1]>a[q][1])return com(p-1,q);
			else if(a[p][2]>a[q][2])return com(p-1,q);
			else return 0;
		}
		else if(a[q][1]!=a[q][2]){
		if(a[p][1]<a[q][1]){
			if(a[p][1]<a[q][2])return 0;
			else if(a[p][1]>a[q][2])return com(p-1,q);
			else if(a[p][1]==a[q][2]){
				if(a[p][2]<=a[q][1])return 0;
				else return com(p-1,q);
			}
		}
	    return com(p-1,q);
	}
}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(n==1&&m==1)cout<<"1";
	if(n!=1&&m==1){
		for(int i=1;i<=n;i++){
			if(com(n,i)==1)cout<<1;
			else cout<<0;
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(com1(n,i)==1)cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
