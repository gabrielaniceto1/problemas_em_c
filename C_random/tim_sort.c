#define RUN 32
#define MIN(a,b) ((a) < (b) ? (a) : (b))

void insertionSortTim(int v[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= left && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void mergeTim(int v[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (!L || !R) {
        free(L);
        free(R);
        return;
    }

    for (int i = 0; i < n1; i++) {
        L[i] = v[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = v[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }

    while (i < n1) {
        v[k++] = L[i++];
    }

    while (j < n2) {
        v[k++] = R[j++];
    }

    free(L);
    free(R);
}

void timsort(int v[], int n) {
    for (int i = 0; i < n; i += RUN) {
        int right = MIN(i + RUN - 1, n - 1);
        insertionSortTim(v, i, right);
    }

    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = MIN(left + size - 1, n - 1);
            int right = MIN(left + 2 * size - 1, n - 1);
            if (mid < right) {
                mergeTim(v, left, mid, right);
            }
        }
    }
}
