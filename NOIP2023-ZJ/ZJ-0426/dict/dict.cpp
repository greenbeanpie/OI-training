#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char map[3005][3005];
bool cmp(char i,char j){
	return i<j;
}
char minn[3005][3005],maxn[3005][3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			char ch;
			cin>>ch;
			map[i][j]=ch;
		}
		sort(map[i]+1,map[i]+1+m,cmp);
		for(int j=1;j<=m;j++){
			minn[i][j]=map[i][j];
			maxn[i][m-j+1]=map[i][j];
		}
	}
	for(i=1;i<=n;i++){
		int yes=1;
		for(j=1;j<=n;j++){
			if(i==j) continue;
			int ok=0;
			for(int k=1;k<=m;k++){
				if(maxn[j][k]>minn[i][k]){
					ok=1;
					break;
				}
				else if(maxn[j][k]<minn[i][k]){
					ok=0;
					break;
				} 
			}
			
			if(ok==0){
				cout<<0;
				yes=0;
				break;
			}
		}
		if(yes) cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}