#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T &...args) { ((cin >> args), ...); }
template <typename... T>
void put(T &&...args) { ((cout << args << " "), ...); }
template <typename... T>
void putl(T &&...args)
{
    ((cout << args << " "), ...);
    cout << '\n';
}
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << "=" << a << ", ";
    err(++it, args...);
}
#define int long long
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vi>
#define vc vector
#define E cerr << '\n';
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define setpr(x) cout << setprecision(x) << fixed
#define seea(a, x, y)           \
    for (int i = x; i < y; i++) \
    {                           \
        cin >> a[i];            \
    }
#define seev(v, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        v.push_back(x);         \
    }
#define sees(s, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        s.insert(x);            \
    }
const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 998244353;
const ll mod = 1000000007;
#define djq 1000000007

// #define P complex<int>
// #define X real()
// #define Y imag()

inline int ksm(int base, int p) {int ret = 1; while (p) {if (p & 1)ret = 1ll * ret * base % djq; base = 1ll * base * base % djq, p >>= 1;} return ret;}
inline void pls(int& x, const int k) { x = (x + k >= djq ? x + k - djq : x + k); }
// inline int add(const int a, const int b) { return a + b >= djq ? a + b - djq : a + b; }
inline void sub(int& x, const int k) { x = (x - k < 0 ? x - k + djq : x - k); }
inline int inc(const int a, const int b) { return a < b ? a - b + djq : a - b; }
inline void ckmn(int& x, const int k) { x = (k < x ? k : x); }
inline void ckmx(int& x, const int k) { x = (k > x ? k : x); }
const int lim = 2e5;






// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using Tree = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// tree


// int dp[200005][20];

// void constructST(int a[], int n)
// {
//     for (int i = 0; i < n; i++)
//         dp[i][0] = a[i];
//     for (int j = 1; j <= 19; j++)
//         for (int i = 0; (i + (1 << j)) <= n; i++)
//             dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
// }

// struct edge
// {
//     int L;
//     int R;
//     int id;
//     edge(int a, int b, int c)
//     {
//         L = a;
//         R = b;
//         id = c;
//     }
// };



// const int N = 1e7 + 5;
// vector<int> smallest_prime_factor(N, 1);
// void calculate_smallest_prime_factor() {
//     int N = 1e7;
//     for (int i = 2; i <= N; i++) {
//         if (dp[i] == 1) {
//             dp[i] = i;
//             for (int j = i + i; j <= N; j += i) {
//                 if (dp[j] == 1) {
//                     dp[j] = i;
//                 }
//             }
//         }
//     }
// }



// const int N = 2000007;
// int f[N], rf[N];
// int C(int u, int v) {
//     if (u < v || u < 0 || v < 0) return 0ll;
//     return ((f[u] * rf[u - v] % mod) * rf[v]) % mod;
// }



const ll MAXM = 2e5;
vector<ll> factors[MAXM + 5];
void init() {
    for (ll i = 1; i <= MAXM; i++) {
        for (ll j = i; j <= MAXM; j += i) {
            factors[j].pb(i);
        }
    }
}



// const int mxN = 1e7 + 6;
// int spf[mxN];
// void sieve() {
//     spf[0] = 1;
//     for (int i = 1; i < mxN; i++)
//         spf[i] = i;
//     for (int i = 2; i * i < mxN; i++) {
//         if (spf[i] == i) {
//             for (int j = i * i; j < mxN; j += i) {
//                 if (spf[j] == j)
//                     spf[j] = i;
//             }
//         }
//     }
// }





// long long  power(long long base, long long exp, long long modulus = inf) {
//     base %= modulus;
//     long long result = 1;
//     while (exp > 0) {
//         if (exp & 1) result = (result * base) % modulus;
//         base = (base * base) % modulus;
//         exp >>= 1;
//         exp %= modulus;
//     }
//     return result;
// }


// vector<int> topo(int n, vector<vector<int>> &adj)
// {
//     vector<int> indegree(n, 0);
//     for (int i = 0; i < n; i++) {
//         for (auto it : adj[i]) {
//             indegree[it]++;
//         }
//     }
//     priority_queue<int, vector<int>, greater<int>> q;
//     for (int i = 0; i < n; i++) {
//         if (indegree[i] == 0) {
//             q.push(i);
//         }
//     }
//     vector<int> topo;
//     while (!q.empty()) {
//         int node = q.top(); q.pop();
//         topo.push_back(node);
//         for (auto i : adj[node]) {
//             indegree[i]--;
//             if (indegree[i] == 0) {
//                 q.push(i);
//             }
//         }
//     }
//     // if (topo.size() == n) return topo;
//     // return {};
//     return topo;
// }

// vector<int> lps_array(string s) {
//     int m = s.size();
//     vector<int> lps(m, 0);
//     int i = 1;
//     int len = 0;
//     while (i < m) {
//         if (s[i] == s[len]) {
//             len++;
//             lps[i] = len;
//             i++;
//         }
//         else {
//             if (len != 0) {
//                 len = lps[len - 1];
//             }
//             else {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
//     return lps;
// }

