#include "list.hpp"
#include <string>

void testWithInt(void);
void testWithFloat(void);
void testWithChar(void);
void testWithString(void);

int main(void)
{
    testWithInt();
    testWithFloat();
    testWithChar();
    testWithString();
    return (0);
}

void testWithInt(void)
{
    list<int> list1;
    
    list1.show_list("After Insertion at end");
 
    int data; 
    int status; 
    int length; 

    puts("SINGLY LINKED LIST:"); 

    assert(list1.get_start(&data) == LIST_EMPTY); 
    assert(list1.pop_start(&data) == LIST_EMPTY); 
    assert(list1.get_end(&data) == LIST_EMPTY); 
    assert(list1.pop_end(&data) == LIST_EMPTY); 
    assert(list1.remove_start() == LIST_EMPTY); 
    assert(list1.remove_end() == LIST_EMPTY); 
    assert(list1.get_length() == 0); 
    assert(list1.is_list_empty() == TRUE); 
    puts("testing, get_start(), pop_start(), get_end(), pop_end(), remove_start(), remove_end() on empty list...OK"); 
    puts("testing, get_length() on empty list ... ok ");
    puts("testing, is_list_empty() on empty list ... ok"); 
    list1.show_list("testing, empty list"); 

    for(data = 0; data <= 40; data = data + 10)
        list1.insert_start(data); 

    list1.show_list("testing, insert_start()"); 

    for(data = 50; data <= 100; data = data + 10)
        list1.insert_end(data); 

    list1.show_list("testing, insert_end()"); 

    puts("testing, insert_after() for false case"); 
    status = list1.insert_after(-300, 500); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insert_after() false case... ok"); 

    puts("testing insert_before() for false case"); 
    status = list1.insert_before(8976, 500); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insert_before() false case ... ok"); 

    puts("testing insert_after() and insert_before() for valid data"); 
    status = list1.insert_after(0, 1000); 
    assert(status == SUCCESS); 
    status = list1.insert_before(0, 2000); 
    assert(status == SUCCESS); 

    list1.show_list("test, insert_after(), insert_before()... ok"); 

    status = list1.get_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "START OF LIST = " << data << std::endl;
    list1.show_list("showing list after get_start()"); 

    status = list1.get_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "END OF LIST = " << data << std::endl;
    list1.show_list("showing list after get_end()"); 

    status = list1.pop_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "START OF LIST = " << data << std::endl;
    list1.show_list("showing list after pop_start()"); 

    status = list1.pop_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "END OF LIST = " << data << std::endl;
    list1.show_list("showing list after pop_end()"); 

    status = list1.remove_start(); 
    assert(status == SUCCESS); 
    list1.show_list("showing list after remove_start()"); 

    status = list1.remove_end(); 
    assert(status == SUCCESS); 
    list1.show_list("showing list after remove_end()"); 

    puts("testing, get_start(), pop_start(), get_end(), pop_end(), remove_start(), remove_end() on non-empty list...OK"); 

    length = list1.get_length(); 
    std::cout << "length = " << length << std::endl;

    puts("testing remove_data() for false case"); 
    status = list1.remove_data(1234); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing remove data for false case ... ok"); 

    puts("testing remove_data() for success case"); 
    status = list1.remove_data(0); 
    assert(status == SUCCESS); 
    puts("testing remove data for success case ... ok"); 
    list1.show_list("showing list after removing 0"); 

    assert(list1.is_list_empty() == FALSE); 
    puts("testing, is_list_empty() for non-empty list...ok"); 

    // struct node* p_list_1 = create_list(); 
    // struct node* p_list_2 = create_list(); 

    // for(data = 10; data <= 50; data += 10)  
    //     insert_end(p_list_1, data); 

    // for(data = 15; data <= 85; data += 10)
    //     insert_end(p_list_2, data); 

    // struct node* p_concat_list = concat_lists(p_list_1, p_list_2); 

    // show_list(p_list_1, "List 1:"); 
    // show_list(p_list_2, "List 2:"); 
    // show_list(p_concat_list, "Concatenated list"); 

    // struct node* p_reversed_list = get_reversed_list(p_list_2); 
    // show_list(p_reversed_list, "Reversed version of list 2"); 

    
    // append(p_list_1, &p_list_2); 
    // assert(p_list_2 == NULL); 
    // show_list(p_list_1, "After appending list 2 to list 1"); 

    // destroy_list(p_list_1); 
    // p_list_1 = NULL; 

    // destroy_list(p_concat_list); 
    // p_concat_list = NULL; 

    // destroy_list(p_reversed_list); 
    // p_reversed_list = NULL; 

    // puts("exiting from application:SUCCESS");   
}


