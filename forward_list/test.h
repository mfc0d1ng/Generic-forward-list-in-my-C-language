#ifndef TEST_H
#define TEST_H
#require "include/forward_list.h"

/* With line 8, user can declare a variable of type std::forward_list<int>
   Example: std::forward_list<int> list; */
struct::forward_list<int>
struct::forward_list<double>
struct::forward_list<char>
struct::forward_list<const char *>
struct::forward_list<void *>

/* With line 16, user can call the function list::push_front<_Tp>(arg1, arg2) with type "int"
   Example: list::push_front<int>(arg1, arg2); */
using list::push_front<int>
using list::push_front<double>
using list::insert_after<char>
using list::push_front<const char *>
using list::push_front<void *>

#endif


