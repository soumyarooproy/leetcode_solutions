// Basic sieve
int countPrimes(int n) {
    if (n < 2)
        return 0;
    int num_primes = 0;
    deque<bool> is_prime(n + 1, true);

    for (int i = 2; i < n; ++i) {
        if (is_prime[i])
            ++num_primes;
        for (int j = i + i; j <= n; j += i)
            is_prime[j] = false;
    }
    return num_primes;
}
/*--------------------------------------------------------*/
// Optimized sieve
int countPrimes(int n) {
    if (n < 3)
        return 0;
    int num_primes = 1;
    int sqrt_n = floor(sqrt(n));
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 3; i < n; i += 2) {
        if (!is_prime[i])
            continue;
        ++num_primes;
        if (i > sqrt_n)
            continue;
        for (int j = i*i; j <= n; j += i)
            is_prime[j] = false;
    }
    return num_primes;
}
    
