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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ll t;
    cin >> t;

    ll elem;
    rep(i, t)
    {
        ll x, y;
        cin >> y >> x;

        if (x > y)
        {
            if (x % 2 == 1)
            {
                elem = pow(x, 2) + 1 - y;
            }
            else
            {
                elem = pow(x - 1, 2) + 2 + y;
            }
        }
        else if (x == y)
        {
            elem = pow(x, 2) - x + 1;
        }
        else
        {
            if (y % 2 == 1)
            {
                elem = pow(y - 1, 2) + 2 + x;
            }
            else
            {
                elem = pow(y, 2) + 1 - x;
            }
        }

        cout << elem << '\n';
    }
}