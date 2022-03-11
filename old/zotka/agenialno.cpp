#include <bits/stdc++.h>

using namespace std;

/* typedef long long ll;
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
#define MP make_pair */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, h;
    cin >> w >> h;
    vector<vector<int>> polje(h, vector<int>(w));
    vector<vector<int>> indeksi(h, vector<int>(w, -1));
    vector<int> vrednosti;
    vrednosti.reserve(1000);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> polje[i][j];
        }
    }

    int num_points = 0;
    bool line = false;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            num_points = polje[i][j];
            if (num_points == 0)
            {
                line = false;
                continue;
            }
            else if (line == false)
            {
                vrednosti.push_back(num_points);
            }
            else
            {
                cout << i << " " << j << endl;
                vrednosti[indeksi[i][j]] += num_points;
            }
            indeksi[i][j] = vrednosti.size() - 1;
            line = true;
        }

        num_points = 0;
        line = false;
    }

    cout << "end" << endl;
}