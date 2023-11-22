#include <bits/stdc++.h>
using namespace std;
ifstream fin("tribool.in");
ofstream fout("tribool.out");
using ll = long long;
using ull = unsigned long long;
using sh = short;
using ush = unsigned short;
/*
struct tribool {
    int8_t v=0;
    tribool()=default;
    tribool(int8_t _v):v(_v) {}
    operator int8_t() {
        return v;
    }
    operator char() {
        return v?(v==1?'T':'F'):'U';
    }
    tribool operator!(){
        return -v;
    }
    bool operator==(tribool& x) {return v==x.v;}
    bool operator==(int8_t x) {return v==x;}
};

struct opn {
    char o='U';
    int i=0,j=-1;
    opn()=default;
    tribool run(vector<tribool> &vs) {
        switch(o) {
        case 'T': vs[i]=1; break;
        case 'F': vs[i]=0; break;
        case 'U': vs[i]=-1; break;
        case '+': vs[i]=vs[j]; break;
        case '-': vs[i]=!vs[j]; break;
        default: return 0;
        }
        return vs[i];
    }
};

bool operator==(vector<tribool>&a, vector<tribool>&b){
    if(a.size()!=b.size()) return false;
    int n=a.size();
    for(int i=0;i<n;++i) if(!(a[i]==b[i])) return false;
    return true;
}
*/
int c,t,n,m;

inline void solve() {
    fin>>n>>m;
    if(c==3||c==4) {
        bitset<100010> isU;
        for(int _i=0; _i<m; ++_i) {
            char op;
            int i;
            fin>>op>>i;
            if(op=='U') isU.set(i);
            else isU.reset(i);
        }
        fout<<isU.count()<<'\n';
        return;
    }
}

int main() {
    fin>>c>>t;
    for(int i=0; i<t; ++i) solve();
    return 0;
}
