/////*****Implementation of Java-style Dynamic Array*****/////

# include <iostream>
# include <string>
template<class T>
class DynamicArray{
		int capacity, size;
		T * arr;
		void extend(int = 2);
	public:
		DynamicArray(int = 5);
		~DynamicArray();
		int length() const;
		T & operator[](int) const;
		void push_back(T, int = 1);
		void print() const;
};



// Creates an DynamicArray structure with intitial capacity c. By default
//	c is 5.
// For example, DynamicArray(10) initializes an DynamicArray with 10
//	0s.
template <class T>
DynamicArray<T>::DynamicArray(int c): size{0} {
	if (c <= 0) {
		c = 1;
	}
	capacity = c;
	arr = new T[c];
}

// destructor, deletes arr
template <class T>
DynamicArray<T>::~DynamicArray(){
	delete [] arr;
}

// accesses the element at index i
template <class T>
T & DynamicArray<T>::operator[](int i) const {
	return arr[i];
}

// gets the size of the array
template<class T>
int DynamicArray<T>::length() const {
	return size;
}

// prints the dynamic array
template <class T>
void DynamicArray<T>::print() const {
	for (int i = 0; i < size; i += 1)
		std::cout << arr[i] << "  ";
	std::cout << std::endl;
}

// pushes an element e to the back
template <class T>
void DynamicArray<T>::push_back(T e, int i){
	if (size+i > capacity)
		extend((size+i)/capacity + 1);
	while (--i != -1) {
		arr[size++] = e;
	}
}

// doubles the capacity
template <class T>
void DynamicArray<T>::extend(int mult) {
	capacity *= mult;
	T * next = new T[capacity];
	for (int i = 0; i < size; i += 1)
		next[i] = arr[i];
	delete [] arr;
	arr = next;
}
