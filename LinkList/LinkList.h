#pragma once

template<typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template<typename T>
class LinkList
{
public:
    Node<T>* first;
    Node<T>** last;

    LinkList();
    ~LinkList();
    void push_back(T value);
    void push_front(T value);
    void insert(size_t idx, T value);
    void pop_back();
    void pop_front();
    void remove_at(size_t index);
    int size() const;
    bool empty() const;
    void clear();
    T front() const;
    T back() const;
    T& operator[](const size_t index);
    const T& operator[](const size_t index) const; 
};


