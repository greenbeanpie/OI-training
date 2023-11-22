#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5,M=3e3+5;
char a[N][M];
int n,m,val[N][26],minval=-1;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;j++){
			val[i][a[i][j]-'a']++;
		}
		if(minval==-1){
			minval=i;
		}else{
			for(int j=1;j<=m;j++){
				if(a[i][j]==a[minval][j]){
					continue;
				}else if(a[i][j]<a[minval][j]){
					minval=i;
					break;
				}else{
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(minval==i){
			printf("1");
		}else{
			bool flag=false;
			for(int j=1;j<=m;j++){
				int x=a[minval][j]-'a';
				for(int k=0;k<x;k++){
					if(val[i][k]>0){
						flag=true;
						break;
					}
				}
				if(flag==true){
					break;
				}
				if(val[i][x]==0){
					break;
				}
				val[i][x]-=1;
			}
			if(flag==true){
				printf("1");
			}else{
				printf("0");
			}
		}
	}
	puts("");
	return 0;
}