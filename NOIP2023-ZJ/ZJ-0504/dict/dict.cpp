#include<bits/stdc++.h>
using namespace std;
int n,m,flag;
char s[3010][3010],ss[3010][3010],ma,a[3010],b[3010],mi;
int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;
	return x*f;
}
void write(int x){
	if (x<0) x=-x,putchar('-');
	if (x<10) putchar(x+48);
	if (x==0) return;
	write(x/10); 
}
bool cmp(char a,char b){
	return a>b;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();
	if (n==1){
		printf("1\n");
		return 0;
	}
	ma='z';mi='a';
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		int len=strlen(s[i]+1);
		a[i]='z';
		b[i]='a';
		for(int j=1;j<=len;j++){
			if (s[i][j]<a[i]) a[i]=s[i][j];
			if (s[i][j]>b[i]) b[i]=s[i][j];
			ss[i][j]=s[i][j];
		}
		if (a[i]<ma) ma=a[i];
		if (b[i]>mi) mi=b[i];
	}
//	for(int i=1;i<=n;i++) printf("%c ",a[i]);
//	printf("%c\n",ma);
	for(int i=1;i<=n;i++){
		if (a[i]>mi) {
			printf("0");
			continue;
		}
		flag=2;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
			s[j][k]=ss[j][k];
		sort(s[i]+1,s[i]+1+m);
//		for(int j=1;j<=m;j++) printf("%c",s[i][j]);
//		printf("\n");
		for(int j=1;j<=n;j++)
			if (j!=i) {
				sort(s[j]+1,s[j]+1+m,cmp);
				for(int k=1;k<=m;k++)
					if (s[i][k]==s[j][k]) continue;
					else if (s[i][k]<s[j][k]) {
						flag=1;
						break;
					}
					else if (s[i][k]>s[j][k]){
						flag=0;
						break;
					}
				if (flag==0) break;
			}
		printf("%d",flag);
	}
	return 0;//80pts?
}
