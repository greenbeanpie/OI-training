#include <bits/stdc++.h>
#define MAXN 100010
#define T 1
#define F -1
#define U 0
using namespace std;
int C,Tt,n,m;


//test 1&2
int startStatus[11],endStatus[11],minU;
char ops[11];
int opn[11][2];
bool check(){
	for(int i=1;i<=n;i++)
		endStatus[i]=startStatus[i];
	for(int i=1;i<=m;i++){
		switch(ops[i]){
			case '+':
				endStatus[opn[i][0]]=endStatus[opn[i][1]];
				break;
			case '-':
				endStatus[opn[i][0]]=-endStatus[opn[i][1]];
				break;
			case 'T':
				endStatus[opn[i][0]]=T;
				break;
			case 'F':
				endStatus[opn[i][0]]=F;
				break;
			case 'U':
				endStatus[opn[i][0]]=U;
				break;
		}
	}
	for(int i=1;i<=n;i++){
		if(endStatus[i]!=startStatus[i])
			return 0;
	}
	return 1;
}
void dfs(int t,int cntU){
	if(cntU>=minU)
		return;
	if(t>n){
		if(check()&&cntU<minU)
			minU=cntU;
		return;
	}
	startStatus[t]=T;
	dfs(t+1,cntU);
	startStatus[t]=F;
	dfs(t+1,cntU);
	startStatus[t]=U;
	dfs(t+1,cntU+1);
}
void test12(){
	minU=n;
	char op;
	for(int i=1;i<=m;i++){
		op=getchar();
		while(op=='\n'||op==' ')
			op=getchar();
		ops[i]=op;
		scanf("%d",&opn[i][0]);
		if(op=='+'||op=='-')
			scanf("%d",&opn[i][1]);
	}
	dfs(1,0);
	printf("%d\n",minU);
}
//end test 1&2


//test 3&4
void test34(){
	int sta[MAXN],index;
	memset(sta,0x3f,sizeof(sta));
	char op;
	for(int i=1;i<=m;i++){
		op=getchar();
		while(op=='\n'||op==' ')
			op=getchar();
		scanf("%d",&index);
		sta[index]=op=='T'?T:(op=='F'?F:U);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=sta[i]==U;
	printf("%d\n",cnt);
}
//end test3&4

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&Tt);
	for(int iT=0;iT<Tt;iT++){
		scanf("%d%d",&n,&m);
		switch(C){
			case 1:
			case 2:
				test12();
				break;
			case 3:
			case 4:
				test34();
				break;
		}
	}
	return 0;
}
