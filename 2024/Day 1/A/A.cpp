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
typedef vector<int> vi;

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

int solve(vector<int>& nums1, vector<int> nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int ret = 0;
    FOR (i, 0, nums1.size()) {
        ret += abs(nums1[i] - nums2[i]);
    }
    return ret;
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    vector<int> nums1, nums2;

    string line;
    while (getline(cin, line)) {
        int num1, num2;
        stringstream scin(line);
        scin >> num1;
        scin >> num2;

        nums1.pb(num1);
        nums2.pb(num2);
    }

    cout << solve(nums1, nums2) << endl;

    return 0;
}
