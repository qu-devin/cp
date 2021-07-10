int sieve[mxa+5];

void erat() {
    sieve[1] = 1;
    for (int i = 2; i <= mxa; ++i) {
        if (sieve[i]) continue;
        sieve[i] = i;
        for (ll j = i*1ll*i; j <= mxa; j += i) sieve[j] = i;
    }
}
