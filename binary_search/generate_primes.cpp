vector<int> solve(int n) {
    vector<bool> primes(n+1,true);
    primes[0]=primes[1]=false;
    for(int i=2;i<=n;i++)
        if(primes[i] && (long long)i*i<=n)
            for(int j=i*i;j<=n; j+=i) primes[j]=false;
    vector<int>res;
    for(int i=2;i<=n;i++)
        if(primes[i]) res.push_back(i);
    return res;
}
