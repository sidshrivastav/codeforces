/*
* Problem: In graph, check if parent of two node is same.
* */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *parent;
    int *rank;
    int n;
} DSU;

DSU* dsu_create(int n) {
    DSU *d = (DSU*)malloc(sizeof(DSU));
    d->n = n;
    d->parent = (int*)malloc((n + 1) * sizeof(int));
    d->rank   = (int*)calloc((n + 1), sizeof(int));
    for (int i = 1; i <= n; i++) d->parent[i] = i;
    return d;
}

int dsu_find(DSU *d, int x) {
    if (d->parent[x] != x) d->parent[x] = dsu_find(d, d->parent[x]);
    return d->parent[x];
}

void dsu_union(DSU *d, int a, int b) {
    a = dsu_find(d, a);
    b = dsu_find(d, b);
    if (a == b) return;
    if (d->rank[a] < d->rank[b]) {
        d->parent[a] = b;
    } else if (d->rank[b] < d->rank[a]) {
        d->parent[b] = a;
    } else {
        d->parent[b] = a;
        d->rank[a]++;
    }
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    DSU *dsu = dsu_create(n);
    int *deg = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++; deg[v]++;          // degree for each vertex
        dsu_union(dsu, u, v);        // build components
    }

    // For each component, check if all vertices in it have degree == 2
    int *seen = (int*)calloc(n + 1, sizeof(int));
    int *all2 = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) all2[i] = 1; // optimistic; will invalidate on first mismatch

    for (int v = 1; v <= n; v++) {
        int r = dsu_find(dsu, v);
        seen[r] = 1;
        if (deg[v] != 2) all2[r] = 0;
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (seen[i] && all2[i]) answer++;
    }

    printf("%d\n", answer);

    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
    free(deg);
    free(seen);
    free(all2);
    return 0;
}

