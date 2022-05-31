#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node* prev;
    Node* next;

};

Node* head = NULL;


void CreatNode(char data);
//void InsertByData(int search, char data, char operation);
//void InsertByPos(int pos, char data);
//void IAfter(Node* cNode, char data);
//void IBefore(Node* cNode, char data);
void ToDelete(Node* cNode);
void DeleteData(char data);
//void DeletePos(int pos);
void Display();

int main()
{
    CreatNode('a');
    CreatNode('b');
    CreatNode('c');
    CreatNode('d');
    CreatNode('e');

    DeleteData('d');
    //Display();
}

void CreatNode(char data)
{
    Node* nNode = new Node();
    nNode->data = data;
    nNode->next = NULL;
    nNode->prev = NULL;

    if (head == NULL)
    {
        head = nNode;
    }
    else
    {
        Node* cNode = head;
        while (cNode->next != NULL)
        {
            cNode = cNode->next;
        }
        cNode->next = nNode;
        nNode->prev = cNode;

    }
}

void Display()
{
    cout << "Display    ";
    Node* cNode = head;
    while (cNode->next != NULL)
    {
        cout << cNode->data << "   ";
        cNode = cNode->next;
    }
}
void DeleteData(char data)
{
    cout << "DeleteData   : ";
    Node* cNode = head;
    while (cNode->data != data)
    {
        cNode = cNode->next;
    }
    ToDelete(cNode);

}

void ToDelete(Node* cNode)
{
    // cNode->prev->next=cNode->next;
    // cNode->next->prev=cNode->prev;

    if(cNode->prev==NULL && cNode->next==NULL)
    {
        head=NULL;
    }
    else if(cNode->prev==NULL)
    {
        head=cNode->next;

    }
    else if(cNode->next==NULL)
    {
        cNode->prev=NULL;
    }
     delete cNode;
    
}







