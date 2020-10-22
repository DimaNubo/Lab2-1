#ifndef _TVECTOR_H_
#define _TVECTOR_H_

#include <iostream>

template <class ValType>
class TVector
{
protected:
  ValType *pVector;
  int Size;       // размер вектора
  int StartIndex; // индекс первого элемента вектора
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector& v);                // конструктор копировани¤
  ~TVector();
  int GetSize() { return Size; } // размер вектора
  int GetStartIndex() { return StartIndex; } // индекс первого элемента
  ValType& operator[](int pos);             // доступ
  bool operator==(const TVector& v) const;  // сравнение
  bool operator!=(const TVector& v) const;  // сравнение
  TVector& operator=(const TVector& v);     // присваивание

  // скал¤рные операции
  TVector  operator+(const ValType& val);   // прибавить скал¤р
  TVector  operator-(const ValType& val);   // вычесть скал¤р
  TVector  operator*(const ValType& val);   // умножить на скал¤р

  // векторные операции
  TVector  operator+(const TVector& v);     // сложение
  TVector  operator-(const TVector& v);     // вычитание
  ValType  operator*(const TVector& v);     // скалярное произведение

  // ввод-вывод
  friend std::istream& operator>>(std::istream& in, TVector& v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const TVector& v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};


template <typename ValType>
TVector<ValType>::TVector(int s, int si)
{
  Size = s;
    StartIndex = si;
    pVector = new ValType[Size];
    for (int i = StartIndex;i < Size; i++)
        pVector[i] = 0;
}

template <typename ValType>
TVector<ValType>::TVector(const TVector& v)
{
  Size = v.Size;
    StartIndex = v.StartIndex;
    pVector = new ValType[Size];
    for (int i = StartIndex; i < Size; i++)
        pVector[i] = v.pVector[i];
}

template<typename ValType>
TVector<ValType>::~TVector()
{
  if (pVector != nullptr)
    delete[] pVector;
}

template<typename ValType>
ValType& TVector<ValType>::operator[](int pos)
{
  if ((pos < StartIndex)||(pos >= Size)) 
  throw "Wrong position";
    return pVector[pos];
}

template <typename ValType>
bool TVector<ValType>::operator==(const TVector &v) const
{
  bool res = true;
	if (this == &v) 
  return res;
    if ((Size != v.Size)||(StartIndex != v.StartIndex)) 
    res = false;
    else for (int i = StartIndex; i < Size; i++)
        if (pVector[i] != v.pVector[i]) {
          res = false; 
          break;
          }
        return res;
}

template <typename ValType>
bool TVector<ValType>::operator!=(const TVector& v) const
{
  bool res = false;   
	if (this == &v) return res;
    if ((Size != v.Size)||(StartIndex != v.StartIndex)) 
    res=true;
    else for (int i = StartIndex;i < Size; i++)
        if (pVector[i] != v.pVector[i]) {
          res=true; 
          break;
          }
        return res;
}

template <typename ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
  if (this != &v)
  {
    if (Size != v.Size)
    {
      Size = v.Size;
      delete[] pVector;
      pVector = new ValType[Size];
    }
    StartIndex = v.StartIndex;
    for (int i = 0; i < Size; i++)
      pVector[i] = v.pVector[i];
  }
  return *this;
}

template <typename ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
  TVector sum(Size, StartIndex);
    for(int i = StartIndex; i < Size; i++)
        sum.pVector[i] = pVector[i] + val;
    return sum;

}

template <typename ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
   TVector sum(Size,StartIndex);
    for(int i = StartIndex; i < Size; i++)
        sum.pVector[i] = pVector[i] - val;
    return sum;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
  TVector comp(Size, StartIndex);
    for(int i = StartIndex; i < Size; i++)
        comp.pVector[i] = pVector[i] * val;
    return comp;


}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector &v)
{
  if ((Size != v.Size)||(StartIndex != v.StartIndex)) 
  throw "Wrong size";
    TVector sum(Size, StartIndex);
    for(int i = StartIndex; i < Size; i++)
        sum.pVector[i] = pVector[i] + v.pVector[i];
    return sum;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector &v)
{
  if ((Size != v.Size)||(StartIndex != v.StartIndex)) 
  throw "Wrong size";
    TVector sum(Size, StartIndex);
    for(int i = StartIndex; i < Size; i++)
        sum.pVector[i] = pVector[i] - v.pVector[i];
    return sum;
}

template<typename ValType>
ValType TVector<ValType>::operator*(const TVector &v)
{
  if ((Size != v.Size)||(StartIndex != v.StartIndex)) 
  throw "Wrong size";
    ValType comp = 0;
    for(int i = StartIndex; i < Size; i++)
        comp += pVector[i] * v.pVector[i];
    return comp;
}

#endif
