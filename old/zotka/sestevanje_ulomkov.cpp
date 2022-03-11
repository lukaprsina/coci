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

    int n, m;
    cin >> n >> m;

    char x;
    int imenovalec = 1;
    double sum = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> x;
            imenovalec *= 2;
            if (x == 'S')
                sum += 1 / (double)imenovalec;
        }
        imenovalec = 1;
    }

    cout << ceil(sum) << endl;
}