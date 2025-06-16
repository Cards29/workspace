#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node* next;
    node* previous;
    // node() : data(0), next(nullptr), previous(nullptr) {}
    node(int value) : data(value), next(nullptr), previous(nullptr) {}
}node;
class linked_list
{
    node* head;
    node* tail;
public:
    linked_list() :head(nullptr), tail(nullptr) {}

    void Insert_front(int key) {
        node* new_node = new node(key);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }
        else {
            new_node->next = head;
            head->previous = new_node;
            head = new_node;
        }
    }
    void Insert_back(int key) {
        node* new_node = new node(key);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->previous = tail;
            tail = new_node;
        }
    }
    void Insert_after_node(int key, int v) {
        node* i = head;
        while (i != NULL && i->data != v) i = i->next;

        if (i == NULL) cerr << "Value not found" << endl;
        else {
            node* new_node = new node(key);
            new_node->next = i->next;
            new_node->previous = i;
            i->next = new_node;
            i->next->previous = new_node;
            if (i == tail) {
                tail = new_node;
            }
        }
    }
    void Update_node(int key, int v) {
        node* i = head;
        while (i != NULL && i->data != v) i = i->next;
        if (i == NULL) cerr << "Value not found" << endl;
        else i->data = key;
    }
    void Remove_head() {
        if (head == nullptr) {
            cerr << "Underflow" << endl;
            return;
        }
        node* temp = head;
        if (tail == head) tail = nullptr;
        head = head->next;
        head->previous = nullptr;
        delete temp;
    }
    void Remove_element(int key) {
        if (head == nullptr) {
            cerr << "Value not found" << endl;
            return;
        }
        if (head->data == key) {
            if (tail == head) tail = nullptr;
            node* temp = head;
            head = head->next;
            head->previous = nullptr;
            delete temp;
            return;
        }
        node* i = head;
        // node* previous_node;
        while (i != nullptr && i->data != key) {
            // previous_node = i;
            i = i->next;
        }
        if (i == nullptr) cerr << "Value not found" << endl;
        else {
            if (tail == i) tail = i->previous;
            i->previous->next = i->next;
            delete i;
        }
    }
    void Remove_end() {
        if (head == nullptr) {
            cerr << "Underflow" << endl;
            return;
        }
        if (head == tail) {
            node* temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;;
            return;
        }
        node* i = head;
        // node* previous_node = nullptr;
        while (i->next != nullptr) {
            // previous_node = i;
            i = i->next;
        }
        tail = i->previous;
        tail->next = nullptr;
        delete i;
    }
    void print_list() {
        node* temp = head;
        if(temp==nullptr) cout<<"Empty"<<endl <<"NULL";
        else cout << temp->data;
        cout << " (HEAD) ";
        if(temp!=nullptr)
            temp = temp->next;
        while (temp != nullptr)
        {
            cout << "-> " << temp->data << " ";
            temp = temp->next;
        }
        cout << "(TAIL) " << endl;
    }
    ~linked_list() {
        for (node* i = head; i != NULL;) {
            node* temp;
            temp = i;
            i = i->next;
            delete temp;
        }
        cout << "linked list was destroyed" << endl;
    }
};
int main() {
    linked_list list;
    while (true) {
        string input;
        cout << "INSERT_FRONT to insert at front" << endl
            << "INSERT_Back to insert at back" << endl
            << "INERT AFTER to insert after a node" << endl
            << "UPDATE to update a node" << endl
            << "REMOVE_HEAD to remove the first node" << endl
            << "REMOVE to remove a node" << endl
            << "REMOVE_TAIL to remove the last node" << endl
            << "EXIT to exit." << endl;
        cin >> input;

        if (input == "INSERT_FRONT") {
            int x; cin >> x;
            list.Insert_front(x);
            cout<<endl;
            list.print_list();
        }
        else if (input == "INSERT_BACK") {
            int x; cin >> x;
            list.Insert_back(x);
            cout<<endl;
            list.print_list();
        }
        else if (input == "INSERT_AFTER") {
            int x, v; cin >> x >> v;
            list.Insert_after_node(x, v);
            cout<<endl;
            list.print_list();
        }
        else if (input == "UPDATE") {
            int x, v; cin >> x >> v;
            list.Update_node(x, v);
            cout<<endl;
            list.print_list();
        }
        else if (input == "REMOVE_HEAD") {
            list.Remove_head();
            cout<<endl;
            list.print_list();
        }
        else if (input == "REMOVE") {
            int x; cin>>x;
            list.Remove_element(x);
            cout<<endl;
            list.print_list();
        }
        else if (input == "REMOVE_TAIL") {
            list.Remove_end();
            list.print_list();
        }
        else if (input == "EXIT") {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid option! Please try again." << endl;
        }
        cout << endl;
    }
    return 0;
}