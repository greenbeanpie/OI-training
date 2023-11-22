#include <bits/stdc++.h>
using namespace std;
string x[3050];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==1){
		printf("1");
	}
	else if(n<=26&&m==1){
		int mini=-1;
		char minx='z'+1;
		for(int i=1;i<=n;i++){
			if(minx>x[i][0]){
				minx=x[i][0];
				mini=i;
				//cout<<i<<endl;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==mini) printf("1");
			else printf("0");
		}
	}
	else if(n<=15&&m==2){
		for(int i=1;i<=n;i++){
			if(x[i][1]>x[i][0]){
				char tt=x[i][1];
				x[i][1]=x[i][0];
				x[i][0]=tt;
			}
		}
		bool f=1;
		for(int i=1;i<=n;i++){
			f=1;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				else{
					if(x[i][1]>=x[j][0]) f=0;//xy ax
				}
			}
			if(f==1) printf("1");
			else printf("0");
		}
	}//70
	else{
		char mem[3050][3];
		for(int i=1;i<=n;i++){
			mem[i][0]=x[i][0];
			mem[i][1]=x[i][0];
			for(int j=1;j<m;j++){
				if(mem[i][0]<x[i][j]) mem[i][0]=x[i][j];
				if(mem[i][1]>x[i][j]) mem[i][1]=x[i][j];
			}
		}
		bool f=1;
		for(int i=1;i<=n;i++){
			f=1;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				else{
					if(mem[i][1]>=mem[j][0]) f=0;
				}
			}
			if(f==1) printf("1");
			else printf("0");
		}
	}//100
	fclose(stdin);
	fclose(stdout);
	return 0;
}
