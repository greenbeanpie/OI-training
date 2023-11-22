#include <bits/stdc++.h>
using namespace std;

// Simulation solution. I'm too rookie.
// This is a solution expected to get 80 points.

// Do not use 'endl' fliply.

// Not put !!! TEST CODE. Copy it back.
//constexpr int N = 1e6;
//constexpr int INSTR = 1e5;

// N = INSTR in this solution. CHECK RANGE OF N
#define N 200003
#define INSTR 100003

int n,m,id,uses;	// uses: Next (not last used) available
int c,t,current_use,dfs_ans;
int eq_fa[N], neq_fa[N];// Remember to clear
//bool neq_corr[N], changed[N];
bool ensure_unknown[N], value_firm[N];
char values[N], simu_values[N];
int represents[N];
// The value of node may depend on its father.
char optype[INSTR];
char attempts[3] = {'T','F','U'};
int op_first[INSTR], op_second[INSTR];
// repres: Current represention
// When look for value do &3.

char set_attempt[N];

char negative_of(char origin) {
	if (origin == 'T') return 'F';
	if (origin == 'F') return 'T';
	return 'U';
}
// call after n,m set, but uses not.
void clear_test() {
	
	for (int i = 1; i < uses; i++) {
		eq_fa[i] = neq_fa[i] = i;
//		eq_unknown[i] = false;
		ensure_unknown[i] = false;
		value_firm[i] = false;
		represents[i] = i;
	}
	dfs_ans = n;
	uses = n + 1;
}

int eq_query(int x) {
	if (eq_fa[x] == x) return x;
	else return eq_fa[x] = eq_query(eq_fa[x]);
}

bool verify_current() {
	current_use = 0;
	for (int i = 1; i <= n; i++) {
		simu_values[i] = values[i];
		if (values[i] == 'U') current_use++;
	}
	for (int i = 0; i < m; i++) {
		if (optype[i] == '+') {
			//cerr << "Value " << simu_values[op_second[i]] << " inherited to " << op_first[i] << " from " << op_second[i] << endl;
			simu_values[op_first[i]] = simu_values[op_second[i]];
		} else if (optype[i] == '-') {
			simu_values[op_first[i]] = negative_of(simu_values[op_second[i]]);
		} else {
			//cerr << "Value " << optype[i] << " directly given to " << op_first[i] << endl;
			simu_values[op_first[i]] = optype[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (simu_values[i] != values[i]) {
			return false;
		}
	}
	return true;
}

// filling #cur.
void s_dfs(int cur) {
	if (cur > n) {
		if (verify_current()) {
			if (current_use < dfs_ans) dfs_ans = current_use;
		}
	} else {
		for (int i = 0; i < 3; i++) {
			values[cur] = attempts[i];
			s_dfs(cur+1);
		}
	}
}

void readin(bool run_joint, bool initial, bool special) {
	cin>>n>>m;
	if (initial) uses = N;
	clear_test();
//	uses = n + 1;
	for (int i = 0; i < m; i++) {	// Pay attention to referrers.
		cin>>optype[i];
		if (optype[i] == '+' || optype[i] == '-') {
			cin>>op_first[i]>>op_second[i];
			if (run_joint) {
			
			}
		} else {
			cin>>op_first[i];	// Can't reach this.
			if (special) {

			} else {
				values[op_first[i]] = optype[i];
				value_firm[op_first[i]] = true;
			}
			
		}
	}
}

void c_12() {
	for (int sgroup = 0; sgroup < t; sgroup++) {
		readin(false, sgroup == 0, false);
		s_dfs(1);
		cout<<dfs_ans<<'\n';
	}
}

void c_56() {
	
}

void c_34() {
	for (int sgroup = 0; sgroup < t; sgroup++) {
		readin(false, sgroup == 0, false);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (values[i] == 'U') cnt++;
		}
		cout<<cnt<<'\n';
	}
}

void c_78() {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	// Remove if ensure no tle
	
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin>>c>>t;	// Don't clean too much things
	if (c == 1 || c == 2) {
		c_12();
	}
	if (c == 3 || c == 4) {
		c_34();
	}
	if (c == 5 || c == 6) {
		c_56();
	}
	if (c == 7 || c == 8) {
		c_78();
	}
	if (c == 9) c_12();
	if (c == 10) c_78();
	
	return 0;
}