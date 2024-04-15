int lcm(int a, int b) {
    int cur = a;
    while (b != 0) {
        int temp = b;
        b = cur % b;
        cur = temp;
    }
    return a / cur * b;
}