int sum[N << 2], ma[N << 2], se[N << 2], num[N << 2], a[N], pos[N];
int tag[N << 2];
int len[N << 2];

inline int ls(int p) { return p << 1;}
inline int rs(int p) { return p << 1 | 1;}

void push_up(int p) {
    sum[p] = sum[ls(p)] + sum[rs(p)];
    ma[p] = max(ma[ls(p)], ma[rs(p)]);
    if (ma[ls(p)] == ma[rs(p)]) {
        se[p] = max(se[ls(p)], se[rs(p)]);
        num[p] = num[ls(p)] + num[rs(p)];
    } else {
        se[p] = max(min(ma[ls(p)], ma[rs(p)]), max(se[ls(p)], se[rs(p)]));
        num[p] = (ma[ls(p)] > ma[rs(p)]) ? num[ls(p)] : num[rs(p)];
    }
}
void build(int p, int pl, int pr) {
    len[p] = pr - pl + 1;
    tag[p] = 0;
    if (pl == pr) {
        sum[p] = a[pl];
        ma[p] = a[pl];
        se[p] = -1;
        num[p] = 1;
        return;
    }
    int mid = (pl + pr) / 2;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p);
}
void add_tag(int p, int x) {
    sum[p] += 1LL * x * len[p];
    ma[p] += x;
    if (se[p] != -1) se[p] += x;
    tag[p] += x;
}
void push_down(int p) {
    if (tag[p]) {
        add_tag(ls(p), tag[p]);
        add_tag(rs(p), tag[p]);
        tag[p] = 0;
    }
}
void update(int L, int R, int p, int pl, int pr, int x) {
    if (L <= pl && pr <= R) {
        add_tag(p, x);
        return;
    }
    push_down(p);
    int mid = (pl + pr) / 2;
    if (L <= mid) update(L, R, ls(p), pl, mid, x);
    if (R > mid)  update(L, R, rs(p), mid + 1, pr, x);
    push_up(p);
}
int queryMax(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return ma[p];
    push_down(p);
    int mid = (pl + pr) / 2;
    int ans = 0;
    if (L <= mid) ans = max(ans, queryMax(L, R, ls(p), pl, mid));
    if (R > mid)  ans = max(ans, queryMax(L, R, rs(p), mid + 1, pr));
    return ans;
}
int querySum(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return sum[p];
    push_down(p);
    int mid = (pl + pr) / 2;
    int ans = 0;
    if (L <= mid) ans += querySum(L, R, ls(p), pl, mid);
    if (R > mid)  ans += querySum(L, R, rs(p), mid + 1, pr);
    return ans;
}

/*单点修改  只求最值*/
int sum[N << 2], ma[N << 2], a[N];

inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }

void push_up(int p) {
    sum[p] = sum[ls(p)] + sum[rs(p)];
    ma[p] = max(ma[ls(p)], ma[rs(p)]);
}

void build(int p, int pl, int pr) {
    if (pl == pr) {
        sum[p] = a[pl];
        ma[p] = a[pl];
        return;
    }
    int mid = (pl + pr) / 2;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p);
}
void update(int pos, int p, int pl, int pr, int x) {
    if (pl == pr) {
        sum[p] = x;
        ma[p] = x;
        return;
    }
    int mid = (pl + pr) / 2;
    if (pos <= mid)
        update(pos, ls(p), pl, mid, x);
    else
        update(pos, rs(p), mid + 1, pr, x);
    push_up(p);
}

int queryMax(int L, int R, int p, int pl, int pr) {
    if (L <= pl && pr <= R) return ma[p];
    int mid = (pl + pr) / 2;
    int ans = -inf;
    if (L <= mid) ans = max(ans, queryMax(L, R, ls(p), pl, mid));
    if (R > mid)  ans = max(ans, queryMax(L, R, rs(p), mid + 1, pr));
    return ans;
}