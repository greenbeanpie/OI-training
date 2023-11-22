#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#ifdef DEBUG
template<typename T>
ostream& operator << (ostream &out,vector<T> a){
	out<<'[';
	for(T x:a)out<<x<<',';
	return out<<']';
}
template<typename T>
vector<T> ary(T *a,int l,int r){
	return vector<T>{a+l,a+1+r};
}
template<typename T>
void debug(T x){
	cerr<<x<<endl;
}
template<typename T,typename...S>
void debug(T x,S...y){
	cerr<<x<<' ',debug(y...);
}
#else
#define debug(...) void()
#endif
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	return 0;
}