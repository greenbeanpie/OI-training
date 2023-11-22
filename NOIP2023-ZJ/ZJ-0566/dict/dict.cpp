#include <bits/stdc++.h>
using namespace std;
int n,m,a[3005][30];
int sum[3005][30];
int book[3005];
string s;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++)a[i][s[j]-'a'+1]++;
		for(int j=26;j>=1;j--)sum[i][j]=sum[i][j+1]+a[i][j];
	}
	if(n==1)printf("1");else{
	for(int i=1;i<=n;i++){
		bool boo=0;
		memset(book,0,sizeof(book));
		for(int j=1;j<=26;j++)if(a[i][j]>0){
			int t=0;
			for(int k=1;k<=n;k++)if(k!=i){
				if(sum[k][j+1]>0){
					book[k]=2;
					continue;
				} 
				if(sum[k][j]<a[i][j]){
					book[k]=1;
					t=1;
					break;
				}
				t=2;
			}
			if(t!=2){
				boo=1-t;
				break;
			}
		}
		if(boo)printf("1");else printf("0");
	}
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}