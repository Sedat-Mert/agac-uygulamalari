all: derle bagla calistir

# Derleme işlemi: Kaynak dosyaları nesne dosyalarına çevirir
derle:
	g++ -c -I "./include" ./src/BinarySearchTree.cpp -o ./lib/BinarySearchTree.o
	g++ -c -I "./include" ./src/LinkedList.cpp -o ./lib/LinkedList.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

# Bağlama işlemi: Nesne dosyalarını birleştirerek çalıştırılabilir dosya oluşturur
bagla: ./bin
	g++ ./lib/BinarySearchTree.o ./lib/LinkedList.o ./lib/Queue.o ./lib/main.o -o ./bin/program

# Çalıştırma işlemi: Programı başlatır
calistir:
	./bin/program