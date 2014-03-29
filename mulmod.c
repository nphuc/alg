ll mul_mod(ll a, ll b, ll m)
{
    long double x;
    ll c;
    ll r;
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    x = a;
    c = x * b / m;
    r = (ll)(a * b - c * m) % (ll)m;
    return r < 0 ? r + m : r;
}
