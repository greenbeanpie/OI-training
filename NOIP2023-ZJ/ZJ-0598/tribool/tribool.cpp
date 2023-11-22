#include<bits/stdc++.h>
using namespace std;
int n,m;
char tp;
bool numd[100000+5];
bool cdd[100000+5];//是否被操作过
int val[100000+5];
int cdnum;
int c,t;
vector<int>edge1[100000+5];//equal
vector<int>edge2[100000+5];//noteq
int eq[100000+5][2],nq[100000+5][2],eqn,nqn;
int H[256];
int abs_(int x){
	return x>0?x:-x;
}
int dfn[100000+5],col[100000+5],low[100000+5],siz[100000+5],top,st[100000+5];
bool vis[100000+5];//第i个联通块是否被访问！！
bool vsn[100000+5];
int tas[100000+5];//-1->U
int tag=0,dfncnt=0,colnum;
void tarjan_memset(){
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(siz,0,sizeof(siz));
	memset(vis,false,sizeof(vis));
	memset(vsn,false,sizeof(vsn));
	memset(tas,0,sizeof(tas));
	memset(col,0,sizeof(col));
	dfncnt=0,tag=0,colnum=0;
	memset(val,0,sizeof(val));
	top=0;
}

void tarjan(int u){
//	cout<<"tarjan "<<u<<"\n";
	dfn[u]=low[u]=++dfncnt;
	st[++top]=u;
	for(int i=0,i1=edge1[u].size();i<i1;i++){
		int v=edge1[u][i];
		if(!cdd[v]) continue;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!col[v]){
			dfn[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		//in
		col[u]=++colnum;
		siz[colnum]++;
		while(st[top]!=u){
			col[st[top]]=colnum;
			top--;
			siz[colnum]++;
		}
		top--;
	}
}
bool vst[100000+5];
int INT_MM=(1<<29);
int soll(int u,int VAL_U){
	//第u个联通块及其能连接到的所有块！
	memset(val,0,sizeof(val));
	for(int i=1;i<=colnum;i++) vsn[i]=vis[i];
	vsn[u]=true;
	val[u]=VAL_U;
	int ans1=0;
	if(VAL_U==0) ans1=siz[u];
	queue<int>g;
	g.push(u);
	while(!g.empty()){
		int pt=g.front();
		g.pop();
		//遍历等边！！
	//	cout<<"start:"<<u<<" on "<<pt<<"\n";
		for(int i=0,i1=edge1[pt].size();i<i1;i++){
			int to=edge1[pt][i];
			if(!vsn[to]){
				val[to]=val[pt];
				if(val[to]==0) ans1+=siz[to];
				vsn[to]=1;
				g.push(to);
			}
			else if(val[to]!=val[pt]){
				return INT_MM;
			}
		}
		for(int i=0,i2=edge2[pt].size();i<i2;i++){
			int to=edge2[pt][i];
			if(!vsn[to]){
				val[to]=0-val[pt];
				if(val[to]==0) ans1+=siz[to];
				vsn[to]=1;
				g.push(to);
			}
			else if(val[to]+val[pt]!=0)
				return INT_MM;
		}
	}
	return ans1;
}
//
int vall(int u){
//	cout<<"on u:"<<u<<"\n";
//	cout<<" 1 -> "<<soll(u,1)<<"\n"<<" 0 ->"<<soll(u,0)<<" -1 -> "<<soll(u,-1)<<"\n";
	int ANS=0;
	ANS=min(soll(u,1),min(soll(u,0),soll(u,-1)));
//	cout<<ANS<<"[[[\n";
	queue<int>g;
	g.push(u);
	vis[u]=1;
	cdnum-=siz[u];
	while(!g.empty()){
		int tt=g.front();
		g.pop();
		for(int i=0,i1=edge1[tt].size();i<i1;i++){
			int to=edge1[tt][i];
			if(!vis[to]){
				vis[to]=1;
				cdnum-=siz[to];
				g.push(to);
			}
		}
		for(int i=0,i2=edge2[tt].size();i<i2;i++){
			int to=edge2[tt][i];
			if(!vis[to]){
				cdnum-=siz[to];
				vis[to]=1;
				g.push(to);
			}
		}
	}
	return ANS;
}
void pp(int stage,int i){
	//cout<<"ENd stage:"<<stage<<" nu:"<<i<<"\n";
}
int ttt[100000+5],eqq[100000+5],nqq[100000+5];
int main(){
	ifstream fin("tribool.in");
	ofstream fout("tribool.out");
	fin>>c>>t;
	H['T']=1,H['F']=-1,H['U']=0;
	int ccc,x1,x2;
	for(int tes=1;tes<=t;tes++){
	//	cout<<"tes="<<tes<<"\n";
		fin>>n>>m;
		cdnum=0;
		for(int i=1;i<=n;i++) val[i]=0,numd[i]=false,cdd[i]=false,ttt[i]=0,eqq[i]=0,nqq[i]=0;
		int ans=0;
	//	cout<<" on "<<tes<<"\n";
		tag=0,eqn=0,nqn=0;
		
		for(int i=1;i<=m;i++){
			fin>>tp;
			if(tp=='T'||tp=='F'||tp=='U'){
				fin>>ccc;
				val[ccc]=H[tp],ttt[ccc]=1;
				if(!numd[ccc])
					cdd[ccc]=1,numd[ccc]=1,cdnum++;
			}
			else if(tp=='+'){
				fin>>x1>>x2;
				//eqn++;
				//eq[eqn][0]=x1,eq[eqn][1]=x2;
				if(!cdd[x1]) cdd[x1]=1,cdnum++;
				if(!cdd[x2]) cdd[x2]=1,cdnum++;
			//	edge1[x1].push_back(x2);
				ttt[x1]=2,eqq[x1]=x2;
			//	edge1[x2].push_back(x1);
			}
			else if(tp=='-'){
				fin>>x1>>x2;
				nqn++;
				nq[nqn][0]=x1,nq[nqn][1]=x2;
				if(!cdd[x1]) cdd[x1]=1,cdnum++;
				if(!cdd[x2]) cdd[x2]=1,cdnum++;
			//	edge2[x1].push_back(x2);
			//	edge2[x2].push_back(x1);
				ttt[x1]=3,nqq[x1]=x2;
			}
		}
	//	cout<<"st:"<<tes<<" stage_num:"<<cdnum<<"\n";
		//pp(-1,tes);
		for(int i=1;i<=n;i++){
			if(ttt[i]==2){
				eqn++;
				eq[eqn][0]=i,eq[eqn][1]=eqq[i];	
				edge1[eqq[i]].push_back(i);
				edge1[i].push_back(eqq[i]);
			}
			else if(ttt[i]==3){
				nqn++;
				nq[nqn][0]=i,nq[nqn][1]=nqq[i];	
				edge2[nqq[i]].push_back(i);
				edge2[i].push_back(nqq[i]);
			}
		}
		queue<int>g;
		for(int i=1;i<=n;i++){
			if(numd[i]){
				if(val[i]==0){
					ans++;
				}
				cdnum--;
				cdd[i]=0;
				g.push(i);
			}
		}
		if(cdnum==0){
			fout<<ans<<"\n";
			continue;
		}
	//	pp(-1,tes);
		//pp(-1,tes);
		//此后cdd用于表示第i个点是否能遍历！！！
		while(!g.empty()){
			int pt=g.front();
			g.pop();
			//遍历等边！！
			if(cdnum==0) break;
			for(int i=0,i1=edge1[pt].size();i<i1;i++){
				int to=edge1[pt][i];
				if(cdd[to]){
					val[to]=val[pt];
					if(val[to]==0) ans++;
					cdd[to]=0,cdnum--;
					g.push(to);
				}
			}
			for(int i=0,i2=edge2[pt].size();i<i2;i++){
				int to=edge2[pt][i];
				if(cdd[to]){
					val[to]=0-val[pt];
					if(val[to]==0) ans++;
					cdd[to]=0,cdnum--;
					g.push(to);
				}
			}
		}
		//	cout<<"taa\n";
		//pp(-1,tes);
		if(cdnum==0){
			//不存在能被操作的变量了！！！
		//	pp(1,tes);
			fout<<ans<<"\n";
			continue;
		}
		//cout<<"ans="<<ans<<"\n";
		//此部分处理能被确定取值的变量！！
		tarjan_memset();
		memset(vst,false,sizeof(vst));
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(cdd[i]&&!dfn[i]){
				//它居然还能操作
				tarjan(i);//缩点！！！
			}
		}
		for(int i=1;i<=colnum;i++)
			edge1[i].clear(),edge2[i].clear();
		for(int i=1;i<=eqn;i++){
			int x1=eq[i][0],x2=eq[i][1];
			//cout<<"x1="<<x1<<"x2="<<x2<<"\n";
			if(cdd[x1]&&col[x1]!=col[x2]){
				//cout<<"NQ"<<x1<<" --- "<<x2<<"\n";
				//edge2[col[x1]].push_back(col[x2]);
			//	edge1[col[x1]].push_back(col[x2]);
				edge1[col[x2]].push_back(col[x1]);
			}
		}
		for(int i=1;i<=nqn;i++){
			int x1=nq[i][0],x2=nq[i][1];
			//cout<<"x1="<<x1<<"x2="<<x2<<"\n";
			if(cdd[x1]&&col[x1]!=col[x2]){
				//cout<<"NQ"<<x1<<" --- "<<x2<<"\n";
			//	edge2[col[x1]].push_back(col[x2]);
				edge2[col[x2]].push_back(col[x1]);
			}
			else if(cdd[x1]&&(col[x1]==col[x2])){
				tas[col[x1]]=-1;
			}
		}
		//pp(-1,tes);
		queue<int>l;
//		cout<<"stat:"<<tes<<"\n";
	//	for(int i=1;i<=n;i++){
	//		if(col[i])
	//			cout<<"col "<<i<<"="<<col[i]<<" ";
	//	}
//		cout<<"\n";
		//int ttt=0;
	//	cout<<"ans="<<ans<<"\n";
		for(int i=1;i<=colnum;i++){
			val[i]=0;
			if(cdnum==0) break;
			if(tas[i]==-1){
				//u!!!
				l.push(i);
				ans+=siz[i];//求和！！
				vis[i]=1;//过了
				cdnum-=siz[i];
				//ttt++;
			}
		}
	//	cout<<"ttt="<<ttt<<"\n";
	//	cout<<"cdnum:"<<cdnum<<"\n";
		//cout<<"ans="<<ans<<"\n";
		if(cdnum==0){
		//	pp(2,tes);
			fout<<ans<<"\n";
			continue;
		}
		while(!l.empty()){
			int pt=l.front();
			l.pop();
			if(cdnum==0) break;
			for(int i=0,i1=edge1[pt].size();i<i1;i++){
				int to=edge1[pt][i];
				if(!vis[to]){
					val[to]=val[pt];
					if(val[to]==0) ans+=siz[to];
					vis[to]=1,cdnum-=siz[to];
					l.push(to);
				}
			}
			for(int i=0,i2=edge2[pt].size();i<i2;i++){
				int to=edge2[pt][i];
				if(!vis[to]){
					val[to]=0-val[pt];
					if(val[to]==0) ans+=siz[to];
					vis[to]=1,cdnum-=siz[to];
					l.push(to);
				}
			}
		}
		//cout<<"ans="<<ans<<"\n";
		if(cdnum==0){
			pp(3,tes);
			fout<<ans<<"\n";
			continue;
		}
	//	for(int i=1;i<=colnum;i++){
	//		cout<<"on "<<i<<" ";
	//		cout<<"size1:"<<edge1[i].size()<<"size2:"<<edge2[i].size()<<"\n";
	//	}
		for(int i=1;i<=colnum;i++){
			if(cdnum==0) break;
			if(!vis[i]){
			//	cout<<"check "<<i<<"\n";
				int tpr=vall(i);
				ans+=tpr;
			//	cout<<"ans on "<<i<<" eq "<<tpr<<"\n";
			}
		}
	//	pp(4,tes);
		fout<<ans<<"\n";
		for(int i=1;i<=n;i++)
			edge1[i].clear(),edge2[i].clear();
	}
	fout.close();
//	system("FC tribool.out tribool2.ans");
	return 0;
}
/*

0.5h t1
4.0h t2
failed for anyway.
  ################################### ib 2023.11.18


*/