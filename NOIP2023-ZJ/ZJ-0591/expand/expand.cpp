#include<bits/stdc++.h>
using namespace std;
int g,a,b,j;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>g>>a>>b>>j;
	if(g==1){
		int x,y;
		cin>>x>>y;
		if(x!=y) cout<<1;
		else cout<<0;
		for(int i=1;i<=j;i++){
			int x1,y1;
			cin>>x1>>y1;
			int x2[10005],x3[10005],y2[10005],y3[10005];
			for(int j=1;j<=x1;j++){
				cin>>x2[j]>>x3[j];
			}
			for(int j=1;j<=y1;j++){
				cin>>y2[j]>>y3[j];
			}
			if(x==y) cout<<0;
			else{
				int v=1;
				for(int j=1;j<=x1;j++)
					for(int k=1;k<=y1;k++)
						if(x2[j]==y2[k]){
							if((x-y)*(x3[j]-y3[k])>0){
								x3[j]=x;
								y3[k]=y;
							}
							else v=0;
						}
				for(int j=1;j<=x1&&v==1;j++)
					if((x-y)*(x3[j]-y)<=0)
						v=0;
				for(int j=1;j<=y1&&v==1;j++)
					if((x-y)*(x-y3[j])<=0)
						v=0;
				cout<<v;
			}
		}
	}	
	return 0;	
}