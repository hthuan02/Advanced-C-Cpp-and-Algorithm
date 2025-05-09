#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

// Hàm thêm 1 Node ở cuối  List
void push_back(Node **array, int value)
{
    Node *temp;
    temp = createNode(value);

    if (*array == NULL)
    {
        *array = temp;
    }
    else
    {
        Node *p = *array;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void printlist(Node *array)
{
    Node *p = array;
    int i = 0;

    while (p != NULL)
    {
        printf("Node = %d - Data = %d\n", i, p->data);
        p = p->next;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    Node *n1 = createNode(5);
    Node *n2 = createNode(6);
    Node *n3 = createNode(7);

    n1->next = n2;
    n2->next = n3;

    push_back(&n1, 15);
    printlist(n1);
    return 0;
}