void testWithFloat(void)
{
    list<float> list1;
    
    list1.show_list("After Insertion at end");
 
    float data; 
    int status; 
    int length; 

    puts("SINGLY LINKED LIST:"); 

    assert(list1.get_start(&data) == LIST_EMPTY); 
    assert(list1.pop_start(&data) == LIST_EMPTY); 
    assert(list1.get_end(&data) == LIST_EMPTY); 
    assert(list1.pop_end(&data) == LIST_EMPTY); 
    assert(list1.remove_start() == LIST_EMPTY); 
    assert(list1.remove_end() == LIST_EMPTY); 
    assert(list1.get_length() == 0); 
    assert(list1.is_list_empty() == TRUE); 
    puts("testing, get_start(), pop_start(), get_end(), pop_end(), remove_start(), remove_end() on empty list...OK"); 
    puts("testing, get_length() on empty list ... ok ");
    puts("testing, is_list_empty() on empty list ... ok"); 
    list1.show_list("testing, empty list"); 

    for(data = 0.5; data <= 40.5; data = data + 10.1)
        list1.insert_start(data); 

    list1.show_list("testing, insert_start()"); 

    for(data = 50.7; data <= 100.7; data = data + 10.1)
        list1.insert_end(data); 

    list1.show_list("testing, insert_end()"); 

    puts("testing, insert_after() for false case"); 
    status = list1.insert_after(-300.5, 500.5); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insert_after() false case... ok"); 

    puts("testing insert_before() for false case"); 
    status = list1.insert_before(8976.5, 500.5); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insert_before() false case ... ok"); 

    puts("testing insert_after() and insert_before() for valid data"); 
    status = list1.insert_after(0.5, 1000.5); 
    assert(status == SUCCESS); 
    status = list1.insert_before(0.5, 2000.5); 
    assert(status == SUCCESS); 

    list1.show_list("test, insert_after(), insert_before()... ok"); 

    status = list1.get_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "START OF LIST = " << data << std::endl;
    list1.show_list("showing list after get_start()"); 

    status = list1.get_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "END OF LIST = " << data << std::endl;
    list1.show_list("showing list after get_end()"); 

    status = list1.pop_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "START OF LIST = " << data << std::endl;
    list1.show_list("showing list after pop_start()"); 

    status = list1.pop_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "END OF LIST = " << data << std::endl;
    list1.show_list("showing list after pop_end()"); 

    status = list1.remove_start(); 
    assert(status == SUCCESS); 
    list1.show_list("showing list after remove_start()"); 

    status = list1.remove_end(); 
    assert(status == SUCCESS); 
    list1.show_list("showing list after remove_end()"); 

    puts("testing, get_start(), pop_start(), get_end(), pop_end(), remove_start(), remove_end() on non-empty list...OK"); 

    length = list1.get_length(); 
    std::cout << "length = " << length << std::endl;

    puts("testing remove_data() for false case"); 
    status = list1.remove_data(1234); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing remove data for false case ... ok"); 

    puts("testing remove_data() for success case"); 
    status = list1.remove_data(0.5); 
    assert(status == SUCCESS); 
    puts("testing remove data for success case ... ok"); 
    list1.show_list("showing list after removing 0"); 

    assert(list1.is_list_empty() == FALSE); 
    puts("testing, is_list_empty() for non-empty list...ok"); 

    // struct node* p_list_1 = create_list(); 
    // struct node* p_list_2 = create_list(); 

    // for(data = 10; data <= 50; data += 10)  
    //     insert_end(p_list_1, data); 

    // for(data = 15; data <= 85; data += 10)
    //     insert_end(p_list_2, data); 

    // struct node* p_concat_list = concat_lists(p_list_1, p_list_2); 

    // show_list(p_list_1, "List 1:"); 
    // show_list(p_list_2, "List 2:"); 
    // show_list(p_concat_list, "Concatenated list"); 

    // struct node* p_reversed_list = get_reversed_list(p_list_2); 
    // show_list(p_reversed_list, "Reversed version of list 2"); 

    
    // append(p_list_1, &p_list_2); 
    // assert(p_list_2 == NULL); 
    // show_list(p_list_1, "After appending list 2 to list 1"); 

    // destroy_list(p_list_1); 
    // p_list_1 = NULL; 

    // destroy_list(p_concat_list); 
    // p_concat_list = NULL; 

    // destroy_list(p_reversed_list); 
    // p_reversed_list = NULL; 

    // puts("exiting from application:SUCCESS");   
}


