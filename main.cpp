#include <iostream>
using namespace std;
class Node
{
public:
    Node()
    {
        next=NULL;
    }
    Node *next;
    int data;
};

class List
{

public:
    List()
    {
        head=NULL;
        tail=NULL;
        curser=NULL;
    }
    void Insert(int X);
    void Backward();
    void Remove();
    void Forward();
    void Clear();
    void Replace(int X);
    void Start();
    void End();
    void Print();

private:
    Node *head;
    Node *tail;
    Node *curser;

};

void List::Insert(int X)
{
    Node *N=new Node();
    N->data=X;
    if(head==NULL)
    {

        head=N;
        tail=N;
        curser=N;
    }
        /*else if(curser==head)
         {
             N=curser->next;   //New Node Created
             curser->next=N;   //Pointed to next Node
             curser=N;         //Pointed to next Node
         }*/
        // [1][2][3][5][]
    else if(curser==tail)
    {
        curser->next=N;
        curser=N;
        tail=N;

    }
    else if(curser!=tail)
    {
        N->next=curser->next;
        curser->next=N;
        curser=N;

    }
}

void List::Print()
{
    cout<<"Print Called"<<endl;
    Node *P=head;

    while(P!=NULL)
    {
        cout<<P->data<<" ";
        P=P->next;

    }
    cout<<endl;
    if(head!=NULL)
    {
        cout << "Head=" << head->data << endl;
        cout << "Curser=" << curser->data << endl;
        cout << "Tail=" << tail->data << endl;
    }
}

void List::Backward() {
    if(head==NULL || head==tail)
    {
        return;
    }
    if (curser == head) {
        /*Node *P=head
         [1][2][3][4]
         while(P->next!=Null)
         {
         if(P->next==Null)
         {
         curser=P;
         break;
         }
         }
         */
        curser = tail;
    }
    else {
        Node *P = head;
        while (P != NULL) {

            if (P->next == curser) {
                curser = P;
                break;
            }
            P=P->next;
        }
    }
}

void List::Forward()
{

    if(curser->next!=NULL)
    {
        curser=curser->next;
    }
    else
    {

        cout<<"Your Next Value is Null"<<endl;
        curser=head;

    }
}

void List::Remove()
{
    if(head==NULL)
    {
        return;
    }
    else if(head==tail)
    {
        delete curser;
        curser=NULL;
        tail=NULL;
        head=NULL;
    }
    else if(curser==head)
    {
        Node *P=head->next;
        delete head;
        head=P;
        curser=P;
    }
    else if(curser==tail)
    {

        Backward();
        delete tail;
        tail=curser;
        curser=head;
        tail->next=NULL;
    }
    else if(curser!=tail || curser!=head)
    {
        Node *P=curser->next;
        Backward();
        delete curser->next;
        curser->next=P;
        curser=P;
    }
}

void List::Clear()
{

    Node *P=head;
    while (head!=NULL)
    {
        Remove();
    }
    /* Node *P=head;
     Node *N=head->next;
     while(P!=NULL) {
         delete P;
         P = N;
         if(N!=NULL) {
             N = N->next;
         }
     }
      head=NULL;
      curser=NULL;
      tail=NULL;*/

}

void List::Replace(int X)
{
    curser->data=X;
}

void List::Start()
{
    curser=head;
}

void List::End()
{
    curser=tail;
}

int main() {
    int N,V;
    List A;
    while(N!=0)
    {
        cout<<"Enter 1 to Insert,,,,Enter 2 for Remove,,,Enter 3 for Forward"<<endl;
        cout<<"Enter 4 for Backward,,,Enter 5 for Clear,,,Enter 6 for Replace"<<endl;
        cout<<"Enter 7 for Course to go start,,,Enter 8 for Couser to go End"<<endl;
        cin>>N;
        if(N==1)
        {
            cout<<"Enter Value To insert "<<endl;
            cin>>V;
            A.Insert(V);
            A.Print();

        }
        if(N==2)
        {
            A.Remove();
            A.Print();
        }
        if(N==3)
        {
            A.Forward();
        }
        if(N==4)
        {
            A.Backward();
        }
        if(N==5)
        {
            A.Clear();
            A.Print();
        }
        if(N==6)
        {
            cout<<"Enter Value You Want To Replace "<<endl;
            cin>>V;
            A.Replace(V);
            A.Print();
        }
        if(N==7)
        {
            A.Start();
        }
        if(N==8)
        {
            A.End();

        }
    }
    return 0;
}