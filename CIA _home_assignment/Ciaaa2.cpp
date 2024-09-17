#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
using namespace std;

// Custom Exception Classes
class BookNotAvailableException : public runtime_error
{
public:
    BookNotAvailableException(const string &message) : runtime_error(message) {}
};

class BookNotBorrowedException : public runtime_error
{
public:
    BookNotBorrowedException(const string &message) : runtime_error(message) {}
};

class DuplicateBookException : public runtime_error
{
public:
    DuplicateBookException(const string &message) : runtime_error(message) {}
};

class DuplicateMemberException : public runtime_error
{
public:
    DuplicateMemberException(const string &message) : runtime_error(message) {}
};

// Book class
class Book
{
private:
    string title;
    string author;
    string ISBN;
    int publication_year;
    int available_copies;

public:
    // Constructor to initialize book attributes
    Book(string title, string author, string ISBN, int pub_year, int copies)
        : title(title), author(author), ISBN(ISBN), publication_year(pub_year), available_copies(copies) {}

    // Getter methods
    string get_title() const { return title; }
    string get_author() const { return author; }
    string get_ISBN() const { return ISBN; }
    int get_available_copies() const { return available_copies; }

    // Setter method (if needed)
    void set_available_copies(int copies) { available_copies = copies; }

    // Borrow a book (decrease available copies if possible)
    bool borrow_book()
    {
        if (available_copies > 0)
        {
            available_copies--;
            return true;
        }
        else
        {
            throw BookNotAvailableException("No available copies of " + title);
        }
    }

    // Return a book (increase available copies)
    void return_book()
    {
        available_copies++;
    }

    // Return a string representation of the book
    string to_string() const
    {
        return "Title: " + title + "\nAuthor: " + author + "\nISBN: " + ISBN +
               "\nPublication Year: " + std::to_string(publication_year) + "\nAvailable Copies: " + std::to_string(available_copies);
    }
};

// Member class
class Member
{
private:
    string name;
    int member_id;
    vector<Book *> borrowed_books; // List of borrowed books (pointers to Book objects)

public:
    // Constructor to initialize member attributes
    Member(string name, int member_id) : name(name), member_id(member_id) {}

    // Getter methods
    string get_name() const { return name; }
    int get_member_id() const { return member_id; }

    // Borrow a book (add to borrowed_books list if available)
    void borrow_book(Book *book)
    {
        if (book->borrow_book())
        {
            borrowed_books.push_back(book);
            cout << name << " borrowed " << book->get_title() << "\n";
        }
    }

    // Return a book (remove from borrowed_books list)
    void return_book(Book *book)
    {
        for (size_t i = 0; i < borrowed_books.size(); i++)
        {
            if (borrowed_books[i]->get_ISBN() == book->get_ISBN())
            {
                borrowed_books[i]->return_book();
                borrowed_books.erase(borrowed_books.begin() + i);
                cout << name << " returned " << book->get_title() << "\n";
                return;
            }
        }
        throw BookNotBorrowedException("The book " + book->get_title() + " was not borrowed by " + name);
    }

    // Return a string representation of the member
    string to_string() const
    {
        return "Name: " + name + "\nMember ID: " + std::to_string(member_id) + "\nBooks Borrowed: " + std::to_string(borrowed_books.size());
    }
};

// Library class
class Library
{
private:
    string name;
    unordered_map<string, Book *> books;  // Map of ISBN to Book object pointers
    unordered_map<int, Member *> members; // Map of member ID to Member object pointers

public:
    // Constructor to initialize library name
    Library(string name) : name(name) {}

    // Add a book to the library
    void add_book(Book *book)
    {
        if (books.find(book->get_ISBN()) != books.end())
        {
            throw DuplicateBookException("Book with ISBN: " + book->get_ISBN() + " already exists.");
        }
        books[book->get_ISBN()] = book;
        cout << "Added book: " << book->to_string() << " to the library.\n";
    }

    // Remove a book by its ISBN
    void remove_book(const string &ISBN)
    {
        if (books.erase(ISBN))
        {
            cout << "Removed book with ISBN: " << ISBN << " from the library.\n";
        }
        else
        {
            cout << "Book with ISBN: " << ISBN << " not found in the library.\n";
        }
    }

    // Add a member to the library
    void add_member(Member *member)
    {
        if (members.find(member->get_member_id()) != members.end())
        {
            throw DuplicateMemberException("Member with ID: " + std::to_string(member->get_member_id()) + " already exists.");
        }
        members[member->get_member_id()] = member;
        cout << "Added member: " << member->to_string() << " to the library.\n";
    }

