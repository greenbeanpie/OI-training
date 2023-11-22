#include <bits/stdc++.h>
using namespace std;
string a[3005],mina[2];
int tong[30];
int n,m,p;

inline void str_sort(int i){
	for(register int j=0;j<m;++j)	tong[a[i][j]-'a']++;
	int cnt=0;
	for(register int j=m-1;j>=0;--j){
		if(tong[cnt] == 0)	while(!tong[cnt])	cnt++;
		tong[cnt]--;
		a[i][j] = cnt+'a';
	}
	return ;
}

inline void check(int i){
	for(register int j=0;j<m;++j){
		if(j == m-1 && mina[0][j] == a[i][j])	break;
		else if(mina[0][j] < a[i][j])	break;
		else if(mina[0][j] > a[i][j]){
			p = i;
			mina[1] = mina[0];
			mina[0] = a[i];
		}
	}
	return ;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a[1];
	str_sort(1);
	mina[0] = a[1];
	for(register int i=2;i<=n;++i){
		cin>>a[i];
		str_sort(i);
		check(i);
	}
	if(n == 1){
		cout<<"1";
		return 0;
	}
	for(register int i=1;i<=n;++i){
		if(i == p){
			for(register int j=0;j<m;++j){
				if(j == m-1 && mina[1][j] <= a[i][m-1-j]){cout<<"0";}
				else if(mina[1][j] < a[i][m-1-j]){cout<<"0";break;}
				else if(mina[1][j] > a[i][m-1-j]){cout<<"1";break;}
			}
		}
		else{
			for(register int j=0;j<m;++j){
				if(j == m-1 && mina[0][j] <= a[i][m-1-j]){cout<<"0";}
				else if(mina[0][j] < a[i][m-1-j]){cout<<"0";break;}
				else if(mina[0][j] > a[i][m-1-j]){cout<<"1";break;}
			}
		}
	}
	return 0;
}
