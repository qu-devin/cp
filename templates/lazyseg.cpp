int t[4*mxn], lazy[4*mxn];

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

void update(int v, int tl, int tr, int l, int r, int add) {
    if (lazy[v]) {
        t[v] += lazy[v];
        if (tl != tr) {
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }

    if (tl > r || tr < l) 
        return;

    if (tl >= l && tr <= r) {
        t[v] += add;
        if (tl != tr) {
            lazy[2*v] += add;
            lazy[2*v+1] += add;
        }
        lazy[v] = 0;
        return;
    }

    int tm = tl + (tr-tl)/2;
    update(2*v, tl, tm, l, r);
    update(2*v+1, tm+1, tr, l, r);
    t[v] = t[2*v] + t[2*v+1];
}

int query(int v, int tl, int tr, int l, int r) {
    if (lazy[v]) {
        t[v] += lazy[v];
        if (tl != tr) {
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }

    if (tl > r || tr < l)
        return 0;

    if (tl >= l && tr <= r)
        return t[v];

    int tm = tl + (tr-tl)/2;
    return query(2*v, tl, tm, l, r) + query(2*v+1, tm+1, tr, l, r);
}
