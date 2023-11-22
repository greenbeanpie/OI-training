#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+ch-'0';
        ch=getchar();
    }
    return s*w;
}
int n,m;
string s[3002];
int sum[30][3002],las[30][3002];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int id){
    while(x<=26){
        sum[x][id]++;
        x+=lowbit(x);
    }
}
int ask(int x,int id){
    int res=0;
    while(x){
        res+=sum[x][id];
        x-=lowbit(x);
    }
    return res;
}
int mx[3002],mi[3002],fi_mx[3002],fi_mi[3002];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int t=clock();
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        cin>>s[i];
		for(int j=m-1;j>=0;j--){
            // sum[][i]++;
            add(s[i][j]-'a'+1,i);
            if(!las[s[i][j]-'a'+1][i])las[s[i][j]-'a'+1][i]=j;
            if(ask(s[i][j]-'a',i)){
                fi_mx[i]=j;
            }
            if(m-j-ask(s[i][j]-'a'+1,i)){
                fi_mi[i]=j;
            }
        }
        mx[i]=mi[i]=-1;
        for(int j=1;j<s[i][fi_mx[i]]-'a'+1;j++){
            if((ask(j,i)-ask(j-1,i))&&las[j][i]>fi_mx[i]){
                mx[i]=las[j][i];
                break;
            }
        }
        for(int j=26;j>s[i][fi_mi[i]]-'a'+1;j--){
            if((ask(j,i)-ask(j-1,i))&&las[j][i]>fi_mx[i]){
                mi[i]=las[j][i];
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        char g;       
        if(~mx[i]){
            g=s[i][fi_mx[i]];
            s[i][fi_mx[i]]=s[i][mx[i]];
            s[i][mx[i]]=g;
        }
        bool flag=1;
   	    for(int j=1;j<=n;j++){
   		    if(i==j)continue;
            char h; 
            if(~mi[j]){
                h=s[j][fi_mi[j]];
                s[j][fi_mi[j]]=s[j][mi[j]];
                s[j][mi[j]]=h; 
            }
			if(s[j]<s[i]){
				flag=0;
			}
            if(~mi[j]){
                s[j][mi[j]]=s[j][fi_mi[j]];
                s[j][fi_mi[j]]=h; 
            }
			
			if(flag==0)break;
		}
        if(~mx[i]){
            s[i][mx[i]]=s[i][fi_mx[i]];
            s[i][fi_mx[i]]=g;
        }
		
		cout<<flag;
	}
	cout<<endl;
}