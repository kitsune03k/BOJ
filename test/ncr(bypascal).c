typedef unsigned long long ull;

ull pascal(int n, int r){
    if(r == 0 || r == n)
        return 1;
    else{
        return pascal(n-1, r-1) + pascal(n-1, r);
    }
}