#include <stdio.h>
#include <stdlib.h>

#include "ex2.h"
#include "struct.h"

struct node* find_by_id(struct node *head, unsigned int id)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int insert_at_the_end_second_list(struct node **head, struct node *node)
{
    if (*head == NULL)
    {
        *head = node;
        (*head)->next = NULL;
        return 0;
    }

    if (node == NULL)
    {
        return 0;
    }

    node->next = *head;
    *head = node;
    return 0;
}

int delete_by_id_second_list(struct node **head, unsigned int id)
{

    if (head == NULL)
    {
        printf("1 \n");
        return 0;
    }

    struct node *temp = *head;

    if (temp->id == id)
    {
        *head = temp->next;
        return 0;
    }

    while (temp->next != NULL && temp->next->id != id)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;
    return 0;
}

int insert_at_the_end(struct node **head, struct node **sterse, unsigned int id, char *name)
{
    if (*head == NULL)
    {
        struct node *temp = (struct node*) find_by_id(*sterse, id);

        if (temp == NULL)
        {
            temp = (struct node*) malloc (sizeof(struct node));
            if (!temp)
            {
                return -1;
            }
            temp->id = id;
            temp->name = name;
            temp->next = NULL;
            *head = temp;
            return 0;
        }
        else
        {
            *head = temp;
            return 0;
        }
    }

    struct node *temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    struct node *node_nou = (struct node*) find_by_id(*sterse, id);

    if (node_nou == NULL)
    {

        node_nou = (struct node*) malloc (sizeof(struct node));
        if (!node_nou)
        {
            return -1;
        }
        node_nou->id = id;
        node_nou->name = name;
        node_nou->next = NULL;
        temp->next = node_nou;
        return 0;
    }
    else
    {
        temp->next = node_nou;
        delete_by_id_second_list(sterse, id);
        return 0;
    }

    return 0;
}


int delete_by_id(struct node **head, struct node **lista_delete_by_id, unsigned int id)
{
    struct node *temp = *head;
    struct node *de_sters = NULL;

    if (temp != NULL && temp->id == id)
    {
        *head = temp->next;
        insert_at_the_end_second_list(lista_delete_by_id, de_sters);
        return 0;
    }

    while (temp != NULL && temp->id != id)
    {
        de_sters = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        de_sters->next = temp->next;
        insert_at_the_end_second_list(lista_delete_by_id, temp);
        return 0;
    }
}

void print_list(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->id);
        head = head->next;
    }
    printf("\n");
}

void delete_list(struct node** head)
{
    struct node* current = *head;
    struct node* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void test_insert()
{
    printf("\n===Test insertion===\n");
    struct node *head = NULL;
    struct node *sterse = NULL;

    insert_at_the_end(&head, &sterse, 10, "sal");
    insert_at_the_end(&head, &sterse, 20, "sal");
    insert_at_the_end(&head, &sterse, 30, "sal");

    printf("Main list:\n");
    print_list(head);

    printf("Second list:\n");
    print_list(sterse);

    delete_list(&head);
    delete_list(&sterse);

    printf("=========END=========\n");
}

void test_search(unsigned int id_find_by_id)
{
    printf("\n===Test searching by id===\n");
    struct node *head = NULL;
    struct node *sterse = NULL;

    insert_at_the_end(&head, &sterse, 10, "sal");
    insert_at_the_end(&head, &sterse, 20, "sal");
    insert_at_the_end(&head, &sterse, 30, "sal");

    struct node *caut = find_by_id(head, id_find_by_id);

    if (caut)
    {
        printf("Found node:\n");
        printf("ID: %d\n", caut->id);
        printf("Name: %s\n", caut->name);
    }
    else
    {
        printf("Node doesn't exist in main list\n");
    }

    delete_list(&head);
    delete_list(&sterse);

    printf("=========END=========\n");
}

void test_delete(unsigned int id)
{
    printf("\n===Test delete by id %d===\n", id);
    struct node *head = NULL;
    struct node *sterse = NULL;

    insert_at_the_end(&head, &sterse, 10, "sal");
    insert_at_the_end(&head, &sterse, 20, "sal");
    insert_at_the_end(&head, &sterse, 30, "sal");

    printf("Main list before deleting id:\n");
    print_list(head);

    printf("Second list:\n");
    print_list(sterse);

    delete_by_id(&head, &sterse, id);

    printf("Main list after deleting %d:\n", id);
    print_list(head);

    printf("Second list:\n");
    print_list(sterse);

    delete_list(&head);
    delete_list(&sterse);

    printf("=========END=========\n");
}

void test_insert_deleted_object(unsigned int id)
{
    printf("\n===Test deleting a node from main list, adding to second list\n");
    printf("and readding to main list===");
    struct node *head = NULL;
    struct node *sterse = NULL;

    insert_at_the_end(&head, &sterse, 10, "sal");
    insert_at_the_end(&head, &sterse, 20, "sal");
    insert_at_the_end(&head, &sterse, 30, "sal");

    printf("Main list before deletion:\n");
    print_list(head);

    printf("Second list:\n");
    print_list(sterse);

    delete_by_id(&head, &sterse, id);

    printf("Main list after deleting %d:\n", id);
    print_list(head);

    printf("Second list:\n");
    print_list(sterse);

    printf("Inserting the node %d in main list: \n", id);
    insert_at_the_end(&head, &sterse, id, "sal");
    print_list(head);

    printf("Second list:\n");
    print_list(sterse);

    delete_list(&head);
    delete_list(&sterse);

    printf("=========END=========\n");
}

void test_insert_new_object_that_is_not_in_second_list(unsigned int id)
{
    printf("\n===Inserting new node that isn't in second list===\n");
    struct node *head = NULL;
    struct node *sterse = NULL;

    insert_at_the_end(&head, &sterse, 10, "sal");
    insert_at_the_end(&head, &sterse, 20, "sal");
    insert_at_the_end(&head, &sterse, 30, "sal");

    printf("Main list before deleting:\n");
    print_list(head);

    printf("Second list:\n");
    print_list(sterse);

    delete_by_id(&head, &sterse, id);

    printf("Main list after deleting node %d:\n", id);
    print_list(head);

    printf("Second list:\n");
    print_list(sterse);

    printf("Insert a new node in main list %d: \n", id);
    insert_at_the_end(&head, &sterse, id, "sal");
    print_list(head);

    printf("Second list:\n");
    print_list(sterse);

    delete_list(&head);
    delete_list(&sterse);

    printf("=========END=========\n");
}

int main()
{
    test_insert();
    test_search(20);
    test_search(40);
    test_delete(20);
    test_delete(40);
    test_insert_deleted_object(20);
    test_insert_new_object_that_is_not_in_second_list(40);

    return 0;
}
