#include<bits/stdc++.h>
#define N int(3e3+5)
using namespace std;
void file();void desync();
struct node{
	int bg;int sm;
}e[N];
int n,m,a[N];
string s[N],minn[N],maxx[N];

bool check(string x,string y){
	for(int i=0;i<m;i++){
		if(x[i]>y[i])return true;
		else if(x[i]<y[i])return false;
	}
	return true;
}
bool ck1(int p){
	for(int i=1;i<=n;i++){
		if(p!=i){
			bool flag=false;
			for(int j=0;j<=m;j++){
				if(minn[p][j]>maxx[i][j])return false;
				if(minn[p][j]<maxx[i][j]){
					flag=true;break;
				}
			}
			if(!flag)return false;
		}
	}
	return true;
}
void reva(){
	int b[N];
	for(int i=0;i<m;i++)b[m-1-i]=a[i];
	for(int i=0;i<m;i++)a[i]=b[i];
}
void sub3(){
	for(int k=1;k<=n;k++){
		cin>>s[k];
		for(int i=0;i<m;i++){
			a[i]=s[k][i]-'a';
		}
		sort(a,a+m);
		for(int i=0;i<m;i++)minn[k][i]=a[i]+'a';
		reva();
		for(int i=0;i<m;i++)maxx[k][i]=a[i]+'a';
	}
	for(int i=1;i<=n;i++){
		if(ck1(i))cout<<"1";
		else cout<<"0";
	}
}

bool kk(int p);
void sub2();
void sub1();

int main(){
	file();
	desync();
	cin>>n>>m;
	if(n==1)cout<<"1";
	else if(m==1)sub1();
	else if(m==2)sub2();
	else sub3();
	return 0;
}

void file(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
}
void desync(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
}

bool kk(int p){
	for(int i=1;i<=n;i++){
		if(i!=p){
			if(e[p].sm>e[i].bg||(e[p].sm==e[i].bg&&e[p].bg>=e[i].sm))
				return false;
		}
	}
	return true;
}
void sub2(){
	string xx;
	for(int i=1;i<=n;i++){
		cin>>xx;
		e[i].bg=max(xx[0]-'a',xx[1]-'a');
		e[i].sm=min(xx[0]-'a',xx[1]-'a');
	}
	for(int i=1;i<=n;i++){
		if(kk(i))cout<<"1";
		else cout<<"0";
	}
}
void sub1(){
	int aa[N],mp=1;char t;bool flag=false;
	cin>>t;aa[1]=t-'a';
	for(int i=2;i<=n;i++){
		cin>>t;aa[i]=t-'a';
		if(aa[i]<aa[mp])mp=i,flag=false;
		else if(i!=mp&&aa[i]==aa[mp])flag=true;
	}
	if(flag)for(int i=1;i<=n;i++)cout<<"0";
	else for(int i=1;i<=n;i++){
		if(mp==i)cout<<"1";
		else cout<<"0";
	}
}
