/**
* @file:  Queue.hpp
* @description: kuyruk yapisi tanimlar.
* @course: 2B
* @assignment:  02
* @date:  18.12.2024
* @author: Sedat Mert sedat.mert@ogr.sakaraya.edu.tr 
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "BinarySearchTree.hpp"



// Kuyruk düğümü yapısı
struct QueueNode {
    TreeNode* agacDugumu; // Kuyrukta saklanan ağaç düğümü
    int seviye;           // Düğümün seviyesi
    QueueNode* sonraki;   // Sonraki kuyruk düğümüne işaretçi

    QueueNode(TreeNode* tDugum, int lvl);
};

// Kuyruk sınıfı
class Queue {
private:
    QueueNode* bas; // Kuyruğun başını işaret eder
    QueueNode* son; // Kuyruğun sonunu işaret eder

public:
    Queue();
    ~Queue();

    bool bosMu();
    void ekle(TreeNode* tDugum, int seviye);
    QueueNode* cikar();
};

#endif
