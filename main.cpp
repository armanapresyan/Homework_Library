#include <iostream>
#include "library.h"

int main(){
    int admin = 123;
    Library myLibrary(1, admin, "dfds", "sdfsdfds");
    myLibrary.addBook("sadsa", "dfdsfds", 0);
    myLibrary.addBook("sdfds", "dsfsd", 1);

    myLibrary.displayLibraryInfo();

    std::cout << "\nTotal Books: " << Library::getTotalBooks() << "\n";

    return 0;
}