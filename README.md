# Задание

1. Реализуйте класс бинарного дерева поиска.

Описание бинарного дерева поиска можно найти в книге Кормена "Алгоритмы. Построение и анализ (3-е издание)", стр 319, глава 12.

```cpp
template <class T>
class BinarySearchTree
{
public:
    struct Node
    {
        Node* Parent;
        Node* Left;
        Node* Right;
        T Value;
    };

    BinarySearchTree();
    ~BinarySearchTree();
    
    void Add(const T&);
    Node* Find(const T&);
    void Remove(Node*);
};
```

2. Реализйте фунцию, которая проверяет явяется ли произвольное дерево бинарным деревом поиска.
```cpp
template <class T>
bool isBST(Node<T>* root);
```
