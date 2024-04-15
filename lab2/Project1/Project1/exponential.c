int exponential(int x) {
    double sum = 1.0;
    for (int n = 1; n <= 20; n++) {
        double term = 1.0;
        for (int i = 1; i <= n; i++) {
            term *= x / i;
        }
        sum += term;
    }
    return sum;
}