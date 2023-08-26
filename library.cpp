#include "library.h"
#include <iostream>

Library::Library(int libraryID, int& adminID, const std::string& address, const std::string& contact) :
    libraryID(libraryID), administratorID(adminID), address(address), contact(contact) {}


Library::~Library() {
    for (Book* book : books) {
        delete book;
    }
}

int Library::getTotalBooks(){
    return Library::totalBooks;
}

std::vector<std::string> Library::Book::genres = {"Fiction", "Mystery", "Science Fiction"};

void Library::addBook(const std::string& title, const std::string& author, int genreIndex){
     Book* book = new Library::Book(title, author, genreIndex);
     books.push_back(book);
     ++totalBooks;
}

bool Library::Book::hasTitle(const std::string& bookTitle){
        return title == bookTitle;
    }

void Library::removeBook(const std::string& title){
   for (auto it = books.begin(); it != books.end(); ++it ) {
    if ((*it)->hasTitle(title)) {
        delete *it;
        it = books.erase(it);  
        --totalBooks;
    } 
}
}

void Library::displayLibraryInfo() const {
    std::cout << "Library ID: " << libraryID << "\n";
    std::cout << "Administrator ID: " << administratorID << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Contact: " << contact << "\n";
}


Library::Book::Book(const std::string& title, const std::string& author, int genreInd):
    title(title), author(author), genreInd(genreInd) {}

Library::Book::~Book(){}