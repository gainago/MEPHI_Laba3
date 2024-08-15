#include <iostream>
#include <vector>
#include <string>
#include "MyString.h"
#include "Person.h"
#include "Complex.h"
#include "test.h"
#include "UI.h"

int main()
{
   testComplex();
    testVector();
    testLinearForm();
    testStack();
    std::string userChoice;
    menu();

    do
    {
        std::getline(std::cin, userChoice);
        std::vector<std::string> words = splitString(userChoice);
        if (userChoice == "menu")
        {
            menu();
        }
        else if (words.size() == 0)
        {
            continue;
        }
        else if (userChoice == "quit")
        {
            break;
        }
        else if (words.size() != 3)
        {
            throw std::invalid_argument("Unknown command");
        }
        else if (words[0] == "linear_form")
        {
            if (words[1] == "int")
            {
                LinearForm<int> linearForm;
                linearFormInterface(linearForm, words[2]);
            }
            else if (words[1] == "double")
            {
                LinearForm<double> linearForm;
                linearFormInterface(linearForm, words[2]);
            }
            else if (words[1] == "complex")
            {
                LinearForm<Complex> linearForm;
                linearFormInterface(linearForm, words[2]);
            }
            else
            {
                throw std::invalid_argument("Unknown type");
            }
        }
        else if (words[0] == "vector")
        {
            if (words[1] == "int")
            {
                Vector<int> vector;
                vectorInterface(vector, words[2]);
            }
            else if (words[1] == "double")
            {
                Vector<double> vector;
                vectorInterface(vector, words[2]);
            }
            else if (words[1] == "complex")
            {
                Vector<Complex> vector;
                vectorInterface(vector, words[2]);
            }
            else
            {
                throw std::invalid_argument("Unknown type");
            }
        }
        else if (words[0] == "stack")
        {
            if (words[1] == "int")
            {
                Stack<int> stack;
                stackInterface(stack, words[2]);
            }
            else if (words[1] == "double")
            {
                Stack<double> stack;
                stackInterface(stack, words[2]);
            }
            else if (words[1] == "complex")
            {
                Stack<Complex> stack;
                stackInterface(stack, words[2]);
            }
            else if (words[1] == "string")
            {
                Stack<MyString> stack;
                stackInterface(stack, words[2]);
            }
            else if (words[1] == "person")
            {
                Stack<Person> stack;
                stackInterface(stack, words[2]);
            }
            else
            {
                throw std::invalid_argument("Unknown type");
            }
        }
        else
        {
            throw std::invalid_argument("Unknown command");
        }
    } while (userChoice != "quit");
    return 0;
}
