/**
* @file:  Main.cpp
* @description: Menu ve diger islemleri yapan fonksiyon govdeleri var.
* @course: 2B
* @assignment:  02
* @date: 18.12.2024
* @author: Sedat Mert sedat.mert@ogr.sakaraya.edu.tr 
*/
#include <iostream>
#include <fstream>
#include <iomanip> // setw için
#include "LinkedList.hpp"

using namespace std;

void printAllNodes(ListNode* head, ListNode* currentNode, int start, int count);
void printTreeStructure(BinarySearchTree* tree);

int main() {
    LinkedList liste;
    ifstream dosya("agaclar.txt");

    if (!dosya.is_open()) {
        cout << "Dosya açılamadı! 'agaclar.txt' dosyasını kontrol edin." << endl;
        return -1;
    }

    string satir;
    while (getline(dosya, satir)) {
        BinarySearchTree* agac = new BinarySearchTree();
        for (size_t i = 0; i < satir.size(); ++i) {
            char karakter = satir[i];
            agac->elemanEkle(karakter);
        }

        liste.ekle(agac);
    }
    dosya.close();

    ListNode* currentNode = liste.head; // İlk düğümle başla
    int totalNodes = 15;                // Toplam düğüm sayısı
    int currentSegmentStart = 0;        // Segmentin başlangıç düğüm indeksi
    int segmentSize = 10;               // İlk segmentin boyutu

    // İlk 10 düğümün bilgilerini göster
    cout << "Bağlı listedeki ilk 10 düğüm:\n" << endl;
    printAllNodes(liste.head, currentNode, currentSegmentStart, segmentSize);
    printTreeStructure(currentNode->tree); // İlk düğümün ağacını göster

    char secim;
    while (true) {
        cout << "\n--- Menü ---" << endl;
        cout << "1. Sağdaki düğüme git (D)" << endl;
        cout << "2. Soldaki düğüme git (A)" << endl;
        cout << "3. Düğüm ve ağacı sil (S)" << endl;
        cout << "4. Ağaç aynalama işlemi yap (W)" << endl;
        cout << "5. Çıkış (Q)" << endl;
        cout << "Seçiminizi yapın: ";
        cin >> secim;

        switch (secim) {
            case 'D': // Sağa git
            case 'd': {
                if (currentNode->next != nullptr) {
                    currentNode = currentNode->next;

                    // Segment değişimi: 9. düğümden 10. düğüme geçerken kalan düğümleri göster
                    if (currentSegmentStart == 0 && currentNode->next == 0) {
                        currentSegmentStart = 10;
                        segmentSize = 5; // Son segmentin boyutu
                        cout << "\nBağlı listedeki kalan 5 düğüm:\n" << endl;
                    }
                } else {
                    cout << "\nSon düğümde bulunuyorsunuz. Daha ileri gidemezsiniz." << endl;
                }
                printAllNodes(liste.head, currentNode, currentSegmentStart, segmentSize);
                printTreeStructure(currentNode->tree); // Yeni düğümün ağacını göster
                break;
            }
            case 'A': // Sola git
            case 'a': {
                if (currentNode != liste.head) {
                    ListNode* tempNode = liste.head;
                    while (tempNode->next != currentNode) {
                        tempNode = tempNode->next;
                    }
                    currentNode = tempNode;

                    // Segment değişimi: 10 düğümden önceki segment
                    if (currentSegmentStart == 10 && currentNode == liste.head->next->next->next->next->next->next->next->next) {
                        currentSegmentStart = 0;
                        segmentSize = 10;
                        cout << "\nBağlı listedeki ilk 10 düğüm:\n" << endl;
                    }
                } else {
                    cout << "\nİlk düğümde bulunuyorsunuz. Daha geri gidemezsiniz." << endl;
                }
                printAllNodes(liste.head, currentNode, currentSegmentStart, segmentSize);
                printTreeStructure(currentNode->tree); // Yeni düğümün ağacını göster
                break;
            }
            case 'S': // Düğüm ve ağacı sil
            case 's': {
                if (currentNode != nullptr) {
                    ListNode* tempNode = currentNode->next; // Sonraki düğüme geçiş için geçici değişken
                    liste.dugumSil(currentNode);           // Düğümü sil
                    currentNode = tempNode;               // Sonraki düğüme geç
                    cout << "\nSeçili düğüm silindi.\n" << endl;
                } else {
                    cout << "\nSilinecek bir düğüm bulunamadı!" << endl;
                }
                printAllNodes(liste.head, currentNode, currentSegmentStart, segmentSize);
                break;
            }
            case 'W': // Ağaç aynalama işlemi yap
            case 'w': {
                if (currentNode->tree != nullptr) {
                    currentNode->tree->aynalama(currentNode->tree->root);
                    cout << "\nSeçili düğümdeki ağaç aynalandı.\n" << endl;
                    printTreeStructure(currentNode->tree);
                } else {
                    cout << "\nAynalanacak bir ağaç bulunamadı!" << endl;
                }
                break;
            }
            case 'Q': // Çıkış
            case 'q':
                cout << "Program sonlandırılıyor." << endl;
                return 0;

            default:
                cout << "Geçersiz seçim! Lütfen tekrar deneyin." << endl;
        }
    }

    return 0;
}

