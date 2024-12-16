#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(decltype((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, string> is;
typedef vector<int> vi;
typedef vector<is> vis;
typedef vector<ii> vii;

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

void printVi(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> getDisk(const string& line) {
    vector<int> ret;

    deque<ii> dq[10];
    queue<int> used, empty;
    for (int i = 0, id = 0; i < line.size(); i ++) {
        int d = line[i] - '0';
        if (i % 2 == 0) {
            dq[d].push_front(ii(id ++, i));
            used.push(d);
        }
        else {
            empty.push(d);
        }
    }

    for (bool b = true; used.size() || empty.size(); b = !b) {
        if (b) {
            int d = used.front();
            used.pop();

            FOR (k, 0, d) {
                ret.pb(dq);
            }
        }
    }

    bool file = true;
    int id = 0;
    for (int i = 0, file = true, id = 0; i < line.size(); i ++, file = !file) {
        int d = line[i] - '0';

        int add = -1;
        if (file) {
            add = id ++;
        }

        FOR (k, 0, d) {
            ret.pb(add);
        }
    }

    return ret;
}

void compactDisk(vector<int>& disk) {
    for (int i = 0, j = disk.size() - 1; i < j; i ++) {
        while (disk[j] == -1 && i < j) {
            j --;
        }

        if (i == j) {
            break;
        }

        if (disk[i] == -1) {
            disk[i] = disk[j];
            disk[j --] = -1;
        }
    }
}

ll getAns(vector<int>& disk) {
    ll ret = 0;

    FOR (i, 0, disk.size()) {
        if (disk[i] == -1) {
            break;
        }

        ret = ret + disk[i] * i;
    }

    return ret;
}

ll solve(const string& line) {
    ll ret = 0;

    vector<int> disk = getDisk(line);
    ret = getAns(disk);

    return ret;
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    string line;
    while (getline(cin, line)) {
    }

    cout << solve(line) << endl;

    return 0;
}
