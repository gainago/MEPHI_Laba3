#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

template <typename T>
class ArraySequence: public Sequence<T>
{
protected:
    DynamicArray<T> *array;
    virtual ArraySequence<T> *GetInstance() = 0;
public:
    ArraySequence()
    {
        this->array = new DynamicArray<T>();
    }

    ArraySequence(T *items, int count)
    {
        this->array = new DynamicArray<T>(items, count);
    }

    ArraySequence(const ArraySequence<T> &seq)
    {
        this->array = new DynamicArray<T>(*seq.array);
    }

    ArraySequence(const Sequence<T> &seq)
    {
        this->array = new DynamicArray<T>(seq.GetLength());
        for (int i = 0; i < seq.GetLength(); i++)
        {
            this->array->Set(i, seq.Get(i));
        }
    }

    ArraySequence(DynamicArray<T> *array)
    {
        this->array = new DynamicArray<T>(*array);
    }

    ArraySequence(const DynamicArray<T> &array)
    {
        this->array = new DynamicArray<T>(array);
    }

    virtual ~ArraySequence()
    {
        delete this->array;
    }

    T GetFirst() const override
    {
        return this->array->Get(0);
    }

    T GetLast() const override
    {
        return this->array->Get(this->array->GetSize() - 1);
    }

    T Get(int index) const override
    {
        return this->array->Get(index);
    }

    int GetLength() const override
    {
        return this->array->GetSize();
    }

    ArraySequence<T> *Append(T item) override
    {
        ArraySequence<T> *result = GetInstance();
        result->array->Resize(result->array->GetSize() + 1);
        result->array->Set(result->array->GetSize() - 1, item);
        return result;
    }

    ArraySequence<T> *Prepend(T item) override
    {
        ArraySequence<T> *result = GetInstance();
        result->array->Resize(result->array->GetSize() + 1);
        T current = this->array->Get(0);
        for (int i = result->array->GetSize() - 1; i > 0; i--)
        {
            result->array->Set(i, result->array->Get(i - 1));
        }
        result->array->Set(0, item);
        return result;
    }

    ArraySequence<T> *InsertAt(T item, int index) override
    {
        ArraySequence<T> *result = GetInstance();
        result->array->Resize(this->array->GetSize() + 1);
        for (int i = result->array->GetSize() - 1; i > index; i--)
        {
            result->array->Set(i, result->array->Get(i - 1));
        }
        result->array->Set(index, item);
        return result;
    }

    T &operator[] (int index) override
    {
        return (*(GetInstance ()->array))[index];
    }
};

template <typename T>
class MutableArraySequence : public ArraySequence<T>
{
private:
    ArraySequence<T> *GetInstance() override
    {
        return static_cast<ArraySequence<T> *> (this);
    }

public:
    using ArraySequence<T>::ArraySequence;

    MutableArraySequence<T> *Concat (Sequence<T> &seq) override
    {
        for (int i = 0; i < seq.GetLength(); i++)
        {
            this->Append(seq.Get(i));
        }
        return this;
    }

    MutableArraySequence<T> *GetSubSequence (int startIndex, int endIndex) const override
    {
        if (startIndex < 0 || endIndex < 0 || endIndex >= this->array->GetSize() || endIndex < startIndex)
        {
            throw "invalid argument";
        }
        DynamicArray<T> *resultArray = new DynamicArray<T>(endIndex - startIndex + 1);
        for (int i = 0; i < endIndex - startIndex + 1; i++)
        {
            resultArray->Set(i, this->array->Get(startIndex + i));
        }
        MutableArraySequence<T> *result = new MutableArraySequence<T>(resultArray);
        result->array = resultArray;
        return result;
    }
};

template <typename T>
class ImmutableArraySequence : public ArraySequence<T>
{
private:
    ArraySequence<T> *GetInstance() override
    {
        ImmutableArraySequence<T> *instance = new ImmutableArraySequence<T> (*this);
        return instance;
    }

public:
    using ArraySequence<T>::ArraySequence;

    ImmutableArraySequence<T> *Concat(Sequence<T> &seq) override
    {
        DynamicArray<T> *resultArray = new DynamicArray<T>(this->GetLength() + seq.GetLength());
        for (int i = 0; i < this->GetLength(); i++)
        {
            resultArray->Set(i, this->Get(i));
        }
        for (int i = 0; i < seq.GetLength(); i++)
        {
            resultArray->Set(this->GetLength() + i, seq.Get(i));
        }
        ImmutableArraySequence<T> *result = new ImmutableArraySequence<T>(resultArray);
        return result;
    }

    ImmutableArraySequence<T> *GetSubSequence(int startIndex, int endIndex) const override
    {
        if (startIndex < 0 || endIndex < 0 || endIndex >= this->array->GetSize() || endIndex < startIndex)
        {
            throw "invalid argument";
        }
        DynamicArray<T> *resultArray = new DynamicArray<T>(endIndex - startIndex + 1);
        for (int i = 0; i < endIndex - startIndex + 1; i++)
        {
            resultArray->Set(i, this->array->Get(startIndex + i));
        }
        ImmutableArraySequence<T> *result = new ImmutableArraySequence<T>(resultArray);
        result->array = resultArray;
        return result;
    }

};

#endif