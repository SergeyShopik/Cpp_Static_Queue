#include<iostream>
#include<fstream>
#include<ctime>

struct Node
{
    int data;
    Node* next;
};
struct Fifo
{
    Node* head;
    Node* tail;
};

void init(Fifo& q)
{
    q.head = nullptr;
    q.tail = nullptr;
}
void pushBack(Fifo& que, int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = nullptr;

    if (que.tail)// if there are elements in the queue
    {
        que.tail->next = temp;// reassign tail's pointer to a new element
    }
    else
    {
        que.head = temp;// assign head to the temp element if the queue is empty
    }
    que.tail = temp;
}
int popFront(Fifo& que)
{
    int key;
    Node* temp = que.head;// create copy of the queue's head

    if (que.head == nullptr)
    {
        return 0;
    }
    else
    {
        key = que.head->data;
    }

    que.head = temp->next;
    delete temp;
    return key;
}

int main()
{
    srand(time(0));

    //1. Given to queue Q1 and Q2 filled randomly with integers. Create Q3 and fill it with sum of the elements Q3[i]=Q1[i]+Q2[i].
    // Keep filling Q3 till one of Q1 or Q2 becomes empty
    Fifo q1, q2, q3;
    init(q1);
    init(q2);
    init(q3);
    int arr[50] = { 0 };
    size_t size1, size2, size;

    size1 = rand() % 10;
    size2 = rand() % 10;
    size1 < size2 ? size = size1 : size = size2;

    for (size_t i = 0; i < size1; i++)
        pushBack(q1, rand() % 20);

    for (size_t i = 0; i < size2; i++)
        pushBack(q2, rand() % 20);


    for (size_t i = 0; i < size; i++)
        pushBack(q3, (popFront(q1) + popFront(q2)));
    std::cout << "Third queue:\n";
    for (size_t i = 0; i < size; i++)
        arr[i] = popFront(q3);

    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}