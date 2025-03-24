/**
* @file:  Queue.cpp
* @description: Agac cizdermek icin gerekli fonksiyonlar var 
* @course: 2B
* @assignment:  02
* @date: 18.12.2024
* @author: Sedat Mert sedat.mert@ogr.sakaraya.edu.tr 
*/
#include "Queue.hpp"
#include <cstddef>

// QueueNode yapıcı fonksiyonu
QueueNode::QueueNode(TreeNode* tDugum, int lvl) : agacDugumu(tDugum), seviye(lvl), sonraki(nullptr) {}

// Queue yapıcı fonksiyonu
Queue::Queue() : bas(nullptr), son(nullptr) {}

// Queue yıkıcı fonksiyonu
Queue::~Queue() {
    while (!bosMu()) {
        delete cikar();
    }
}

// Kuyruğun boş olup olmadığını kontrol eder
bool Queue::bosMu() {
    return bas == nullptr;
}

// Kuyruğa yeni bir düğüm ekler
void Queue::ekle(TreeNode* tDugum, int seviye) {
    QueueNode* yeniDugum = new QueueNode(tDugum, seviye);
    if (son) {
        son->sonraki = yeniDugum;
    }
    son = yeniDugum;
    if (!bas) {
        bas = son;
    }
}

// Kuyruktan bir düğüm çıkarır
QueueNode* Queue::cikar() {
    if (bosMu()) return nullptr;
    QueueNode* gecici = bas;
    bas = bas->sonraki;
    if (!bas) son = nullptr;
    return gecici;
}
