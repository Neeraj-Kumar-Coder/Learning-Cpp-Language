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

class InfixToPostfix
{
private:
    string infixExpression;
    string postfixExpression;

protected:
    int precedence(char operation)
    {
        if (operation == '+' || operation == '-')
        {
            return 1;
        }
        else if (operation == '*' || operation == '/')
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

    int isOperator(char character)
    {
        switch (character)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
            break;

        default:
            return 0;
            break;
        }
    }

public:
    void inputInfixExpression(void)
    {
        cout << "Enter the Infix expression: ";
        getline(cin, infixExpression);
    }
    void convertToPostfix(void)
    {
        int length = infixExpression.length();
        Stack operatorStack;
        int index = 0;
        while (index < length)
        {
            if (operatorStack.isEmpty() && isOperator(infixExpression[index]))
            {
                operatorStack.push(infixExpression[index++]);
            }
            else if (isOperator(infixExpression[index]))
            {
                if (precedence(infixExpression[index]) > precedence(operatorStack.stackTop()))
                {
                    operatorStack.push(infixExpression[index++]);
                }
                else
                {
                    postfixExpression.push_back(operatorStack.pop());
                }
            }
            else if (infixExpression[index] == '(')
            {
                operatorStack.push(infixExpression[index++]);
            }
            else if (infixExpression[index] == ')')
            {
                ++index;
                while (operatorStack.stackTop() != '(')
                {
                    postfixExpression.push_back(operatorStack.pop());
                }
                operatorStack.pop();
            }
            else
            {
                postfixExpression.push_back(infixExpression[index++]);
            }
        }

        while (!operatorStack.isEmpty())
        {
            postfixExpression.push_back(operatorStack.pop());
        }
    }
    void displayInfixExpression(void)
    {
        cout << "The infix expression is: " << infixExpression << '\n';
    }
    void displayPostfixExpression(void)
    {
        cout << "The postfix expression is: " << postfixExpression << '\n';
    }
};

int main(void)
{
    InfixToPostfix object;
    object.inputInfixExpression();
    object.convertToPostfix();
    object.displayInfixExpression();
    object.displayPostfixExpression();
    return 0;
}