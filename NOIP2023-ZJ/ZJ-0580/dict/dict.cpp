#include<bits/stdc++.h>
using namespace std;
int n,m,ji;
string c1[3005];
char c[3005][3005];
char b[3005];
bool cmp1(char a,char b){
	return a<b;
}
bool pan(int x){
	/*int y[3005];
	for(int i=1;i<=m;i++){
		y[i]=c[k][i];
	}*/
	sort(c[x]+1,c[x]+1+m,cmp1);
	for(int i=1;i<=m;i++){
		if(c[x][i]<b[i]) return true;
		if(c[x][i]>b[i]) return false;
	}
	return false;
}
bool cmp(char a,char b){
	return a>b;
}

int main(){
	memset(b,'z',sizeof(b));
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	/*for(int i=1;i<=n;i++){
		cin>>c1[i];
	}
	/*if(n==1){
		cout<<1;
		return 0;
	}*/
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			cin>>c[i][k];
		}
	}
	//for(int i=1;i<=n;i++) cout<<c[i][1]<<endl;
	for(int k=1;k<=n;k++){
		sort(c[k]+1,c[k]+m+1,cmp);
		for(int i=1;i<=m;i++){
			//cout<<c[k][i]<<" "<<b[i]<<endl;
			if(b[i]<c[k][i]) break;
			if(b[i]>c[k][i]){
				
				for(int l=1;l<=m;l++){
					b[l]=c[k][l];
				}
				ji=k;
				break;
			}
		}
		
	}
	
	//cout<<b[0];
	/*for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}*/
	//cout<<endl;
	//cout<<pan(1)<<endl;
	for(int i=1;i<=n;i++){
		if(i==ji||pan(i)) printf("1");
		else printf("0");
	}
	return 0;
}
