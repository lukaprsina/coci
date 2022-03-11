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

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    if (n % 4 == 1 || n % 4 == 2)
        cout << "NO" << endl;
    else if (n % 4 == 3)
    {
        cout << "YES" << endl;

        cout << n / 2 << endl;
        for (int i = 2; i <= n / 2; i += 2)
            cout << i << " " << n - i << " ";

        cout << n << endl;

        cout << n / 2 + 1 << endl;
        for (int i = 1; i <= n / 2; i += 2)
            cout << i << " " << n - i << " ";
    }
    else
    {
        cout << "YES" << endl;

        cout << n / 2 << endl;
        for (int i = 2; i <= n / 2; i += 2)
            cout << i << " " << n - i + 1 << " ";

        cout << n / 2 << endl;
        for (int i = 1; i <= n / 2; i += 2)
            cout << i << " " << n - i + 1 << " ";
    }
    cout << endl;
}