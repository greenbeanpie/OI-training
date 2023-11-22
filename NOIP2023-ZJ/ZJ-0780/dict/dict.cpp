#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[3005][3005],b[3005][3005];
int pre[3005],pre2[3005];
bool cmp(int x,int y){
	return x>y;
}
bool check(int x,int y){
	for(int i=1;i<=m;++i){
		if(a[x][i]<b[y][i]) return 1;
		if(a[x][i]>b[y][i]) return 0;
	}
	return 0;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			char c;
			scanf(" %c",&c);
			pre[j]=pre2[j]=c-'a'+1;
		}
		sort(pre+1,pre+m+1);
		sort(pre2+1,pre2+m+1,cmp);
		int now=0,pos=1;
		for(int j=1;j<=m;++j){
			a[i][pos]=a[i][pos]*30+pre[j];
			b[i][pos]=b[i][pos]*30+pre2[j];
			now++;
			if(now==5) now=0,pos++;
		} 
	}
	m=(m+4)/5;
	for(int i=1;i<=n;++i){
		bool chk=1;
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			if(!check(i,j)){
				chk=0;
				break;
			}
		}
		if(chk) printf("1");
		else printf("0");
	}
	
	return 0;
}
