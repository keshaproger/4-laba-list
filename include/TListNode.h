template<class T>
class TListNode{
  protected:
	TListNode<T>* next;
	TListNode<T>* prev;
	T* data;
  public:
	TListNode();
	TListNode(TListNode<T>* n,TListNode<T>* p,T* d);
	TListNode(const TListNode<T>& p);
	TListNode(TListNode<T>&& p);
	~TListNode();
	TListNode<T>* GetNext();
	TListNode<T>* GetPrev();
	T* GetData();
	void SetNext(TListNode<T>* n);
	void SetPrev(TListNode<T>* p);
	void SetData(T* A);
	TListNode& operator=(const TListNode& p);
};

template<class T>
TListNode<T>::TListNode<T>::TListNode() {
  data = nullptr;
  next = nullptr;
  prev = nullptr;
}

template<class T>
TListNode<T>::TListNode<T>::TListNode(TListNode<T>* n, TListNode<T>* p, T* d) {
  data = d;
  prev = p;
  next = n;
}

template<class T>
TListNode<T>::TListNode<T>::TListNode(const TListNode<T>& p) {
  next = p.next;
  data = p.data;
  prev = p.prev;
}

template<class T>
TListNode<T>::TListNode<T>::TListNode(TListNode<T>&& p) {
  next = p.next;
  data = p.data;
  prev = p.prev;
  p.next = nullptr;
  p.prev = nullptr;
  delete[] p.data;
}

template<class T>
TListNode<T>::TListNode<T>::~TListNode() {
  next = nullptr;
  prev = nullptr;
  delete[]data;
}

template<class T>
TListNode<T>* TListNode<T>* TListNode<T>::GetNext() {
  return next;
}

template<class T>
TListNode<T>* TListNode<T>* TListNode<T>::GetPrev() {
  return prev;
}

template<class T>
T* TListNode<T>::GetData() {
  return data;
}

void SetNext(TListNode<T>* n) {
  next = n;
}

template<class T>
void SetPrev(TListNode<T>* p) {
  prev = p;
}

template<class T>
void TListNode<T>::SetData(T* p) {
  data = p;
}

template<class T>
TListNode<T>* TListNode<T>& TListNode<T>::operator=(const TListNode& p) {
  prev = p.prev;
  next = p.prev;
  data = p.data;
  return*this;
}
