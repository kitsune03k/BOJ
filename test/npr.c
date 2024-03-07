unsigned long long npr(int n, int r)
{
    unsigned long long ret = 1;

    int nr = n-r;

    for(int i=nr+1; i<=n; i++){
        ret *= i;
    }

    return ret;
}