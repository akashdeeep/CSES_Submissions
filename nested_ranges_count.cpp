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
// #define int long long
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// int dp[200005][20];

// void constructST(int a[], int n)
// {
//     for (int i = 0; i < n; i++)
//         dp[i][0] = a[i];
//     for (int j = 1; j <= 19; j++)
//         for (int i = 0; (i + (1 << j)) <= n; i++)
//             dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
// }

struct edge
{
    int L;
    int R;
    int id;
    edge(int a, int b, int c)
    {
        L = a;
        R = b;
        id = c;
    }
};

bool comp(edge a, edge b)
{
    if (a.L == b.L)
        return a.R > b.R;
    return a.L < b.L;
}

void solve()
{
    int n;
    cin >> n;
    vector<edge> arr;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        arr.push_back(edge(l, r, i));
    }
    sort(arr.begin(), arr.end(), comp);
    vector<int> ans1(n);
    vector<int> ans2(n);
    oset<pair<int, int>> st1;
    oset<pair<int, int>> st2;
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        int temp1 = arr[j].R;
        int index1 = st1.order_of_key({temp1 + 1, -1});
        ans1[arr[j].id] = index1;
        int temp2 = arr[i].R;
        int index2 = i - st2.order_of_key({temp2, -1});
        ans2[arr[i].id] = index2;
        st1.insert({temp1, index1});
        st2.insert({temp2, index2});
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;
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
