#include <stdio.h>
#include <stdlib.h>
#require "test.h"


int main(void)
{
    forward_list<int> list1 = list::new();

    for (size_t i = 6; i > 0; )
    {
        list::push_front<int>(&list1, --i);
    }

    printf("list1 contains: ");
    for (list::iterator<int> it = list::begin(&list1); it != list::end(); it = it->next)
    {
        printf("%i \033[1;31m->\033[0m ", it->data);
    }
    puts("NULL\n");
    
    list::delete(&list1);


    forward_list<double> list2 = list::new();

    for (double i = 3; i > 0; )
    {
        list::push_front<double>(&list2, i -= 0.5);
    }

    printf("list2 contains: ");
    for (list::iterator<double> it = list::begin(&list2); it != list::end(); it = it->next)
    {
        printf("%.1lf \033[1;31m->\033[0m ", it->data);
    }
    puts("NULL\n");

    list::delete(&list2);


    forward_list<char> list3 = list::new();

    list::iterator<char> it = list::before_begin(&list3);

    for (char i = 'A'; i < 'H'; ++i)
    {
        it = list::insert_after<char>(&list3, it, i);
    }

    printf("list3 contains: ");
    for (list::iterator<char> it = list::begin(&list3); it != list::end(); it = it->next)
    {
        printf("'%c' \033[1;31m->\033[0m ", it->data);
    }
    puts("NULL\n");

    list::delete(&list3);


    forward_list<const char *> list4 = list::new();

    list::push_front<const char *>(&list4, "world");
    list::push_front<const char *>(&list4, "Hello");

    printf("list4 contains: ");
    for (list::iterator<const char *> it = list::begin(&list4); it != list::end(); it = it->next)
    {
        printf("\"%s\" \033[1;31m->\033[0m ", it->data);
    }
    puts("NULL\n");

    list::delete(&list4);


    forward_list<void *> list5 = list::new();

    list::push_front<void *>(&list5, (void *)0xfff);
    list::push_front<void *>(&list5, (void *)0xff4);

    printf("list5 contains: ");
    for (list::const_iterator<void *> it = list::begin(&list5); it != list::end(); it = it->next)
    {
        printf("%p \033[1;31m->\033[0m ", it->data);
    }
    puts("NULL\n");

    list::delete(&list5);

    return EXIT_SUCCESS;
}
