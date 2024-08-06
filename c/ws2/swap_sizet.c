#include <stdio.h>

// Function to swap two size_t values
void swap_size_t(size_t *a, size_t *b) {
    size_t temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap two size_t pointers using the swap_size_t function
void swap_size_t_pointers(size_t **a, size_t **b) {
    // Swap the addresses stored in the pointers
    swap_size_t((size_t *)a, (size_t *)b);
}

int main() {
    // Example usage
    size_t x = 10;
    size_t y = 20;
    size_t *px = &x;
    size_t *py = &y;

    printf("Before swapping: px = %p, py = %p\n", (void *)px, (void *)py);
    swap_size_t_pointers(&px, &py);
    printf("After swapping: px = %p, py = %p\n", (void *)px, (void *)py);

    return 0;
}

