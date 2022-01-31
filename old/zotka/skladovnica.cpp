#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef deque<int> di;
typedef vector<int> vi;
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

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s)
{
    return '"' + s + '"';
}

string to_string(const char *s)
{
    return to_string((string)s);
}

string to_string(bool b)
{
    return (b ? "true" : "false");
}

string to_string(vector<bool> v)
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++)
    {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p)
{
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p)
{
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

__int128 triangular_num(__int128 n)
{
    return n * (n + 1) / 2;
}

__int128 get_pile(__int128 n, __int128 p, __int128 k)
{
    __int128 var_p = n + 1;
    __int128 var_k = triangular_num(n);

    return var_p * p + var_k * k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ull base, addition, num_days;
    cin >> base >> addition >> num_days;

    vector<__int128> days;

    for (__int128 i = 0; i < num_days; i++)
    {
        ull day;
        cin >> day;
        days.PB(day);
    }

    __int128 sum = 0;
    for (__int128 i = 0; i < num_days; i++)
    {
        __int128 num_of_box = days[i];

        // binary search
        __int128 left = 0, right = num_of_box;
        while (left < right)
        {
            __int128 mid = left + (right - left) / 2;
            __int128 top = get_pile(mid, base, addition);
            __int128 bottom = get_pile(mid - 1, base, addition) + 1;

            if (num_of_box >= bottom && num_of_box <= top)
            {
                sum -= num_of_box;
                sum += top;
                // debug(num_of_box, bottom, mid, top, ": ", top - bottom);
                break;
            }
            else if (num_of_box < bottom)
            {
                right = mid;
            }
            else if (num_of_box > top)
            {
                left = mid + 1;
            }
            else
            {
                throw("error");
            }
        }
    }

    printf("%lld\n", sum);
}