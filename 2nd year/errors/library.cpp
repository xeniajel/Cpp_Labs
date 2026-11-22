#include <array>
#include <cassert>
#include <iostream>

struct Book
{
    int id{};
    bool isAvailable{true};
};

struct Reader
{
    std::array<int, 5> borrowedBooks{};
    int borrowedCount{};
};

struct Library
{
    std::array<Book, 3> books{};
};

enum class LibraryError
{
    None,
    BookNotFound,
    BookNotAvailable,
    ReaderBufferFull,
};

LibraryError giveBook(Library &library, int bookId, Reader &reader)
{
    Book *neededBook = nullptr;
    for (size_t i{}; i < library.books.size(); i++)
    {
        if (bookId == library.books[i].id)
        {
            neededBook = &library.books[i];
            break;
        }
    }
    if (neededBook == nullptr)
    {
        return LibraryError::BookNotFound;
    }

    if (!neededBook->isAvailable)
    {
        return LibraryError::BookNotAvailable;
    }

    if (reader.borrowedCount == reader.borrowedBooks.size())
    {
        return LibraryError::ReaderBufferFull;
    }

    neededBook->isAvailable = false;
    reader.borrowedBooks[reader.borrowedCount] = neededBook->id;
    reader.borrowedCount++;
    return LibraryError::None;
}

int main()
{
    Library library{
        std::array<Book, 3>{Book{223, false}, Book{245, true}, Book{000, true}}};
    Reader reader{};
    {
        LibraryError error = giveBook(library, 333, reader);
        assert(error == LibraryError::BookNotFound);
        assert(reader.borrowedCount == 0);

        assert(library.books[0].isAvailable == false);
        assert(library.books[1].isAvailable == true);
        assert(library.books[2].isAvailable == true);
        std::cout << "book not found" << std::endl;
    }
    {
        LibraryError error = giveBook(library, 223, reader);
        assert(error == LibraryError::BookNotAvailable);
        assert(reader.borrowedCount == 0);

        assert(library.books[0].isAvailable == false);
        assert(library.books[1].isAvailable == true);
        assert(library.books[2].isAvailable == true);
        std::cout << "book is not available" << std::endl;
    }
    {
        reader.borrowedCount = 5;
        LibraryError error = giveBook(library, 245, reader);
        assert(error == LibraryError::ReaderBufferFull);
        assert(reader.borrowedCount == 5);

        assert(library.books[0].isAvailable == false);
        assert(library.books[1].isAvailable == true);
        assert(library.books[2].isAvailable == true);
        std::cout << "reader's buffer is full" << std::endl;
    }
    {
        reader.borrowedCount = 0;
        LibraryError error = giveBook(library, 000, reader);
        assert(error == LibraryError::None);
        assert(reader.borrowedCount == 1);

        assert(library.books[0].isAvailable == false);
        assert(library.books[1].isAvailable == true);
        assert(library.books[2].isAvailable == false);
        std::cout << "the book is given" << std::endl;
    }
}