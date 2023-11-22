//dict
#include <bits/stdc++.h>
#define re register
using namespace std;
int n,m;
string dic;
int turnint[3010];
int dictup[3010][3010],dictdown[3010][3010];
int mindown=1,nxtdown=1;

inline bool cmpd(int a,int b){return a>b;}

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(re int i=1;i<=n;i++){
		cin>>dic;
		if(n==1) {
			cout<<1;
			return 0;
		}
		for(re int j=0;j<m;j++) turnint[j]=dic[j]-'a'+1;
		sort(turnint,turnint+m);
		for(re int j=0;j<m;j++) {
//			cout<<turnint[j]<<" ";//
			dictup[i][j]=turnint[j];
		}
//		cout<<endl;//
		bool f1=true,f2=true;
		sort(turnint,turnint+m,cmpd);
		for(re int j=0;j<m;j++) {
//			cout<<turnint[j]<<" "<<dictdown[mindown][j]<<" ";//
			dictdown[i][j]=turnint[j];
			if(mindown==i) continue;
			if(turnint[j]>dictdown[mindown][j]) f1=false;
			if(turnint[j]>dictdown[nxtdown][j]) f2=false;
			if(f1&&turnint[j]<dictdown[mindown][j]) nxtdown=mindown,mindown=i;
			else if(f2&&turnint[j]<dictdown[nxtdown][j]) nxtdown=i;
		}
//		cout<<endl;//
	}
	bool f=false;
	for(re int i=1;i<=n;i++){
		f=false;
		if(i==mindown){
			for(re int j=0;j<m;j++){
//				cout<<dictup[i][j]<<" "<<dictdown[nxtdown][j]<<endl;//
				if(dictup[i][j]<dictdown[nxtdown][j]) {
					f=true;
					break;
				}
				else if(dictup[i][j]>dictdown[nxtdown][j]) break;
			}
		}
		else{
			for(re int j=0;j<m;j++){
//				cout<<dictup[i][j]<<" "<<dictdown[mindown][j]<<endl;//
				if(dictup[i][j]<dictdown[mindown][j]) {
					f=true;
					break;
				}
				else if(dictup[i][j]>dictdown[mindown][j]) break;
			}
		}
		cout<<f;
	}
	return 0;
}
