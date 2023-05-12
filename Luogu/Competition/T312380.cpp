#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    char l = '*', m = '*', r = '*', fa = '*';
};
int point(char a) {
    if (a == '*') {
        return -1;
    }
    if (a >= 'a' && a <= 'z') {
        return a - 'a';
    }
    else {
        return a - 'A' + 26;
    }
}
char point2(char a) {
    if (a < 26) {
        return 'a' + a;
    }
    else {
        return 'A' + a - 26;
    }
}

map<char, node> tree;
void getroot(char root) {
    printf("%c", root);
    if (tree[root].l != '*') {
        getroot(tree[root].l);
    }
    if (tree[root].m != '*') {
        getroot(tree[root].m);
    }
    if (tree[root].r != '*') {
        getroot(tree[root].r);
    }
}
void getright(char root) {
    if (tree[root].r != '*') {
        getright(tree[root].r);
    }
    if (tree[root].l != '*') {
        getright(tree[root].l);
    }
    printf("%c", root);
    if (tree[root].m != '*') {
        getright(tree[root].m);
    }
}
void getmid(char root) {
    if (tree[root].m != '*') {
        getmid(tree[root].m);
    }
    printf("%c", root);
    if (tree[root].r != '*') {
        getmid(tree[root].r);
    }
    if (tree[root].l != '*') {
        getmid(tree[root].l);
    }

}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("T312380.in","r",stdin);
    #endif
    int n;
    cin >> n;
    char cr, l, m, r;
    bool isfa[52]={0};
    while (cin >> cr >> l >> m >> r) {
        isfa[point(cr)]=1;
        isfa[point(l)]=0;
        isfa[point(m)]=0;
        isfa[point(r)]=0;
        tree[cr].l = l, tree[cr].m = m, tree[cr].r = r;
        if (l != '*') {
            tree[l].fa = cr;
        }
        if (m != '*') {
            tree[m].fa = cr;
        }
        if (r != '*') {
            tree[r].fa = cr;
        }
    }
    char root;
    for(int i=0;i<52;i++){
        if(isfa[i]){
            root=point2(i);
            break;
        }
    }
    getroot(root);
    cout << "\n";
    getmid(root);
    cout << "\n";
    getright(root);
    return 0;
}