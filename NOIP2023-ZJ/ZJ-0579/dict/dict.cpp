#include<bits/stdc++.h>
using namespace std;

int read(){
	int f=1,x=0; char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}

int n,m;
string a[3010];
int b[3010][30];

void check(int i,string u){
	for(int j=0;j<n;j++){
		if(i!=j&&u>=a[j]){
			printf("0");
			return;
		}
	}
	printf("1");
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<m;j++){
			b[i][a[i][j]-'a']++;
		}
	}
	for(int i=0;i<n;i++){
		string u="";
		for(int j=0;j<26;j++){
			while(b[i][j]--){
				u+=((char)(j+'a'));
			}
		}
		check(i,u);
	}
	return 0;
}