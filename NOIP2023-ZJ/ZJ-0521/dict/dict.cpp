#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int n,m,mx[N],mn[N][N],MX[N][N],a[N],k;
char c[N];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(mx,0x3f,sizeof mx);
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		for(int j=1;j<=m;j++)a[j]=c[j]-'a';
		sort(a+1,a+1+m,cmp);
		for(int j=1;j<=m;j++)
			if(a[j]>mx[j])break;
			else if(a[j]<mx[j]){
				k=i;
				for(int x=j;x<=m;x++)mx[x]=a[x];
				break;
			}
		for(int j=m;j>=1;j--)mn[i][m-j+1]=a[j],MX[i][j]=a[j];
	}
	if(n==1){printf("1");return 0;}
	for(int i=1;i<=n;i++){
		int ans=0;
		if(i==k){
			ans=1;
			for(int j=1;j<=n;j++){
				int sum=0;
				if(j==k)continue;
				for(int x=1;x<=m;x++)
					if(MX[j][x]>mn[i][x])break;
					else if(MX[j][x]==mn[i][x])sum++;
				if(sum==m){ans=0;break;}
			}
			printf("%d",ans);
			continue;
		}
		for(int j=1;j<=m;j++)
			if(mn[i][j]<mx[j]){ans=1;break;}
			else if(mn[i][j]>mx[j])break;
		printf("%d",ans);
	}
	return 0;
}