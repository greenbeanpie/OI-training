#include<bits/stdc++.h>
using namespace std;
const int N=3005;
char p[N];
int n,m;
int tot[N][35];
bool comp(int x,int y){//x zheng y fan
	int nowx,nowy;
	for(int i=1;i<=26;i++){
		if(tot[x][i]){
			nowx=i;
			break;
		}
	}
	for(int i=26;i>=1;i--){
		if(tot[y][i]){
			nowy=i;
			break;
		}
	}
	if(nowx>nowy)	return 1;
	if(nowy>nowx)	return 0;
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	int siz=0;
	for(int i=1;i<=n;i++){
		scanf("%s",p+1);
		for(int j=1;j<=m;j++)	tot[i][p[j]-'a'+1]++;
	}
	for(int i=1;i<=n;i++){
		bool yes=1;
		for(int j=1;j<=n;j++){
			if(i==j)	continue;
			if(comp(i,j)){
				yes=0;
				break;
			}
		}
		cout<<yes;
	}
	return 0;
}/*
2 2
aa
aa
*/