long long highestPowerof2(long long N)
{
    // if N is a power of two simply return it
    if (!(N & (N - 1)))
        return N;
    // else set only the most significant bit
    return 0x8000000000000000 >> (__builtin_clzll(N));
}



// vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
//     int n = a.size();
//     vector<vector<int>> c(n, vector<int> (n, 0));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             for (int k = 0; k < n; k++) {
//                 (c[i][j] += a[i][k] * b[k][j] % mod) %= mod;
//             }
//         }
//     }
//     return c;
// }
// vector<vector<int>> exp(vector<vector<int>> x, int y) {
//     int n = x.size();
//     vector<vector<int>> res(n, vector<int> (n, 0));
//     for (int i = 0; i < n; i++) {
//         res[i][i] = 1;
//     }
//     while (y > 0) {
//         if (y & 1) {
//             res = mul(res, x);
//         }
//         y = y >> 1;
//         x = mul(x, x);
//     }
//     return res;
// }

long long nearestPowerOf2(long long N)
{
    long long a = log2(N);
    if (pow(2, a) == N)
        return N;
    return pow(2, a + 1);
}


// vector<int> z_arr(string s) {
//     int n = s.size();
//     vector<int> z(n);
//     int x = 0, y = 0;
//     for (int i = 1; i < n; i++) {
//         z[i] = max(0LL, min(z[i - x], y - i + 1));
//         while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
//             x = i; y = i + z[i]; z[i]++;
//         }
//     }
//     return z;
// }


// const int N = 131072;
// int arr[N];
// int seg[N * 2][41];



// void build(int n) {
//     for (int i = 0; i < n; i++) {
//         for (int k = 1; k <= 40; k++) {
//             seg[i + n][k] = arr[i] == k;
//         }
//     }
//     for (int i = n - 1; i > 0; i--) {
//         // seg[i][0] = (seg[2 * i][0] + seg[2 * i + 1][0]);
//         for (int k = 1; k <= 40; k++) {
//             seg[i][k] = seg[i * 2][k] + seg[i * 2 + 1][k];
//         }
//     }
// }

// int find(int a, int b, int n) {
//     if (a > b) return 0;
//     a += n; b += n;
//     int s = 0;
//     while (a <= b) {
//         if (a % 2 == 1) {
//             // s = (s + seg[a][0]);
//             s = mul(s, seg[a]);
//             a++;
//         }
//         if (b % 2 == 0) {
//             // s = (s + seg[b][0]);
//             s2 = mul(seg[b], s2);
//             b--;
//         }
//         a /= 2; b /= 2;
//     }
//     return mul(s, s2);
// }

// void update(int ind, int u, int n) {
//     ind += n;
//     seg[ind][arr[ind - n]] = 0;
//     seg[ind][u] = 1;
//     arr[ind - n] = u;
//     for (int i = ind / 2; i >= 1; i /= 2) {
//         for (int k = 1; k <= 40; k++) {
//             seg[i][k] = seg[i * 2][k] + seg[i * 2 + 1][k];
//         }
//     }
// }




// class TrieNode {
// public:
//     TrieNode *child[2];
//     int cnt;
//     set<int> s;
//     TrieNode() {
//         for (auto &a : child) a = nullptr;
//         cnt = 0;
//     }
// };

// TrieNode *root = new TrieNode();
// void insert(string n, int ind) {
//     TrieNode *p = root;
//     for (char c : n) {
//         int i = c - '0';
//         if (!p->child[i]) p->child[i] = new TrieNode();
//         p = p->child[i];
//         p->cnt++;
//         p->s.insert(ind);
//     }
// }

// int search(string n) {
//     TrieNode *p = root;
//     bool parted = false;
//     for (char c : n) {
//         int i = c - '0';
//         if (parted) {
//             p = p->child[i];
//         }
//         else {
//             if (p->child[i]->cnt == 1) {
//                 p = p->child[1 - i];
//                 parted = true;
//             }
//             else {
//                 p = p->child[i];
//             }
//         }
//     }
//     return *p->s.begin();
// }





void solve() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int l = -1;
    int curr = 0;
    int ans = 0;
    map<int, int> ends;
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            curr = 0;
            l = i;
            ends[i] = i + 1;
        }
        else {
            curr += arr[i];
            if (curr > x) {
                ends[i] = ends[l] + 1;
                curr = 0;
                l = i;
            }
            else {

            }
        }
    }
}





signed main()
{
    // f[0] = 1;
    // for (int i = 1; i < N; ++i) f[i] = f[i - 1] * i % mod;
    // rf[N - 1] = power(f[N - 1], mod - 2, mod);
    // for (int i = N - 1; i > 0; --i) rf[i - 1] = rf[i] * i % mod;


    init();

    // sieve();


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef ONLINEJUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);   // can need to change file . this one for taking input
    freopen("output.txt", "w", stdout); // this one for output
#endif



    int T = 1;
    cin >> T;
    // // int cnt = 1;
    while (T--) {
        solve();
    }

#ifdef ONLINEJUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
#endif

    return 0;
}


// Why must I suffer so