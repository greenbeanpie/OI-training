#include<bits/stdc++.h>
using namespace std;
int n,l;
char d[3010][3010];
int a[3010],b[3010][3010];
int mas[3010];
int mis[3010];
int ma[3010];
int mi[3010];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>l;
	if(n==1){
		cout<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++){
		ma[i]=0;
		mi[i]=1000;
	}
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=l;j++){
			cin>>d[i][j];
			b[i][j]=int(d[i][j])-'a'+1;
		
			ma[i]=max(b[i][j],ma[i]);
			mi[i]=min(b[i][j],mi[i]);
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=1;
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			if(ma[j]<=mi[i]){
				a[i]=0;
				break;
			}
			if(ma[j]>mi[i]){	
				continue;
			}
			
			
		}
		cout<<a[i];
	}
	return 0;
}
