#ifndef SEQUENCE
#define SEQUENCE
#include<iostream>
#include <string>


using namespace std;

template <typename Key,typename Info>
class Sequence {

private:

//single-linked list

    struct Node {
        Key value;
        Info info;
        Node* next;
    };
    Node* head;

    int amount;
    
public:
//default constructor
    Sequence() {
        head = nullptr;
        amount = 0;
    }

    // Copy constructor
    Sequence(const Sequence& other) {
        head = nullptr;
        amount = 0;
        Node* current = other.head;
        while (current != nullptr) {
            insert_end(current->value, current->info);
            current = current->next;
        }
    }

//removes all the elements
    void remove_all() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        amount = 0;
    } 
//default destructor
    ~Sequence(){
        remove_all();
    }
//removes the first element
    void remove_first() {
        if (head != nullptr) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            amount--;
        }
    }
//copies all the elements of the input object to the object of this class
    void copy_all(const Sequence& other) {
        remove_all();
        Node* current = other.head;
        while (current) {
            insert_end(current->value, current->info);
            current = current->next;
        }
    }
//prints all the elements
    void print_All() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->value << ":" << current->info << " ";
            current = current->next;
        }

        cout <<"\n";
    }
    void print_Key() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->value <<" ";
            current = current->next;
        }

        cout <<"\n";
    }

//calculates how many elements does the linked list have
    int count_elements() const {
        return amount;
    }
//inserts elements from the other side
    void insert_end(const Key& value, const Info& info) {
        Node* new_node = new Node;
        new_node->value = value;
        new_node->info = info;
        new_node->next = nullptr;

        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }

        amount++;
    }
//same insert function but in the other direction
    void insert_front(const Key& value, const Info& info) {
        Node* new_node = new Node;
        new_node->value = value;
        new_node->info = info;
        new_node->next = head;
        head = new_node;
        amount++;
    }
//sets the size of the linked list it can be used for further upgrades in the code
    int get_size() const {
        return amount;
    }
//check if its empty
    bool is_it_empty() const {
        return amount == 0;
    }
//returns the current key 
    Key current_Key() {
        if (is_it_empty()) {

        cout<<"Empty linked-list"<<endl;
            return Key(); // returns default constructed Key object
        }
        return head->value;
    }
    Info current_Info() {
        if (is_it_empty()) {

        cout<<"Empty linked-list"<<endl;
            return Info(); // returns default constructed Key object
        }
        return head->info;
    }
//operator = 
    Sequence& operator=(const Sequence& other) {
        if (this != &other) {
            remove_all();
            copy_all(other);
        }
        return *this; 
    }
};

#endif