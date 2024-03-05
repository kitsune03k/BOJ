unsigned long long npr(int n, int r)
{
    unsigned long long ret = 1;

    int nr = n-r;

    for(int i=nr+1; i<=n; i++){
        ret *= i;
    }

    return ret;
}

unsigned long long ncr(int n, int r)
{
    unsigned long long ret = 1;

    int nr = n-r;
    int div1, div2; // div1 < div2, div1 + div2 = n

    if(nr < r){
        div1 = nr;
        div2 = r;
    }
    else{ // nr >= r
        div1 = r;
        div2 = nr;
    }

    unsigned long long k = 1, kref = 1;

    for(int i = div2+1; i<=n; i++){
        ret *= i;
        k *= kref++;
    }

    return ret/k;
}