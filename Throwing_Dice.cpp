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
const ll inf = 1LL << 62;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const ll mod = 1000000007;
#define djq 1000000007

inline int ksm(int base, int p) {int ret = 1; while (p) {if (p & 1)ret = 1ll * ret * base % djq; base = 1ll * base * base % djq, p >>= 1;} return ret;}
inline void pls(int& x, const int k) { x = (x + k >= djq ? x + k - djq : x + k); }
inline int add(const int a, const int b) { return a + b >= djq ? a + b - djq : a + b; }
inline void sub(int& x, const int k) { x = (x - k < 0 ? x - k + djq : x - k); }
inline int inc(const int a, const int b) { return a < b ? a - b + djq : a - b; }
inline void ckmn(int& x, const int k) { x = (k < x ? k : x); }
inline void ckmx(int& x, const int k) { x = (k > x ? k : x); }
const int lim = 2e5;






// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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



const int N = 200007;
int f[N], rf[N];
int C(int u, int v) {
    if (u < v || u < 0 || v < 0) return 0ll;
    return ((f[u] * rf[u - v] % mod) * rf[v]) % mod;
}


// const ll MAXM = 1e5;
// vector<ll> factors[MAXM + 5];
// void init() {
//     for (ll i = 1; i <= MAXM; i++) {
//         for (ll j = i; j <= MAXM; j += i) {
//             factors[j].pb(i);
//         }
//     }
// }





long long  power(long long base, long long exp, long long modulus) {
    base %= modulus;
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
        exp %= modulus;
    }
    return result;
}


vector<int> topo(int n, vector<vector<int>> &adj)
{
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto i : adj[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    // if (topo.size() == n) return topo;
    // return {};
    return topo;
}

long long highestPowerof2(long long N)
{
    // if N is a power of two simply return it
    if (!(N & (N - 1)))
        return N;
    // else set only the most significant bit
    return 0x8000000000000000 >> (__builtin_clzll(N));
}


int bfs(int source, int sink, vector<vector<int>> &g, int n, vector<int> &parent) {
    queue<pair<int, int>> q;
    vector<bool> vis(n, 0);
    q.push({source, INT_MAX});
    vis[source] = 1;
    while (!q.empty())
    {
        source = q.front().first;
        int cap = q.front().second;
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (g[source][i] && !vis[i])
            {
                parent[i] = source;
                if (i == sink)
                    return min(cap, g[source][i]);
                q.push({i, min(cap, g[source][i])});
                vis[i] = 1;
            }
        }
    }
    return 0;
}

int ford_fulkerson(int source, int sink, vector<vector<int>> &g, int n)
{
    int flow = 0;
    vector<int> parent(n, -1);
    int min_cap;
    while (min_cap = bfs(source, sink, g, n, parent))
    {
        flow += min_cap;
        int u, v = sink;
        while (v != source)
        {
            u = parent[v];
            g[u][v] -= min_cap;
            g[v][u] += min_cap;
            v = u;
        }
    }
    return flow;
}

vector<vector<int>> adj(N);
vector<int> vis(N);
vector<int> parity(N);



void solve() {
    int n; cin >> n;
    vector<vector<int>> e;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        e.push_back({a, b, 1});
    }
    queue<int> q;
    int i = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int node = q.front();
            vis[node] = 1;
            q.pop();
            if (i % 2) {
                parity[node] = 1;
            }
            else {
                parity[node] = 0;
            }
            for (auto i : adj[node]) {
                if (!vis[i]) {
                    q.push(i);
                }
            }
        }
        i++;
    }
    for (int i = 1; i <= n; i++) {
        if (parity[i] == 1) {
            e.push_back({i, n + 1, 1});
        }
        else {
            e.push_back({0, i, 1});
        }
    }
    cout << ford_fulkerson(0, n + 1, e, n + 2) << endl;
}




signed main()
{
    // f[0] = 1;
    // for (int i = 1; i < N; ++i) f[i] = f[i - 1] * i % mod;
    // rf[N - 1] = power(f[N - 1], mod - 2, mod);
    // for (int i = N - 1; i > 0; --i) rf[i - 1] = rf[i] * i % mod;


    // init();


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef ONLINEJUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);   // can need to change file . this one for taking input
    freopen("output.txt", "w", stdout); // this one for output
#endif



    int T;
    cin >> T;
    // int count = 0;
    while (T--)
        solve();

#ifdef ONLINEJUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
#endif

    return 0;
}


