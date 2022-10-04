#include <bits/stdc++.h> 
using namespace std; 

struct node {
    char currentCharacter;       
    bool isWord;      
    struct node *children[27]; 
    node() {
        isWord = false;
    }
}*trie; 

void init() {
    trie = new node();  
}

void insertWord(string word) {   
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) { 
        int character = word[i] - 'a';  
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
        }
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
    }
    currentNode->isWord = true;
}

bool searchWord(string word) {  
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    cout<<currentNode->currentCharacter<<endl;
    return currentNode->isWord;
}

void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe"<<endl;
    }
}

void deleteWord(string word) {
    if(searchWord(word)) {
        node *currentNode = trie;
        int tempDepth = 0;
        int deleteNode = 0;
        for (int i = 0; i< word.length(); i++) {
            int character = word[i] - 'a';
            if(currentNode->children[character]->isWord && word.length() != i+1) {
                deleteNode+= tempDepth;
            }
            currentNode = currentNode->children[character];
            tempDepth++;
        }
        currentNode->isWord = false;
        currentNode = trie;
        for (int i = 0; i< deleteNode; i++) {
            int character = word[i] - 'a';
            currentNode = currentNode->children[character];
        }
        currentNode = NULL;
        delete currentNode;
        cout << "Se elimino la palabra " << word << " correctamente." << endl;
    }
}

int main() {

    init();  
    string word = "casa";
    insertWord(word);
    isThereWord(word);
    word = "acampar";   
    insertWord(word);
    isThereWord("auto");
    isThereWord(word);
    return 0;
}