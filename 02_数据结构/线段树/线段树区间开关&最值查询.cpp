struct SegTree {
    int n;
    vector<long long> allMax, allMin;
    vector<long long> curMax, curMin; 
    vector<int> lazy;                
    SegTree(const vector<long long>& w) {
        n = (int)w.size() - 1;
        allMax.assign(4 * n + 5, -inf);
        allMin.assign(4 * n + 5, inf);
        curMax.assign(4 * n + 5, -inf);
        curMin.assign(4 * n + 5, inf);
        lazy.assign(4 * n + 5, -1);
        build(1, 1, n, w);
    }
    void build(int p, int l, int r, const vector<long long>& w) {
        if (l == r) {
            allMax[p] = allMin[p] = w[l];
            curMax[p] = -inf;
            curMin[p] = inf;
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, w);
        build(p << 1 | 1, mid + 1, r, w);
        allMax[p] = max(allMax[p << 1], allMax[p << 1 | 1]);
        allMin[p] = min(allMin[p << 1], allMin[p << 1 | 1]);
        curMax[p] = max(curMax[p << 1], curMax[p << 1 | 1]);
        curMin[p] = min(curMin[p << 1], curMin[p << 1 | 1]);
    }

    void apply(int p, int state) {
        if (state == 1) {
            curMax[p] = allMax[p];
            curMin[p] = allMin[p];
            lazy[p] = 1;
        } else {
            curMax[p] = -inf;
            curMin[p] = inf;
            lazy[p] = 0;
        }
    }
    void pushdown(int p) {
        if (lazy[p] != -1) {
            apply(p << 1, lazy[p]);
            apply(p << 1 | 1, lazy[p]);
            lazy[p] = -1;
        }
    }
    void update(int p, int l, int r, int ql, int qr, int state) {
        if (ql <= l && r <= qr) {
            apply(p, state);
            return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (ql <= mid) update(p << 1, l, mid, ql, qr, state);
        if (qr > mid) update(p << 1 | 1, mid + 1, r, ql, qr, state);
        curMax[p] = max(curMax[p << 1], curMax[p << 1 | 1]);
        curMin[p] = min(curMin[p << 1], curMin[p << 1 | 1]);
    }
    void update(int l, int r, int state) {
        if (l > r) return;
        update(1, 1, n, l, r, state);
    }
    pair<long long, long long> query() {
        return {curMin[1], curMax[1]};
    }
};


struct SegTree {
    int n;
    vector<long long> allMax, allMin;
    vector<long long> curMax, curMin;
    vector<int> allMaxId, allMinId; // 区间所有点中最值对应的编号
    vector<int> curMaxId, curMinId; // 当前开启点中最值对应的编号
    vector<int> lazy;

    SegTree(const vector<long long>& w) {
        n = (int)w.size() - 1;
        allMax.assign(4 * n + 5, -inf);
        allMin.assign(4 * n + 5, inf);
        curMax.assign(4 * n + 5, -inf);
        curMin.assign(4 * n + 5, inf);
        allMaxId.assign(4 * n + 5, -1);
        allMinId.assign(4 * n + 5, -1);
        curMaxId.assign(4 * n + 5, -1);
        curMinId.assign(4 * n + 5, -1);
        lazy.assign(4 * n + 5, -1);
        build(1, 1, n, w);
    }

    void build(int p, int l, int r, const vector<long long>& w) {
        if (l == r) {
            allMax[p] = allMin[p] = w[l];
            allMaxId[p] = allMinId[p] = l;   // 叶子编号就是 l
            curMax[p] = -inf;
            curMin[p] = inf;
            curMaxId[p] = curMinId[p] = -1;  // 初始全部关闭，无有效编号
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, w);
        build(p << 1 | 1, mid + 1, r, w);

        // 更新 all 值
        allMax[p] = max(allMax[p << 1], allMax[p << 1 | 1]);
        allMin[p] = min(allMin[p << 1], allMin[p << 1 | 1]);
        // 更新 all 的编号
        if (allMax[p << 1] >= allMax[p << 1 | 1])
            allMaxId[p] = allMaxId[p << 1];
        else
            allMaxId[p] = allMaxId[p << 1 | 1];
        if (allMin[p << 1] <= allMin[p << 1 | 1])
            allMinId[p] = allMinId[p << 1];
        else
            allMinId[p] = allMinId[p << 1 | 1];

        // 更新 cur 值
        curMax[p] = max(curMax[p << 1], curMax[p << 1 | 1]);
        curMin[p] = min(curMin[p << 1], curMin[p << 1 | 1]);
        // 更新 cur 的编号
        if (curMax[p << 1] >= curMax[p << 1 | 1])
            curMaxId[p] = curMaxId[p << 1];
        else
            curMaxId[p] = curMaxId[p << 1 | 1];
        if (curMin[p << 1] <= curMin[p << 1 | 1])
            curMinId[p] = curMinId[p << 1];
        else
            curMinId[p] = curMinId[p << 1 | 1];
    }

    void apply(int p, int state) {
        if (state == 1) { // 开启
            curMax[p] = allMax[p];
            curMin[p] = allMin[p];
            curMaxId[p] = allMaxId[p];
            curMinId[p] = allMinId[p];
            lazy[p] = 1;
        } else {          // 关闭
            curMax[p] = -inf;
            curMin[p] = inf;
            curMaxId[p] = -1;
            curMinId[p] = -1;
            lazy[p] = 0;
        }
    }

    void pushdown(int p) {
        if (lazy[p] != -1) {
            apply(p << 1, lazy[p]);
            apply(p << 1 | 1, lazy[p]);
            lazy[p] = -1;
        }
    }

    void update(int p, int l, int r, int ql, int qr, int state) {
        if (ql <= l && r <= qr) {
            apply(p, state);
            return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (ql <= mid) update(p << 1, l, mid, ql, qr, state);
        if (qr > mid) update(p << 1 | 1, mid + 1, r, ql, qr, state);

        // 更新 cur 值
        curMax[p] = max(curMax[p << 1], curMax[p << 1 | 1]);
        curMin[p] = min(curMin[p << 1], curMin[p << 1 | 1]);
        // 更新 cur 的编号
        if (curMax[p << 1] >= curMax[p << 1 | 1])
            curMaxId[p] = curMaxId[p << 1];
        else
            curMaxId[p] = curMaxId[p << 1 | 1];
        if (curMin[p << 1] <= curMin[p << 1 | 1])
            curMinId[p] = curMinId[p << 1];
        else
            curMinId[p] = curMinId[p << 1 | 1];
    }

    void update(int l, int r, int state) {
        if (l > r) return;
        update(1, 1, n, l, r, state);
    }

    // 返回当前全局开启点中最小值和最大值对应的编号
    pair<int, int> query() {
        return {curMinId[1], curMaxId[1]};
    }
};