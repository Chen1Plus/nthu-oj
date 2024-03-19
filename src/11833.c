#include <stdio.h>

int arr_idx_from_value[200000];
int arr[200000];
int pre_arr[200000];

void parse(int arr_l, int arr_r, int pre_l, int pre_r) {
    if (arr_l > arr_r) return;

#define mid_idx arr_idx_from_value[pre_arr[pre_l]]
    parse(arr_l, mid_idx - 1, pre_l + 1, pre_l + mid_idx - arr_l);
    parse(mid_idx + 1, arr_r, pre_l + mid_idx - arr_l + 1, pre_r);
    printf("%d ", pre_arr[pre_l]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr_idx_from_value[arr[i]] = i;
    }
    for (int i = 0; i < n; i++) scanf("%d", &pre_arr[i]);

    parse(0, n - 1, 0, n - 1);
    printf("\n");
}