#include "bst.hpp"

int main()
{
    BinarySearchTree<int> a;
    a.Add(12);
    a.Add(5);
    a.Add(2);
    a.Add(9);
    a.Add(18);
    a.Add(15);
    a.Add(13);
    a.Add(19);
    a.Add(17);
    a.Add(16);
    BinarySearchTree<int>::Node* tmp = a.Find(15);
    Node<int> tm;
    Node<int> t;
    Node<int> r;
    Node<int> e;
    tm.Value = 12;
    tm.Parent = nullptr;
    tm.Left = &r;
    tm.Right = &t;
    t.Value = 12;
    t.Parent = &tm;
    t.Left = nullptr;
    t.Right = nullptr;
    r.Value = 5;
    r.Parent = &tm;
    r.Left = &e;
    r.Right = nullptr;
    e.Value = 14;
    e.Parent = &r;
    e.Left = nullptr;
    e.Right = nullptr;
    Node<int>* ty = &tm;
    a.Remove(tmp);
    std::cout << isBST<int>(ty);
    return 0;
}
