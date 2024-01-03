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
    struct HashEntry* next; // �������һ���ڵ�
} HashEntry;
typedef struct HashTable {
    HashEntry* table[TABLE_SIZE]; // ÿ����λ��һ�������ͷָ��
    int collisions;
} HashTable;
void initializeTable(HashTable* ht) {
    ht->collisions = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL; // ��ʼ��ÿ����λΪ NULL����ʾ������
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
    printf("����������: ");
    scanf("%d", &numData);
    for (int i = 0; i < numData; i++) {
        unsigned long long int phoneNumber;
        UserInfo userInfo;
        printf("�绰����: ");
        scanf("%llu", &phoneNumber);
        printf("����: ");
        scanf("%s", userInfo.name);
        printf("��ַ: ");
        scanf("%s", userInfo.address);
        insertChaining(&ht, phoneNumber, userInfo, hashFunction1);
}
    printf("��ͻ����: %d\n", ht.collisions);
    printf("ƽ�����ҳ���: %.2f\n", calculateAverageSearchLength(&ht));
    return 0;
}

