#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
string s[3010],ss[3010],sm[3010];
int sum1[3010],n,m,f;
string s1="zzzzzzzzzzzzzzzzzzzzzzzzzz",s2="zzzzzzzzzzzzzzzzzzzzzzzzzz";
string ss1,ss2;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		memset(sum1,0,sizeof(sum1));
		for(int j=0;j<m;j++){
			sum1[int(s[i][j]-96)]++;
		}for(int j=1;j<=26;j++){
			while(sum1[j]>0){
				sm[i]+=char(j+96);
				ss[i]=char(j+96)+ss[i];
				sum1[j]--;
			}
		}
	}for(int i=1;i<=n;i++){
		if(ss[i]<s1){
			s2=s1;
			s1=ss[i];
			f=i;
		}else if(ss[i]<s2)
			s2=ss[i];
	}for(int i=1;i<=n;i++){
		if(f!=i&&sm[i]<s1)cout<<1;
		else if(f==i&&sm[i]<s2)cout<<1;
		else if(m==1)cout<<1;
		else cout<<0;
	}
}