void testWithChar(void)
{
    list<char> list1;
 
    char data; 
    int status; 
    int length; 

    puts("SINGLY LINKED LIST:"); 

    assert(list1.get_start(&data) == LIST_EMPTY); 
    assert(list1.pop_start(&data) == LIST_EMPTY); 
    assert(list1.get_end(&data) == LIST_EMPTY); 
    assert(list1.pop_end(&data) == LIST_EMPTY); 
    assert(list1.remove_start() == LIST_EMPTY); 
    assert(list1.remove_end() == LIST_EMPTY); 
    assert(list1.get_length() == 0); 
    assert(list1.is_list_empty() == TRUE); 
    puts("testing, get_start(), pop_start(), get_end(), pop_end(), remove_start(), remove_end() on empty list...OK"); 
    puts("testing, get_length() on empty list ... ok ");
    puts("testing, is_list_empty() on empty list ... ok"); 
    list1.show_list("testing, empty list"); 

    for(data = 'A'; data <= 'E'; data = data + 1)
        list1.insert_start(data); 

    list1.show_list("testing, insert_start()"); 

    for(data = 'F'; data <= 'J'; data = data + 1)
        list1.insert_end(data); 

    list1.show_list("testing, insert_end()"); 

    puts("testing, insert_after() for false case"); 
    status = list1.insert_after('Z', 'Y'); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insert_after() false case... ok"); 

    puts("testing insert_before() for false case"); 
    status = list1.insert_before('Z', 'Y'); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insert_before() false case ... ok"); 

    puts("testing insert_after() and insert_before() for valid data"); 
    status = list1.insert_after('A', 'X'); 
    assert(status == SUCCESS); 
    status = list1.insert_before('A', 'Z'); 
    assert(status == SUCCESS); 

    list1.show_list("test, insert_after(), insert_before()... ok"); 

    status = list1.get_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "START OF LIST = " << data << std::endl;
    list1.show_list("showing list after get_start()"); 

    status = list1.get_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "END OF LIST = " << data << std::endl;
    list1.show_list("showing list after get_end()"); 

    status = list1.pop_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "START OF LIST = " << data << std::endl;
    list1.show_list("showing list after pop_start()"); 

    status = list1.pop_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "END OF LIST = " << data << std::endl;
    list1.show_list("showing list after pop_end()"); 

    status = list1.remove_start(); 
    assert(status == SUCCESS); 
    list1.show_list("showing list after remove_start()"); 

    status = list1.remove_end(); 
    assert(status == SUCCESS); 
    list1.show_list("showing list after remove_end()"); 

    puts("testing, get_start(), pop_start(), get_end(), pop_end(), remove_start(), remove_end() on non-empty list...OK"); 

    length = list1.get_length(); 
    std::cout << "length = " << length << std::endl;

    puts("testing remove_data() for false case"); 
    status = list1.remove_data('O'); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing remove data for false case ... ok"); 

    puts("testing remove_data() for success case"); 
    status = list1.remove_data('A'); 
    assert(status == SUCCESS); 
    puts("testing remove data for success case ... ok"); 
    list1.show_list("showing list after removing 0"); 

    assert(list1.is_list_empty() == FALSE); 
    puts("testing, is_list_empty() for non-empty list...ok"); 

    // struct node* p_list_1 = create_list(); 
    // struct node* p_list_2 = create_list(); 

    // for(data = 10; data <= 50; data += 10)  
    //     insert_end(p_list_1, data); 

    // for(data = 15; data <= 85; data += 10)
    //     insert_end(p_list_2, data); 

    // struct node* p_concat_list = concat_lists(p_list_1, p_list_2); 

    // show_list(p_list_1, "List 1:"); 
    // show_list(p_list_2, "List 2:"); 
    // show_list(p_concat_list, "Concatenated list"); 

    // struct node* p_reversed_list = get_reversed_list(p_list_2); 
    // show_list(p_reversed_list, "Reversed version of list 2"); 

    
    // append(p_list_1, &p_list_2); 
    // assert(p_list_2 == NULL); 
    // show_list(p_list_1, "After appending list 2 to list 1"); 

    // destroy_list(p_list_1); 
    // p_list_1 = NULL; 

    // destroy_list(p_concat_list); 
    // p_concat_list = NULL; 

    // destroy_list(p_reversed_list); 
    // p_reversed_list = NULL; 

    // puts("exiting from application:SUCCESS");   
}

