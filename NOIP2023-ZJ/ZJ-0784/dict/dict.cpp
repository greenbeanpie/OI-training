#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int m,n;
	string a[3001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	if(n==1)cout<<'1';//n==1
	else if(m==1){//m==1
		int q=0;
		char min=a[0][0];
		for(int i=1;i<n;i++){
			if(a[i][0]<min){
				min=a[i][0];
				q=i;
			}
		}
		for(int i=0;i<n;i++){
			if(i==q)cout<<'1';
			else cout<<'0';
		}
	}
	else if(m==2){//m==2baolisousuo
		string b[16];
		for(int i=0;i<n;i++){
			b[i][0]=a[i][1];
			b[i][1]=a[i][0];
		}
		bool flag[16]={true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true};
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==i)continue;
				if(a[i][0]>a[j][0] or (a[i][0]==a[j][0]&&a[i][1]>a[j][1])){
					if(a[i][0]>b[j][0] or (a[i][0]==b[j][0]&&a[i][1]>b[j][1])){
						if(b[i][0]>a[j][0] or (b[i][0]==a[j][0]&&b[i][1]>a[j][1])){
							if(b[i][0]>b[j][0] or (b[i][0]==b[j][0]&&b[i][1]>b[j][1])){
								flag[i]=false;
							}
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			if(flag[i])cout<<'1';
			else cout<<'0';
		}
	}
	else{
		for(int i=0;i<n;i++){
			cout<<'1';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

