//long long
//bfs pop
//shuzukaixiao
//MLE
#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[3005][3005],smax[3005][3005],smin[3005][3005];
bool cmp1(char a,char b){
	return a<b;
}
bool cmp2(char a,char b){
	return a>b;
}
bool check(int x,int y){
	for(int i=1;i<=m;i++){
		if(smin[x][i]<smax[y][i]) return true;
		if(smin[x][i]>smax[y][i]) return false;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		sort(s[i]+1,s[i]+m+1,cmp1);
		for(int j=1;j<=m;j++){
			smin[i][j]=s[i][j];
		}
		sort(s[i]+1,s[i]+m+1,cmp2);
		for(int j=1;j<=m;j++){
			smax[i][j]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=false;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(check(i,j)==false){//i<j
				flag=true;
				break;
			}
		}
		if(flag==false) cout<<1;
		else cout<<0;
	}
	
	
	return 0;
}//9:05 90pts
