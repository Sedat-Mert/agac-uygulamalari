/**
* @file:  LinkedList.hpp
* @description: bagli liste yapisi tanimlar. herbir dugum ikili arama agaci barindirir. 
* @course: 2B
* @assignment:  02
* @date:  15.12.2024
* @author: Sedat Mert sedat.mert@ogr.sakaraya.edu.tr 
*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "BinarySearchTree.hpp"

// Bağlı liste düğümü
struct ListNode {
    BinarySearchTree* tree;
    ListNode* next;

    ListNode(BinarySearchTree* tree) : tree(tree), next(nullptr) {}
};

// Bağlı liste sınıfı
class LinkedList {
public:
    ListNode* head;

    LinkedList();
    ~LinkedList();

    void ekle(BinarySearchTree* tree); // Bağlı listeye ekleme
    void temizle(); // Listeyi temizle
    void dugumSil(ListNode* node);
};

#endif
