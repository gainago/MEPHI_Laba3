#ifndef UI_H
#define UI_H
#include "Complex.h"
#include <sstream>

std::vector<std::string> splitString(const std::string& str) {
    std::istringstream iss(str);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

template <typename T>
void printStack(const Stack<T> &stack)
{
    std::cout << "[";
    for (int i = 0; i < stack.GetSize(); i++)
    {
        std::cout << stack.Peek(i);
        i + 1 != stack.GetSize() ? std::cout << ", " : std::cout << "";
    }
    std::cout << ']' << std::endl;
}

template <typename T>
void setStack(Stack<T> &stack)
{
    int size;
    std::cout << "Enter size of stack" << std::endl;
    std::cin >> size;
    T elem;
    std::cout << "Enter elements" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> elem;
        stack.Push(elem);
    }
}

template <typename T>
void printVector(const Vector<T> &vector)
{
    std::cout << "{";
    for (int i = 0; i < vector.GetSize(); i++)
    {
        std::cout << vector[i];
        i + 1 != vector.GetSize() ? std::cout << ", " : std::cout << "";
    }
    std::cout << "}\n";
}

template <typename T>
void setVector(Vector<T> &vector)
{
    int size;
    std::cout << "Enter size of vector" << std::endl;
    std::cin >> size;
    T *elems = new T[size];
    std::cout << "Enter elements" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> elems[i];
    }

    Vector<T> buf(elems, size);
    vector = buf;
}

template <typename T>
void printLinearForm(const LinearForm<T> &linearForm)
{
    for (int i = 0; i < linearForm.GetSize(); i++)
    {
        std::string index = std::to_string(i);
        std::cout << "(" << linearForm[i] << " * x" << i << ")" ;
        i + 1 != linearForm.GetSize() ? std::cout << " + " : std::cout << "";
    }
    std::cout << '\n';
}

template <typename T>
void setLinearForm(LinearForm<T> &linearForm)
{
    int size;
    std::cout << "Enter size of linear form" << std::endl;
    std::cin >> size;
    T *elems = new T[size];
    std::cout << "Enter elements" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> elems[i];
    }

    LinearForm<T> buf(elems, size);
    linearForm = buf;
}

void menu()
{
    std::cout << "Supported containers: linear_form, vector, stack" << std::endl;
    std::cout << "Supported functions and types for containers: " << std::endl;
    std::cout << "linear_form: print, sum, subtract, multiply_by_scalar, calculate, get_size, get_element"
    << std::endl;
    std::cout << "Types: int, double, complex" << std::endl;
    std::cout << "vector: print, sum, multiply_vectors, multiply_by_scalar, get_size, get_element"
    << std::endl;
    std::cout << "Types: int, double, complex" << std::endl;
    std::cout << "stack: is_empty, peek, push, pop, get_size, get_top, is_substack_here, get_substack, concat"
    << std::endl;
    std::cout << "Types: int, double, complex, string, person" << std::endl;
    std::cout << "To use program enter: <container> <type> <function>" << std::endl;
    std::cout << "Enter <quit> to stop program" << std::endl;
    std::cout << "Enter <menu> to get help" << std::endl;
}

template <typename T>
void linearFormInterface(LinearForm<T> &linearForm, std::string operation)
{
    T item;
    int index;
    T *items = new T[linearForm.GetSize()];
    LinearForm<T> secondLinearForm;
    LinearForm<T> *result;
    if (operation == "print")
    {
        std::cout << "Create linear form" << std::endl;
        setLinearForm(linearForm);
        printLinearForm(linearForm);
    }
    else if (operation == "sum")
    {
        std::cout << "Create first linear form" << std::endl;
        setLinearForm(linearForm);
        std::cout << "Create second linear form" << std::endl;
        setLinearForm(secondLinearForm);
        result = linearForm + secondLinearForm;
        std::cout << "Result: ";
        printLinearForm(*result);
    }
    else if (operation == "subtract")
    {
        std::cout << "Create first linear form" << std::endl;
        setLinearForm(linearForm);
        std::cout << "Create second linear form" << std::endl;
        setLinearForm(secondLinearForm);
        result = linearForm - secondLinearForm;
        std::cout << "Result: ";
        printLinearForm(*result);
    }
    else if (operation == "multiply_by_scalar")
    {
        std::cout << "Create linear form" << std::endl;
        setLinearForm(linearForm);
        std::cout << "Enter scalar" << std::endl;
        std::cin >> item;
        result = linearForm * item;
        std::cout << "Result: ";
        printLinearForm(*result);
    }
    else if (operation == "calculate")
    {
        std::cout << "Create linear form" << std::endl;
        setLinearForm(linearForm);
        std::cout << "Enter values" << std::endl;
        for (int i = 0; i < linearForm.GetSize(); i++)
        {
            std::cin >> items[i];
        }
        std::cout << "Result: " << linearForm.CalcValue(items) << std::endl;
    }
    else if (operation == "get_size")
    {
        std::cout << "Create linear form" << std::endl;
        setLinearForm(linearForm);
        std::cout << "Result: " << linearForm.GetSize() << std::endl;
    }
    else if (operation == "get_element")
    {
        std::cout << "Create linear form" << std::endl;
        setLinearForm(linearForm);
        std::cout << "Enter index" << std::endl;
        std::cin >> index;
        std::cout << "Result: " << linearForm[index] << std::endl;
    }
    else
    {
        throw std::invalid_argument("Unknown command");
    }
    delete[] items;
}

