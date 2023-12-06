#pragma once



#include <iostream>
#include <Vector.h>


using namespace std;



// матрица
template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
    TMatrix(int n=1, int m=1);
    TMatrix(const TMatrix<T>&p);
    TMatrix(TMatrix<T>&& p);
    ~TMatrix();

    TMatrix<T>& operator = (const Tmatrix<T>& p);
    TMatrix<T>& operator = (TMatrixr<T>&& p);

    bool operator==(const TMatrix& p) const;      // сравнение
    bool operator!=(const TMatrix& p) const;      // сравнение

    TMatrix<T> operator+ (const TMatrix& p);        // присваивание
    TMatrix<T>  operator* (const TMatrix& p);        // сложение
    TMatrix<T> operator- (const TMatrix& p);        // вычитание

    TMatrix<T> operator+ ( double a);        // присваивание
    TMatrix<T>  operator* ( double a);        // сложение
    TMatrix<T> operator- ( double a);        // вычитание
    void Resize(int N, int M);
    
    ;
    // ввод / вывод
    friend istream& operator>>(istream& in, TMatrix& p)
    {
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& p)
    {
        for (int i = 0; i < mt.Size; i++)
            out << mt.pVector[i] << endl;
        return out;
    }
};

template<class T>
inline TMatrix<T>::TMatrix(int n, int m)
{
    if ((n < 0) || (m < 0)) throw("invalid size");
    size = n;
    data = new TVector[size];
    for (int i = 0; i < size; i++)
        data[i].Resize(m);
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& p)
{
    size = p.size;
    data = new TVector<T>[size];
    for (int i = 0; i < size; i++)
        data[i] = p.data[i];
}

template<class T>
inline TMatrix<T>::TMatrix(TMatrix<T>&& p)
{
    size = p.size;
    data = p.data;
    p.size = 0;
    p.data = nullptr;
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
    if (data != nullptr)
    {
        delete[]data;
        size = 0;
        data = nullptr;
    }
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const Tmatrix<T>& p)
{
    if (this == &p)
        return *this;
    delete[]data;
    size = p.size;
    data = new TVector<T>[size];
    fot(int i = 0; i < size; i++)
        data[i] = p.data;
    return *this;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(TMatrixr<T>&& p)
{
    if (this == &p)
        return *this;
    delete[]data;
    size = p.size;
    data = new TVector<T>[size];
    fot(int i = 0; i < size; i++)
        data[i] = p.data;
    delete[]p.data;
    p.data = nullptr;
    p.size = 0;
    return *this;
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix& p) const
{
    if (size != p.size) return false;
    for (int i = 0; i < size; i++)
        if (data != p.data) return false;
    return true;
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix& p) const
{
    if (size != p.size) return true;
    for (int i = 0; i < size; i++)
        if (data != p.data) return true;
    return false;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix& p)
{
    TMatrix<T> res = *this;
    {
        if (size != p.size) throw("invalid sizes");
        for (int i = 0; i < size; i++)
            res[i] = data[i] + p.data[i];
    }
    return this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix& p)
{
    TMatrix<T> res = *this;
    {
        if (size != p.size) throw("invalid sizes");
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                res[i][j] = 0;
                for (int n = 0; n < size; n++)
                {
                    res[i][j] += data[i][n] * p.data[n][j];
                }
            }
           
    }
    return this;

}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix& p)
{
    TMatrix<T> res = *this;
    {
        if (size != p.size) throw("invalid sizes");
        for (int i = 0; i < size; i++)
            res[i] = data[i] - p.data[i];
    }
    return this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(double a)
{
    TMatrix<t> res = *this;
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                res[i][j] += a;
    }
    return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(double a)
{
    TMatrix<t> res = *this;
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                res[i][j] *= a;                  
    }
    return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(double a)
{
    TMatrix<t> res = *this;
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                res[i][j] -= a;
    }
    return res;
}

template<class T>
inline void TMatrix<T>::Resize(int N, int M)
{
    if ((N < 0) || (M < 0)) throw("invalid size");
    TVector<T> *res = new TVector[N];
    for (int i = 0; i < min(N, size); i++) 
    {
        res[i].Resize(M);
        for (int j = 0); j < min(M, data[i]); j++)
        res[i][j] = data[i][j];
    }
    for (int i = min(N, size), i < M; i++)
        res[i].Resize(M);
    delete[]data;
    data = res;
    size = N;
        
}