void testWithString(void)
{
    list<std::string> list1;
    
    list1.show_list("After Insertion at end");
 
    std::string data; 
    int status; 
    int length; 

    puts("SINGLY LINKED LIST:"); 

    assert(list1.get_start(&data) == LIST_EMPTY); 
    assert(list1.pop_start(&data) == LIST_EMPTY); 
    assert(list1.get_end(&data) == LIST_EMPTY); 
    assert(list1.pop_end(&data) == LIST_EMPTY); 
    assert(list1.remove_start() == LIST_EMPTY); 
    assert(list1.remove_end() == LIST_EMPTY); 
    assert(list1.get_length() == 0); 
    assert(list1.is_list_empty() == TRUE); 
    puts("testing, get_start(), pop_start(), get_end(), pop_end(), remove_start(), remove_end() on empty list...OK"); 
    puts("testing, get_length() on empty list ... ok ");
    puts("testing, is_list_empty() on empty list ... ok"); 
    list1.show_list("testing, empty list"); 


    list1.insert_start("Vidya"); 
    list1.insert_start("Sandhya");
    list1.insert_start("Sahil");
    list1.insert_start("Amruta");
    list1.insert_start("Amit");

    list1.show_list("testing, insert_start()"); 

    list1.insert_end("Kunal"); 
    list1.insert_end("Ashish"); 
    list1.insert_end("Prahlad"); 
    list1.insert_end("Gurubas"); 
    list1.insert_end("Anuraj"); 
    list1.insert_end("Mayur"); 

    list1.show_list("testing, insert_end()"); 

    puts("testing, insert_after() for false case"); 
    status = list1.insert_after("Mayuresh", "Indrajit"); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insert_after() false case... ok"); 

    puts("testing insert_before() for false case"); 
    status = list1.insert_before("Guarav", "Indrajit"); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insert_before() false case ... ok"); 

    puts("testing insert_after() and insert_before() for valid data"); 
    status = list1.insert_after("Sahil", "Piu"); 
    assert(status == SUCCESS); 
    status = list1.insert_before("Sahil", "Gobya"); 
    assert(status == SUCCESS); 

    list1.show_list("test, insert_after(), insert_before()... ok"); 

    status = list1.get_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "START OF LIST = " << data << std::endl;
    list1.show_list("showing list after get_start()"); 

    status = list1.get_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "END OF LIST = " << data << std::endl;
    list1.show_list("showing list after get_end()"); 

    status = list1.pop_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "START OF LIST = " << data << std::endl;
    list1.show_list("showing list after pop_start()"); 

    status = list1.pop_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "END OF LIST = " << data << std::endl;
    list1.show_list("showing list after pop_end()"); 

    status = list1.remove_start(); 
    assert(status == SUCCESS); 
    list1.show_list("showing list after remove_start()"); 

    status = list1.remove_end(); 
    assert(status == SUCCESS); 
    list1.show_list("showing list after remove_end()"); 

    puts("testing, get_start(), pop_start(), get_end(), pop_end(), remove_start(), remove_end() on non-empty list...OK"); 

    length = list1.get_length(); 
    std::cout << "length = " << length << std::endl;

    puts("testing remove_data() for false case"); 
    status = list1.remove_data("Saurav"); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing remove data for false case ... ok"); 

    puts("testing remove_data() for success case"); 
    status = list1.remove_data("Sahil"); 
    assert(status == SUCCESS); 
    puts("testing remove data for success case ... ok"); 
    list1.show_list("showing list after removing 0"); 

    assert(list1.is_list_empty() == FALSE); 
    puts("testing, is_list_empty() for non-empty list...ok"); 

    // struct node* p_list_1 = create_list(); 
    // struct node* p_list_2 = create_list(); 

    // for(data = 10; data <= 50; data += 10)  
    //     insert_end(p_list_1, data); 

    // for(data = 15; data <= 85; data += 10)
    //     insert_end(p_list_2, data); 

    // struct node* p_concat_list = concat_lists(p_list_1, p_list_2); 

    // show_list(p_list_1, "List 1:"); 
    // show_list(p_list_2, "List 2:"); 
    // show_list(p_concat_list, "Concatenated list"); 

    // struct node* p_reversed_list = get_reversed_list(p_list_2); 
    // show_list(p_reversed_list, "Reversed version of list 2"); 

    
    // append(p_list_1, &p_list_2); 
    // assert(p_list_2 == NULL); 
    // show_list(p_list_1, "After appending list 2 to list 1"); 

    // destroy_list(p_list_1); 
    // p_list_1 = NULL; 

    // destroy_list(p_concat_list); 
    // p_concat_list = NULL; 

    // destroy_list(p_reversed_list); 
    // p_reversed_list = NULL; 

    // puts("exiting from application:SUCCESS");   
}

