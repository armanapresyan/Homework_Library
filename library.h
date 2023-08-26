#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>

class Library{
public:
  static int getTotalBooks();
  
public:
  Library(int libraryID, int& adminID, const std::string& address, const std::string& contact);
  ~Library();

public:
  void displayLibraryInfo() const;
  void addBook(const std::string& title, const std::string& author, int genreIndex);
  void removeBook(const std::string& title);

private:
  static int totalBooks;
  const int libraryID;
  const std::string address;
  const std::string contact;
  int& administratorID;
  int genreIndex;

  class Book{
    public:
     static std::vector<std::string> genres;  
    
    public:
       bool hasTitle(const std::string& bookTitle);
    
    public:
     Book(const std::string& title, const std::string& author, int genreIndex);
    ~Book();

    private:
      std::string title;
      std::string author;
      int genreInd;
  };
  std::vector<Book*> books;
};


#endif //LIBRARY.H