    // Remove a member by their ID
    void remove_member(int member_id)
    {
        if (members.erase(member_id))
        {
            cout << "Removed member with ID: " << member_id << " from the library.\n";
        }
        else
        {
            cout << "Member with ID: " << member_id << " not found in the library.\n";
        }
    }

    // Find a book by its ISBN
    Book *find_book(const string &ISBN) const
    {
        auto it = books.find(ISBN);
        if (it != books.end())
        {
            return it->second;
        }
        else
        {
            cout << "Book with ISBN: " << ISBN << " not found.\n";
            return nullptr;
        }
    }

    // Find a member by their ID
    Member *find_member(int member_id) const
    {
        auto it = members.find(member_id);
        if (it != members.end())
        {
            return it->second;
        }
        else
        {
            cout << "Member with ID: " << member_id << " not found.\n";
            return nullptr;
        }
    }

    // List all books in the library
    void list_books() const
    {
        cout << "Books in the library:\n";
        for (const auto &pair : books)
        {
            cout << pair.second->to_string() << "\n";
        }
    }

    // List all members in the library
    void list_members() const
    {
        cout << "Members in the library:\n";
        for (const auto &pair : members)
        {
            cout << pair.second->to_string() << "\n";
        }
    }

    // Return a string representation of the library
    string to_string() const
    {
        return "Library Name: " + name + "\nTotal Books: " + std::to_string(books.size()) + "\nTotal Members: " + std::to_string(members.size());
    }
};

// Text-based interface to interact with the system
void library_menu(Library &library)
{
    int choice;
    do
    {
        cout << "\n----- Library Menu -----\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Add Member\n";
        cout << "4. Remove Member\n";
        cout << "5. Borrow Book\n";
        cout << "6. Return Book\n";
        cout << "7. List All Books\n";
        cout << "8. List All Members\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string title, author, ISBN;
        int pub_year, copies, member_id;
        Book *book;
        Member *member;

        switch (choice)
        {
        case 1:
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            cin >> ISBN;
            cout << "Enter publication year: ";
            cin >> pub_year;
            cout << "Enter number of copies: ";
            cin >> copies;
            try
            {
                book = new Book(title, author, ISBN, pub_year, copies);
                library.add_book(book);
            }
            catch (const DuplicateBookException &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 2:
            cout << "Enter ISBN of the book to remove: ";
            cin >> ISBN;
            library.remove_book(ISBN);
            break;

        case 3:
            cout << "Enter member name: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter member ID: ";
            cin >> member_id;
            try
            {
                member = new Member(title, member_id);
                library.add_member(member);
            }
            catch (const DuplicateMemberException &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 4:
            cout << "Enter member ID to remove: ";
            cin >> member_id;
            library.remove_member(member_id);
            break;

        case 5:
            cout << "Enter member ID: ";
            cin >> member_id;
            member = library.find_member(member_id);
            if (member)
            {
                cout << "Enter ISBN of the book to borrow: ";
                cin >> ISBN;
                book = library.find_book(ISBN);
                if (book)
                {
                    try
                    {
                        member->borrow_book(book);
                    }
                    catch (const BookNotAvailableException &e)
                    {
                        cout << e.what() << endl;
                    }
                }
            }
            break;

        case 6:
            cout << "Enter member ID: ";
            cin >> member_id;
            member = library.find_member(member_id);
            if (member)
            {
                cout << "Enter ISBN of the book to return: ";
                cin >> ISBN;
                book = library.find_book(ISBN);
                if (book)
                {
                    try
                    {
                        member->return_book(book);
                    }
                    catch (const BookNotBorrowedException &e)
                    {
                        cout << e.what() << endl;
                    }
                }
            }
            break;

        case 7:
            library.list_books();
            break;

        case 8:
            library.list_members();
            break;

        case 9:
            cout << "Exiting the library system...\n";
            break;

        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 9);
}

// Main function to run the library system
int main()
{
    Library library("City Library");

    // Sample books and members for testing
    try
    {
        Book *book1 = new Book("The C++ Programming Language", "Bjarne Stroustrup", "12345", 2013, 5);
        Book *book2 = new Book("Effective C++", "Scott Meyers", "67890", 2005, 2);
        Member *member1 = new Member("Alice", 1);
        Member *member2 = new Member("Bob", 2);

        library.add_book(book1);
        library.add_book(book2);
        library.add_member(member1);
        library.add_member(member2);
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    // Start the text-based interface
    library_menu(library);

    return 0;
}
