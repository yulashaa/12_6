#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

typedef string Info;
struct Elem{
    Elem* link;
    Info info;
};

void Insert(Elem* &first, Elem* &last, Info value){
    Elem *tmp = new Elem;
    tmp->info = value;
    tmp->link = nullptr;
    if(last != nullptr){
        last->link = tmp;
    }
    last = tmp;
    if(first == nullptr){
        first = tmp;
    }
}

void Print(Elem* first) {
    Elem* p = first;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->link;
    }
    cout << endl;
}

void Inverse(Elem*& first) {
    Elem* current = first;
    Elem* prev = nullptr;
    Elem* next = nullptr;

    while (current != nullptr) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    first = prev;
}

void ReadFromFile(Elem* &first, Elem* &last, const string& fileName) {
    ifstream infile(fileName);
    string words[10];
    int count = 0;

    string line;
    while (getline(infile, line) && count < 5) {
        string word = line;
        words[count] = word;
        count++;
    }

    for (int i = 0; i < count; i++) {
        Insert(first, last, words[i]);
    }
}

int main(){
    Elem *first = nullptr,
         *last = nullptr;
    ReadFromFile(first, last, "/Users/uliazapletnuk/Desktop/^_^/АП/filesAp12.6/inputs.txt");
    cout << "Original queue: " << endl;
    Print(first);
    Inverse(first);
    cout << "Inversed queue: " << endl;
    Print(first);
}
