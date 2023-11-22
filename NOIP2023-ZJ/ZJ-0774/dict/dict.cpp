#include<bits/stdc++.h>
using namespace std;
const int maxm = 3e3+5;
const int maxn =3e3+5;
int n,m,k,l,sum;
string s;
int ans[maxn];
int a[maxn][30];
bool flag=0;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		cin>>s;
		for(int j=0;j<m;++j)++a[i][(int)s[j]-'a'];
	}
	
	for(int i=1;i<=n;++i){
		ans[i]=1;
		for(int j=1;j<=n;++j){
			if(j==i)continue;
			k=0;l=25;sum=0;flag=0;
			while(sum<m){
				while(a[i][k]==0)++k;
				while(a[j][l]==0)--l;
				if(k<l){
					flag=1;
					break;
				}
				if(k>l){
					flag=0;
					break;
				}
				if(k==l){
					flag=0;
					break;
				}
			}
			if(flag==0){
				ans[i]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d",ans[i]);
	}
	
	printf("\n");
	return 0;
}
