#include <iostream>

using namespace std;

class Stack;

class Node
{
protected:
    char data;
    Node *next = NULL;
    friend class Stack;
};

class Stack
{
private:
    Node *top;

public:
    Stack(void)
    {
        top = NULL;
    }

    int isEmpty(void)
    {
        return !top;
    }

    void push(char key)
    {
        Node *temp = new Node;
        temp->data = key;
        temp->next = top;
        top = temp;
    }

    char pop(void)
    {
        if (!isEmpty())
        {
            char key = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            return key;
        }
        return '\0';
    }

    char stackTop(void)
    {
        if (!isEmpty())
        {
            return top->data;
        }
        return '\0';
    }

    char stackBottom(void)
    {
        if (!isEmpty())
        {
            Node *temp = top;
            while (temp->next)
            {
                temp = temp->next;
            }
            return temp->data;
        }
        return '\0';
    }
};

class ParenthesisMatching
{
private:
    string parenthesizedString;

protected:
    int isMatching(char param1, char param2)
    {
        if (param1 == '(' && param2 == ')')
        {
            return 1;
        }
        else if (param1 == '[' && param2 == ']')
        {
            return 1;
        }
        else if (param1 == '{' && param2 == '}')
        {
            return 1;
        }
        else if (param1 == '<' && param2 == '>')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

public:
    void input(void)
    {
        cout << "Enter the string you want to check for balanced parenthesis: ";
        getline(cin, parenthesizedString);
    }

    int isBalanced(void)
    {
        Stack parenthesisStack;
        int lengthOfString = parenthesizedString.length();
        for (int i = 0; i < lengthOfString; i++)
        {
            if (parenthesizedString[i] == '(' || parenthesizedString[i] == '[' || parenthesizedString[i] == '{' || parenthesizedString[i] == '<')
            {
                parenthesisStack.push(parenthesizedString[i]);
            }
            else if (parenthesizedString[i] == ')' || parenthesizedString[i] == ']' || parenthesizedString[i] == '}' || parenthesizedString[i] == '>')
            {
                if (!isMatching(parenthesisStack.pop(), parenthesizedString[i]))
                {
                    return 0;
                }
            }
        }
        if (!parenthesisStack.isEmpty())
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

int main(void)
{
    ParenthesisMatching object;
    object.input();
    if (object.isBalanced())
    {
        cout << "The Brackets are BALANCED!\n";
    }
    else
    {
        cout << "The Brackets are NOT BALANCED\n";
    }
    return 0;
}