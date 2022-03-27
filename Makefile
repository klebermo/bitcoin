CURL = /Users/klebe/Downloads/curl-7.70.0-win64-mingw

all: bitcoin

bitcoin: sha256.o var_int.o block.o block_header.o block_template.o transaction.o transaction_factory.o merkle_node.o merkle_tree.o json_factory.o main.o
	g++ -std=c++11 -L${CURL}/lib -o release/bitcoin build/sha256.o build/json_factory.o build/var_int.o build/block.o build/block_header.o build/block_template.o build/transaction.o build/transaction_factory.o build/merkle_node.o build/merkle_tree.o build/main.o -lcurl

sha256.o: src/sha256.cpp
	g++ -std=c++11 -c src/sha256.cpp -o build/sha256.o

var_int.o: src/var_int.cpp
	g++ -std=c++11 -c src/var_int.cpp -o build/var_int.o

block.o: src/block.cpp
	g++ -std=c++11 -c src/block.cpp -o build/block.o

block_header.o: src/block_header.cpp
	g++ -std=c++11 -c src/block_header.cpp -o build/block_header.o

block_template.o: src/block_template.cpp
	g++ -std=c++11 -c src/block_template.cpp -o build/block_template.o

transaction.o: src/transaction.cpp
	g++ -std=c++11 -c src/transaction.cpp -o build/transaction.o

transaction_factory.o: src/transaction_factory.cpp
	g++ -std=c++11 -c src/transaction_factory.cpp -o build/transaction_factory.o

merkle_node.o: src/merkle_node.cpp
	g++ -std=c++11 -c src/merkle_node.cpp -o build/merkle_node.o

merkle_tree.o: src/merkle_tree.cpp
	g++ -std=c++11 -c src/merkle_tree.cpp -o build/merkle_tree.o

json_factory.o: src/json_factory.cpp
	g++ -std=c++11 -I${CURL}/include -c src/json_factory.cpp -o build/json_factory.o

main.o: src/main.cpp
	g++ -std=c++11 -c src/main.cpp -o build/main.o

clean:
	rm build/*.o
	rm release/bitcoin