// Tüm düğümleri yazdıran fonksiyon
void printAllNodes(ListNode* head, ListNode* currentNode, int start, int count) {
    ListNode* temp = head;

    // Segment başlangıcına git
    for (int i = 0; i < start && temp; i++) {
        temp = temp->next;
    }

    // Üst satır: Düğüm adresleri
    ListNode* iter = temp;
    for (int i = 0; i < count && iter; i++) {
        cout << setw(15) << iter;
        iter = iter->next;
    }
    cout << endl;

    // Çizgi: Düğüm adresleri ile toplam değerleri ayıran çizgi
    iter = temp;
    for (int i = 0; i < count && iter; i++) {
        cout << setw(15) << "------------";
        iter = iter->next;
    }
    cout << endl;

    // Orta satır: Ağacın toplam değerleri
    iter = temp;
    for (int i = 0; i < count && iter; i++) {
        cout << setw(15) << iter->tree->ozelToplamHesapla();
        iter = iter->next;
    }
    cout << endl;

    // Çizgi: Toplam değerler ile sonraki düğüm adreslerini ayıran çizgi
    iter = temp;
    for (int i = 0; i < count && iter; i++) {
        cout << setw(15) << "------------";
        iter = iter->next;
    }
    cout << endl;

    // Alt satır: Sonraki düğüm adresleri
    iter = temp;
    for (int i = 0; i < count && iter; i++) {
        if (iter->next) {
            cout << setw(15) << iter->next;
        } else {
            cout << setw(15) << "NULL"; // Son düğüm için NULL göster
        }
        iter = iter->next;
    }
    cout << endl;

    // Çizgi: Okun üstündeki çizgi
    iter = temp;
    for (int i = 0; i < count && iter; i++) {
        cout << setw(15) << "------------";
        iter = iter->next;
    }
    cout << endl;

    // Seçili düğümü vurgulamak için ok ekle
    iter = temp;
    for (int i = 0; i < count && iter; i++) {
        if (iter == currentNode) {
            cout << setw(15) << "   ↑↑↑↑↑↑↑↑↑↑↑↑";
        } else {
            cout << setw(15) << " ";
        }
        iter = iter->next;
    }
    cout << endl;
}


// Ağaç yapısını yazdıran fonksiyon
void printTreeStructure(BinarySearchTree* tree) {
    if (tree) {
        cout << "\nSeçili düğümün ağacı:\n";
        tree->agacCiz(tree->root, 0);
        cout << "-----------------------------------------" << endl;
    } else {
        cout << "Bu düğümde bir ağaç yok!" << endl;
    }
}
