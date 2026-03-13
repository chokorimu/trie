#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARR_SIZE 26

struct node {
    struct node* next[ARR_SIZE];
    bool isEnd;
};

struct node* allocate() {
    struct node* newNode = malloc(sizeof(*newNode));
    for(int i=0; i<ARR_SIZE; i++) {
        newNode->next[i] = NULL;
    }
    newNode->isEnd = false;
    return newNode;
}

void insert(struct node** head, char* newValue) {
    if((*head) == NULL) {
        *head = allocate();
    }
    struct node* cursor = *head;
    for(int i=0; newValue[i]!='\0'; i++) {
        int index = newValue[i]-'a';
        if(cursor->next[index] == NULL) {
            cursor->next[index] = allocate();
        }
        cursor=cursor->next[index];
    }
    cursor->isEnd = true;
}

bool search(struct node** head, char* value) {
    if (*head == NULL) {
        return false;
    }
    struct node* cursor = *head;
    for(int i=0; value[i]!='\0'; i++) {
        int index = value[i]-'a';
        if(cursor->next[index] == NULL) {
            return false;
        }
        cursor=cursor->next[index];
    }
    if(cursor->isEnd == true) {
        return true;
    }
    return false;
}

void check(struct node** head, char* value) {
    bool found = search(head, value);
    if(found) {
        printf("\"%s\" ditemukan\n", value);
    } else {
        printf("\"%s\" tidak ditemukan\n", value);
    }
}

int main() {
    struct node* head = NULL;
    insert(&head, "kuda");
    insert(&head, "kudalaut");
    check(&head, "kuda");
    check(&head, "kudala");

    return 0;
}