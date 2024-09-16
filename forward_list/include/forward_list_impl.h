#ifndef FORWARD_LIST_IMPL_H
#define FORWARD_LIST_IMPL_H

#template forward_list<T>
#end

#template struct::forward_list<T>
typedef struct __attribute__((packed)) list::node<T>
{
    T data;
    struct list::node<T>* next;
}list::node<T>;
typedef struct std::forward_list<T>
{
    list::node<T>* head;
    size_t size;
}std::forward_list<T>;
typedef std::forward_list<T> forward_list<T>;
#end

#macro std::forward_list<T> 
    stdforward_list##T
#end

#macro forward_list<T>
    forward_list##T
#end

#macro list::node <T>
    list_node_##T
#end

#macro list::constructor()
    {.head = NULL, .size = 0}
#end

#macro list::construct<T>
    std_list_construct_##T
#end

#macro list::_m_before_begin(__list)
    ((void *)(&list::_m_begin(__list)))
#end

#macro list::_m_begin(__list)
    ((__list)->head)
#end

#macro list::_m_end()
    (NULL)
#end

#macro list::_m_front(__list)
    (list::_m_begin(__list)->data)
#end

#macro list::get_node<T>
    (list::node<T> *) malloc(sizeof(list::node<T>))
#end

#macro list::push_front<T>
    std_list_push_front_##T
#end

#macro list::pop_front<T>
    std_list_pop_front_##T
#end

#macro list::insert_after<T>
    std_list_insert_after_##T
#end

#macro list::display<T>
    std_list_display_##T
#end

#macro list::_m_size(__list)
    ((__list)->size)
#end

#macro list::_m_delete(__list)
({
    if(!list::empty(__list))
    {
        void* __temp = NULL;
        while (!list::empty(__list))
        {
            __temp = list::begin(__list);
            list::begin(__list) = list::begin(__list)->next;
            free(__temp);
        }
        list::size(__list) = 0;
    }
})
#end

void list::exit(const char* __errmsg)
{
    puts(__errmsg);
    exit(EXIT_FAILURE);
}

#endif