template <typename T>
void vectorInterface(Vector<T> &vector, std::string operation)
{
    T item;
    int index;
    T *items = new T[vector.GetSize()];
    Vector<T> secondVector;
    Vector<T> *result;
    if (operation == "print")
    {
        std::cout << "Create vector" << std::endl;
        setVector(vector);
        printVector(vector);
    }
    else if (operation == "sum")
    {
        std::cout << "Create first vector" << std::endl;
        setVector(vector);
        std::cout << "Create second vector" << std::endl;
        setVector(secondVector);
        result = vector + secondVector;
        std::cout << "Result: ";
        printVector(*result);
    }
    else if (operation == "multiply_vectors")
    {
        std::cout << "Create first vector" << std::endl;
        setVector(vector);
        std::cout << "Create second vector" << std::endl;
        setVector(secondVector);
        item = vector * secondVector;
        std::cout << "Result: " << item;
    }
    else if (operation == "multiply_by_scalar")
    {
        std::cout << "Create vector" << std::endl;
        setVector(vector);
        std::cout << "Enter scalar" << std::endl;
        std::cin >> item;
        result = vector * item;
        std::cout << "Result: ";
        printVector(*result);
    }
    else if (operation == "get_size")
    {
        std::cout << "Create vector" << std::endl;
        setVector(vector);
        std::cout << "Result: " << vector.GetSize() << std::endl;
    }
    else if (operation == "get_element")
    {
        std::cout << "Create vector" << std::endl;
        setVector(vector);
        std::cout << "Enter index" << std::endl;
        std::cin >> index;
        std::cout << "Result: " << vector[index] << std::endl;
    }
    else
    {
        throw std::invalid_argument("Unknown command");
    }
    delete[] items;
}

template <typename T>
void stackInterface(Stack<T> &stack, std::string operation)
{
    T item;
    int startIndex, endIndex;
    Stack<T> secondStack;
    Stack<T> *result;
    if (operation == "is_empty")
    {
        std::cout << "Create the stack" << std::endl;
        setStack(stack);
        stack.IsEmpty() == true ? std::cout << "Stack is empty" : std::cout << "Stack is not empty";
        std::cout << std::endl;
    }
    else if (operation == "push")
    {
        std::cout << "Create the stack" << std::endl;
        setStack(stack);
        std::cout << "Enter item you want to push to the stack: " << std::endl;
        std::cin >> item;
        stack.Push(item);
        std::cout << "Result: ";
        printStack(stack);
    }
    else if (operation == "peek")
    {
        std::cout << "Create the stack" << std::endl;
        setStack(stack);
        std::cout << "Enter index: ";
        std::cin >> startIndex;
        std::cout << "Result: " << stack.Peek(startIndex);
    }
    else if (operation == "pop")
    {
        std::cout << "Create the stack" << std::endl;
        setStack(stack);
        stack.Pop();
        std::cout << "Result: ";
        printStack(stack);
    }
    else if (operation == "get_size")
    {
        std::cout << "Create the stack" << std::endl;
        setStack(stack);
        std::cout << "Size: " << stack.GetSize();
    }
    else if (operation == "get_top")
    {
        std::cout << "Create the stack" << std::endl;
        setStack(stack);
        std::cout << "Top element: " << stack.Top();
    }
    else if (operation == "is_substack_here")
    {
        std::cout << "Create the main stack" << std::endl;
        setStack(stack);
        std::cout << "Create the second stack" << std::endl;
        setStack(secondStack);
        std::cout << "Result: " << stack.IsSubStackHere(secondStack) << std::endl;
    }
    else if (operation == "get_substack")
    {
        std::cout << "Create the stack" << std::endl;
        setStack(stack);
        std::cout << "Enter start and end indices" << std::endl;
        std::cin >> startIndex >> endIndex;
        std::cout << "Result: " << std::endl;
        result = stack.GetSubStack(startIndex, endIndex);
        printStack(*result);
    }
    else if (operation == "concat")
    {
        std::cout << "Create the first stack" << std::endl;
        setStack(stack);
        std::cout << "Create the second stack" << std::endl;
        setStack(secondStack);
        std::cout << "Result: ";
        result = stack.Concat(secondStack);
        printStack(*result);
    }
    else
    {
        throw std::invalid_argument("Unknown command");
    }
}

#endif
