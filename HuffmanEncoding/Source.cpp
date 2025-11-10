#include "HuffmanTree.h"

using namespace std;

int main()
{
	string input = "";

	cout << "Please enter a string to encode: " << endl;
	getline(cin, input);

	HuffmanTree example = HuffmanTree(input);

	cout << endl;
	example.printMapping();
	cout << endl;
	example.printEncoded();
	cout << endl;
	cout << "Original: " << example.decode() << endl;

	return 0;
}