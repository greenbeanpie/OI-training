#include<bits/stdc++.h>
#define gc getchar()
using namespace std;
inline int read(){
	int x=0,f=1;char ch=gc;
	for(;!isdigit(ch);ch=gc)if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc)x=x*10+ch-'0';
	return x*f;
}
const int MAX=3005;
int n,m;
string a[MAX];//min
struct str{
	string s;
	int id;
};
str b[MAX];//max & id
bool cmp(char x,char y){
	return x<=y;
}
bool cmp2(char x,char y){
	return x>=y;
}
bool cmp3(str a,str b){
	return a.s<=b.s;
}
string ans="";
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].s=a[i],b[i].id=i;
		sort(b[i].s.begin(),b[i].s.end(),cmp2);
		sort(a[i].begin(),a[i].end(),cmp);
	}
	sort(b+1,b+1+n,cmp3);
	for(int i=1;i<=n;i++){
		if(i==b[1].id){
			if(a[i]>b[2].s){
				ans+='0';
			}else{
				ans+='1';
			}
		}else{
			if(a[i]>b[1].s){
				ans+='0';
			}else{
				ans+='1';
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}