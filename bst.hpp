#pragma once
#include <iostream>

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
        Node()
        {
            this->Parent = nullptr;
            this->Left = nullptr;
            this->Right = nullptr;
            this->Value = T();
        }
    };

    BinarySearchTree()
    {
        Root = new Node();
    }
    ~BinarySearchTree()
    {
        Delete(Root);
    };
    void Delete(Node* el)
    {
        if (el != nullptr)
        {
            Delete(el->Left);
            Delete(el->Right);
            delete el;
        }
        return;
    }
    Node* Insert(Node* parent, const T& value) const
    {
        Node* tmp = new Node();
        tmp->Parent = parent;
        tmp->Value = value;
        return tmp;
    }
    void Add(const T& element)
    {
        Node* copy = Root;
        while (copy->Value != T())
        {
            if (element < copy->Value)
            {
                if (copy->Left == nullptr)
                {
                    copy->Left = Insert(copy, element);
                    return;
                }
                copy = copy->Left;
            }
            else
            {
                if (copy->Right == nullptr)
                {
                    copy->Right = Insert(copy, element);
                    return;
                }
                copy = copy->Right;
            }
        }
        Root->Value = element;
    }
    Node* Find(const T& element)
    {
        Node* copy = Root;
        while (copy->Value != element)
        {
            if (copy->Value > element)
                copy = copy->Left;
            else
                copy = copy->Right;
        }
        return copy;
    }
    void Remove(Node* tmp)
    {
        Node* first = tmp->Left;
        Node* second = tmp->Right;
        for (size_t i = 0; i != 2; ++i)
        {
            if (first == nullptr)
            {
                if (tmp->Parent->Left == tmp)
                    tmp->Parent->Left = second;
                else
                    tmp->Parent->Right = second;
                second->Parent = tmp->Parent;
                return;
            }
            std::swap(first, second);
        }
        Node* copy = tmp->Right;
        while (copy->Left != nullptr)
        {
            copy = copy->Left;
        }
        tmp->Value = copy->Value;
        Node * del = copy->Parent->Left;
        copy->Parent->Left = nullptr;
        delete del;
    }
private:
    Node* Root;
};
template<class T>
struct Node
{
    Node* Parent;
    Node* Left;
    Node* Right;
    T Value;
};

template<class T>
bool isBST(Node<T>* root)
{
    if (root == nullptr)
    {
        return true;
    }
    Node<T>* copy = root;
    while (copy->Parent != nullptr)
    {
        if (copy->Parent->Left == copy)
        {
            if (copy->Parent->Value <= root->Value)
                return false;
        }
        else
        {
            if (copy->Parent->Value > root->Value)
                return false;
        }
        copy = copy->Parent;
    }
    return isBST<T>(root->Left) && isBST<T>(root->Right);
}
