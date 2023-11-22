#define PROBLEM tribool

#ifdef DEBUG_zPbYWEQlRAWJ3OvuMksw50wYDAJC1812TmBHJtbb6mMCAYXCXJ1B3EZrwVgIcUA0
#include <iostream>
#else
#define _STR(x) #x
#define _FNAME(x, ext) _STR(x) "." #ext
#include <fstream>
namespace std {
    ifstream cin(_FNAME(PROBLEM, in));
    ofstream cout(_FNAME(PROBLEM, out));
}
#undef _FNAME
#undef _STR
#endif

namespace ns0 {
    class TriBool {
    private:
        bool unknown;
        bool value;
    public:
        TriBool() : unknown(true) { }
        TriBool(bool booleanValue) : unknown(false), value(booleanValue) { }
        inline bool IsUnknown() { return unknown; }
        inline bool IsTrue() { return !unknown && value; }
        inline bool IsFalse() { return !unknown && !value; }
        inline operator bool() { return IsTrue(); }
        inline TriBool operator !() {
            TriBool result = *this;
            result.value = !result.value;
            return result;
        }
        inline static TriBool Unknown() { return TriBool(); };
        inline static TriBool True() { return TriBool(true); };
        inline static TriBool False() { return TriBool(false); };
    };
    struct State {
        int Target;
        TriBool Tag;
    };
    State variables[100000];
    void Initialize(int tsz) {
        for (int i = 0; i < tsz; i++) {
            variables[i].Tag = TriBool::False();
            variables[i].Target = i;
        }
    }
    TriBool visiting[100000];
    TriBool NormalizeState(int id, bool reverseTag = false) {
        if (variables[id].Target == -1) {
            return variables[id].Tag;
        }
        if (visiting[id].IsUnknown()) {
            visiting[id] = reverseTag;
            if (variables[id].Tag) {
                variables[id].Tag = !NormalizeState(variables[id].Target, !reverseTag);
            }
            else {
                variables[id].Tag = NormalizeState(variables[id].Target, reverseTag);
            }
            variables[id].Target = -1;
            visiting[id] = TriBool::Unknown();
            return variables[id].Tag;
        }
        else {
            variables[id].Target = -1;
            if (visiting[id] != reverseTag) {
                return variables[id].Tag = TriBool::Unknown();
            }
            else {
                return variables[id].Tag = false;
            }
        }
    }
    int main() {
        int _, T;
        std::cin >> _ >> T;
        for (int _ = 0; _ < T; _++) {
            int n, m;
            std::cin >> n >> m;
            Initialize(n);
            for (int i = 0; i < m; i++) {
                char opcode;
                int lvar, rvar;
                std::cin >> opcode >> lvar;
                lvar--;
                switch (opcode) {
                case '+':
                    std::cin >> rvar;
                    rvar--;
                    variables[lvar].Target = variables[rvar].Target;
                    variables[lvar].Tag = variables[rvar].Tag;
                    break;
                case '-':
                    std::cin >> rvar;
                    rvar--;
                    variables[lvar].Target = variables[rvar].Target ;
                    variables[lvar].Tag = !variables[rvar].Tag;
                    break;
                case 'T':
                    variables[lvar].Target = -1;
                    variables[lvar].Tag = TriBool::True();
                    break;
                case 'F':
                    variables[lvar].Target = -1;
                    variables[lvar].Tag = TriBool::False();
                    break;
                case 'U':
                    variables[lvar].Target = -1;
                    variables[lvar].Tag = TriBool::Unknown();
                    break;
                default: throw; // Should not happen.
                }
            }
            for (int i = 0; i < n; i++) {
                NormalizeState(i);
            }
            int unknowns = 0;
            for (int i = 0; i < n; i++) {
                unknowns += variables[i].Tag.IsUnknown();
            }
            std::cout << unknowns << '\n';
        }
        return 0;
    }
}

int main() {
    return ns0::main();
}
