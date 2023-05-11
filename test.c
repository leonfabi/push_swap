#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    void* content;
    struct List* next;
} List;

typedef struct {
    int number;
    int position;
} MyStruct;

int main() {
    List* first = malloc(sizeof(List));
    List* second = malloc(sizeof(List));
    List* third = malloc(sizeof(List));

    first->content = NULL;
    first->next = second;

    second->content = NULL;
    second->next = third;

    third->content = NULL;
    third->next = NULL;

    MyStruct myStruct;
    myStruct.number = 42;
    myStruct.position = 3;

    // Assign the struct as content for the first node
    first->content = &myStruct;

    // Access and print the struct values
    printf("Number: %d\n", ((MyStruct*)first->content)->number);
    printf("Position: %d\n", ((MyStruct*)first->content)->position);

    // Free the allocated memory
    free(first);
    free(second);
    free(third);

    return 0;
}
