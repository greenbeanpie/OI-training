#include<bits/stdc++.h>
using namespace std;
long long s,d,a[3005],b[3005],c[55];char ch;
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF)n=(n<<1)+(n<<3)+(ch&15),ch=getchar();
	n*=w;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	read(s),read(d);
	for(int g=1;g<=s;g++){
		long long k1=0,k2=25;
		for(int h=1;h<=d;h++){
			ch=getchar();
			while(ch<'a'||ch>'z')ch=getchar();
			k1=max(k1,(long long)(ch-'a')),k2=min(k2,(long long)(ch-'a'));
		}
		a[g]=k1,b[g]=k2,c[k1]++;
	}
	for(int g=1;g<=s;g++){
		c[a[g]]--;
		long long kk=0;
		for(int h=b[g]+1;h<26;h++)kk+=c[h];
		if(kk==s-1)cout<<'1';else cout<<'0';
		c[a[g]]++;
	}
	return 0;
}
