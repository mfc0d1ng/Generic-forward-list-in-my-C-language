#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#require "forward_list_impl.h"
#require "struct.h"

#macro list::iterator<T>
    list::node<T>*
#end

#macro list::const_iterator<T>
    const list::node<T>*
#end

/* Constructing an empty %forward_list. */
#macro list::new()
    list::constructor()
#end

/**
 *  @brief Constructing a %forward_list.
 *  @param T      %forward_list type.
 *  @param __arr  An array of elements.
 *  @param __size Array size.
 * 
 *  This function constructs the %forward_list using copies of the 
 *  elements in array @a __arr.
 *
 *  Requires:
 *  @using forward_list::push_front<T>
 */
#template list::construct<T>
static
std::forward_list<T> list::construct<T>(const T* __arr, size_t __size)
{
    std::forward_list<T> new = list::new();
    if(!__arr)
    { 
        return new;
    }
    for (size_t i = __size; i > 0; )
    {
        list::push_front<T>(&new, __arr[--i]);
    }
    return new;
}
#end

/**
 *  @param __list Reference to a %forward_list object.
 *  @returns An iterator that points before the first element 
 *           in the %forward_list.
 */
#macro list::before_begin(__list)
    list::_m_before_begin(__list)
#end

/**
 *  @param __list Reference to a %forward_list object.
 *  @returns A read/write iterator that points to the first element 
 *           in the %forward_list. Iteration is done in ordinary 
 *           element order.
 */
#macro list::begin(__list)
    list::_m_begin(__list)
#end

/**
 *  @returns An iterator that points one past the last 
 *           element in the %forward_list.
 */
#macro list::end()
    list::_m_end()
#end

/**
 * @param __list  Reference to a %forward_list object.
 * @returns A read/write access to the first element 
 *          in non-empty %forward_list.
 */
#macro list::front(__list)
    list::_m_front(__list)
#end

/* Returns true if the %forward_list is empty. */
#macro list::empty(__list)
    (list::begin(__list) == NULL)
#end

/**
 * @brief  Add data to the front of the %forward_list.
 * @param T       %forward list type.
 * @param __list  Reference to a %forward_list object.
 * @param __x     Data to be added.
 *
 * This is a typical stack operation.  The function creates an
 * element at the front of the %forward_list and assigns the given 
 * data to it.  Due to the nature of a %forward_list this operation 
 * can be done in constant time, and does not invalidate iterators 
 * and references.
 */
#template list::push_front<T>
static
void list::push_front<T>(std::forward_list<T>* __list, T __x)
{
    list::node<T>* node = list::get_node<T>;
    if(!node)
    {
        list::exit("list::push_front<T>(): memory allocation failed");
    }
    node->data = __x;
    if(list::empty(__list))
    {
        node->next = NULL;
        list::begin(__list) = node;
    }
    else
    {
        node->next = list::begin(__list);
        list::begin(__list) = node;
    }
    ++list::size(__list);
}
#end

/**
 * @brief  Removes first element.
 * @param T      %forward list type.
 * @param __list Reference to a %forward_list object.
 *
 * This is a typical stack operation.  It shrinks the %forward_list
 * by one.  Due to the nature of a %forward_list this operation can 
 * be done in constant time, and only invalidates iterators/references
 * to the element being removed.
 *
 * Note that no data is returned, and if the first element's data
 * is needed, it should be retrieved before list::pop_front<T>() is
 * called.
 */
#template list::pop_front<T>
static
void list::pop_front<T>(std::forward_list<T>* __list)
{
    if(!list::empty(__list))
    {
        void* temp = list::begin(__list);
        list::begin(__list) = list::begin(__list)->next;
        free(temp);
        --list::size(__list);
    }
}
#end

/**
 * @brief Inserts given value into %forward_list after specified iterator.
 * @param T            %forward list type.
 * @param __list       Reference to a %forward_list object.
 * @param __position   An iterator into the %forward_list.
 * @param __x          Data to be inserted.
 * @return An iterator that points to the inserted data.
 * 
 * This function will insert a copy of the given value after the specified location.
 * Due to the nature of a %forward_list this operation can be done in constant time,
 * and does not invalidate iterators and references.
 */
#template list::insert_after<T>
static
list::iterator<T> list::insert_after<T>(std::forward_list<T>* __list, list::iterator<T> __position, T __x)
{
    list::node<T>* node = list::get_node<T>;
    if(!node)
    {
        list::exit("list::insert<T>(): memory allocation failed");
    }
    node->data = __x;
    if(list::empty(__list))
    {
        node->next = NULL;
        list::begin(__list) = node;
    }
    else
    {
        if(__position == list::before_begin(__list))
        {
            node->next = list::begin(__list);
            list::begin(__list) = node;
        }
        else
        {
            node->next = __position->next;
            __position->next = node;
        }
    }
    ++list::size(__list);
    return node;
}
#end

/* 
 * @brief Returns the number of elements in the %forward_list.
 * @param __list  Reference to a %forward_list object.
 */
#macro list::size(__list)
    list::_m_size(__list)
#end

/**
 * @brief  Erases all the elements.
 * @param  __list  Reference to a %forward_list object.
 * 
 * Note that this function only erases the elements, and
 * that if the elements themselves are pointers, the pointed-to
 * memory is not touched in any way. Managing the pointer is the
 * user's responsibility.
 */
#macro list::clear(__list)
    list::_m_clear(__list)
#end

#macro list::delete(__list)
    list::_m_clear(__list)
#end

#template list::display<T>
static 
void list::display<T>(const char* __fmt, const std::forward_list<T>* __list)
{
    for (list::iterator<T> it = list::begin(__list); 
                           it != list::end();
                           it = it->next)
    {
        printf(__fmt, it->data);
    }
    putchar('\n');
}
#end

#endif


