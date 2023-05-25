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

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

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

int power(int x, int y, int p = 1e9 + 7)
{
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
            res = (res * x);
        res %= p;
        y = y >> 1;
        x = (x * x);
        x %= p;
    }
    return res % p;
}

bool comp(int a, int b)
{
    if (a % 2 == 0)
        return true;
    if (b % 2 == 0)
        return false;
    return false;
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

void dfs(int ind, vector<int> &vis, vector<int> &s, vector<vector<int>> &adj) {
    vis[ind] = 1;
    // cout << ind << endl;
    int ans = 0;
    for (int j : adj[ind]) {
        if (!vis[j]) {
            dfs(j, vis, s, adj);
            ans += s[j];
        }
    }
    s[ind] = ans;
}

int calculateNcR(int n, int r, int mod)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;
    return p;
}


long long nearestPowerOf2(long long N)
{
    long long a = log2(N);

    if (pow(2, a) == N)
        return N;

    return pow(2, a + 1);
}
int find(int a, int b, vector<int> &seg_tree) {
    if (a < 0) return 0;
    int n = seg_tree.size() / 2;
    a += n; b += n;
    int s = INT_MAX;
    while (a <= b) {
        if (a % 2 == 1) s = min(s, seg_tree[a++]);
        if (b % 2 == 0) s = min(s, seg_tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}
void update(int k, int u, vector<int> &seg_tree) {
    int n = seg_tree.size() / 2;
    k += n;

    seg_tree[k] = u;
    for (k /= 2; k >= 1; k /= 2) {
        // cout << k << endl;
        seg_tree[k] = min(seg_tree[2 * k], seg_tree[2 * k + 1]);
    }

}

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    n = nearestPowerOf2(n);
    vector<int> sgt1(2 * n, INT_MAX);
    for (int i = 0; i < n and i < arr.size(); i++) {
        sgt1[i + n] = arr[i] + i;
    }
    vector<int> sgt2(2 * n, INT_MAX);
    for (int i = 0; i < n and i < arr.size(); i++) {
        sgt2[i + n] = arr[i] + (n - 1 - i);
    }
    for (int i = n - 1; i > 0; i--) {
        sgt1[i] = min(sgt1[2 * i], sgt1[2 * i + 1]);
        sgt2[i] = min(sgt2[2 * i], sgt2[2 * i + 1]);
    }
    while (q--) {

        int ver; cin >> ver;
        if (ver == 1) {
            int k,  x; cin >> k >> x;
            update(k - 1, x + k - 1, sgt1);
            update(k - 1, x + (n - k), sgt2);
        }
        else {
            int k; cin >> k;
            int ans = min(find(0, k - 1, sgt2) - (n - k), find(k - 1, n - 1, sgt1) - k + 1);
            cout << ans << endl;
        }
        // for (int i = 0; i < 2 * n; i++) {
        //     cout << sgt1[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < 2 * n; i++) {
        //     cout << sgt2[i] << " ";
        // }
        // cout << endl;
        // endl;
    }

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
    // // int count = 0;
    // while (T--)
    solve();

#ifdef ONLINEJUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
#endif

    return 0;
}


