int getMax(int v[], int n) {
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

void countingSortPorDigito(int v[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digito = (v[i] / exp) % 10;
        count[digito]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digito = (v[i] / exp) % 10;
        output[count[digito] - 1] = v[i];
        count[digito]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = output[i];
    }
}

void radixsort(int v[], int n) {
    int max = getMax(v, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortPorDigito(v, n, exp);
    }
}
