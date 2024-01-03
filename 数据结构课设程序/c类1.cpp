#include <stdio.h>
void make_change(int amount) {
    int coins[] = {25, 10, 5, 1}; 
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    int change[num_coins]; 
    for (int i = 0; i < num_coins; i++) {
        change[i] = 0; 
    }
    for (int i = 0; i < num_coins; i++) {
        while (amount >= coins[i]) {
            change[i]++; 
            amount -= coins[i]; 
        }
    }
    printf("找零的硬币数量：\n");
    for (int i = 0; i < num_coins; i++) {
        if (change[i] > 0) {
            printf("%d个%d 分硬币\n", change[i], coins[i]);
        }
    }
}
int main() {
    int test_cases[] = {32, 50};
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        printf("%d 分：\n", test_cases[i]);
        make_change(test_cases[i]);
        printf("\n");
    }
    return 0;
}

