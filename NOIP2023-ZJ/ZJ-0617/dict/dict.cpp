#include <bits/stdc++.h>
using namespace std;
int n,m,mini[3030],maxi[3030],mmm[3030];
char a[3030][3030];
char minx[3030],maxx[3030];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		char x='z',y='a';
		for (int j=1;j<=m;j++){
			cin>>a[i][j];
			if (a[i][j]<x){
				x=a[i][j];
				mini[i]=j;
			}
			if (a[i][j]>y){
				y=a[i][j];
				maxi[i]=j;
			}
		}
		minx[i]=x;
		maxx[i]=y;
	}
	if(n==1){
		cout<<"1";
	}else if(m==1){
		int mm=1;
		for (int i=1;i<=n;i++){
			if(minx[i]<minx[mm]){
				mm=i;
			}
		}
		for (int i=1;i<=n;i++){
			if(i==mm){
				cout<<'1';
			}else{
				cout<<'0';
			}
		}
	}else{
		for (int i=1;i<=n;i++){
			int bj=1;
			for (int j=1;j<=n;j++){
				if(minx[i]>maxx[j]){
					bj=0;
					break;
				}
			}
			mmm[i]=bj;
		}
		for (int i=1;i<=n;i++){
			cout<<mmm[i];
		}
	}
	return 0;
}