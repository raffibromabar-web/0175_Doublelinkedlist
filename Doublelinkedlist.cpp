#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "Enter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newnode = new Node();

        // Step 2: Assign value to the data field
        newnode->noMhs = nim;

        // If list is empty or inserting at 1st is empty or not in sorted
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate roll numbers not allowed" << endl;
                return;
            }

                       // Step 3: newnode.next = START
            newnode->next = START;

            // Step 4: START.prev = newnode (if START exists)
            if (START != NULL)
                START->prev = newnode;

            // Step 5: newnode.prev = NULL
            newnode->prev = NULL;

            // Step 6: START = newnode
            START = newnode;
            return;
        }

        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

           // Step 8: Insert between current and current->next
        newnode->next = current->next;
        newnode->prev = current;    // Step 10

        if (current->next != NULL)
            current->next->prev = newnode; // Step 11

        current->next = newnode;      // Step 12
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

         Node *current = START;

         // Step 1: Traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // Step 2: If node is at the beginning
        if (current == START)
        {
            START = current->next; // Step 3a
            if (START != NULL)
                START->prev = NULL; // Step 3b
        }
        else
        {
            // Step 4: Link previous node to next of current
            current->prev->next = current->next;

            // Step 5: Link next node to prev of current
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // Step 6: Delete node
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Start from first node as currentnode
        Node *currentnode = START;

        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (currentnode != NULL)
        {
            // Step 2: Print roll no as currentnode->info
            cout << i + 1 << ". " << currentnode->noMhs << " " << endl;

            // Step 3: Move to next node
            currentnode = currentnode->next;
            i++;
        }
        
    }

     void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Move to last node
        Node *currentnode = START;
        int i = 0;

        while (currentnode->next != NULL)
        {
            currentnode = currentnode->next;
            i++;
        }

        // Step 2: Traverse backward
        cout << "\nRecords in descending order of roll number are:\n";
        while (currentnode != NULL)
        {
            cout << i + 1 << ". " << currentnode->noMhs << " " << endl;

            // Step 3: Move to previous node
            currentnode = currentnode->prev;
            i--;
        }
    }

        void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse and search roll no
        while (current != NULL && current->noMhs != rollNo)
        
            current = current->next;
        

        // Step 2: Output result
        if (current == NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll number: " << current->noMhs << endl;
        }
    }
};