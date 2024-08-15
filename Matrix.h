#ifndef MATRIX_H
#define MATRIX_H
#include "Vector.h"


template <typename Type>
class Matrix{
private:
    Vector< Vector<Type>* >* Elems; //можно было использовать не указатели памяти не на много больше ушло бы
    size_t lines;
    size_t columns;
public:
    Matrix(size_t lines, size_t columns)
    {
        Elems = new Vector< Vector<Type>* >((int)lines);
            if(Elems == nullptr)
                throw "error new\n";
        for(size_t i = 0 ; i < lines; i++)
        {
            Elems->operator[](i) = new Vector<Type>(columns);
            if(Elems->operator[](i) == nullptr)
                throw "new error\n";
        }
        this->lines = lines;
        this->columns = columns;
    }

    template<size_t lines, size_t columns>
    Matrix(Type (&array)[lines][columns])
    {
         Elems = new Vector< Vector<Type>* >((int)lines);
            if(Elems == nullptr)
                throw "error new\n";
        for(size_t i = 0 ; i < lines; i++)
        {
            Elems->operator[](i) = new Vector<Type>(columns);
            if(Elems->operator[](i) == nullptr)
                throw "new error\n";
        }
        for(size_t i = 0; i < lines; i++)
        {
            for(size_t j = 0; j < columns; j++)
            {
                Type current = array[i][j];
                ((*Elems->operator[](i)))[j] = current;
            }
        }
        this->lines = lines;
        this->columns = columns;
    }

    Matrix(Matrix<Type> const & Mat) : Matrix<Type>(Mat.GetLines(), Mat.GetColumns())
    {
        
        for(size_t i = 0; i < lines; i++)
        {
            for(size_t j = 0; j < columns; j++)
            {
                this->operator[](i)[j] = Mat.GetElem(i, j);
            }
            
        }
    }
    ~Matrix()
    {
        if(Elems == nullptr)
            return;
        for(size_t i = 0 ; i < lines; i++)
        {
            delete Elems->operator[](i);
            
        }
        delete Elems;
    }
    Type GetElem(size_t line, size_t colum) const
    {
        if(line >= this->GetLines() || colum >=GetColumns())
            throw "error\n";
        return ((*Elems->operator[](line)))[colum];

    }
    size_t GetLines() const
    {   
        if(this->Elems == nullptr)
            return 0;
        return this->Elems->GetSize();
    }
    size_t GetColumns() const
    {
        if(this->Elems == nullptr)
            return 0;
        if(this->Elems->operator[](0) == nullptr)
            return 0;
        return this->Elems->operator[](0)->GetSize();
    }
    Vector<Type> & operator[](size_t i)
    {
        return *(Elems->operator[](i));
    }

    void operator=(Matrix<Type> const & MatTwo)
    {
        this->~Matrix();

        this->lines = MatTwo.GetLines();
        this->columns = MatTwo.GetColumns();

        Elems = new Vector< Vector<Type>* >((int)lines);
            if(Elems == nullptr)
                throw "error new\n";
        
        for(size_t i = 0 ; i < lines; i++)
        {
            Elems->operator[](i) = new Vector<Type>(columns);
            if(Elems->operator[](i) == nullptr)
                throw "new error\n";
        }

        for(size_t i = 0; i < lines; i++)
        {
            for(size_t j = 0; j < columns; j++)
            {
                this->operator[](i)[j] = MatTwo.GetElem(i, j);
            }
            
        }
    }

    Matrix<Type> operator*(int coefficient) const
    {
        Matrix<Type> MatReturn(*this);

        for(size_t i = 0; i < lines; i++)
        {
            for(size_t j = 0; j < columns; j++)
            {
                MatReturn[i][j] = (MatReturn.GetElem(i, j) * coefficient);
            }
            
        }
        return MatReturn;
    }

    Matrix<Type> operator/(int coefficient) const
    {
        Matrix<Type> MatReturn(*this);

        for(size_t i = 0; i < lines; i++)
        {
            for(size_t j = 0; j < columns; j++)
            {
                MatReturn[i][j] = (MatReturn.GetElem(i, j) / coefficient);
            }
            
        }
        return MatReturn;
    }

    
    Matrix<Type> operator*(Matrix<Type> const & MatTwo) const
    {
        if(this->GetColumns() != MatTwo.GetLines())
            throw "undefined operation\n";
        size_t LinesReturn = this->GetLines();
        size_t ColumsReturn = MatTwo.GetColumns();
        Matrix <Type> MatReturn(LinesReturn, ColumsReturn);
        Type Buffer = 0;
        for(size_t i = 0; i < this->GetLines(); i++)
        {
            for(size_t j = 0; j < MatTwo.GetColumns(); j++)
            {
                for(size_t line = 0; line < this->GetColumns(); line++)
                {
                        Buffer+= this->GetElem(i,line) * MatTwo.GetElem(line,j);
                    
                }
                MatReturn[i][j] = Buffer;
                Buffer = 0; 
            }
        }

        
        return MatReturn;
    }
    Matrix<Type> operator+(Matrix<Type> const & Mat) const
    {
        if(this->GetLines() != Mat.GetLines() || this->GetColumns() != Mat.GetColumns())
            throw "invalid sizes\n";
        Matrix<Type> MatReturn(this->GetLines(),this->GetColumns());
        for(size_t i = 0; i < lines; i++)
        {
            for(size_t j = 0; j < columns; j++)
            {
                MatReturn[i][j] = this->GetElem(i, j) + Mat.GetElem(i, j);
            }
        }
        return MatReturn;
    }

    

};


#endif