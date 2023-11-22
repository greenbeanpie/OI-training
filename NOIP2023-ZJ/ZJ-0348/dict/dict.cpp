#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[3010][3010];
int cnt[3010][26];
int c[26];
bool judge(int a,int b){
	int l,r;
	for(int i=25;~i;i--){
		if(cnt[b][i]){
			l=i;
			break;
		}	
	}
	for(int i=0;i<26;i++){
		if(cnt[a][i]){
			r=i;
			break;
		}	
	}
	if(l<=r)	return true;
	return false;
}
int base[26];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt[i][s[i][j]-'a']++;
		}
	}
	for(int i=1;i<=n;i++){
		int fl=1;
		for(int j=1;j<=n;j++){
			if(i==j)	continue;
			if(judge(i,j)){
				fl=0;
				break;
			}
		}
		printf("%d",fl);
	}
	return 0;
}