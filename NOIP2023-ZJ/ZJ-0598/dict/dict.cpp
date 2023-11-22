#include<bits/stdc++.h>
using namespace std;
int n,m;
string lst[3005];
typedef struct st{
	string s;
	int index;
}st;
st cst(string ss,int indexx){
	st s;
	s.s=ss,s.index=indexx;
	return s;
}
st minl[3005];
st maxl[3005];
bool cmpst(st a,st b){
	return a.s<b.s;
}
bool cmpch(char x,char y){
	return x>y;
}
int NT[27];
string gp(char A,int T){
	string ANS="",x="";
	x+=A;
	while(T){
		if(T&1) ANS+=x;
		x=x+x,T/=2;
	}
	return ANS;
}
string NN(string s){//min	
	memset(NT,0,sizeof(NT));
	for(int i=0,imax=s.length();i<imax;i++)
		NT[s[i]-'a']++;
//	printf("min value: %s --> %s\n",s.c_str(),T);
	string k="";
	for(int i=0;i<26;i++) k+=gp('a'+i,NT[i]);
	return k;
}
string RR(string s){//max
	memset(NT,0,sizeof(NT));
	for(int i=0,imax=s.length();i<imax;i++)
		NT[s[i]-'a']++;
//	printf("min value: %s --> %s\n",s.c_str(),T);
	string k="";
	for(int i=25;i>=0;i--) k+=gp('a'+i,NT[i]);
	return k;
}
int main(){
	//freopen("dict1.in","r",stdin);
	///reopen("dict.out","w",stdout);
	ifstream fin("dict.in");
	ofstream fout("dict.out");
	//scanf("%d%d",&n,&m);
	fin>>n>>m;
	for(int i=0;i<n;i++)
		//scanf("%s",lst[i]);
		fin>>lst[i];
	if(n==1){
		//printf("0");
		fout<<1;
	}
	else{
		for(int i=0;i<n;i++)
			minl[i]=cst(NN(lst[i]),i),maxl[i]=cst(RR(lst[i]),i);
		sort(maxl,maxl+n,cmpst);
		//for(int i=0;i<m;i++)
		//	cout<<maxl[i].s<<" ;;\n";
		// 对于minl[n-1].index而言，它的min最大，因而只需要比较它的最大字典序
		//与次大
		string ans="";
		for(int i=0;i<n;i++){
			//cout<<"minl i"<<minl[i].s<<" maxl[0]:"<<maxl[0].s<<"\n";
			if(i==maxl[0].index){
				if(minl[i].s<maxl[1].s) ans+="1";
				else ans+="0";
				continue;
			}
			if(minl[i].s<maxl[0].s) ans+="1";
			else ans+="0";
		}
		fout<<ans;
		fout.close();
	}
	//system("FC dict.out dict4.ans");
	return 0;
	
}