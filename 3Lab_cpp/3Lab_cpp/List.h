#pragma once
#include "stdexcept"

template<typename Type>
class List
{
private:
    struct Node;
    Node* _head; 
    Node* _end;


public:
    class Iterator{
        public:
            Iterator(Node* node) : _node(node){}

            bool operator==(const Iterator& other) const{
                return _node == other._node;
            }

            bool operator!=(const Iterator& other) const{
                return !(*this == other);
            }

            Type& operator*() const{
                if(_node){
                    return _node->_item;
                }
                throw std::out_of_range("Iterator is out of bounds");
            } 
            Iterator& operator++(){
                if(_node){
                    _node = _node->_next;
                }
                return *this;
            }
            Iterator& operator--(){
                if(_node->_previous){
                    _node = _node->_previous;
                }
                return *this;
            }   
        private:
            Node* _node;
    };

private:
    struct Node{
        Node(): _next(nullptr), _previous(nullptr){}

        Node(const Type& item) : _item(item), _next(nullptr), _previous(nullptr) {}

        Type _item;
        Node* _next;
        Node* _previous;
    };

public:
    List();
    ~List();

    void PushBack(const Type& item);
    void PushFront(const Type& item);
    void Insert(const Type& item, size_t index);

    void RemoveLast();
    void RemoveFirst();
    void RemoveAfter(Node* node);

    Type& GetByIndex(int index) const;
    Type& operator[](int indext) const;

    Type GetLast() const;
    Type GetFirst() const;

    Iterator begin() const;

    Iterator end() const;

    size_t Size() const;

private:
    bool is_empty() const{
        return (_head == nullptr);
    }
};

template<typename Type>
List<Type>::List() : _head(nullptr), _end(nullptr){}

template<typename Type>
List<Type>::~List(){
    while(!is_empty()){
        RemoveFirst();
    }
}

template<typename Type>
void List<Type>::RemoveFirst(){
    if(is_empty()){
        return;
    }
    Node* temp = _head;
    _head = _head->_next;
    if (_head) {
        _head->_previous = nullptr;
    }
    else {
        _end = nullptr;
    }
    delete temp;
}

template<typename Type> 
void List<Type>::RemoveLast(){
    if(is_empty()){
        return;
    }
    if(_head == _end){
        delete _head;
        _head = _end = nullptr;
        return;
    }
    Node* current = _end->_previous;
    delete _end;
    _end = current;
    _end->_next = nullptr;
}

template<typename Type>
void List<Type>::PushFront(const Type& item) {
    Node* node = new Node(item);
    if (is_empty()) {
        _head = _end = node;
        return;
    }
    node->_next = _head;
    _head->_previous = node;
    _head = node;
}
template<typename Type>

void List<Type>::PushBack(const Type& item) {
    Node* node = new Node(item);
    if (is_empty()) {
        _head = node;
        _end = node;
        return;
    }
    _end->_next = node;
    node->_previous = _end;
    _end = node;
}

template<typename Type>
void List<Type>::Insert(const Type& item, const size_t index) {
    if (index > Size() - 1 || index < 0) {
        throw std::out_of_range("Индекс выходит за пределы списка");
    }
    if (is_empty()) {
        PushFront(item);
        return;
    }
    if (index == 0) {
        PushFront(item);
        return;
    }
    Node* node = new Node(item);
    Node* current = _head;
    for (int i = 0; i < index-1; i++) {
        current = current->_next;
    }
    node->_next = current->_next;
    if (current->_next) {
        current->_next->_previous = node;
    }
    else {
        _end = node;
    }
    node->_previous = current;
    current->_next = node;
}

template<typename Type>
Type List<Type>::GetFirst() const {
    if (is_empty()) {
        throw std::runtime_error("Список пуст");
    }
    return _head->_item;
}

template<typename Type>
Type List<Type>::GetLast() const {
    if (is_empty()) {
        throw std::runtime_error("Списко пуст");
    }
    return _end->_item;
}

template<typename Type>
Type& List<Type>::GetByIndex(int index) const {
    int fixed_size = Size() - 1;
    if (index > fixed_size || ((-index) - 1) > fixed_size) {
        throw std::out_of_range("Индекс выходит за пределы списка");
    }
    if(index < 0){
        index = -(index)-1;
        Node* current = _end;
        for (size_t i = 0; i < index; ++i) {
            current = current->_previous;
        }
        return current->_item;
    }
    Node* current = _head;
    for (size_t i = 0; i < index; ++i) {
        current = current->_next;
    }
    return current->_item;
}

template<typename Type>
Type& List<Type>::operator[](int index) const{
    return GetByIndex(index);
}

template<typename Type>
typename List<Type>::Iterator List<Type>::begin() const {
    return Iterator(_head);
}

template<typename Type>
typename List<Type>::Iterator List<Type>::end() const {
    return Iterator(nullptr);
}
template<typename Type>
size_t List<Type>::Size() const {
    size_t size = 0;
    for (Iterator current = begin(); current != end(); ++current) {
        ++size;
    }
    return size;
}
