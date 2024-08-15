#ifndef LINEAR_FORM_H
#define LINEAR_FORM_H
#include "ArraySequence.h"

template <typename T>
class LinearForm
{
private:
    DynamicArray<T> *elems;
public:
    LinearForm()
    {
        elems = new DynamicArray<T>();
    }

    LinearForm(T *items, int dimension)
    {
        elems = new DynamicArray<T>(items, dimension);
    }

    LinearForm(const LinearForm<T> &linearForm)
    {
        elems = new DynamicArray<T>(linearForm.GetSize());
        for (int i = 0; i < this->GetSize(); i++)
        {
            elems->Set(i, linearForm[i]);
        }
    }

    ~LinearForm()
    {
        delete elems;
    }

    LinearForm<T> *Sum(const LinearForm<T> linearForm) const
    {
        if (this->GetSize() != linearForm.GetSize())
        {
            throw "invalid argument";
        }
        T *resultElems = new T[this->GetSize()];
        for (int i = 0; i < linearForm.GetSize(); i++)
        {
            resultElems[i] = (*this)[i] + linearForm[i];
        }
        auto *result = new LinearForm(resultElems, this->GetSize());
        return result;
    }

    LinearForm<T> *Subtract(const LinearForm<T> linearForm) const
    {
        if (this->GetSize() != linearForm.GetSize())
        {
            throw "invalid argument";
        }
        T *resultElems = new T[this->GetSize()];
        for (int i = 0; i < linearForm.GetSize(); i++)
        {
            resultElems[i] = (*this)[i] - linearForm[i];
        }
        auto *result = new LinearForm(resultElems, this->GetSize());
        return result;
    }

    LinearForm<T> *MultiOnScalar(const T scalar) const
    {
        T *resultElems = new T[this->GetSize()];
        for (int i = 0; i < this->GetSize(); i++)
        {
            resultElems[i] = (*this)[i] * scalar;
        }
        auto *result = new LinearForm(resultElems, this->GetSize());
        return result;
    }

    T CalcValue(const T *items) const
    {
        T result = items[0] * (*this)[0];
        for (int i = 1; i < this->GetSize(); i++)
        {
            result = result + items[i] * (*this)[i];
        }
        return result;
    }

    int GetSize() const
    {
        return elems->GetSize();
    }

    LinearForm<T> *operator*(const T scalar) const
    {
        LinearForm<T> *result = this->MultiOnScalar(scalar);
        return result;
    }

    LinearForm<T> *operator+(const LinearForm<T> linearForm) const
    {
        LinearForm<T> *result = this->Sum(linearForm);
        return result;
    }

    LinearForm<T> *operator-(const LinearForm<T> linearForm) const
    {
        LinearForm<T> *result = this->Subtract(linearForm);
        return result;
    }

    T operator[](const int index) const
    {
        return elems->Get(index);
    }

    LinearForm<T> &operator=(const LinearForm<T>& linearForm)
    {
        if (this != &linearForm)
        {
            elems = new DynamicArray<T>(*(linearForm.elems));
        }
        return *this;
    }

    bool operator==(const LinearForm<T>& linearForm) const
    {
        if (this->GetSize() != linearForm.GetSize())
        {
            return false;
        }
        for (int i = 0; i < elems->GetSize(); i++)
        {
            if ((*this)[i] != linearForm[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const LinearForm<T>& linearForm) const
    {
        if (this->GetSize() != linearForm.GetSize())
        {
            return true;
        }
        for (int i = 0; i < this->GetSize(); i++)
        {
            if ((*this)[i] != linearForm[i])
            {
                return true;
            }
        }
        return false;
    }


    T operator[](const int index)
    {
        return elems->Get(index);
    }
};

#endif
