#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
using namespace std;

unordered_map<char, string> huffmanCode;
void descomprimir();
//Estructura del arbol
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

// Funcion para crear/obtener un nuevo nodo.
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Estructura para comparar la cual va a ser usada en la cola de
// de prioridad.
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

// Se recorre el arbol y se almacena la codificacion en un mapa.
void codificar(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	//Si el nodo es NULL, se retorna a la anterior posicion.
	if (root == nullptr)
		return;

	// Si se encuentra una hoja, (que es donde estan los caracteres)
	// se guarda el codigo asociado a ese caracter.
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}
	//LLamado recursivo a la derecha o a la izquierdaa
	//0 a la izquierda o 1 a la derecha.
	codificar(root->left, str + "0", huffmanCode);
	codificar(root->right, str + "1", huffmanCode);
}

string descomprimidoMensaje;
// Recorre todo el arbol y decodifica el mensaje.
void decodificar(Node* root, int &index, string str)
{
	
	
	//Retorna si encuentra null.
	if (root == nullptr) {
		return;
	}

	// Si se encuentra el nodo hoja, se imprime el 
	// caracter encontrado.
	if (!root->left && !root->right)
	{
		descomprimidoMensaje+= root->ch;
		return;
	}
	//Se suma 1 a index para recorrer el string que contien el mensjae
	//cofificado.
	index++;

	if (str[index] =='0')
		decodificar(root->left, index, str);
	else
		decodificar(root->right, index, str);
}

// Funcion para construir todo el arbol de Huffman, codificarlo
// y decodificarlo.
Node* root;

void construrirArbol(string text)
{
	//1. Se encuentra la frecuencia de cada caracter
	//y se almacenan en un mapa llamado freq.
	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}

	// Se crea una cola de prioridad con los 
	// nodos creados para la correcta implementacion del arbol de
	// Huffman.
	priority_queue<Node*, vector<Node*>, comp> pq;

	// Crear los nodos con la informacion guardada en el
	// mapa y anadirlo a la cola de prioridad.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// Hacer lo siguiente mientras el tamano de la cola de prioriodad 
	// sea diferente a 1.
	while (pq.size() != 1)
	{
		// El nodo izquierdo pasa a ser el nodo con la menor prioridad.
		Node *left = pq.top(); 
		//Se elimina de la cola el elemento que acaba de ser anadido.
		pq.pop();
		// El nodo derecho pasa a ser el nodo con la segunda menor prioridad.
		Node *right = pq.top();	
		//Se elimina de la cola el elemento que acaba de ser anadido.
		pq.pop();

		// Por ultimo, se encuentra la suma de las frecuencias del nodo
		// derecho y el izquierdo y se crea el nodo raiz con toda esa 
		// informacion.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// Al final de todo el proceso anterior, se crea un apuntador
	// al nodo que quedo dentro de la cola de prioridad.
	root = pq.top();

	// Se recorre el arbol de huffman para encontrar los codigos y 
	// se almacenan en un mapa llamado huffmanCode el cual esta
	// como variable global en la linea 8.

	codificar(root, "", huffmanCode);

    // Logica para imprimir la codificacion de huffman 
	// en un archivo de .txt y .bin
        ofstream codigosHuffman;
        ofstream codigosBin;
        
        codigosHuffman.open("codigosHuffman.txt");
        codigosBin.open("codigosBin.bin");
		string str;
		//Se guarda el el string codificado el cual esta almacenado en el mapa.
		str = "";
		for (char ch: text) {
			str += huffmanCode[ch];
		}
    //Para imprimir el codigo dentro de los archivos.
        codigosHuffman<< str;
        codigosBin<<str;

	// cout << "\ncodificard string is :\n" << str << '\n';

	// // Para decodificar el string.
	// int index = -1;
	// cout << "\ndecodificard string is: \n";
	// while (index < (int)str.size() - 2) {
	// 	decodificar(root, index, str);
	// }
}

void descomprimir(string data){
	ofstream descomprimido;
	descomprimido.open("descomprimido.txt");
	int indice = -1;
	while (indice < (int)data.size() - 2) {
		cout<<"Im decomppresing"<<endl;
	 	decodificar(root, indice, data);
	}
	descomprimido << descomprimidoMensaje;
}
// Huffman coding algorithm
// int main()
// {
// 	string text = "AABBCCDDD";

// 	buildHuffmanTree(text);

// 	return 0;
// }



// void crearTxtCodigos(string text){
    
//     ofstream codigosHuffman;

//     codigosHuffman.open("codigosHuffman.txt");
    
//     string str = "";
//     for (char ch: text) {
//         codigosHuffman<< str += huffmanCode[ch];
//     }
// }