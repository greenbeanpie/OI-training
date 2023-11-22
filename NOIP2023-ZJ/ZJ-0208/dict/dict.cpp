#include<bits/stdc++.h>
using namespace std;
#define pa pair<int,int>
#define mp make_pair
#define fi first
#define se second

const int N=3e3+5;
char s[N][N],mnstr[N],cstr[N];
int n,m,id;
bool a[N];
map<pa,int>M;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		sort(s[i],s[i]+m);
		if(i==1){
			for(int j=m-1;j>=0;--j) mnstr[j]=s[i][j];
			id=1;
			continue;
		}
		if(i==2){
			for(int j=m-1;j>=0;--j) cstr[j]=s[i][j];
			for(int j=m-1;j>=0;--j)
				if(cstr[j]<mnstr[j]){
					swap(cstr,mnstr);
					id=2;
					break;
				}else
				if(cstr[j]>mnstr[j]) break;
			continue;
		}
		bool flag=false,tag=false;
		for(int j=m-1;j>=0;--j)
			if(s[i][j]<mnstr[j]){
				for(int j=0;j<m;++j) cstr[j]=mnstr[j];
				for(int j=0;j<m;++j) mnstr[j]=s[i][j];
				id=i;
				flag=true;
				break;
			}else
			if(s[i][j]>mnstr[j]){tag=true;break;}
		if(flag) continue;
		if(!tag){
			for(int j=0;j<m;++j) cstr[j]=mnstr[j];
			continue;
		}
		for(int j=m-1;j>=0;--j)
			if(s[i][j]<cstr[j]){
				for(int j=0;j<m;++j) cstr[j]=s[i][j];
				break;
			}else
			if(s[i][j]>cstr[j]) break;
	}
	for(int i=1;i<=n;++i){
		bool flag=false;
		if(i==id){
			for(int j=0;j<m;++j)
				if(s[i][j]<cstr[m-j-1]){
					flag=true;break;
				}else
				if(s[i][j]>cstr[m-j-1]) break;
		}else{
			for(int j=0;j<m;++j)
				if(s[i][j]<mnstr[m-j-1]){
					flag=true;break;
				}else
				if(s[i][j]>mnstr[m-j-1]) break;
		}
		if(flag) putchar('1');else putchar('0');
	}
	puts("");
	return 0;
}