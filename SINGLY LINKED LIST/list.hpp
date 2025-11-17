#ifndef _SINGLY_LINKED_LIST_HPP
#define _SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <cassert>
#include <cstdlib>

#define SUCCESS                 1 
#define TRUE                    1 
#define FALSE                   0 
#define LIST_INVALID_DATA       2 
#define LIST_EMPTY              3 

template <typename T>
class Node
{
    public:
        T data;
        Node<T>* next;

        Node(T _data, Node<T>* p_next) : data(_data), next(p_next) {}
};

template <typename T>
class list
{
    private:
        Node<T>* node;
    public:
        list() : node(new Node<T>(T(), nullptr)){}

        int get_start(T* p_start_data)
        {
            if(node->next == nullptr)
                return (LIST_EMPTY);
            *p_start_data = node->next->data;
            return (SUCCESS);
        }

        int get_end(T* p_end_data)
        {
            if(node->next == nullptr)
                return (LIST_EMPTY);
            Node<T>* run = node;   
            while(run->next != nullptr)
                run = run->next;
            *p_end_data = run->data;
            return (SUCCESS);
        }

        void insert_start(T new_data)
        {
            Node<T>* p_node = new Node<T>(new_data, node->next);
            node->next = p_node;
        }

        void insert_end(T new_data)
        {   
            Node<T>* run = node;
            while(run->next != nullptr)
                run = run->next;
            run->next = new Node<T>(new_data, nullptr);
        }

        int insert_after(T e_data, T new_data)
        {
            Node<T>* p_node = search_node(e_data);
            if(p_node == nullptr)
                return (LIST_INVALID_DATA);
            Node<T>* p_new_node = new Node<T>(new_data, p_node->next);
            p_node->next = p_new_node;
            return (SUCCESS);
        }

        Node<T>* search_node(T e_data)
        {
            Node<T>* run = node->next;
            while(run != nullptr)
            {
                if(run->data == e_data)
                    break;
                run = run->next;
            }
            return (run);
        }

        int insert_before(T e_data, T new_data)
        {
            Node<T>* p_pred_node;
            Node<T>* p_node;

            get_node_and_its_pred(e_data, &p_pred_node, &p_node);
            if(p_pred_node == nullptr && p_node == nullptr)
                return (LIST_INVALID_DATA);
            Node<T>* p_new_node = new Node<T>(new_data, p_node);
            p_pred_node->next = p_new_node;
            return (SUCCESS);
        }

        void get_node_and_its_pred(T e_data, Node<T>** pp_pred_node, Node<T>** pp_node)
        {
            Node<T>* p_pred_node = node;
            Node<T>* p_node = node->next;

            while(p_node != nullptr)
            {
                if(p_node->data == e_data)
                {
                    *pp_pred_node = p_pred_node;
                    *pp_node = p_node;
                    return;
                }
                p_pred_node = p_node;
                p_node = p_node->next;
            }

            *pp_pred_node = nullptr;
            *pp_node = nullptr;
        }

        int pop_start(T* p_start_data)
        {
            if(node->next == nullptr)
                return (LIST_EMPTY);
            Node<T>* first_node = node->next;
            *p_start_data = first_node->data;
            node->next = first_node->next;
            delete first_node;
            first_node = nullptr;
            return (SUCCESS);
        }

        int pop_end(T* p_end_data)
        {
            Node<T>* p_pred_last;
            Node<T>* p_last;

            get_last_and_its_pred(&p_pred_last, &p_last);
            if(p_pred_last == nullptr && p_last == nullptr)
                return (LIST_EMPTY);
            *p_end_data = p_last->data;
            delete p_last;
            p_last = nullptr;
            p_pred_last->next = nullptr;
            return (SUCCESS);
        } 

        int remove_start(void)
        {
            if(node->next == nullptr)
                return (LIST_EMPTY);
            Node<T>* first_node = node->next;
            node->next = first_node->next;
            delete first_node;
            first_node = nullptr;
            return (SUCCESS);
        }

        int remove_end(void)
        {
            Node<T>* p_pred_last;
            Node<T>* p_last;

            get_last_and_its_pred(&p_pred_last, &p_last);
            if(p_pred_last == nullptr && p_last == nullptr)
                return (LIST_EMPTY);
            delete p_last;
            p_last = nullptr;
            p_pred_last->next = nullptr;
            return (SUCCESS);
        }

        void get_last_and_its_pred(Node<T>** pp_pred_last, Node<T>** pp_last)
        {
            Node<T>* p_pred_last = node;
            Node<T>* p_last = node->next;

            if(p_last == nullptr)
            {
                *pp_pred_last = nullptr;
                *pp_last = nullptr;
                return;
            }

            while(p_last->next != nullptr)
            {
                p_pred_last = p_last;
                p_last = p_last->next;
            }

            *pp_pred_last =  p_pred_last;
            *pp_last = p_last;
        }

        int remove_data(T r_data)
        {
            Node<T>* p_pred_node;
            Node<T>* p_node;
            get_node_and_its_pred(r_data, &p_pred_node, &p_node);
            if(p_pred_node == nullptr && p_node == nullptr)
                return (LIST_INVALID_DATA);
            p_pred_node->next = p_node->next;
            delete p_node;
            p_node = nullptr;
            return (SUCCESS);
        }

        int get_length(void)
        {
            int count = 0;
            Node<T>* run = node->next;
            while(run != nullptr)
            {
                count++;
                run = run->next;
            }
            return (count);
        }

        int is_list_empty(void)
        {
            return (node->next == nullptr);
        }

        void show_list(const char* msg)
        {
            if(msg)
                std::cout << msg << std::endl;
            std::cout << "[START]->";
            Node<T>* run = node->next;
            while(run != nullptr)
            {
                std::cout << "[" << run->data << "]->";
                run = run->next;
            }
            std::cout << "[END]";
        }

        ~list()
        {
            Node<T>* run = node->next;
            Node<T>* run_next;

            while(run != nullptr)
            {
                run_next = run->next;
                delete run;
                run = run_next;
            }

            delete node;
            node = nullptr;
        }
}; 

#endif 

