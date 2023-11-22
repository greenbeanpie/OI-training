#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,cnt[N][30],mn[N],mx[N];
char s[N][N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i]+1);
		for(int j = 1; j <= m; j++) cnt[i][s[i][j]-'a']++;
		for(int j = 0; j <= 25; j++)
			if(cnt[i][j]){
				mn[i]=j;
				break;
			}
		for(int j = 25; j >= 0; j--)
			if(cnt[i][j]){
				mx[i]=j;
				break;
			}
	}	
	if(n==1){
		printf("1");
	}else{
		for(int i = 1; i <= n; i++){
			bool flag=1;
			for(int j = 1; j <= n; j++){
				bool f=1;
				if(i!=j){
					if(mn[i]>=mx[j]) f=0;
				}
				if(f==0) flag=0;
			}
			if(flag) printf("1");
			else printf("0");
		}
	}
	return 0;
}
