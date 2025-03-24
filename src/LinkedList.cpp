/**
* @file:  LinkedList.cpp
* @description: bagli listedeki dugumleri silme islemi barindirir.
* @course: 2B
* @assignment:  02
* @date:  17.12.2024
* @author: Sedat Mert sedat.mert@ogr.sakaraya.edu.tr 
*/

#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    temizle();
}
void LinkedList::temizle() {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp->tree; // Ağacı sil
        delete temp;       // Düğümü sil
    }
}


void LinkedList::ekle(BinarySearchTree* tree) {
    ListNode* yeniDugum = new ListNode(tree);
    if (!head) {
        head = yeniDugum;
    } else {
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = yeniDugum;
    }
}

void LinkedList::dugumSil(ListNode* node) {
    if (head == nullptr || node == nullptr) return;

    // Eğer düğüm listenin başıysa
    if (head == node) {
        head = head->next;
        delete node->tree; // Ağacı sil
        delete node;       // Düğümü sil
        return;
    }

    // Diğer durumlar için
    ListNode* prev = head;
    while (prev->next != nullptr && prev->next != node) {
        prev = prev->next;
    }

    if (prev->next == node) {
        prev->next = node->next;
        delete node->tree; // Ağacı sil
        delete node;       // Düğümü sil
    }
}

