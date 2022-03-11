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
    /* Prva vrstica je vzorec, druga število besed, nato besede */
    int n;
    bool ok = true;
    string vzorec;
    string beseda;
    cin >> vzorec;
    cin >> n;
    rep(i, n)
    {
        cin >> beseda;
        if (vzorec.length() == beseda.length())
        {
            rep(i, beseda.length())
            {
                if (vzorec[i] == '*')
                    continue;
                else if (vzorec[i] != beseda[i])
                    ok = false;
                break;
            }

            if (ok)
                cout << beseda << endl;
            ok = true;
        }
    }
}

/* B del:

Seznam besed iz slovarja bi morali pretvoriti v drevo.
"Listi" drevesa bi bile črke.

Algoritem:
     za vsako črko v vzorcu:
        beleži globino v drevesu
        če se ujema z dolžino vzorca, je beseda ujema!

        če je vzorčev znak črka:
            preveri, če se otroci v drevesu trenutne korenine ujemajo z vzorčevo črko
            če se:
                rekurzivno išči v tem novem drevesu
        če je zvezdica:
            preveri vse veje v trenutni korenini
 */