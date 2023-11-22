#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3010;
int n,m;
char w[N][N],s[N][N],mx1[N],mx2[N];
bool cmp(char a[],char b[]){
	for(int i=0;i<m;i++)
		if(a[i]<b[i]) return 1;
		else if(a[i]>b[i]) return 0;
	if(a[m-1]==b[m-1]) return 0;
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",&w[i]);
	if(n==1) printf("1\n");
	else if(m==1){
		char mn='z'+1;
		for(int i=1;i<=n;i++) mn=min(mn,w[i][0]);
		int pos=0;
		for(int i=1;i<=n;i++){
			if(w[i][0]==mn&&pos==0) pos=i;
			else if(w[i][0]==mn) pos=n+1;
		}
		for(int i=1;i<=n;i++)
			if(i==pos) printf("1");
			else printf("0");
		printf("\n");
	}
	else{
		for(int i=1;i<=n;i++){
			sort(w[i],w[i]+m);
			for(int j=0;j<m;j++) s[i][j]=w[i][m-j-1];
		}		
		int m1=1,m2=1;
		for(int i=2;i<=n;i++){
			if(cmp(s[i],s[m1])) m2=m1,m1=i;
			else if(cmp(s[i],s[m2])) m2=i;
		}
		for(int i=1;i<=n;i++){
			int a=cmp(w[i],s[m2]),b=cmp(w[i],s[m1]);
			if(i==m1) printf("%d",a);
			else printf("%d",b);
		}
		printf("\n");
	}
	return 0;
}

