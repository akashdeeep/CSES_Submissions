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
#define L cout << '\n';
#define E cerr << '\n';
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define setpr(x) cout << setprecision(x) << fixed
#define sz size()
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

int dp[200005][20];

void constructST(int a[], int n)
{
    for (int i = 0; i < n; i++)
        dp[i][0] = a[i];
    for (int j = 1; j <= 19; j++)
        for (int i = 0; (i + (1 << j)) <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}

// BFS template

// DFS template
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, ls);
        }
    }
}

bool comp(int a, int b)
{
    return a > b;
}

int temp(vector<int> arr, int s)
{
    int count = 0;
    int temp = 0;
    for (auto i : arr)
    {
        if (temp + i > s)
        {
            if (i > s)
            {
                return INT_MAX;
            }
            temp = i;
            count += 1;
        }
        else
        {
            temp += i;
        }
    }
    count += 1;
    return count;
}

vector<int> bfs(int V, vector<int> adj[])
{
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i : adj[node])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return ans;
}
vector<int> topological_sort(int n, vector<int> adj[])
{
    int indegree[n] = {0};
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
                q.push(i);
        }
    }
    return topo;
}

signed main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> adj[n];
    vector<vector<int>> ans(n, vector<int>(n, 1000000000000));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        ans[a][a] = 0;
        ans[b][b] = 0;
        ans[a][b] = min(ans[a][b], c), ans[b][a] = min(ans[b][a], c);
    }

    rep(k, 0, n)
    {
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (ans[i][j] == 1000000000000)
                ans[i][j] = -1;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << ans[a][b] << " ";
    }
}
