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

    string seq;
    cin >> seq;

    int n = 1;
    int maxNum = 1;
    char last = 'B';

    for (char c : seq)
    {
        if (c == last)
        {
            n++;
            maxNum = max(maxNum, n);
        }
        else
        {
            n = 1;
            last = c;
        }
    }

    cout << maxNum << endl;
}