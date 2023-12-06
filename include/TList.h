#include "TListNode.h"
#include <iostream>

template<class T>
class TList {
  protected:
    TListNode<T>* begin;
	TListNode<T>* end;
	int count;	
  public:
	TList();
	TList(const TList<T>& p);
	TList(TList<T>&& p);
	~TList();
	void PushBegin(TListNode<T>* a);
	void PushEnd(TListNode<T>* a);
	void DeleteBegin();
	void DeleteEnd();
	int GetCount();
	TListNode<T>* GetBegin();
	TListNode<T>* GetEnd();
	TList<T>& operator=(const TList<T>& p);
};

template<class T>
TList<T>::TList<T>::TList(){
  begin = nullptr;
  end = nullptr;
  count = 0;
}

template <class T>
TList<T>::TList(const TList<T>& p) {
  count = p.count;
  if (p.begin == nullptr) {
    begin = nullptr;
    end = nullptr;
  }
  else
  {
    // Copy the first node
    begin = new TListNode<T>(*p.begin);
    TListNode<T>* par = begin;
    TListNode<T>* rap = p.begin->GetNext(); // Move to the next node in the source list

    // Copy the rest of the nodes
    while (rap != p.begin)
    {
      TListNode<T>* newNode = new TListNode<T>();
      newNode->SetPrev(par);
      newNode->SetData(new T(*rap->GetData()));
      par->SetNext(newNode);
      par = par->GetNext();
      rap = rap->GetNext();
    }

    // Set the end node
    end = par;
  }
}

template<class T>
TList<T>::TList<T>::TList(TList<T>&& p) {
  if ((data == p.data) && (p.end == end) && (count == p.count))
	data = p.data;
  begin = p.begin;
  end = p.end;
  count - p.count;
  p.begin = nullptr;
  p.end = nullptr;
  count = 0;
}

template<class T>
TList<T>::void TList<T>::PushBegin(TListNode<T>* c) {
  c = new TListNode<T>((TListNode<T>*)begin, (TListNode<T>*)end, (T*)c);
  begin = c;
}

template<class T>
TList<T>::TList<T>::~TList() {
  begin = nullptr;
  end = nullptr;
  count = 0;
}

template<class T>
TList<T>::void TList<T>::PushEnd(TListNode<T>* c) {
  c = new TListNode<T>((TListNode<T>*)begin, (TListNode<T>*)end, (T*)c);
  end = a;
}

template<class T>
TList<T>::void TList<T>::DeleteBegin() {
  TListNode<T>* a = begin;
  end->SetNext(begin->GetNext());
  begin = begin->GetNext();
  begin->SetPrev(end);
  delete a;
}

template<class T>
TList<T>::void TList<T>::DeleteEnd() {
	TListNode<T>* a = end;
	begin->SetPrev(end->GetPrev());
	end = end->GetPrev();
	end->SetNext(begin);
	delete a;
}

template<class T>
int TList<T>::TList<T>::GetCount() {
	return count;
}

template<class T>
TList<T>::TListNode<T>* TList<T>::GetBegin() {
	return begin;
}

template<class T>
TList<T>::TListNode<T>* TList<T>::GetEnd() {
	return end;
}

template<class T>
TList<T>::TList<T>& TList<T>::operator=(const TList<T>& p) {
	return TList<T>::TList(p);
}

