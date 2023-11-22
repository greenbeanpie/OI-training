#include<bits/stdc++.h>
using namespace std;
int n,m;
short a[3002][26];
struct note{
	int n,op;
	note(){}
	note(int n,int op):n(n),op(op){}
	bool operator< (note k) const{
		if(op==0&&k.op==0){
			for(int i=0;i<26;i++){
				if(a[n][i]>a[k.n][i])return 1;
				if(a[n][i]<a[k.n][i])return 0;
			}
			return 0;
		}if(op==1&&k.op==1){
			for(int i=25;i>=0;i--){
				if(a[n][i]<a[k.n][i])return 1;
				if(a[n][i]>a[k.n][i])return 0;
			}
			return 0;
		}if(op==0&&k.op==1){
			if(n==k.n)return 1;
			int t1=0,t2=25;
			while(a[n][t1]==0)t1++;
			while(a[k.n][t2]==0)t2--;
			if(t1<t2)return 1;
			return 0;
		}if(op==1&&k.op==0)return !(k<*this);
	}
}b[6010];
int btop=0;
bool ans[3002];
int sum;
void read(){
	scanf("%d%d",&n,&m);
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			a[i][s[j]-'a']++;
		}
		b[btop++]=note(i,0);
		b[btop++]=note(i,1);
	}
}
void write(){
	for(int i=0;i<n;i++){
		if(ans[i]==0)printf("0");
		if(ans[i]==1)printf("1");
	}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	read();
	sort(b,b+btop);
	sum=n;
	for(int i=0;i<btop;i++){
		if(b[i].op==0)ans[b[i].n]=1;
		else if(b[i].op==1)break;
	}
	write();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

















