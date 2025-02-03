# ex00
```c
int main(void)
{
    int_list_t *list_head = NULL;
    if (int_list_is_empty(list_head))
        printf("The list is empty\n");
    else
        printf("The list is not empty\n");
    int_list_add_elem_at_back(&list_head, 1);
    int_list_add_elem_at_back(&list_head, 2);
    printf("There are %u elements in the list\n",
    int_list_get_size(list_head));
    int_list_dump(list_head);
    int_list_clear(&list_head);
    printf("There are %u elements in the list\n",
    int_list_get_size(list_head));
    return 0;
}
```

# ex01
```c
int main(void)
{
    int_list_t *list_head = NULL;
    printf("%d\n",int_list_get_size(list_head));
    printf("%d\n",int_list_is_empty(list_head));
    int_list_add_elem_at_back(&list_head, 1804289383);
    int_list_add_elem_at_back(&list_head, 846930886);
    int_list_add_elem_at_back(&list_head, 1681692777);
    int_list_dump(list_head);
    printf("----\n");
    int_list_add_elem_at_front(&list_head, 1714636915);
    int_list_add_elem_at_front(&list_head, 1957747793);
    int_list_add_elem_at_front(&list_head, 424238335);
    int_list_dump(list_head);
    printf("----\n");
    int_list_add_elem_at_position(&list_head, 1189641421, 1);
    int_list_add_elem_at_position(&list_head, 1649760492, 4);
    int_list_add_elem_at_position(&list_head, 1350490027, 5);
    int_list_dump(list_head);
    printf("----\n");
    int_list_add_elem_at_position(&list_head, 783368690, 0);
    int_list_dump(list_head);
    printf("%d\n",int_list_get_size(list_head));
    printf("%d\n",int_list_is_empty(list_head));
    int_list_clear(&list_head);
    return 0;
}
```

# ex02
```c
int main(void)
{
    int_list_t *list_head = NULL;
    int_list_add_elem_at_front(&list_head, 1);
    int_list_add_elem_at_front(&list_head, 2);
    int_list_add_elem_at_position(&list_head, 3, 1);
    printf("There are %u elements in the list\n", int_list_get_size(list_head));
    printf("The first element is %d\n", int_list_get_elem_at_front(list_head));
    printf("The last element is %d\n", int_list_get_elem_at_back(list_head));
    int_list_clear(& list_head);
    return 0;
}
```

# ex03
```c
int main(void)
{
    int_list_t *list_head = NULL;
    int_list_add_elem_at_back(&list_head, 1);
    int_list_add_elem_at_back(&list_head, 2);
    int_list_add_elem_at_back(&list_head, 3);
    printf("There are %u elements in the list\n", int_list_get_size(list_head));
    int_list_del_elem_at_front(&list_head);
    int_list_dump(list_head);
    int_list_clear(&list_head);
    return 0;
}
```

# ex04
```c
static void int_displayer(const void * data)
{
    int value = *((const int *)data);
    printf("%d\n", value);
}

static void test_size(list_t * list_head)
{
    printf("There are %u elements in the list\n", list_get_size(list_head));
    list_dump(list_head, &int_displayer);
}

static void test_del(list_t ** list_head)
{
    list_del_elem_at_back(list_head);
    printf("There are %u elements in the list \n", list_get_size(*list_head));
    list_dump(*list_head, &int_displayer);
}

int main(void)
{
    list_t * list_head = NULL;
    int i = 5;
    int j = 42;
    int k = 3;
    list_add_elem_at_back(&list_head, &i);
    list_add_elem_at_back(&list_head, &j);
    list_add_elem_at_back(&list_head, &k);
    test_size(list_head);
    test_del(&list_head);
    list_clear(&list_head);
    return 0;
}
```
