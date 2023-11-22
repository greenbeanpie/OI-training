#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[3005];
int x[3005][3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++){
		cin>>a;
		int j;
		for(j=1;j<=m;j++){
			x[i][j]=a[j-1]-'a';
		}
	}
	for(i=1;i<=n;i++){
		sort(x[i]+1,x[i]+m+1);
	}
	for(i=1;i<=n;i++){
		int flag=0;
		for(int w=1;w<=n;w++){
			if(w!=i){
				for(j=1;j<=m;j++){
					int k=m-j+1;
					if(x[i][j]<x[w][k]){
						flag=1;
						break;
					}
					else if(x[i][j]>x[w][k]){
						
						flag=2;
						//cout<<endl<<flag<<endl;
						//cout<<"***";
						break;
					}
				}
				if(flag==1){
					
					flag=0;
				}
				else if(flag==2){
					
					break;
				}
			}
		}
		if(flag==2){
			cout<<0;
		}
		if(flag==0){
			cout<<1;
		}
	}
	return 0;
}
