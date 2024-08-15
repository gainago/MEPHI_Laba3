#ifndef VECTOR_H
#define VECTOR_H
#include "ArraySequence.h"
#include "cmath"


template <typename T>
class Vector
{
private:
    DynamicArray<T> *elems;
public:
    Vector()
    {
        elems = new DynamicArray<T>();
    }
    Vector(int size)
    {
        elems = new DynamicArray<T>(size);
    }

    Vector(T *items, int size)
    {
        elems = new DynamicArray<T>(items, size);
    }

    Vector(const Vector<T> &vector)
    {
        elems = new DynamicArray<T>(vector.GetSize());
        for (int i = 0; i < this->GetSize(); i++)
        {
            elems->Set(i, vector[i]);
        }
    }

    ~Vector()
    {
        delete elems;
    }

    Vector<T> *Sum(const Vector<T> &vector) const
    {
        if (vector.GetSize() != this->GetSize())
        {
            throw "error\n";
        }
        T *resultElems = new T[this->GetSize()];
        for (int i = 0; i < vector.GetSize(); i++)
        {
            resultElems[i] = (*this)[i] + vector[i];
        }
        auto *result = new Vector(resultElems, this->GetSize());
        return result;
    }

    Vector<T> *MultiOnScalar(const T scalar) const
    {
        T *resultElems = new T[this->GetSize()];
        for (int i = 0; i < this->GetSize(); i++)
        {
            resultElems[i] = (*this)[i] * scalar;
        }
        auto *result = new Vector(resultElems, this->GetSize());
        return result;
    }

    T scalarProduct(const Vector<T> &vector) const
    {
        if (this->GetSize() != vector.GetSize())
        {
            throw "error";
        }
        T result = (*this)[0] * vector[0];
        for (int i = 1; i < this->GetSize(); i++)
        {
            result = result + (*this)[i] * vector[i];
        }
        return result;
    }

    

    int GetSize() const
    {
        return elems->GetSize();
    }

    Vector<T> *operator+(const Vector<T> &vector) const
    {
        Vector<T> *result = this->Sum(vector);
        return result;
    }

    Vector<T> *operator*(const T scalar) const
    {
        Vector<T> *result = this->MultiOnScalar(scalar);
        return result;
    }

    T operator*(const Vector<T>& vector) const
    {
        T result = this->scalarProduct(vector);
        return result;
    }

    T& operator[](const int index) const
    {
        return elems->Get(index);
    }

    Vector<T> &operator=(const Vector<T>& vector)
    {
        if (this != &vector)
        {
            delete this->elems;
            elems = new DynamicArray<T>(*(vector.elems));
        }
        return *this;
    }

    bool operator==(const Vector<T>& vector) const
    {
        if (this->GetSize() != vector.GetSize())
        {
            return false;
        }
        for (int i = 0; i < elems->GetSize(); i++)
        {
            if ((*this)[i] != vector[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector<T>& vector) const
    {
        if (this->GetSize() != vector.GetSize())
        {
            return true;
        }
        for (int i = 0; i < this->GetSize(); i++)
        {
            if ((*this)[i] != vector[i])
            {
                return true;
            }
        }
        return false;
    }
};

#endif
