#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct 
{
    char name[50];
    char address[100];
} UserInfo;
typedef struct 
{
    unsigned long long int phoneNumber; 
    UserInfo info;
} HashEntry;
typedef struct {
    HashEntry table[TABLE_SIZE];
    int collisions;
} HashTable;
void initializeTable(HashTable* ht) {
    ht->collisions = 0;
    for (int i = 0; i < TABLE_SIZE; i++) 
	{
        ht->table[i].phoneNumber = 0;
    }
}
unsigned int hashFunction1(unsigned long long int phoneNumber) 
{
    return phoneNumber % TABLE_SIZE;
}
void insertLinearProbe(HashTable* ht, unsigned long long int phoneNumber, UserInfo info, unsigned int (*hashFunction)(unsigned long long int)) {
    unsigned int index = hashFunction(phoneNumber);
    while (ht->table[index].phoneNumber != 0) { 
        index = (index + 1) % TABLE_SIZE; 
        ht->collisions++; 
    }
    ht->table[index].phoneNumber = phoneNumber;
    strcpy(ht->table[index].info.name, info.name);
    strcpy(ht->table[index].info.address, info.address);
}
float calculateAverageSearchLength(HashTable* ht) {
    int totalSearches = 0;
    int elements = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i].phoneNumber != 0) {
            totalSearches += i; 
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
        insertLinearProbe(&ht, phoneNumber, userInfo, hashFunction1);
    }
    printf("冲突次数: %d\n", ht.collisions);
    printf("平均查找长度: %.2f\n", calculateAverageSearchLength(&ht));
    return 0;
}

