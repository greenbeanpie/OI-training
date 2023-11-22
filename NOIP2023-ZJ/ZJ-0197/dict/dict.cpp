#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int n,m,sum,lst,minn[maxn];
char s[maxn][maxn];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) sort(s[i]+1,s[i]+1+m);
	for(int i=1;i<=m;i++) minn[i]=s[1][m-i+1];
	sum=1,lst=1;
	for(int i=2;i<=n;i++){
		int b=2;
		for(int j=1;j<=m;j++) if(minn[j]<s[i][m-j+1]){b=1;break;}else if(minn[j]>s[i][m-j+1]){b=0;break;}
		if(b==2){
			bool p=1;
			for(int j=1;j<=m;j++) if(minn[j]!=minn[m-j+1]){b=0;break;}
			if(p) sum++;continue;
		}
		if(b) continue;sum=1;lst=i;
		for(int j=1;j<=m;j++) minn[j]=s[i][m-j+1];
	}
	for(int i=1;i<=n;i++){
		if(sum>1){printf("0");continue;}
		if(i==lst){printf("1");continue;}
		bool b=1;
		for(int j=1;j<=m;j++) if(s[i][j]<minn[j]){b=1;break;}else if(s[i][j]>minn[j]){b=0;break;}
		if(!b) printf("0");
		else printf("1");
	}
	return 0;
}