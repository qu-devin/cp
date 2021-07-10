int st[mxn][25];

void build() {
    int k = 0;
    while (1<<(k+1) <= n)
        ++k;

    for (int i = 0; i < n; ++i)
        st[i][0] = a[i];

    for (int j = 1; j <= k; ++j)
        for (int i = 0; i+(1<<j) <= n; ++i)
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}

int q(int l, int r) {
    int j = 0;
    while (1<<(j+1) <= (r-l+1))
        ++j;

    return min(st[l][j], st[r-(1<<j)+1][j]);
}



