#include <iostream>

using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

void insertAfter(struct Node* prev_node, struct Node* to_insert)
{
    if (prev_node == NULL)
    {
       cout <<"the given previous node cannot be NULL";
       return;
    }

    to_insert->next = prev_node->next;
    prev_node->next = to_insert;

}

void mergeLists(struct Node* ll1, struct Node* ll2) {
    while(ll1->next != NULL) {
        Node* next_ll2 = ll2->next;
        insertAfter(ll1, ll2);

        if (next_ll2 == NULL) break;

        ll2 = next_ll2;
        ll1 = ll1->next->next;
    }

    ll1->next = ll2;
}

void append(struct Node** head_ref, struct Node* to_insert)
{

    to_insert->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = to_insert;
       return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = to_insert;
    return;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
     cout << node->data << " ";
     node = node->next;
  }
}

int main(){

    int n, k, a, b;
    struct Node* ll1 = NULL;
    struct Node* ll2 = NULL;

    cout << "podaj liczbe elementow listy 1: " << endl;
    cin >> n;

    for ( int i = 0 ; i < n ; i++ ){
        cout << "podaj element listy 1: " << endl;
        cin >> a;
        Node* node_to_append = new Node();
        node_to_append->data = a ;
        append(&ll1, node_to_append);
    }

    cout << "podaj liczbe elementow listy 2: " << endl;
    cin >> k;

    for ( int i = 0 ; i < k ; i++ ){
        cout << "podaj element listy 2: " << endl;
        cin >> b;
        Node* node_to_append = new Node();
        node_to_append->data = b ;
        append(&ll2, node_to_append);

    }

    mergeLists(ll1, ll2);

    cout <<"Created Linked list is: ";
    printList(ll1);

  return 0;
}
