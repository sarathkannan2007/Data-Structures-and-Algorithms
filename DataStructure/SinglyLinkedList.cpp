#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
Node* createNode(int value);
void display();
void insertBeginning(int value);
void insertEnd(int value);
void insertPosition(int value, int pos);
void deleteBeginning();
void deleteEnd();
void deletePosition(int pos);
void search(int key);
void countNodes();
void update(int oldValue, int newValue);
void reverseList();
void deleteList();

Node* createNode(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void display()
{   
    if(head == NULL){
        cout<<"List Is Empty"<<endl;
        return;
    }
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

void insertBeginning(int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}
void insertEnd(int value)
{
    Node *newNode = createNode(value);
    Node *temp = head;
    while(temp->next != NULL){
        temp =temp->next;
    }
    temp->next = newNode;
}
void insertPosition(int value, int pos)
{
    if(pos == 1){
       insertBeginning(value);
       return;
    }
    Node *newNode = createNode(value);
    Node *temp = head;
    for(int i =1;i<pos-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteBeginning()
{
    if(head == NULL){
        cout<<"List Is Empty"<<endl;
        return;
    }
    head= head->next;
}
void deleteEnd()
{
    Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next=NULL;
}
void deletePosition(int pos)
{
    Node *temp = head;
    for(int i =1;i<pos-1;i++){
        temp = temp->next;
    }
    Node *del;
    del = temp->next;
    temp->next=del->next;
}
void search(int key)
{
    Node *temp = head;
    int count =1;
    while(temp != NULL){
        if(temp->data == key){
            cout<<"Element Found  "<<endl;
           
            return;
        }
         temp=temp->next;
        
    }
    cout<<"Element not Found"<<endl;
    
}
void reverseList()
{
    Node *temp = head;
    Node *prev = NULL;
    Node *next = NULL;
    while(temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}
void deleteList()
{   
    while(head != NULL){
        head=head->next;
    }
}


int main()
{
    int choice;
    int value, pos, key, oldValue, newValue;

    do
    {
        cout << "\n========== Singly Linked List ==========\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Display\n";
        cout << "8. Search\n";
        cout << "11. Reverse List\n";
        cout << "12. Delete Entire List\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter Value : ";
                cin >> value;
                insertBeginning(value);
                break;

            case 2:
                cout << "Enter Value : ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                cout << "Enter Value : ";
                cin >> value;
                cout << "Enter Position : ";
                cin >> pos;
                insertPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                cout << "Enter Position : ";
                cin >> pos;
                deletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Enter Element to Search : ";
                cin >> key;
                search(key);
                break;

            case 11:
                reverseList();
                break;

            case 12:
                deleteList();
                break;

            case 0:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    } while(choice != 0);

    return 0;
}
