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