#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[3005];
int cnt[3005][30];
bool check(int a,int b){
	for(int i=1;i<=26;i++){
		if(cnt[a][i]){
			for(int j=26;j>=1;j--){
				if(cnt[b][j]){
					if(i<j)return true;
					return false;
				}
			}
		}
	}
	return false;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			cnt[i][s[j]-'a'+1]++;
		}
	}
	for(int i=1,pd;i<=n;i++){
		pd=1;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			if(!check(i,j))pd=0;
		}
		printf("%d",pd);
	}
	return 0;
}