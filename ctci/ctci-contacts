#include <iostream>
#include <string>
#include <sstream>

const int AB = 26;
using namespace std;

class node {
public:
	void addWord(string word);
	int getSize(char c);
	node* getChild(char c);
private:
	int sizes[AB] = { 0 };
	node* children[AB];
};

void node::addWord(string word) {
	if (word.size() == 0)
		return;
	this->sizes[word[0] - 'a']++;
	if (this->children[word[0] - 'a'] == NULL)
		this->children[word[0] - 'a'] = new node();
	this->children[word[0] - 'a']->addWord(word.substr(1));
}

node* node::getChild(char c) {
	return this->children[c - 'a'];
}

int node::getSize(char c) {
	return this->sizes[c - 'a'];
}

class myTrie {
public:
	myTrie() {
		root = new node();
	}
	void add(string word);
	int find(string word);
private:
	node* root;
};

void myTrie::add(string word) {
	this->root->addWord(word);
}

int myTrie::find(string word) {
	node* iter = this->root;
	int count;
	for (auto c : word) {
		if (iter == NULL)
			return 0;
		count = iter->getSize(c);
		iter = iter->getChild(c);
	}
	return count;
}

int main() {
	string add("add"), find("find");
	int n;
	cin >> n;
	string command, word;
	myTrie trie;
	for (int i = 0; i < n; i++) {
		getline(cin >> ws, command);
		istringstream iss(command);
		iss >> word;
		if (!word.compare(add)) {
			iss >> word;
			trie.add(word);
		} else if (!word.compare(find)) {
			iss >> word;
			cout << trie.find(word) << endl;
		}
	}
	return 0;
}
