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


    
};