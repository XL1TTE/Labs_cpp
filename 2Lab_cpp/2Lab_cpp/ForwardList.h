#pragma once
#include "stdexcept"

template <typename Type>
class ForwardList {

private:
    struct Node;
    Node* _head;
    Node* _end;

public:
    class Iterator {
    public:
        Iterator(Node* node) : _node(node) {}

        Type& item() const{
            return this->_node->_item;
        }

        bool operator==(const Iterator& ToCompare) const {
            return _node == ToCompare._node;
        }

        bool operator!=(const Iterator& ToCompare) const {
            return !(*this == ToCompare);
        }

        Type& operator*() const {
            if (_node) {
                return _node->_item;
            }
            return;
        }

        Iterator& operator++() {
            if (_node) {
                _node = _node->_next;
            }
            return *this;
        }
    private:
        Node* _node;
    };

public:

    ForwardList();
    ~ForwardList();


    void PushFront(const Type& item);
    void PushBack(const Type& item);
    void Insert(const Type& item, const size_t index);

    void RemoveLast();
    void RemoveFirst();

    Type GetFirst() const;
    Type GetLast() const;

    Type& GetByIndex(size_t index) const;

    Type& operator[](size_t index) const;

    Iterator begin() const;

    Iterator end() const;

    size_t Size() const;

private:
    bool is_empty() const{
        return (_head == nullptr);
    }

private:
    struct Node
    {
        Node() : _next(nullptr) {}

        Node(const Type& item) : _item(item), _next(nullptr) {}

        Type _item;
        Node* _next;
    };
};

template<typename Type>
ForwardList<Type>::ForwardList() : _head(nullptr), _end(nullptr) {}

template<typename Type>
ForwardList<Type>::~ForwardList() {
    while (!is_empty()) {
        RemoveFirst();
    }
}

template<typename Type>
void ForwardList<Type>::PushFront(const Type& item) {
    Node* node = new Node(item);
    if (is_empty()) {
        _head = _end = node;
        return;
    }
    node->_next = _head;
    _head = node;
}
template<typename Type>
void ForwardList<Type>::PushBack(const Type& item) {
    Node* node = new Node(item);
    if (is_empty()) {
        _head = node;
        _end = node;
        return;
    }
    _end->_next = node;
    _end = node;
}

template<typename Type>
void ForwardList<Type>::Insert(const Type& item, const size_t index) {
    if (index > Size() - 1 || index < 0) {
        throw std::out_of_range("Индекс выходит за пределы списка");
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
    current->_next = node;
}

template<typename Type>
void ForwardList<Type>::RemoveLast() {
    if (is_empty()) {
        return;
    }
    if (_head == _end) {
        delete _head;
        _head = _end = nullptr;
        return;
    }
    Node* current = _head;
    while (current->_next != _end) {
        current = current->_next;
    }
    delete _end;
    _end = current;
    _end->_next = nullptr;
}

template<typename Type>
void ForwardList<Type>::RemoveFirst() {
    if (is_empty()) {
        return;
    }
    Node* temp = _head;
    _head = _head->_next;
    delete temp;
    if (_head == nullptr) {
        _end = nullptr;
    }
}

template<typename Type>
Type ForwardList<Type>::GetFirst() const {
    if (is_empty()) {
        throw std::runtime_error("Список пуст");
    }
    return _head->_item;
}

template<typename Type>
Type ForwardList<Type>::GetLast() const {
    if (is_empty()) {
        throw std::runtime_error("Списко пуст");
    }
    return _end->_item;
}

template<typename Type>
Type& ForwardList<Type>::GetByIndex(size_t index) const {
    if (index > Size() - 1 || index < 0) {
        throw std::out_of_range("Индекс выходит за пределы списка");
    }
    Node* current = _head;
    for (size_t i = 0; i < index; ++i) {
        current = current->_next;
    }
    return current->_item;
}

template<typename Type>
Type& ForwardList<Type>::operator[](size_t index) const{
    return GetByIndex(index);
}



template<typename Type>
typename ForwardList<Type>::Iterator ForwardList<Type>::begin() const {
    return Iterator(_head);
}

template<typename Type>
typename ForwardList<Type>::Iterator ForwardList<Type>::end() const {
    return Iterator(nullptr);
}
template<typename Type>
size_t ForwardList<Type>::Size() const {
    size_t size = 0;
    for (Iterator current = begin(); current != end(); ++current) {
        ++size;
    }
    return size;
}


