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
    int w, h;
    cin >> w >> h;
    vector<vector<int>> polje(h, vector<int>(w));

    vector<vector<int>> h_indeksi(h, vector<int>(w, -1));
    vector<vector<int>> v_indeksi(h, vector<int>(w, -1));
    vi h_vrednosti(0, 100);
    vi v_vrednosti(0);

    rep(i, h)
    {
        rep(j, w)
        {
            cin >> polje[i][j];
        }
    }

    int num_points = 0;
    bool line = false;

    rep(i, h)
    {
        rep(j, w)
        {
            num_points = polje[i][j];
            if (num_points == 0)
            {
                line = false;
                continue;
            }
            if (line == false)
            {
                h_vrednosti.push_back(num_points);
                h_indeksi[i][j] = h_vrednosti.size() - 1;
                line = true;
            }
            else
            {
                h_indeksi[i][j] = h_vrednosti.size() - 1;
                h_vrednosti[h_indeksi[i][j]] += num_points;
                line = true;
            }
        }

        num_points = 0;
        line = false;
    }

    num_points = 0;
    line = false;

    rep(j, w)
    {
        rep(i, h)
        {
            num_points = polje[i][j];
            if (num_points == 0)
            {
                line = false;
                continue;
            }
            else if (line == false)
            {
                v_vrednosti.push_back(num_points);
                v_indeksi[i][j] = v_vrednosti.size() - 1;
                line = true;
            }
            else
            {
                v_indeksi[i][j] = v_vrednosti.size() - 1;
                v_vrednosti[v_indeksi[i][j]] += num_points;
                line = true;
            }
        }

        num_points = 0;
        line = false;
    }

    int best = 0;
    int is = 0;
    int js = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            int h = h_indeksi[i][j];
            int v = v_indeksi[i][j];
            if (h == -1 || v == -1)
                continue;
            int sum = h_vrednosti[h] + v_vrednosti[v] - (2 * polje[i][j]);
            if (sum > best)
            {
                best = sum;
                is = i;
                js = j;
            }
        }
    }

    cout << is << " " << js << endl;
}