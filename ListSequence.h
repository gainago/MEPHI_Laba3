#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"

template <typename T>
class ListSequence: public Sequence<T>
{
protected:
    LinkedList<T> *list;
    virtual ListSequence<T> *GetInstance() = 0;
public:
    ListSequence()
    {
        this->list = new LinkedList<T>();
    }

    ListSequence(T *items, int count)
    {
        this->list = new LinkedList<T>(items, count);
    }

    ListSequence(const ListSequence<T> &seq)
    {
        this->list = new LinkedList<T>(*seq.list);
    }

    ListSequence(const Sequence<T> &seq)
    {
        this->list = new LinkedList<T>();
        for (int i = 0; i < seq.GetLength(); i++)
        {
            this->list->Append(seq.Get(i));
        }
    }

    ListSequence(LinkedList<T> *list)
    {
        this->list = new LinkedList<T>(*list);
    }

    ListSequence (const LinkedList<T>& list)
    {
        this->list = new LinkedList<T>(list);
    }

    ~ListSequence()
    {
        delete this->list;
    }

    T GetFirst() const override
    {
        return this->list->GetFirst();
    }

    T GetLast() const override
    {
        return this->list->GetLast();
    }

    T Get(int index) const override
    {
        return this->list->Get(index);
    }

    int GetLength() const override
    {
        return this->list->GetLength();
    }

    ListSequence<T> *Append(T item) override
    {
        ListSequence<T> *result = GetInstance();
        result->list->Append(item);
        return result;
    }

    ListSequence<T> *Prepend(T item) override
    {
        ListSequence<T> *result = GetInstance();
        result->list->Prepend(item);
        return result;
    }

    ListSequence<T> *InsertAt(T item, int index) override
    {
        ListSequence<T> *result = GetInstance();
        result->list->InsertAt(item, index);
        return result;
    }

    T &operator[] (int index) override
    {
        return (*(this->list))[index];
    }
};

template <typename T>
class MutableListSequence : public ListSequence<T>
{
private:
    ListSequence<T> *GetInstance() override
    {
        return static_cast<ListSequence<T> *> (this);
    }

public:
    using ListSequence<T>::ListSequence;

    MutableListSequence<T> *Concat(Sequence<T> &seq) override
    {
        for (int i = 0; i < seq.GetLength(); i++)
        {
            this->Append(seq.Get(i));
        }
        return this;
    }

    MutableListSequence<T> *GetSubSequence(int startIndex, int endIndex) const override
    {
        if (startIndex < 0 || endIndex < 0 || endIndex >= this->list->GetLength() || endIndex < startIndex)
        {
            throw "invalid argument";
        }
        LinkedList<T> *resultList = this->list->GetSubList(startIndex, endIndex);
        MutableListSequence<T> *result = new MutableListSequence<T>(resultList);
        result->list = resultList;
        return result;
    }

};

template <typename T>
class ImmutableListSequence : public ListSequence<T>
{
private:
    ListSequence<T> *GetInstance() override
    {
        ImmutableListSequence<T> *instance = new ImmutableListSequence<T> (*this);
        return instance;
    }

public:
    using ListSequence<T>::ListSequence;

    ImmutableListSequence<T> *Concat(Sequence<T> &seq) override
    {
        LinkedList<T> *resultList = new LinkedList<T>;
        for (int i = 0; i < this->GetLength(); i++)
        {
            resultList->Append(this->Get(i));
        }
        for (int i = 0; i < seq.GetLength(); i++)
        {
            resultList->Append(seq.Get(i));
        }
        ImmutableListSequence<T> *result = new ImmutableListSequence<T>(resultList);
        return result;
    }

    ImmutableListSequence<T> *GetSubSequence(int startIndex, int endIndex) const override
    {
        if (startIndex < 0 || endIndex < 0 || endIndex >= this->list->GetLength() || endIndex < startIndex)
        {
            throw "invalid argument";
        }
        LinkedList<T> *resultList = this->list->GetSubList(startIndex, endIndex);
        ImmutableListSequence<T> *result = new ImmutableListSequence<T>(resultList);
        result->list = resultList;
        return result;
    }
};

#endif