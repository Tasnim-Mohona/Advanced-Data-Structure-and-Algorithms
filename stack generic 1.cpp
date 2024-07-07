#ifndef Stack_h
#define Stack_h
#include <iostream>

template <class T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* top;

public:
    // Constructors
    Stack() : top(nullptr){}                                                 // empty constructor
    Stack(Stack const& value);                                               // copy constructor
    Stack<T>(Stack<T>&& move) noexcept;                                      // move constuctor
    Stack<T>& operator=(Stack&& move) noexcept;                              // move assignment operator
    ~Stack();                                                                // destructor

    // Overload operators
    Stack& operator=(Stack const& rhs);
    friend std::ostream& operator<<(std::ostream& str, Stack<T> const& data) {
        data.show(str);
        return str;
    }

    // Member functions
    void swap(Stack& other) noexcept;
    bool isEmpty();
    int getSize();
    void push(const T& theData);
    void push(T&& theData);
    void pop();
    void show(std::ostream &str) const;
};

template <class T>
Stack<T>::Stack(Stack const& value) : top(nullptr) {
    for(Node* loop = value->data; loop != nullptr; loop = loop->next) {
        push(loop->data);
    }
}

template <class T>
Stack<T>::Stack(Stack<T>&& move) noexcept : top(nullptr) {
    move.swap(*this);
}

template <class T>
Stack<T>& Stack<T>::operator=(Stack<T> &&move) noexcept {
    move.swap(*this);
    return *this;
}

template <class T>
Stack<T>::~Stack() {
    while(top != nullptr) {
        pop();
    }
}

template <class T>
Stack<T>& Stack<T>::operator=(Stack const& rhs) {
    Stack copy(rhs);
    swap(copy);
    return *this;
}


template <class T>
void Stack<T>::swap(Stack<T> &other) noexcept {
    using std::swap;
    swap(top,other.top);
}

template <class T>
bool Stack<T>::isEmpty() {
    if(top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
int Stack<T>::getSize() {
    int size = 0;
    Node* current = top;
    while(current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

template <class T>
void Stack<T>::push(const T &theData) {
    Node* newNode = new Node;
    newNode->data = theData;
    newNode->next = nullptr;

    if(top != nullptr) {
        newNode->next = top;
    }
    top = newNode;
}

template <class T>
void Stack<T>::push(T&& theData) {
    Node* newNode = new Node;
    newNode->data = std::move(theData);
    newNode->next = nullptr;

    if(top != nullptr) {
        newNode->next = top;
    }
    top = newNode;
}

template <class T>
void Stack<T>::pop() {
    Node* temp;
    if(top == nullptr) {
        throw std::invalid_argument("The list is already empty, nothing to pop.");
    }
    temp = top;
    top = top->next;
    delete temp;
}

template <class T>
void Stack<T>::show(std::ostream &str) const {
    for(Node* loop = top; loop != nullptr; loop = loop->next) {
        str << loop->data << "\t";
    }
    str << "\n";
}


#endif /* Stack_h */
