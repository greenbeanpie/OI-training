#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int c,t;
int n,m;
int a[N];
int b[N];
vector<int> s[N];
bool bl[N][2];

void sn(int p){
	for(int i = 0;i < s[p].size();i++){
		int p2=s[p][i],y=0;
		if(p2<0){
			p2=-p2;
			y=1;
		}
//		if(p==8)cout << ":" << i << endl;
		if(a[p2]==0)continue;
		a[p2]=0;
		b[p2]=b[p]*pow(-1,y);
		sn(p2);
	}
	return;
}

void fn(int p,int x){
//	cout << p << endl;
	if(bl[p][0]){
		a[p]=0;
		if(bl[p][1]==x)b[p]=1;
		else b[p]=0;
		sn(p);
		return;
	}
	bl[p][0]=1;
	bl[p][1]=x;
	if(a[p]==0){
		sn(p);
		return;
	}
	int y = x,p2=a[p];
	if(p2<0){
		y=1-x;
		p2=-p2;
	}
//	cout << " " << p2 << endl;
	fn(p2,y);
	return;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> c >> t;
while(t--){
	cin >> n >> m;
	for(int _i = 1;_i <= n;_i++){
		a[_i]=_i;
		s[_i].clear();
		bl[_i][0]=0;
	}
	char v;
	for(int _i = 0;_i < m;_i++){
		cin >> v;
		int i,j;
		if(v == 'T'){
			cin >> i;
			a[i]=0;
			b[i]=1;
		}
		if(v == 'U'){
			cin >> i;
			a[i]=0;
			b[i]=0;
		}
		if(v == 'F'){
			cin >> i;
			a[i]=0;
			b[i]=-1;
		}
		if(v == '+'){
			cin >> i >> j;
			a[i]=a[j];
			if(a[j]==0){
				b[i]=b[j];
			}
		}
		if(v == '-'){
			cin >> i >> j;
			a[i]=-a[j];
			if(a[j]==0){
				b[i]=-b[j];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(a[i]==0||a[i]==i)continue;
		if(a[i]==-i){
			a[i]=0;
			b[i]=0;
		}
		if(a[i]>0)s[a[i]].push_back(i);
		if(a[i]<0)s[-a[i]].push_back(-i);
	}
//	for(int i = 1;i <= n;i++)cout << i << " " << a[i] << endl;
	for(int i = 1;i <= n;i++){
		if(!bl[i][0]){
			fn(i,1);
		}
	}
	int ans = 0;
//	cout << endl;
	for(int i = 1;i <= n;i++){
		if(b[i]==0)ans++;
	}
	cout << ans << endl;
}
	fclose(stdin);
	fclose(stdout);
}

