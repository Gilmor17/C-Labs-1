int sum(int *start, int *end) {
    int total = 0;
    while (start < end) {
        total += *(start++);  // Dereference and increment in one step
    }
    return total;
}
