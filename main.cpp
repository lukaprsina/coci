#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef deque<int> di;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pr;
typedef vector<pr> vii;
typedef vector<string> vstr;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repi(i, a, n) for (int i = a; i < n; i++)
#define all(n) n.begin(), n.end()
#define allr(n) n.rbegin(), n.rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair

const ll MOD = 1e9 + 7;

ll fastpow2(int x)
{
    ll res = 1;
    ll a = 2;
    while (x > 0)
    {
        if (x & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        x >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ll n;
    cin >> n;

    cout << fastpow2(n) << endl;
}