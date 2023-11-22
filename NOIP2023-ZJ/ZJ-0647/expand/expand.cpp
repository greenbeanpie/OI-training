#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int a[500010],b[500010];

inline int read(){
	int ans=0;
	char c=getchar();
	while(!(c>='0'&&c<='9'))c=getchar();
	while(c>='0'&&c<='9'){
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans;
}

inline void solve(){
	int i=0,j=0;
	bool k=0;
	a[n]=-1;
	while(i>=0&&j<m){
		if(a[i]>b[j]){
			k=1;i++;
		}else if(k==1){
			j++;k=0;
		}else{
			i--;
		}
	}
	if(i==n&&j==m){
		printf("1");
		return;
	}
	i=0,j=0;
	k=0;
	a[n]=1000000010;
	while(i>=0&&j<m){
		if(a[i]<b[j]){
			k=1;i++;
		}else if(k==1){
			j++;k=0;
		}else{
			i--;
		}
	}
	if(i==n&&j==m){
		printf("1");
		return;
	}
	printf("0");
	return;
}
stack<pair<int,int> >s1,s2;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read();
	n=read(),m=read(),q=read();
	for(register int i=0;i<n;i++)a[i]=read();
	for(register int i=0;i<m;i++)b[i]=read();
	solve();
	for(int i=0,kx,ky,ki,kj;i<q;i++){
		kx=read(),ky=read();
		for(register int i=0;i<kx;i++){
			ki=read()-1,kj=read();
			s1.push(pair<int,int>(ki,a[ki]));
			a[ki]=kj;
		}
		for(register int i=0;i<ky;i++){
			ki=read()-1,kj=read();
			s2.push(pair<int,int>(ki,b[ki]));
			b[ki]=kj;
		}
		solve();
		while(!s1.empty()){
			a[s1.top().first]=s1.top().second;
			s1.pop();
		}
		while(!s2.empty()){
			b[s2.top().first]=s2.top().second;
			s2.pop();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
