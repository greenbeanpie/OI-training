#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(; isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f*x;
}
inline void write(int x){
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline void readc(vector<char> &s){
	char ch=getchar();
	for(;ch<'a'||ch>'z';ch=getchar());
	for(;ch>='a'&&ch<='z';ch=getchar())s.push_back(ch);
}
int n,m;
vector<char> dict[3010];
pair<vector<char>,int> d_min[3010];
vector<char> d_max;
int flag;
bool errors=0;
//check if the s have two or more d_max;
//then which smaller ,which is 1;
//if errors==1:
//    nothing
//else errors==0:
//ans[flag]=1;
bitset<3010> ans;
void get_min(vector<char> s,int pos){
	sort(s.begin(),s.end());
	d_min[pos]=mk(s,pos);
}
bool operator<(const vector<char> &s1,const vector<char> &s2){
	int i=0;
	for(;s1[i]==s2[i]&&i<s1.size()-1;++i);
	return s1[i]<s2[i];
}
bool cmp(const char &a,const char &b){
	return a>b;
}
void get_max(vector<char> *s){
	flag=0;
	for(int i=1;i<=m;i++) d_max.push_back('z'+1);
	for(int i=1;i<=n;i++){
		sort(s[i].begin(),s[i].end(),cmp);
		if(s[i]==d_max) errors=1;
		if(s[i]<d_max) d_max=s[i],errors=0,flag=i;
	}
}
void init(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) readc(dict[i]);//O(mn)
	if(n==1){ putchar('1');exit(0);} 
	for(int i=1;i<=n;++i) get_min(dict[i],i);//O(nmlogm)
	get_max(dict);//O(nmlogm)
}
void clac(){
	for(int i=1;i<=n;++i)
		ans[d_min[i].second]=(d_min[i].first<d_max);
	if(!errors) ans[flag]=1;
}
int main(){
	init();
	clac();
	for(int i=1;i<=n;i++) putchar(ans[i]^48);
	return 0;
}//90