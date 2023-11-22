#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[3010],d[3010],y;
char ch;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	memset(x,0x3f,sizeof(x));
	if(n==1){
		cout<<"1";
		return 0;
	}else{
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>ch;
				y=ch-'a'+1;
				x[i]=min(x[i],y);
				d[i]=max(d[i],y);
			}
		}
		for(int i=1;i<=n;++i){
			int bj=0;
			for(int j=1;j<=n;++j){
				if(i!=j){
					if(x[i]>=d[j]){
						bj=1;
						break;
					}
				}
			}
			if(bj==1){
				cout<<"0";
			}else{
				cout<<"1";
			}
		}
		return 0;
	}
}
