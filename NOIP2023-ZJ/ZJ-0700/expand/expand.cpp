#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}

int c,n,m,q,x[500050],y[500050],tmp,a,b,p,v;
vector< vector<int> >prex;
vector< vector<int> >prey;
vector<int>t;

bool ex(int x[500050],int y[500050],bool c){
	int i,j;
	tmp=0;
	if(c){
		a=read();b=read();
		while(a--){
			p=read();v=read();
			p--;
			t.push_back(p);t.push_back(x[p]);
			prex.push_back(t);
			x[p]=v;
			t.pop_back();t.pop_back();
		}
		while(b--){
			p=read();v=read();
			p--;
			t.push_back(p);t.push_back(y[p]);
			prey.push_back(t);
			y[p]=v;
			t.pop_back();t.pop_back();
		}
	}
	//for(i=0;i<n;i++)cout<<x[i]<<" ";cout<<endl;
	//for(i=0;i<m;i++)cout<<y[i]<<" ";cout<<endl;
	if(y[0]<x[0])tmp=1;
	else if(y[0]>x[0])tmp=2;
	else tmp=-1;
	if((y[m-1]<x[n-1]&&tmp==2)||(y[m-1]>x[n-1]&&tmp==1)||(y[m-1]==x[m-1]))tmp=-1;
	if(tmp==1){
		j=0;
		for(i=1;i<m-1;i++){
			if(x[j]<=y[i])j++;
			if(j>=n){
				tmp=-1;
				break;
			}
		}
	}else if(tmp==2){
		j=0;
		for(i=1;i<m-1;i++){
			if(x[j]>=y[i])j++;
			if(j>=n){
				tmp=-1;
				break;
			}
		}
	}
	if(tmp==-1)printf("0");
	else printf("1");
	for(i=prex.size()-1;i>=0;i--){
		x[prex[i][0]]=prex[i][1];
		prex.pop_back();
	}
	for(i=prey.size()-1;i>=0;i--){
		y[prey[i][0]]=prey[i][1];
		prey.pop_back();
	}
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int i,j;
	c=read();n=read();m=read();q=read();
	for(i=0;i<n;i++)x[i]=read();
	for(i=0;i<m;i++){
		y[i]=read();
	}
	ex(x,y,0);
	while(q--)ex(x,y,1);
	
	return 0;
}
