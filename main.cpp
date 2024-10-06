#include <iostream>
#include <string>

using namespace std;

// LL Function Prototypes
void addNodeToHead(Node* &head);
void addNodeToTail(Node* &head);


// Create our Node Structure
class Node
{
    int reviewRating;
    string reviewComment;

    Node* next;
};


int main()
{
    // Create head pointer
    Node* head = nullptr;

    // Initialize our Upkeep Variables
    char listChoice = '';
    char continueChoice = '';




    return 0;
}

void addNodeToHead(Node* &head)
{
    // Allocate new Node to heap
    Node* newNode = new Node;

    // Initialize Input Variables
    int userReview = 0;
    string userComment = "";

    // Get Review Rating & Test-Case
    cout << "(0-5) Enter Review Rating: ";
    cin >> userReview;

    if (userReview < 0 || userReview > 5)
    {
        cout << "\nInvalid Review Rating";
        break;
    }

    // Get Review Comment
    cin.ignore();
    cout << "\nEnter Review Comment: ";
    getline(cin, userComment);

    // Set newNode Data Correctly with User Input
    newNode->reviewRating = userReview;
    newNode->reviewComment = userComment;

    // Set end of tail to null
    newNode->next = nullptr;

    // Now Connect the List. 2 Test Cases: If the list if filled or not.
    if (head) // 
    {

    }


}

void addNodeToTail(Node* &head)
{
    // Allocate new Node to heap
    Node* newNode = new Node;

    // Initialize Input Variables
    int userReview = 0;
    string userComment = "";

    // User Input
    // Get Review Rating & Test-Case
    cout << "(0-5) Enter Review Rating: ";
    cin >> userReview;

    if (userReview < 0 || userReview > 5)
    {
        cout << "\nInvalid Review Rating";
        break;
    }

    // Get Review Comment
    cin.ignore();
    cout << "\nEnter Review Comment: ";
    getline(cin, userComment);

    // Set newNode Data Correctly with User Input
    newNode->reviewRating = userReview;
    newNode->reviewComment = userComment;

    // Set end of tail to null
    newNode->next = nullptr;

    // Now Connect the List. 2 Cases : If LL is empty, or if its contained
    if (head) // If Linked List Containers items, then we have to find end and set it to NewNode
    {
        Node* traversalPtr = head;
        while (traversalPtr->next != nullptr)
        {
            traversalPtr = traversalPtr->next;
        }

        traversalPtr->next = newNode; // Connect end of List to newNode

    } else {

        head = newNode;
    }
}