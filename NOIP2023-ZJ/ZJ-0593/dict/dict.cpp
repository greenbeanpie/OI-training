#include<bits/stdc++.h>
using namespace std;
char read(){
	char ch=getchar();
	while(ch<'a' || ch>'z'){ch=getchar();}
	return ch;
}
void write(int x){
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=3e3+10;
char c;
int maap[N][28],mx[N],mn[N],s1=3001,s2=3002;
int n,m,k;
bool cmp(int k, int l){
	if(mx[k]==mx[l]){
		for(int i=mx[k]; i>=1; i--){
			if(maap[k][i]!=maap[l][i])return maap[k][i]>maap[l][i];
		}
	}
	return mx[k]>mx[l];
}
bool check(int k,int l){
	if(mn[k]<mx[l])return true;
	return false;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	mx[3001]=30;
	mx[3002]=31;
	for(int i=1; i<=n; i++){
		mn[i]=30;
		for(int j=1; j<=m; j++){
			c=read();
			k=c-'a'+1;
			maap[i][k]++;
			mx[i]=max(mx[i],k);
			mn[i]=min(mn[i],k);
		}
		if(n==1){
			write(1);
			return 0;
		}
		if(cmp(s1,i)){
			s2=s1;
			s1=i;
		}else{
			if(cmp(s2,i))s2=i;	
		}
	}	
	for(int i=1; i<=n; i++){
		if(i==s1){
			if(check(i,s2))write(1);
			else write(0);
		}else{
			if(check(i,s1))write(1);
			else write(0);
		}
	}
	return 0;
}