#include<bits/stdc++.h>//everyone have a min and a max
using namespace std;
int n,m;
//string smax[3010],smin[3010];
char smax[3001][3001],smin[3001][3001];
bool fa(int a,int b){//a's min < b's max
	for(int i=0;i<m;i++){
		if(smin[a][i]<smax[b][i])	return true;
		if(smin[a][i]>smax[b][i])	return false;
	}
	return true;//not equal
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	char c[m+1];
	for(int i=1;i<=n;i++){
	//	string str;
	//	cin>>str;
	//	int len=str.size();	
		for(int j=0;j<m;j++)	cin>>c[j];
		sort(c,c+m);
		string strmin,strmax;
		for(int j=0;j<m;j++){
			smin[i][j]=c[j];
			smax[i][m-j-1]=c[j];
		}		
		//smax[i]=strmax;smin[i]=strmin;
		//for(int j=0;j<m;j++)	cout<<smin[i][j];
		//for(int j=0;j<m;j++)	cout<<smax[i][j];
	//	for(int j=0;j<m;j++)	cout<<c[j];
	//	cout<<endl;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		bool f=true;
		for(int j=1;j<=n;j++){
			if(i==j)	continue;
			if(!fa(i,j)){
				f=false;
				cout<<0;
				break;
			}
		}
		if(f)	cout<<1;
	}
	return 0;
}
//need check
//guo yang li
