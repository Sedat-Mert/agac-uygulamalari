/**
* @file:  BinarySearchTree.cpp
* @description: ikili arama agaci tanimladim ve agaci cizdirme,aynalama yapma ve ASCII degerlerini hesaplama islemlerini yerine getirir.
* @course: 2B
* @assignment:  02
* @date:  13.12.2024
* @author: Sedat Mert sedat.mert@ogr.sakaraya.edu.tr 
*/

#include "BinarySearchTree.hpp"
#include "Queue.hpp"
#include <iostream>
#include <iomanip> // setw için

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    agaciSil(root);
}

// Ağaca eleman ekleme
void BinarySearchTree::elemanEkle(char value) {
    root = elemanEkleRecursive(root, value);
}



TreeNode* BinarySearchTree::elemanEkleRecursive(TreeNode* node, char value) {
    if (!node) return new TreeNode(value);
    if (value < node->data)
        node->left = elemanEkleRecursive(node->left, value);
    else
        node->right = elemanEkleRecursive(node->right, value);
    return node;
}

void BinarySearchTree::aynalama(TreeNode* node) {
    if (node == nullptr) return;

    // Sol ve sağ alt düğümleri değiştir
    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;

    // Rekürsif olarak alt düğümleri aynala
    aynalama(node->left);
    aynalama(node->right);
}


// ASCII toplam değeri hesaplama
int BinarySearchTree::toplamDegerHesapla() {
    return toplamDegerHesaplaRecursive(root);
}

int BinarySearchTree::toplamDegerHesaplaRecursive(TreeNode* node) {
    if (!node) return 0;
    return (int)node->data + toplamDegerHesaplaRecursive(node->left) +
           toplamDegerHesaplaRecursive(node->right);
}

// Özel toplam değeri hesaplama
int BinarySearchTree::ozelToplamHesapla() {
    return ozelToplamHesaplaRecursive(root);
}

int BinarySearchTree::ozelToplamHesaplaRecursive(TreeNode* node) {
    if (!node) return 0;
    int solToplam = 2 * ozelToplamHesaplaRecursive(node->left);
    int sagToplam = ozelToplamHesaplaRecursive(node->right);
    return (int)node->data + solToplam + sagToplam;
}
void BinarySearchTree::agacCiz(TreeNode* node, int depth, int sabitBosluk) {
    if (!root) {
        cout << "Ağaç boş!" << endl;
        return;
    }

    Queue queue;
    queue.ekle(root, 0);

    int currentLevel = 0;
    int spaceBetween = 40;

    while (!queue.bosMu()) {
        QueueNode* qNode = queue.cikar();

        // Eğer seviye değiştiyse, bir alt satıra geç
        if (qNode->seviye > currentLevel) {
            cout << endl;
            currentLevel = qNode->seviye;
            spaceBetween = max(spaceBetween / 2, 1);
        }

        // Düğüm değerini hizalayarak yazdır
        if (qNode->agacDugumu) {
            cout << setw(spaceBetween) << qNode->agacDugumu->data;
            queue.ekle(qNode->agacDugumu->left, currentLevel + 1);
            queue.ekle(qNode->agacDugumu->right, currentLevel + 1);
        } else {
            cout << setw(spaceBetween) << " ";
        }

        delete qNode; // Bellek temizleme
    }
    cout << endl;
}
// Ağacı silme
void BinarySearchTree::agaciSil(TreeNode* node) {
    if (!node) return;
    agaciSil(node->left);
    agaciSil(node->right);
    delete node;
}
