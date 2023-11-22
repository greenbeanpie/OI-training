#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	char j[301];
	char ooo[301];
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>j[i];
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>j[i]>>ooo[i];
		}
	}
	if(n==1){
		cout<<"1";//10分测试点1 
	}else if(n>1&&m==1){//30分测试点2-4 
		char minfu='z';
		int minbiao=0;
		for(int k=1;k<=n;k++){
			if(int(j[k])<int(minfu)){
				minfu=j[k];
				minbiao=k;
			}
		}
		for(int rp=1;rp<=n;rp++){
			if(rp!=minbiao){
				cout<<"0";
			}else{
				cout<<"1";
			}
		}
	}else if(n>1&&m==2){ //30分测试点5-7 
		char yqe='{';//fangzuixiaode
		char csx='{';
		int biaoji=0;
		for(int ccc=1;ccc<=n;ccc++){
			if(int(j[ccc])<int(yqe)){
				yqe=j[ccc];
				csx=ooo[ccc];
				biaoji=ccc;
			}else if(int(j[ccc])==int(yqe)){
				if(int(ooo[ccc])<int(csx)){
					yqe=j[ccc];
					csx=ooo[ccc];
					biaoji=ccc;
				}
			}
		}
		for(int ttt=1;ttt<=n;ttt++){
			if(ttt!=biaoji){
				swap(j[ttt],ooo[ttt]);
				if(int(j[ttt])<int(yqe)){
					cout<<"1";
				}else if(int(j[ttt])==int(yqe)){
					if(int(ooo[ttt])<int(csx)){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"0";
				}
			}else{
				cout<<"1";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
