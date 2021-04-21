#include <bits/stdc++.h>

using namespace std;

struct Node 
{
    int data;
    struct Node* next, *prev;
};

int countPairs(struct Node* first, struct Node* second, int value)
{
    int count = 0;

    while (first != NULL && second != NULL && first != second && second->next != first) 
    {

        if ((first->data + second->data) == value) 
        {
            count++;
            first = first->next;
            second = second->prev;
        }
        else if ((first->data + second->data) > value)
            second = second->prev;
        else
            first = first->next;
    }
    return count;
}

int countTriplets(struct Node* head, int x)
{
    if (head == NULL)
        return 0;

    struct Node* current, *first, *last;
    int count = 0;

    last = head;
    while (last->next != NULL)
        last = last->next;

    for (current = head; current != NULL; current = current->next) 
    {

        first = current->next;
        count += countPairs(first, last, x-current->data);
    }
    return count;
}

void insert(struct Node** head, int data)
{
    struct Node* temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;

    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

int main()
{
    struct Node* head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

    int x = 17;

    cout << "Count = "<< countTriplets(head, x);
    return 0;
}
