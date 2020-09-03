#ifndef EX2_H_INCLUDED
#define EX2_H_INCLUDED

struct node* find_by_id(struct node*, unsigned int);
int insert_at_the_end(struct node**, struct node**, unsigned int, char*);
int insert_at_the_end_second_list(struct node**, struct node*);
int delete_by_id(struct node**, struct node**, unsigned int);
int delete_by_id_second_list(struct node**, unsigned int);
void print_list(struct node*);
void delete_list(struct node**);

void test_insert();
void test_serach(unsigned int);
void test_delete(unsigned int);
void test_insert_deleted_object(unsigned int);
void test_insert_new_object_that_is_not_in_second_list(unsigned int);
#endif // EX2_H_INCLUDED
