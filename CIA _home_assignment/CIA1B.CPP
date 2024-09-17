#include <bits/stdc++.h>
using namespace std;
class Book
{
private:
    string title;
    string author;
    string ISBN;
    int publication_year;
    int available_copies;
public:
    Book(const string &title, const string &author,
         const string &ISBN, int publication_year, int available_copies);
    void borrow_book();
    void return_book();
    string to_string() const;
};
Book::Book(const string &title, const string &author, const string &ISBN, int publication_year, int available_copies)
    : title(title), author(author), ISBN(ISBN), publication_year(publication_year), available_copies(available_copies)  {}
void Book::borrow_book()
{
    if (available_copies > 0)
    {
        available_copies--;
    }
}
void Book::return_book()
{
    available_copies++;
}
string Book::to_string() const
{
    return "Title: " + title + ", Author: " + author + ", ISBN: " + ISBN + ", Year: " + to_string(publication_year) + ", Available Copies: " + to_string(available_copies);
}
class Member {
private:
    string name;
    string member_id;
    vector<string> borrowed_books;
public:
    Member(const string& name, const string& member_id);
    void borrow_book(const string& book_ISBN);
    void return_book(const string& book_ISBN);
    string to_string() const;
};
Member::Member(const string& name, const string& member_id)
    : name(name), member_id(member_id) {}

void Member::borrow_book(const string& book_ISBN) {
    borrowed_books.push_back(book_ISBN);
}
void Member::return_book(const string& book_ISBN) {}
string Member::to_string() const {
    return "Name: " + name + ", Member ID: " + member_id;
}
class Library {
private:
    string name;
    unordered_map<string, Book> books;
    unordered_map<string, Member> members;
public:
    Library(const string& name);
    void add_book(const Book& book);
    void remove_book(const string& ISBN);
    void add_member(const Member& member);
    void remove_member(const string& member_id);
    Book* find_book(const string& ISBN);
    Member* find_member(const string& member_id);
    void list_books() const;
    void list_members() const;
    string to_string() const;
};
Library::Library(const string& name) : name(name) {}
void Library::add_book(const Book& book) {}
void Library::remove_book(const string& ISBN) {}
void Library::add_member(const Member& member) {}
void Library::remove_member(const &string member_id) {}
Book* Library::find_book(const string& ISBN) {    return nullptr;
}
Member* Library::find_member(const string& member_id) {
    return nullptr;
}
void Library::list_books() const {
}
void Library::list_members() const {
}
string Library::to_string() const {
    return "Library Name: " + name;
}
int main() {
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 1925, 5);
    Member member1("John Doe", "M123");
    Library myLibrary("Awesome Library");
    myLibrary.add_book(book1);
    myLibrary.add_member(member1);
    member1.borrow_book("9780743273565");
    std::cout << "Book Info:\n" << book1.to_string() << "\n\n";
    std::cout << "Member Info:\n" << member1.to_string() << "\n\n";
    std::cout << "All Books in the Library:\n";
    myLibrary.list_books();
    cout << "\n";
    std::cout << "All Members in the Library:\n";
    myLibrary.list_members();
    std::cout << "\n";
    return 0;}
    // #include <iostream>
// #include "Book.h" // Include the Book class header
// #include "Member.h" // Include the Member class header
// #include "Library.h" // Include the Library class header
    // Implementation left to you
// #endif // LIBRARY_H
   // Create a library
   // Borrow the book
   // Add the book to the library
// #endif // MEMBER_H
    // Add the member to the library
// #ifndef BOOK_H
// #define BOOK_H
    // Display book and member information
    // List all books in the library
// Book.cpp// #include "Book.h"
 // List all members in the library
    // Implementation left to you
// Library.h
// #ifndef LIBRARY_H
// #define LIBRARY_H

// #include <string>
// #include <unordered_map>
// #include "Book.h"
// #include "Member.h"
    // Create a member
        // Create a member// Remove the book from borrowed_books (if borrowed)// Implementation left to you
            // Implementation left to you
            // Library.cpp
//#include "Library.h"
// Member.cpp//#include "Member.h"
    // Implementation left to you
    // Implementation left to you
    // Implementation left to you
    // Implementation left to you
    // Implementation left to you


// Member.h// #ifndef MEMBER_H// #define MEMBER_H// #include <string>// #include <vector>