/**
* @file:  BinarySearchTree.hpp
* @description: ikili arama ağacı tanımlar ve işlemler gerçekleştirmek için gerekli olan fonksiyonları içerir.
* @course: 2B
* @assignment:  02
* @date:  12.12.2024
* @author: Sedat Mert sedat.mert@ogr.sakaraya.edu.tr 
*/

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
using namespace std;

// Ağacın düğüm yapısı
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// İkili Arama Ağacı Sınıfı
class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree(); // Yapıcı
    ~BinarySearchTree(); // Yıkıcı

    void elemanEkle(char value); // Ağaç düğümü ekleme
    int toplamDegerHesapla(); // Ağacın toplam ASCII değerini hesaplar
    void aynalama(TreeNode* node);
    int ozelToplamHesapla(); // Özel toplam değeri hesaplar
    void agacCiz(TreeNode* node, int depth, int sabitBosluk = 4); // Ağaç çizim fonksiyonu

private:
    TreeNode* elemanEkleRecursive(TreeNode* node, char value);
    int toplamDegerHesaplaRecursive(TreeNode* node);
    int ozelToplamHesaplaRecursive(TreeNode* node);
    void agaciSil(TreeNode* node);
};

#endif
