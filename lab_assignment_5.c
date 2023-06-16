#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int numNode = 0;
    node* present = head;

    //iterating to count how many nodes are present
    while(present != NULL) {
        numNode++;
        present = present->next;
    }
    return numNode;

}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    int lengthStr = length(head);
    char* str = (char*)malloc((lengthStr + 1) * sizeof(char));
    node* present = head;
    int r = 0;

    //advancing through the string
    while(present != NULL) {
        str[r] = present->letter;
        present = present->next;
        r++;
    }


    str[r] = '\0';
    return str;

}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newNode = (node*)malloc(sizeof(node));

    newNode->letter = c;
    newNode->next = NULL;

    //if the head of the list is NULL, insert a new node
    if(*pHead == NULL) {
        *pHead = newNode;
    }
    else{
        node* present = *pHead;

        while(present->next != NULL) {
            present = present->next;
        }

        present->next = newNode;

    }


}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* present = *pHead;

    while(present != NULL) {
        node* nextNode = present->next;
        free(present);
        present = nextNode;
    }

    *pHead = NULL;

}
int main(void)
{
int i, strLen, numInputs;
node* head = NULL;
char* str;
char c;
FILE* inFile = fopen("input.txt","r");
fscanf(inFile, " %d\n", &numInputs);
while (numInputs-- > 0)
{
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)
{
fscanf(inFile," %c", &c);
insertChar(&head, c);
}
str = toCString(head);
printf("String is : %s\n", str);
free(str);
deleteList(&head);
if (head != NULL)
{
printf("deleteList is not correct!");
break;
}
}
fclose(inFile);
}