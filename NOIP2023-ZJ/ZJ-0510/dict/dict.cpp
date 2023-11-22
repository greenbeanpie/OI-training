#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,id=1,cnt[155];
char mn[N],t[N];
char s[N][N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);


//	freopen("dict4.in","r",stdin);
//	freopen("my.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int o=1;o<=m;o++) ++cnt[s[i][o]];
		int j=0;
		for(int o='z';o>='a';o--)
			while(cnt[o]) s[i][++j]=o,--cnt[o];
		
		if(i==1) for(int o=1;o<=m;o++) mn[o]=s[i][o];
		else {
			if(strcmp(s[i]+1,mn+1)<0){
				id=i;
				for(int o=1;o<=m;o++) mn[o]=s[i][o];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int o='a';o<='z';o++) cnt[o]=0;
		for(int o=1;o<=m;o++) ++cnt[s[i][o]];
		int j=0;
		for(int o='a';o<='z';o++)
			while(cnt[o]) t[++j]=o,--cnt[o];
		if(i==id) printf("1");
		else if(strcmp(t+1,mn+1)<0) printf("1");
		else printf("0");
	}
	return 0;
}
/*
437 494
*/