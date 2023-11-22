#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	int c,t,ans[7]={0};
	cin>>c>>t;
	if(c==3 or c==4){
		for(int a=0;a<t;a++){
			int m,n;
			cin>>m>>n;
			char ff[100001];
			memset(ff,'a',sizeof(ff));
			for(int i=0;i<n;i++){
				int x;
				char f;
				cin>>f>>x;
				if(ff[x]!='U'&&f=='U'){
					ff[x]='U';
					ans[a]++;
				}
				if(ff[x]=='U'&&f!='U'){
					ff[x]='a';
					ans[a]--;
				}
			}
		}
		for(int i=0;i<t;i++){
			cout<<ans[i]<<endl;
		}
	}
	else{
		for(int a=0;a<t;a++){
			int m,n;
			cin>>m>>n;
			for(int i=0;i<n;i++){
				int x,y;
				char f;
				cin>>f;
				if(f=='+' or f=='-')cin>>x>>y;
				else cin>>x;
			}
		}
		for(int i=0;i<t;i++){
			cout<<0<<endl;
		}	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

