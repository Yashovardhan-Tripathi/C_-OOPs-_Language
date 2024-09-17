#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Item
{
protected:
    string title;

    int publication_year;
    int available_copies;

public:
    string ISBN;
    Item(const string &title, const string &ISBN, int publication_year, int available_copies);
    void borrow_item();
    void return_item();
    virtual string to_string() const;
};

Item::Item(const string &title, const string &ISBN, int publication_year, int available_copies) : title(title), ISBN(ISBN), publication_year(publication_year), available_copies(available_copies) {}

void Item::borrow_item()
{
    if (available_copies > 0)
    {
        available_copies--;
    }
}

void Item::return_item()
{
    available_copies++;
}

string Item::to_string() const
{
    return "\nTitle: " + title + "\nISBN: " + ISBN + "\nYear: " + std::to_string(publication_year) + "\nAvailable Copies: " + std::to_string(available_copies);
}

class Book : public Item
{
private:
    string author;

public:
    Book(const string &title, const string &author, const string &ISBN, int publication_year, int available_copies);
    string to_string() const override;
};

Book::Book(const string &title, const string &author, const string &ISBN, int publication_year, int available_copies)
    : Item(title, ISBN, publication_year, available_copies), author(author) {}

string Book::to_string() const
{
    return "\nBook: " + Item::to_string() + "\nAuthor: " + author;
}

class Member : public Item
{
private:
    string name;
    vector<string> borrowed_books;

public:
    Member(const string &name, const std::string &member_id);
    void borrow_book(const string &book_ISBN);
    string to_string() const override;
};

Member::Member(const string &name, const string &member_id)
    : Item(name, member_id, 0, 0), name(name) {}

void Member::borrow_book(const string &book_ISBN)
{
    borrowed_books.push_back(book_ISBN);
}

string Member::to_string() const
{
    return "\nMember: " + Item::to_string() + "\nName: " + name;
}

class Library
{
private:
    string name;
    unordered_map<string, Item *> items;

public:
    Library(const string &name);
    void add_item(Item *item);
    void remove_item(const string &identifier);
    Item *find_item(const string &identifier);
    void list_items() const;
    string to_string() const;
};

Library::Library(const string &name) : name(name) {}

void Library::add_item(Item *item)
{
    items[item->ISBN] = item;
}

void Library::remove_item(const std::string &identifier)
{
    items.erase(identifier);
}

Item *Library::find_item(const string &identifier)
{
    if (items.find(identifier) != items.end())
    {
        return items[identifier];
    }
    return nullptr;
}

void Library::list_items() const
{
    for (const auto &pair : items)
    {
        cout << pair.second->to_string() << endl;
    }
}

int main()
{
    Library myLibrary("Awesome Library");
    // while (true)
    // {
    //     std::cout << "Library Management System\n";
    //     std::cout << "1. Add Book\n";
    //     std::cout << "2. Add Member\n";
    //     std::cout << "3. Borrow Book\n";
    //     std::cout << "4. Return Book\n";
    //     std::cout << "5. List Items\n";
    //     std::cout << "6. Exit\n";
    //     std::cout << "Enter your choice: ";

    //     int choice;
    //     std::cin >> choice;
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 1925, 5);
    //     switch (choice)
    //     {
    //     case 1:
    //     {

    Member member1("John Doe", "M123");
    //         break;
    //     }
    //     case 2:
    //     {
    myLibrary.add_item(&book1);
    //         break;
    //     }
    //     case 3:
    //     {
    myLibrary.add_item(&member1);
    //         break;
    //     }

    member1.borrow_book("9780743273565");

    myLibrary.list_items();

    return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// class Item
// {
// protected:
//     string title;
//     string author;
//     string ISBN;
//     int publication_year;
//     int available_copies;

// public:
//     Item(const string &title, const string &author,
//          const string &ISBN, int publication_year, int available_copies);
//     void borrow_item();
//     void return_item();
//     virtual string to_string() const;
// };

// Item::Item(const string &title, const string &author,
//            const string &ISBN, int publication_year, int available_copies)
//     : title(title), author(author), ISBN(ISBN),
//       publication_year(publication_year), available_copies(available_copies) {}

// void Item::borrow_item()
// {
//     if (available_copies > 0)
//     {
//         available_copies--;
//     }
// }

// void Item::return_item()
// {
//     available_copies++;
// }

// string Item::to_string() const
// {
//     return "Title: " + title + ", Author: " + author + ", ISBN: " + ISBN + ", Year: " + to_string(publication_year) + ", Available Copies: " + to_string(available_copies);
// }

// class Book : public Item
// {
// public:
//     Book(const string &title, const string &author,
//          const string &ISBN, int publication_year, int available_copies);
//     string to_string() const override;
// };

// Book::Book(const string &title, const string &author,
//            const string &ISBN, int publication_year, int available_copies)
//     : Item(title, author, ISBN, publication_year, available_copies) {}

// string Book::to_string() const
// {
//     return "Book " + Item::to_string();
// }

// class Member : public Item
// {
// private:
//     vector<string> borrowed_books;

// public:
//     Member(const string &name, const string &member_id);
//     void borrow_book(const string &book_ISBN);
//     string to_string() const override;
// };

// Member::Member(const string &name, const string &member_id)
//     : Item(name, "", member_id, 0, 0) {}

// void Member::borrow_book(const string &book_ISBN)
// {
//     borrowed_books.push_back(book_ISBN);
// }

// string Member::to_string() const
// {
//     return "Member " + Item::to_string();
// }

// class Library
// {
// private:
//     string name;
//     unordered_map<string, Item *> items;

// public:
//     Library(const string &name);
//     void add_item(Item *item);
//     void remove_item(const string &identifier);
//     Item *find_item(const string &identifier);
//     void list_items() const;
//     string to_string() const;
// };

// Library::Library(const string &name) : name(name) {}

// void Library::add_item(Item *item)
// {
//     // Implementation left to you
// }

// void Library::remove_item(const string &identifier)
// {
//     // Implementation left to you
// }

// Item *Library::find_item(const string &identifier)
// {
//     // Implementation left to you
//     return nullptr;
// }

// void Library::list_items() const
// {
//     // Implementation left to you
// }

// string Library::to_string() const
// {
//     return "Library Name: " + name;
// }

// int main()
// {
//     // Create instances of Book, Member, and Library
//     // Test their methods here

//     return 0;
// }
