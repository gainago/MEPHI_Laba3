#ifndef STACK_H
#define STACK_H
#include "ListSequence.h"

template <typename T>
class Stack
{
private:
    MutableListSequence<T> *elements;
public:
    Stack()
    {
        elements = new MutableListSequence<T>();
    }

    Stack(T *items, int count)
    {
        elements = new MutableListSequence<T>(items, count);
    }

    Stack(const Stack<T> &stack)
    {
        elements = new MutableListSequence<T>();
        for (int i = 0; i < stack.GetSize(); i++)
        {
            this->elements->Append(stack.elements->Get(i));
        }
    }

    ~Stack()
    {
        delete elements;
    }

    int GetSize() const
    {
        return this->elements->GetLength();
    }

    bool IsEmpty() const
    {
        return this->GetSize() == 0;
    }

    T Peek(int i) const
    {
        return this->elements->Get(i);
    }

    T Top() const
    {
        return this->elements->GetLast();
    }

    void Push(const T item)
    {
        this->elements->Append(item);
    }

    void Pop()
    {
        if (this->GetSize() != 1)
        {
            MutableListSequence<T> *result = this->elements->GetSubSequence(0, this->GetSize() - 2);
            delete this->elements;
            this->elements = result;
        }
        else
        {
            MutableListSequence<T> *result = this->elements->GetSubSequence(0, 0);
            delete this->elements;
            this->elements = result;
        }
    }

    template<typename U>
    Stack<T> *Map(U (*func)(T))
    {
        Stack<U> *result = new Stack<U>();
        for (int i = 0; i < this->GetSize(); i++)
        {
            result->Push((*func)(this->elements->Get(i)));
        }
        return result;
    }

    T Reduce(T (*func)(T, T), T start) const
    {
        for (int i = 0; i < this->GetSize(); i++)
        {
            start = (*func)(start, this->elements->Get(i));
        }
        return start;
    }

    template <typename... Types>
    Stack<T> *Where(bool (*func)(T, Types &...)) const
    {
        Stack<T> *result = new Stack<T>();
        for (int i = 0; i < this->GetSize(); i++)
        {
            if ((*func)(this->elements->Get(i)) == true)
            {
                result->Push(this->elements->Get(i));
            }
        }
        return result;
    }

    Stack<T> *Concat(const Stack<T> &stack)
    {
        for (int i = 0; i < stack.GetSize(); i++)
        {
            this->Push((*stack.elements)[i]);
        }
        return this;
    }

    Stack<T> *GetSubStack(int startIndex, int endIndex)
    {
        Stack<T> *result = new Stack<T>();
        result->elements = elements->GetSubSequence(startIndex, endIndex);
        return result;
    }

    bool IsSubStackHere(const Stack<T> &stack)
    {
        if (this->GetSize() < stack.GetSize())
        {
            return false;
        }
        bool flag = false;
        for (int i = 0; i < this->GetSize() - stack.GetSize(); i++)
        {
            flag = true;
            int j;
            j = 0;
            while (j < stack.GetSize() && flag) {
                if (this->elements->Get(i + j) == stack.elements->Get(j))
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
                j++;
            }
            if (flag) {
                break;
            }
        }
        return flag;
    }
};

#endif
