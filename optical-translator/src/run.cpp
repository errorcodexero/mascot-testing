#include <iostream>

using namespace std;

int main() {
	system("javac Importer.java");
	system("javac Parser.java");
	system("javac Translator.java");
	system("java Translator");
}
