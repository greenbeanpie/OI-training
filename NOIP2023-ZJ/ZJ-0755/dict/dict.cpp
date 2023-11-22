#include<bits/stdc++.h>
using namespace std;


int n,m;
char s[3500][3500];
int a[3500][3500];
bool b[3500];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	cin>>n>>m;
	if(n==1){cout<<1; return 0;}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
			a[i][j]=s[i][j]-'a';
		}
	}
	for(int i=1;i<=n;i++){
		sort(a[i]+1,a[i]+m+1,cmp);
	}
	for(int k=1;k<=n;k++){
		bool flag=true;
		memset(b,0,sizeof(b));
		
		reverse(a[k]+1,a[k]+1+m);
		
		for(int j=1;j<=m;j++){
			if(!flag) break;
			
			for(int i=1;i<=n;i++){
				if(i==k) continue;
				if(b[i]) continue;
				if(a[k][j]<a[i][j]){
					b[i]=1;
					continue;
				}
				if(a[k][j]>a[i][j]){
					flag=0;
					break;
				}
			}
		}
		
		reverse(a[k]+1,a[k]+1+m);
		if(flag)cout<<1;
		else cout<<0;
	}
	return 0;
}
