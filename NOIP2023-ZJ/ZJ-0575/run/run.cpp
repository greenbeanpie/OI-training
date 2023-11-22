#include<bits/stdc++.h>
using namespace std;

struct node{
	int l;
	int r;
	int z;
};

int c,t;
int n,m,k,d;
bool bl[100005];
long long ans = 0;
node a[100005];

void add(int p){
//	cout << p << endl;
	bl[p]=1;
	long long num = a[p].r-a[p].l+1;
	num *= d;
	if(a[p].z > num)ans+=a[p].z-num;
	return;
}

bool j(node n1,node n2){
	if(n1.l < n2.l)return true;
	if(n1.l > n2.l)return false;
	return n1.r < n2.r;
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
cin >> c >> t;
while(t--){
	ans = 0;
	cin >> n >> m >> k >> d;
	for(int i = 0;i < m;i++){
		bl[i]=0;
	}
	int y;
	int i = 0;
	while(i<m){
		cin >>a[i].r >> y >> a[i].z;
		if(y>k){
			m--;
			continue;
		}
		a[i].l=a[i].r-y+1;
		i++;
	}
	sort(a,a+m,j);
//	for(int i = 0;i < m;i++){
//		cout << a[i].l << " " << a[i].r << " " << a[i].z << endl;
//	}
	bool bol[100005];bol[0]=1;bol[m]=1;
	for(int i = 1;i < m;i++){
		if(a[i-1].r<a[i].l)bol[i]=1;
	}
	for(int i = 0;i < m;i++){
		if(bol[i]&&bol[i+1]&&!bl[i])add(i);
	}
	int p = 0;
	while(true){
		while(bl[p]&&p<m)p++;
		if(p==m)break;
		int q=p;
		while(!bl[q]&&q<m)q++;
		q--;
//		cout << p << " " << q << endl;
		int l = p,r=p;
		long long num = a[p].r-a[p].l+1;
		num *= d;
		num = a[p].z-num;
//		cout << num << endl;
		long long mx = num;if(mx<0)mx=0;
		int h = a[p].r,h2;long long dd;
		for(int i = p+1;i <= q;i++){
			h2 = max(h,a[i].r);
			num+=a[i].z;
			dd=h2-h;dd*=d;num-=dd;h=h2;
			long long t=0;
//		cout << num << endl;
			for(int j = l;j < i;j++){
				t+=a[j].z;
				dd=a[j+1].l-a[j].l;dd*=d;
				t-=dd;
				if(t<0||h-a[l].l+1>k){
					num-=t;
					t=0;
					l=j;
				}
			}
			mx = max(mx,num);
//			cout << "!" << mx << endl;
		}
		ans += mx;
//		cout << ans;
		p=q+1;
	}
	cout << ans << endl;
}
fclose(stdin);
fclose(stdout);
}
//1 1
//10 5 5 1
//3 2 3
//5 2 1
//5 4 6
//8 3 5
//10 3 3
