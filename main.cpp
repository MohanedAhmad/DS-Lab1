#include <iostream>

using namespace std;

class Node{

public:
    int data;
    Node *next;
    Node *prev;

    Node( int _data = 0)
    {
        this->next = this->prev = NULL;
        this->data = _data;
    }
};

class linkedList{

private:
    Node *head;
    Node *tail;

    Node* getNode(int value)
    {
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->data == value)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }


public:
    linkedList()
    {
        this->head = this->tail = NULL;
    }

    void addNode(int _data)
    {
        Node* ptr = new Node(_data);

        if(head == NULL)
        {
            head = tail = ptr;
            return;
        }

        ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }

    void addNodeAfter(int _data, int afterData)
    {
        Node* newNode = new Node(_data);
        Node* foundNode = getNode(afterData);

        if(foundNode == NULL)
        {
            cout << "\nThere is NO node with value " << _data << " to add data after !!!\n";
            delete newNode;
        }
        else if(tail == foundNode)
        {
            this->addNode(_data);
        }
        else
        {
            newNode->next = foundNode->next;
            newNode->prev = foundNode;
            newNode->next->prev = newNode;
            foundNode->next = newNode;
        }
    }

    void addNodeBefore(int _data, int beforeData)
    {
        Node* newNode = new Node(_data);
        Node* foundNode = getNode(beforeData);

        if(foundNode == NULL)
        {
            cout << "\nThere is NO node with value " << _data << " to add data before !!!\n";
            delete newNode;
        }
        else if(head == foundNode)
        {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
        }
        else
        {
            newNode->prev = foundNode->prev;
            newNode->next = foundNode;
            newNode->prev->next = newNode;
            foundNode->prev = newNode;
        }
    }

    void removeNode(int _data)
    {
        Node* foundNode = getNode(_data);

        if(foundNode == NULL)
        {
            cout << "\nThere is NO node with value " << _data << " !!!\n";
            return;
        }
        if(head == foundNode)
        {
            if(head == tail)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
            }
        }
        else if(tail == foundNode)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            foundNode->prev->next = foundNode->next;
            foundNode->next->prev = foundNode->prev;
        }

        delete foundNode;
    }

    int GetCount()
    {
        int counter = 0;
        Node* temp = head;

        while(temp != NULL)
        {
            counter++;
            temp = temp->next;
        }

        return counter;
    }

    int GetDataByIndex(int index)
    {
        int counter = 0;
        Node* temp = head;

        if(temp == NULL)
        {
            cout << "\nThe LinkedList is empty now !!!\n";
            return -1;
        }

        while(temp != NULL)
        {
            if(counter == index)
            {
                return temp->data;
            }
            counter++;
            temp = temp->next;
        }

        cout << "\nIndex is out of range, the range is between 0 and " << counter - 1 << endl;
        return -1;
    }

    void print()
    {
        Node* temp = head;
        if(temp == NULL)
        {
            cout << "\nThe LinkedList is empty now !!!\n";
            return;
        }
        cout << "\n[ ";
        while(temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "]\n";
    }
};

int main()
{
    linkedList l;
    l.addNode(10);
    l.addNode(20);
    l.addNode(30);
    l.addNode(40);
    l.addNode(50);
    l.print();

    cout << "\n**************************************************************************\n";

    cout << "\nThe number of current nodes is : " << l.GetCount() << endl;

    cout << "\n**************************************************************************\n";

    cout << "\nThe value of node with index 0 is : " << l.GetDataByIndex(0) << endl;
    cout << "\nThe value of node with index 2 is : " << l.GetDataByIndex(2) << endl;
    cout << "\nThe value of node with index 7 is : " << l.GetDataByIndex(7) << endl;

    cout << "\n**************************************************************************\n";

    cout << "\nAdding 60 before 10 : " << endl;
    l.addNodeBefore(60,10);
    l.print();

    cout << "\nAdding 70 before 50 : " << endl;
    l.addNodeBefore(70,50);
    l.print();

    cout << "\nAdding 80 before 30 : " << endl;
    l.addNodeBefore(80,30);
    l.print();

    cout << "\nAdding 1000 before 1000 : " << endl;
    l.addNodeBefore(1000,1000);

    cout << "\n**************************************************************************\n";

    cout << "\nAdding 90 after 60 : " << endl;
    l.addNodeAfter(90,60);
    l.print();

    cout << "\nAdding 100 after 50 : " << endl;
    l.addNodeAfter(100,50);
    l.print();

    cout << "\nAdding 110 after 20 : " << endl;
    l.addNodeAfter(110,20);
    l.print();

    cout << "\nAdding 1000 after 1000 : " << endl;
    l.addNodeAfter(1000,1000);

    cout << "\n**************************************************************************\n";

    l.removeNode(15);

    l.removeNode(10);
    l.print();

    l.removeNode(50);
    l.print();

    l.removeNode(30);
    l.print();

    l.removeNode(40);
    l.print();

    l.removeNode(20);
    l.print();

    return 0;
}
