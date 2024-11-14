#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

void printBook(const Book& book) {
    cout << "Title: " << book.title << ", Autor: " << book.author
        << ",Publisher: " << book.publisher << ", Genre: " << book.genre << endl;
}

void editBook(Book& book) {
    cout << "Enter a new book title: ";
    getline(cin, book.title);
    cout << "Enter a new author: ";
    getline(cin, book.author);
    cout << "Enter a new publisher: ";
    getline(cin, book.publisher);
    cout << "Enter a new genre: ";
    getline(cin, book.genre);
    cout << "The book has been successfully edited!\n";
}

void printAllBooks(const vector<Book>& books) {
    for (const auto& book : books) {
        printBook(book);
    }
}

void searchByAuthor(const vector<Book>& books, const string& author) {
    bool found = false;
    for (const auto& book : books) {
        if (book.author == author) {
            printBook(book);
            found = true;
        }
    }
    if (!found) {
        cout << "No books by this author were found.\n";
    }
}

void searchByTitle(const vector<Book>& books, const string& title) {
    bool found = false;
    for (const auto& book : books) {
        if (book.title == title) {
            printBook(book);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No book with this title was found.\n";
    }
}

void sortByTitle(vector<Book>& books) {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
    cout << "Books are sorted by title.\n";
}

void sortByAuthor(vector<Book>& books) {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
    cout << "Books are sorted by author.\n";
}

void sortByPublisher(vector<Book>& books) {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
    cout << "Books are sorted by publisher.\n";
}

int main() {
    vector<Book> books = {
       {"Title1", "Author1", "Publisher1", "Genre1"},
       {"Title2", "Author2", "Publisher2", "Genre2"},
       {"Title3", "Author1", "Publisher3", "Genre3"},
       {"Title4", "Author3", "Publisher2", "Genre1"},
       {"Title5", "Author4", "Publisher1", "Genre2"},
       {"Title6", "Author5", "Publisher3", "Genre3"},
       {"Title7", "Author2", "Publisher1", "Genre1"},
       {"Title8", "Author3", "Publisher2", "Genre2"},
       {"Title9", "Author6", "Publisher3", "Genre3"},
       {"Title10", "Author4", "Publisher1", "Genre1"}
    };

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Edit a book\n";
        cout << "2. Printing of all books\n";
        cout << "3. Search books by author\n";
        cout << "4. Search for a book by title\n";
        cout << "5. Sort by name\n";
        cout << "6. Sort by author\n";
        cout << "7. Sort by publisher\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1: {
            int index;
            cout << "Enter the book index to edit (0-9): ";
            cin >> index;
            cin.ignore();
            if (index >= 0 && index < books.size()) {
                editBook(books[index]);
            }
            else {
                cout << "Invalid index!\n";
            }
            break;
        }
        case 2:
            printAllBooks(books);
            break;
        case 3: {
            string author;
            cout << "Enter the author's name: ";
            getline(cin, author);
            searchByAuthor(books, author);
            break;
        }
        case 4: {
            string title;
            cout << "Enter the title of the book: ";
            getline(cin, title);
            searchByTitle(books, title);
            break;
        }
        case 5:
            sortByTitle(books);
            break;
        case 6:
            sortByAuthor(books);
            break;
        case 7:
            sortByPublisher(books);
            break;
        case 0:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Wrong choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
