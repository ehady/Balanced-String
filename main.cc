#include <iostream>
#include "stack.h"
#include "node.h"

int main()
{
    Stack c;
    std::cout << "Enter a string: ";
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            c.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (c.empty())
            {
                std::cout << "String is not balanced" << std::endl;
                return 0;
            }
            if (str[i] == ')' && c.top() == '(')
            {
                c.pop();
            }
            else if (str[i] == '}' && c.top() == '{')
            {
                c.pop();
            }
            else if (str[i] == ']' && c.top() == '[')
            {
                c.pop();
            }
            else
            {
                std::cout << "String is not balanced" << std::endl;
                return 0;
            }
        }
    }
    if (c.empty())
    {
        std::cout << "String is balanced" << std::endl;
    }
    else
    {
        std::cout << "String is not balanced" << std::endl;
    }
}