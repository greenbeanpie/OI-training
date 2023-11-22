#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100,N1=2e3+10;
int C,n,m,q;
int x_1[N1],y_1[N1],x_11[N1],y_11[N1],flag_1;
bool f_1[N1][N1];
void copy_1(){
	for (int i=1;i<=n;++i) x_11[i]=x_1[i];
	for (int i=1;i<=m;++i) y_11[i]=y_1[i];
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			f_1[i][j]=0;
		}
	}
}
void dfs_1_1(int i_1,int j_1){
	if (flag_1||f_1[i_1][j_1]) return;
	if (i_1==n&&j_1==m){
		if (x_11[i_1]>y_11[j_1]) flag_1=1;
		return;
	}
	if (x_11[i_1]>y_11[j_1]){
		if (i_1<n) dfs_1_1(i_1+1,j_1);
		if (j_1<m) dfs_1_1(i_1,j_1+1);
		if (i_1<n&&j_1<m) dfs_1_1(i_1+1,j_1+1);
	}
	f_1[i_1][j_1]=1;
}
void dfs_1_2(int i_1,int j_1){
	if (flag_1||f_1[i_1][j_1]) return;
	if (i_1==n&&j_1==m){
		if (x_11[i_1]<y_11[j_1]) flag_1=1;
		return;
	}
	if (x_11[i_1]<y_11[j_1]){
		if (i_1<n) dfs_1_2(i_1+1,j_1);
		if (j_1<m) dfs_1_2(i_1,j_1+1);
		if (i_1<n&&j_1<m) dfs_1_2(i_1+1,j_1+1);
	}
	f_1[i_1][j_1]=1;
}
void work_1(){
	if (x_11[1]==y_11[1]){
		printf("0");
		return;
	}
	flag_1=0;
	if (x_11[1]>y_11[1]&&x_11[n]>y_11[m]){
		dfs_1_1(1,1);
	}
	if (x_11[1]<y_11[1]&&x_11[n]<y_11[m]){
		dfs_1_2(1,1);
	}
	if (flag_1) printf("1");
	else printf("0");
}
void solve_1(){
	for (int i=1;i<=n;++i) scanf("%d",&x_1[i]);
	for (int i=1;i<=m;++i) scanf("%d",&y_1[i]);
	copy_1();
	work_1();
	for (int i=1;i<=q;++i){
		int kx_1,ky_1;
		scanf("%d%d",&kx_1,&ky_1);
		copy_1();
		for (int j=1;j<=kx_1;++j){
			int x_1,v_1;
			scanf("%d%d",&x_1,&v_1);
			x_11[x_1]=v_1;
		}
		for (int j=1;j<=ky_1;++j){
			int y_1,v_1;
			scanf("%d%d",&y_1,&v_1);
			y_11[y_1]=v_1;
		}
		work_1();
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&C,&n,&m,&q);
	if (C<=7){
		solve_1();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
