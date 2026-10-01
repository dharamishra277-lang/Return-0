#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int p[105];
        int bad[105];
        int count = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);

            // Store indices where value is not in its correct position
            if (p[i] != i + 1) {
                bad[count] = i;
                count++;
            }
        }

        int possible = 1;

        int left = 0;
        int right = count - 1;

        while (left < right) {
            // bad[left] and bad[right] are 0-based indices.
            // So correct values are index + 1.
            if (p[bad[left]] != bad[right] + 1 ||
                p[bad[right]] != bad[left] + 1) {
                possible = 0;
                break;
            }

            left++;
            right--;
        }

        if (possible)