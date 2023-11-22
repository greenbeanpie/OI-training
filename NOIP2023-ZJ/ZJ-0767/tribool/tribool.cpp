#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LL long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int c,t,n,m,Ufa[N],Ffa[N],Tfa[N],num1,num2;
string op;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			Ufa[i]=Ffa[i]=Tfa[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>op;
			if(op=="U"){
				cin>>num1;
				cout<<op<<endl;
			}else
			if(op=="T"){
				cin>>num1;
				cout<<op<<endl;
			}else
			if(op=="F"){
				cin>>num1;
				cout<<op<<endl;
			}else
			if(op=="-"){
				cin>>num1>>num2;
				cout<<op<<endl;
			}else
			if(op=="+"){
				cin>>num1>>num2;
				cout<<op<<endl;
			}
		}
	}




	return 0;
}

