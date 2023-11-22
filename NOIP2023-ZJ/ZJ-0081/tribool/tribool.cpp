#include<bits/stdc++.h>
using namespace std;
long long T,s,d,f,o,i,fa[200015],af[200015];char ch;
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF)n=(n<<1)+(n<<3)+(ch&15),ch=getchar();
	n*=w;
}
long long find(long long x){if(af[x]==x)return x;else return af[x]=find(af[x]);}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	read(T),read(T);
	while(T--){
		read(s),read(d),f=s+2;
		for(int g=1;g<=2*f-1;g++)fa[g]=g;
		for(int g=1;g<=d;g++){
			ch=getchar();
			while(ch!='T'&&ch!='U'&&ch!='F'&&ch!='+'&&ch!='-')ch=getchar();
			if(ch=='+')read(o),read(i),fa[o]=fa[i],fa[o+f]=fa[i+f];
			else if(ch=='-'){
				read(o),read(i);long long k1=fa[i+f],k2=fa[i];
				fa[o]=k1,fa[o+f]=k2;
			}
			else{
				read(o);
				if(ch=='T')fa[o]=s+1,fa[o+f]=s+1+f;
				else if(ch=='F')fa[o]=s+1+f,fa[o+f]=s+1;else fa[o]=fa[o+f]=s+2;
			}
		}
		long long kk=0;
		for(int g=1;g<=2*f-1;g++)af[g]=g;
		for(int g=1;g<=2*f-1;g++)af[find(g)]=find(fa[g]);
		for(int g=1;g<=s;g++)if(find(g)==find(g+f))kk++;
		cout<<kk<<'\n';
	}
	return 0;
}
