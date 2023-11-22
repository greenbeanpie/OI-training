#include<bits/stdc++.h>
using namespace std;
char s[3005][3005];
char smax[3005][3005];
char smin[3005][3005];
string sxx[3005];
string sii[3005];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	//	cout<<n<<i<<endl;
		for(int j=0;j<m;j++){
			smax[i][j]=s[i][j];
			smin[i][j]=s[i][j];
		//	cout<<1<<smax[i][j]<<smin[i][j];
		}
		sort(smin[i],smin[i]+m);
		sort(smax[i],smax[i]+m,cmp);
		for(int j=0;j<m;j++){
			sxx[i]+=smax[i][j];
		//	cout<<1<<smax[i][j]<<smin[i][j];
			sii[i]+=smin[i][j];
		}
	}

	for(int i=0;i<n;i++){
		int pd=0;
		for(int j=0;j<n;j++){
			
			//cout<<i;
			if(j==i){
				continue;
			}
			if(sii[i]<sxx[j]){
				pd++;
			}
			
		}
	//	cout<<pd;
		if(pd==n-1){
			printf("1");
		}else{
			printf("0");
		}
	}
	return 0;
}
