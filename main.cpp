#include <iostream>
#include <string>

using namespace std;


// Review Tracker Variable
static int reviewCount = 0;

// Create our Node Structure
class Node
{
    public:
    double reviewRating;
    string reviewComment;

    Node* next;
};

// LL Function Prototypes
void addNodeToHead(Node* &head);
void addNodeToTail(Node* &head);
void printNodes(Node* &head);
int getListChoice();

int main()
{
    // Create head pointer
    Node* head = nullptr;

    // Initialize our Choice Variables
    char continueChoice = 'Y';

    // Start out menu while loop.
    while (continueChoice == 'Y' || continueChoice == 'y')
    {
        int listChoice = getListChoice();

        if (listChoice == 1)
        {
            addNodeToHead(head);
        } else if (listChoice == 2)
        {
            addNodeToTail(head);
        } else
        {
            cout << "Invalid Input" << endl;
            return 1;
        }

        // Ask for Continue Choice Again
        cout << "Would you like to add another Review?";
        cin >> continueChoice;
        cin.ignore();

    } // End While

    return 0;
}

int getListChoice()
{
    // Temp Tracker Variable
    int tempChoice = 0;

    // Get User Input
    cout << "Would you like your data entered to the front or back of the list?" << endl;
    cout << "[1]: Front" << endl << "[2]: Back" << endl;
    cin >> tempChoice;
    cin.ignore();

    // Return Input
    return tempChoice;
}

void addNodeToHead(Node* &head)
{
    // Allocate new Node to heap
    Node* newNode = new Node;

    // Initialize Input Variables
    double userReview = 0;
    string userComment = "";

    // Get Review Rating & Test-Case
    cout << "(0-5) Enter Review Rating: ";
    cin >> userReview;
    cin.ignore();

    if (userReview < 0 || userReview > 5)
    {
        cout << "\nInvalid Review Rating";
        return;
    }

    // Get Review Comment
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
        newNode->next = head;
        head = newNode;
    } else 
    {
        head = newNode;
    }


}

void addNodeToTail(Node* &head)
{
    // Allocate new Node to heap
    Node* newNode = new Node;

    // Initialize Input Variables
    double userReview = 0;
    string userComment = "";

    // User Input
    // Get Review Rating & Test-Case
    cout << "(0-5) Enter Review Rating: ";
    cin >> userReview;
    cin.ignore();

    if (userReview < 0 || userReview > 5)
    {
        cout << "\nInvalid Review Rating";
        return;
    }

    // Get Review Comment
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

    } else 
    {
        head = newNode;
    }
}

void printNodes(Node* &head)
{
    // Create Average Counter

    // Print Node Data as long as next isnt a nullptr
    Node* traversalPtr = head;
    double averageTracker = 0.0;

    // Test Case if theres no Nodes to Print
    if (!traversalPtr) { cout << "Invalid Review List" << endl; return; }

    // Traverse through List
    while (traversalPtr)
    {
        cout << "Review #" << reviewCount + 1 << " " << traversalPtr->reviewRating << ": " << traversalPtr->reviewComment << endl;

        // Add Average Count and Review Count in List
        averageTracker += traversalPtr->reviewRating;
        reviewCount++;

        // Point to next node
        traversalPtr = traversalPtr->next;
    }

    cout << "\nAverage Rating: " << averageTracker / static_cast<double>(reviewCount) << endl;
}