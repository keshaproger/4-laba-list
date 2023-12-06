#include "TList.h"
#include "TListNode.h"
template<class T>
class TListIterator {
  protected:
	TList<T> list;
	TListNode<T>* cur;
  public:
	TListIterator();
	TListIterator(TList<T>& l, TListNode<T>* p);
	TListIterator(const TListIterator<T>& p);
	TListIterator(TListIterator<T>&& p);
	~TListIterator();
	TListIterator<T>& operator=(const TListIterator<T>& p);
	TListIterator<T>& operator=(TListIterator<T>&& p);
	TListIterator<T>& operator++();
	TListIterator<T>& operator--();
	bool operator==(const TListIterator<T>& p);
	bool operator!=(const TListIterator<T>& p);
	void PushAfter(T* a);
	void PushBefore(T* a);
};

template<class T>
TListIterator<T>::TListIterator<T>::TListIterator() {
  TList<T> q;
  list = q;
}

template<class T>
TListIterator<T>::TListIterator<T>::TListIterator(TList<T>& l, TListNode<T>* p) {
  list = l;
  cur = p;
}

template<class T>
TListIterator<T>::TListIterator<T>::TListIterator(const TListIterator<T>& p) {
  list = p.list;
  cur = p.cur;
}

template<class T>
TListIterator<T>::TListIterator<T>::TListIterator(TListIterator<T>&& p) {
  list = p.list;
  cur = p.cur;
}

template<class T>
TListIterator<T>::TListIterator<T>::~TListIterator() {
  cur = nullptr;
}

template<class T>
TListIterator<T>::TListIterator<T>& TListIterator<T>::operator=(const TListIterator<T>& p) {
  if (this == &p) return *this;
  list = p.list;
  cur = p.cur;
  return *this;
}

template<class T>
TListIterator<T>::TListIterator<T>& TListIterator<T>::operator=(TListIterator<T>&& p){
  cur = p.cur;
  list = p.list;
  p.cur = nullptr;
  return *this;
}

template<class T>
TListIterator<T>::TListIterator<T>& TListIterator<T>::operator++() {
  cur = cur->GetNext();
  if (cur == end)
	cur = nullptr;
  return *this;
}

template<class T>
TListIterator<T>::TListIterator<T>& TListIterator<T>::operator--() {
  cur = cur->GetPrev();
  if (cur == end)
	cur = begin;
  return *this;
}

template<class T>
TListIterator<T>::bool TListIterator<T>::operator==(const TListIterator<T>& p) {
  if ((p.cur == cur) && (p.list == list))
	return true;
  return false;
}

template<class T>
TListIterator<T>::bool TListIterator<T>::operator!=(const TListIterator<T>& p) {
  if ((p.cur != cur) && (p.list != list))
    return true;
  return false;
}

template<class T>
TListIterator<T>::void TListIterator<T>::PushAfter(T* a) {
  TListNode<T>* cat = new TListNode<T>(cur->GetNext(), cur, a); 
  cur->SetNext(cat);
  cur->GetNext()->SetPrev(cat);
}

template<class T>
TListIterator<T>::void TListIterator<T>::PushBefore(T* a) {
  TListNode<T>* cat = new TListNode<T>(cur->GetPrev(), cur, a);
  cur->SetPrev(cat);
  cur->GetPrev()->SetNext(cat);
}

