#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
int n,m,id,Max[30],tt[30],s[maxn][30];
char a[maxn][maxn],b[maxn],c[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void check(int k){
	bool flg=0;
	for(int i=26;i;i--)
	if(s[k][i]<Max[i]){flg=1;break;}
	else if(s[k][i]>Max[i])break;
	
	if(flg){
		id=k;
		for(int i=1;i<=26;i++)Max[i]=s[k][i];
	}
}
void check2(int k){
	bool flg=0;
	for(int i=26;i;i--)
	if(s[k][i]<tt[i]){flg=1;break;}
	else if(s[k][i]>tt[i])break;
	
	if(flg)for(int i=1;i<=26;i++)tt[i]=s[k][i];
}
void calc(int k){
	bool flg=0;
	int j=26;
	while(!Max[j])j--;
	for(int i=1;i<=26;i++){
		if(!s[k][i])continue;
		if(i<j){flg=1;break;}
		else break;
	}
	flg?putchar('1'):putchar('0');
}
void CALC(int k){
	bool flg=0;
	memset(tt,63,sizeof tt);
	for(int i=1;i<=n;i++)if(i!=k)check2(i);
	int j=26;
	while(!tt[j])j--;
	for(int i=1;i<=26;i++){
		if(!s[k][i])continue;
		if(i<j){flg=1;break;}
		else break;
	}
	flg?putchar('1'):putchar('0');
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)s[i][a[i][j]-'a'+1]++;
	memset(Max,63,sizeof Max);
	for(int i=1;i<=n;i++)check(i);
	for(int i=1;i<=n;i++)if(i!=id)calc(i);else CALC(i);
	return 0;
}