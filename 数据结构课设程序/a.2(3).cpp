#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct UserInfo {
    char name[50];
    char address[100];
} UserInfo;
typedef struct HashEntry {
    unsigned long long int phoneNumber;
    UserInfo info;
    struct HashEntry* next; // 链表的下一个节点
} HashEntry;
typedef struct HashTable {
    HashEntry* table[TABLE_SIZE]; // 每个槽位是一个链表的头指针
    int collisions;
} HashTable;
void initializeTable(HashTable* ht) {
    ht->collisions = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL; // 初始化每个槽位为 NULL，表示空链表
    }
}
unsigned int hashFunction1(unsigned long long int phoneNumber) {
    return phoneNumber % TABLE_SIZE;
}
void insertChaining(HashTable* ht, unsigned long long int phoneNumber, UserInfo info, unsigned int (*hashFunction)(unsigned long long int)) {
    unsigned int index = hashFunction(phoneNumber);
    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    if (newEntry == NULL) {
        exit(EXIT_FAILURE);
    }
    newEntry->phoneNumber = phoneNumber;
    strcpy(newEntry->info.name, info.name);
    strcpy(newEntry->info.address, info.address);
    newEntry->next = NULL;
    if (ht->table[index] == NULL) {
        ht->table[index] = newEntry;
    } else {
        HashEntry* current = ht->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEntry;
    }
    ht->collisions++;
}
float calculateAverageSearchLength(HashTable* ht) {
    int totalSearches = 0;
    int elements = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashEntry* current = ht->table[i];
        while (current != NULL) {
            totalSearches++; 
            current = current->next;
        }
        if (ht->table[i] != NULL) {
            elements++;
        }
    }
    return (float)totalSearches / elements;
}
int main() {
    HashTable ht;
    initializeTable(&ht);
    int numData;
    printf("输入数据量: ");
    scanf("%d", &numData);
    for (int i = 0; i < numData; i++) {
        unsigned long long int phoneNumber;
        UserInfo userInfo;
        printf("电话号码: ");
        scanf("%llu", &phoneNumber);
        printf("姓名: ");
        scanf("%s", userInfo.name);
        printf("地址: ");
        scanf("%s", userInfo.address);
        insertChaining(&ht, phoneNumber, userInfo, hashFunction1);
}
    printf("冲突次数: %d\n", ht.collisions);
    printf("平均查找长度: %.2f\n", calculateAverageSearchLength(&ht));
    return 0;
}

