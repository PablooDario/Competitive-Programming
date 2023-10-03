#include <iostream>
#include <vector>

//Create the Node Structure to connect the Stack
struct Node{
  int value;
  Node* next;
  Node(int x): value(x), next(nullptr){}
};

class MaxStack
{
//Create the size and relations properties
private:
  int size2=-1;
  Node* top;
public:
    //The top will be null when the constructor came out
    MaxStack()
    {
        top=nullptr;
    }

    //Just return the size property
    int size()
    {
        return size2;
    }

    //When the size is -1, the stack is empty
    bool isEmpty()
    {
        if(size2==-1)
          return true;
       return false;
    }

    //If the top is null, the stack is empty
    int peek()
    {
        if(!top)
            return -1;
        return top->value;
    }

    //Traverse the stack to find the max
    int max()
    {
        int maxi=INT_MIN;
        if(!top)
          return -1;
        Node* Aux=top;
        while(Aux!=nullptr)
        {
          if(Aux->value>maxi)
            maxi=Aux->value;
          Aux=Aux->next;
        }
        return maxi;
    }

    void push(int i)
    {
        if(!top)
          size2=1;
        else
           size2++;
        Node *newNode= new Node(i);
        newNode->next=top;
        top=newNode;
        return;
    }

    int pop()
    {
        if(!top)
            return -1;
        Node* Aux=top;
        top=top->next;
        int x=Aux->value;
        Aux->next=nullptr;
        delete(Aux);
        if(size2==1)
           size2=-1;
        else
            size2--;
        return x;
    }
};

// Testing helpers
void test(int testNum, int actual, int expected)
{
    if (actual == expected)
        std::cout << testNum << " : PASSED" << std::endl;
    else
        std::cout << testNum << " : FAILED" << std::endl;
}

void test(int testNum, bool actual, bool expected)
{
    test(testNum, actual ? 1 : 0, expected ? 1 : 0);
}

// Main part running the test output
#ifndef RunTests
int main()
{
    MaxStack maxStack;
    test(1, maxStack.isEmpty(), true);
    test(2, maxStack.size(), -1);
    maxStack.push(1);
    test(2, maxStack.peek(), 1);
    test(3, maxStack.pop(), 1);
    test(4, maxStack.pop(), -1);
    test(5, maxStack.peek(), -1);
    test(6, maxStack.isEmpty(), 1);
    /*
    test(2, maxStack.isEmpty(), false);
    test(3, maxStack.peek(), 3);
    test(4, maxStack.max(), 3);
    test(5, maxStack.pop(), 3);
    test(6, maxStack.peek(), 2);
    test(7, maxStack.max(), 2);
    */
}
#endif