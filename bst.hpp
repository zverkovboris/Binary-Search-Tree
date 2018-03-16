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
    };

    BinarySearchTree()
    {
        Element = new Node;
        Element->Parent = nullptr;
        Element->Left = nullptr;
        Element->Right = nullptr;
        Element->Value = 0;
    }
    ~BinarySearchTree() = default;

    void Add(const T& element)
    {
        Node* copy = Element;
        while (copy->Value != 0)
        {
            if (element < copy->Value)
            {
                if (copy->Left == nullptr)
                {
                    Node* tmp = new Node;
                    tmp->Parent = copy;
                    copy->Left = tmp;
                    tmp->Value = element;
                    tmp->Left = 0;
                    tmp->Right = 0;
                    return;
                }
                copy = copy->Left;
            }
            else
            {
                if (copy->Right == nullptr)
                {
                    Node* tmp = new Node;
                    tmp->Parent = copy;
                    copy->Right = tmp;
                    tmp->Value = element;
                    tmp->Left = nullptr;
                    tmp->Right = nullptr;
                    return;
                }
                copy = copy->Right;
            }
        }
        Element->Value = element;
    }
    Node* Find(const T& element)
    {
        Node* copy = Element;
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
        if (tmp->Left == nullptr)
        {
            if (tmp->Parent->Left == tmp)
                tmp->Parent->Left = tmp->Right;
            else
                tmp->Parent->Right = tmp->Right;
            tmp->Right->Parent = tmp->Parent;
            return;
        }
        else if (tmp->Right = nullptr)
        {
            if (tmp->Parent->Left == tmp)
                tmp->Parent->Left = tmp->Left;
            else
                tmp->Parent->Right = tmp->Left;
            tmp->Left->Parent = tmp->Parent;
            return;
        }
        else
        {
            Node* n = tmp->Left;
            Node* copy = n;
            do
            {
                n = copy->Right;
                copy = copy->Right;
            } while (copy->Right != nullptr);
            tmp->Value = n->Value;
            n->Parent->Right = nullptr;
        }
    }
private:
    Node* Element;
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
    Node<T>* par = root->Parent;
    Node<T>* copy = root;
    while (par != nullptr)
    {
        if (par->Left == copy)
        {
            if (par->Value <= root->Value)
                return false;
        }
        else
        {
            if (par->Value > root->Value)
                return false;
        }
        copy = par;
        par = par->Parent;
    }
    bool left = false;
    bool right = false;
    if (root->Left != nullptr)
        left = isBST<T>(root->Left);
    else
        left = true;
    if (root->Right != nullptr)
        right = isBST<T>(root->Right);
    else
        right = true;
    return (left && right);
}
