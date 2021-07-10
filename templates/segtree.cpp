int t[4*mxn];

void build(int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = tl + (tr-tl)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = t[2*v] + t[2*v+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;

    if (l == tl && r == tr)
        return t[v];

    int tm = tl + (tr-tl)/2;
    return sum(2*v, tl, tm, l, min(r, tm)) + sum(2*v+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int x) {
    if (tl == tr)
        t[v] = x;
    else {
        int tm = tl + (tr-tl)/2;
        if (pos <= tm) 
            update(2*v, tl, tm, pos, x);
        else
            update(2*v+1, tm+1, tr, pos, x);
        t[v] = t[2*v] + t[2*v+1];
    }
}
