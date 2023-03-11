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

// tree

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

bool comp(pair<int, int> a, pair<int, int>b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int N = 1e5 + 5;
int vis[100005];
void dij(int s, vector<int> &dis, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>> pq;
    rep(i, 1, N) {
        dis[i] = inf;
    }
    dis[s] = 0;
    pq.push({0, s});
    memset(vis, 0, sizeof vis);
    while (!pq.empty()) {
        int a = pq.top().S;
        // cout << pq.top().F << " " << pq.top().S << endl;
        pq.pop();
        if (vis[a]) continue;
        vis[a] = 1;
        for (auto [b, w] : adj[a]) {
            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                pq.push({ -dis[b], b});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj1(n + 1);
    vector<vector<pair<int, int>>> adj2(n + 1);
    vector<tuple<int, int, int>> e;
    rep(i, 0, m) {
        int a, b, w;
        cin >> a >> b >> w;
        adj1[a].pb({b, w});
        adj2[b].pb({a, w});
        e.pb({a, b, w});
    }
    vector<int> dis1(N);
    vector<int> dis2(N);
    dij(1, dis1, adj1);
    dij(n, dis2, adj2);
    // for (int i : dis1) {
    //     cout << i << " ";
    // }
    int ans = inf;
    for (auto [a, b, w] : e) {
        ans = min(ans, dis1[a] + dis2[b] + w / 2);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef ONLINEJUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);   // can need to change file . this one for taking input
    freopen("output.txt", "w", stdout); // this one for output
#endif

    // int T;
    // cin >> T;
    // while (T--)
    solve();

#ifdef ONLINEJUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
#endif

    return 0;
}
