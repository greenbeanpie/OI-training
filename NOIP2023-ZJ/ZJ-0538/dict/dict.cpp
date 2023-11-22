#include<bits/stdc++.h>
using namespace std;
int n,m;
bool ans[3100];
char c[3005][3005];

int book[20][2];
int bin[20];

bool cmp(string a,string b){
	return a<b;
}

void data0(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	return ;
}

int checkmin(int n1,int mod){
	int pl=1;
	if(mod){
		char c1=c[1][1];
		for(int i=2;i<=n1;i++){
			if(c[i][1]<c1){
				pl=i;
				c1=c[i][1];
			}
		}
	}
	else{
		int bina=bin[1];
		for(int i=2;i<=n1;i++){
			if(bin[i]<bina){
				pl=i;
				bina=bin[i];
			}
		}
	}
	
	
	return pl;
}
void carryout(int n1,int m1){
	if(n1==1){
		ans[1]=1;
	}
	else{
		if(m1==1){
			int p=checkmin(n1,1);	
			for(int i=1;i<=n1;i++){
				ans[i]=0;
				if(i==p)ans[i]=1;
			}	
		}
		else{
			if(n1<=15 and m<=2){
				for(int i=1;i<=n1;i++){
					book[i][0]=max((c[i][1]-'a')*26+c[i][2]-'a',(c[i][2]-'a')*26+c[i][1]-'a');
					book[i][1]=min((c[i][1]-'a')*26+c[i][2]-'a',(c[i][2]-'a')*26+c[i][1]-'a');
				}
				
				for(int i=1;i<=n1;i++){
					for(int j=1;j<=n1;j++){
						bin[j]=book[j][0];
						if(j==i)bin[j]=book[j][1];
					}
					int p2=checkmin(n1,0);
					ans[i]=(i==p2);
				}
			}
			else{
				for(int i=1;i<=n1;i++)
					ans[i]=1;	
			}
		}
	}
	
	
	for(int i=1;i<=n1;i++){
		cout<<ans[i];
	}cout<<"\n";
	return ;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	data0();
	carryout(n,m);
	return 0;
}