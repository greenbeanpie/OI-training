//lzy AK IOI
//lzx AK IOI
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e3+10;
int n,m;
char s[N][N],smi[N][N],sma[N][N],mi[N];
//priority_queue <char,vector<char>,greater<char> > qmi;
//priority_queue <char> qma;
bool cmp(char x,char y){
	return x > y;
}
bool pd(int x){
	for(int i=0;i<m;i++){
		if(mi[i] < sma[x][i])return 0;
		if(mi[i] > sma[x][i])return 1;
	}
	return 1;
}
bool pd2(int x){
	for(int i=0;i<m;i++){
		if(mi[i] < smi[x][i])return 0;
		if(mi[i] > smi[x][i])return 1;
	}
	return 1;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		char ch = getchar();
		while(ch < 'a' || ch > 'z')ch = getchar();
		for(int j=0;j<m;j++){
			s[i][j] = ch;
			ch = getchar();
		}
		sort(s[i],s[i]+m);
		for(int j=0;j<m;j++){
			smi[i][j] = s[i][j];
		}
		sort(s[i],s[i]+m,cmp);
		for(int j=0;j<m;j++){
			sma[i][j] = s[i][j];
		}
	}
	for(int i=0;i<m;i++){
		mi[i] = sma[1][i];
	}
	for(int i=2;i<=n;i++){
		if(pd(i)){
			for(int j=0;j<m;j++){
				mi[j] = sma[i][j];
			}
		}
	}
	if(n == 1){
		cout <<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(pd2(i) || pd(i)){
			printf("1");
		}
		else printf("0");
	}
	return 0;
}
