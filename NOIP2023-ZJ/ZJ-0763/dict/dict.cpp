#include<algorithm>
#include<iostream>
#include<cstring>
#define qwq Œ“∞ÆCCF
using namespace std;
const int N=1e5+10;
string a[N],b[N],c[N];
int n,m;
bool pd(string a,string b){
	bool res=true;
	for(int i=0;i<m;i++){
		if(a[i]==b[i]) continue;
		else if(int(a[i])<int(b[i]))
			break;
		else{
			res=false;
			break;
		}
	}
	return res;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=b[i]=a[i];
		for(int j=0;j<m;j++)
			for(int k=j;k<m;k++)
				if(int(b[i][j])>int(b[i][k]))
				 	swap(b[i][j],b[i][k]);
		for(int j=0;j<m;j++)
			for(int k=j;k<m;k++)
				if(int(c[i][j])<int(c[i][k]))
				 	swap(c[i][j],c[i][k]);
	}
	/*for(int i=1;i<=n;i++){
		cout<<b[i]<<" "<<c[i]<<"\n";
	}*/
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(pd(b[i],c[j])==false){
				cout<<"0";
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<"1";
	}
	return 0;//qwq
}
