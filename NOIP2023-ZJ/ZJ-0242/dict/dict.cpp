#include<bits/stdc++.h>
using namespace std;
const int N=3005,P=131;
typedef unsigned long long ull;
//bool be;
int n,m;
char s[N][N],mi[N][N],ma[N][N];
ull a[N],hsh[N][N];
//bool en;
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			hsh[i][j]=hsh[i][j-1]*P+ma[i][j];
		}
	}
	return;
}
int main(){
//	printf("%d\n",(&en-&be)/1024/1024);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			mi[i][j]=ma[i][j]=s[i][j];
		}
		sort(mi[i]+1,mi[i]+m+1);
		sort(ma[i]+1,ma[i]+m+1,greater<char>());
	}
	init();
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=m;j++){
			a[j]=a[j-1]*P+mi[i][j];
		}
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int l=1,r=m,res=0;
			while(l<=r){
				int mid=l+r>>1;
				if(hsh[j][mid]==a[mid]){
					res=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			if(res==m||ma[j][res+1]<=a[res+1]){
				flag=0;
				break;
			}
		}
		printf("%d",flag);
	}
	return 0;
}