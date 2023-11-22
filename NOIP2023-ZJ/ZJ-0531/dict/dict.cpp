#include<iostream>
using namespace std;
const int N=3000;
int mn[N+5],mx[N+5];
int tong[30];
int n,m;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	char t[N+5];
	for(int i=1;i<=n;i++){
		scanf("%s",t);
		int minn=27,maxx=-1;
		for(int j=0;j<m;j++){
			minn=min(minn,t[j]-'a');
			maxx=max(maxx,t[j]-'a');
		}
		++tong[maxx];
		mn[i]=minn,mx[i]=maxx;
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=mn[i]+1;j<=27;j++){
			cnt+=tong[j];
		}
		if(mn[i]<mx[i])--cnt;
		printf("%d",(cnt==n-1? 1:0));
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}