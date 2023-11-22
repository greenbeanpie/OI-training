#include<bits/stdc++.h>
using namespace std;
int c,t,mi,n,m;
int F[100005];
int T[100005];
int U[100005];
int g[100005],gg[100005];
char cun[20],pai[20],y[20];
int cc[20][5];
char zi[3]={'T','F','U'};
int lu[100005][1000],ll[100005];
void zhao(int x){
	for(int i=0;i<ll[x];i++){
		int c=lu[x][i];
		U[c]=1;
		T[c]=0;
		F[c]=0;
		zhao(c);
	}
}

bool pan(){
	for(int i=1;i<=n;i++){
		y[i]=pai[i];
	}
	
	for(int i=1;i<=m;i++){
		if(cun[i]=='T'){
			y[cc[i][0]]='T';
			//cout<<1;
		}
		if(cun[i]=='U'){
			y[cc[i][0]]='U';
			//cout<<2<<" "<<i;
		}
		if(cun[i]=='F'){
			y[cc[i][0]]='F';
			
		}
		if(cun[i]=='+'){
			y[cc[i][1]]=y[cc[i][2]];
			
		}
		if(cun[i]=='-'){
			if(y[cc[i][2]]=='T'){
				y[cc[i][1]]='F';
				//cout<<3;
			}
			else if(y[cc[i][2]]=='F'){
				y[cc[i][1]]='T';
				//cout<<4;
			}
			else{
				y[cc[i][1]]='U';
				//cout<<5;
			}
			
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<y[i]<<pai[i]<<endl;
		
	}
	
	cout<<endl;*/
	for(int i=1;i<=n;i++){
		
		if(y[i]!=pai[i]) return false;
	}
	return true;
}

void search(int x,int ji){
	if(x>n){
		if(pan()&&ji<mi){
		    mi=ji; 	
		}
		return ;
	}
	for(int i=0;i<3;i++){
		pai[x]=zi[i];
		if(i==2) search(x+1,ji+1);
		else search(x+1,ji);
	}
}

void yun1(){
	scanf("%d%d",&n,&m);
	memset(T,-1,sizeof(T));
	memset(F,-1,sizeof(F));
	memset(U,-1,sizeof(U));
	memset(gg,0,sizeof(gg));
	memset(g,0,sizeof(g));
	memset(lu,0,sizeof(lu));
	memset(ll,0,sizeof(ll));
	//cout<<m<<n;
	for(int i=1;i<=m;i++){
		char v;
		cin>>v;
		//cout<<v;
		if(v=='F'){
			int a;
			scanf("%d",&a);
			F[a]=1;
			T[a]=0;
			U[a]=0;
		}
		if(v=='U'){
			//cout<<1;
			int a;
			scanf("%d",&a);
			U[a]=1;
			T[a]=0;
			F[a]=0;
		}
		if(v=='T'){
			int a;
			scanf("%d",&a);
			T[a]=1;
			F[a]=0;
			U[a]=0;
		}
		if(v=='+'){
			int a,b;
			scanf("%d%d",&a,&b);
			gg[g[a]]--;
			g[a]=b;
			gg[b]++;
			if(U[b]!=1){
				U[a]=-1;
				T[a]=-1;
				F[a]=-1;
			}
			/*if(U[b]==1){
				U[a]=1;
				T[a]=0;
				F[a]=0;
			}
			if(T[b]==1){
				T[a]=1;
				U[a]=0;
				F[a]=0;
			}
			if(F[b]==1){
				F[a]=1;
				T[a]=0;
				U[a]=0;
			}*/
		}
		if(v=='-'){
			int a,b;
			scanf("%d",&a,&b);
		}
	}
}

void yun2(){
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		char v;
		cin>>v;
		cun[i]=v;
		if(v=='T'||v=='U'||v=='F'){
			int a;
			cin>>a;
			cc[i][0]=a;
		}
		else{
			int a,b;
			cin>>a>>b;
			cc[i][1]=a;
			cc[i][2]=b;
		}
	}
	mi=10000;
	search(1,0);
	cout<<mi<<endl;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==3||c==4){
		for(int o=1;o<=t;o++){
			yun1();
			mi=0;
			for(int i=1;i<=n;i++){
				if(U[i]==1){
					mi++;
				}
			}
			cout<<mi<<endl;
		}
	}
	else if(c==5||c==6){
		for(int o=1;o<=t;o++){
			yun1();
			for(int i=1;i<=n;i++){
				lu[g[i]][ll[g[i]]++]=i;
			}
			for(int i=1;i<=n;i++){
				int ss=0;
				for(int i=1;i<=n;i++){
					if(U[g[i]]==1){
						U[i]=1;
						ss++;
					}
				}
				if(ss==0) break;
				/*if(g[i]==0&&U[i]==1){
					zhao(i);
				}*/
			}
			mi=0;
			for(int i=1;i<=n;i++){
				if(U[i]==1) mi++;
			}
			cout<<mi<<endl;
		}
	}
	else if(c==7||c==8){
		for(int o=1;o<=t;o++){
			
			
		}
	}
	else if(c==1||c==2){
		for(int o=1;o<=t;o++){
			yun2();
		}
	
	}
	return 0;
}