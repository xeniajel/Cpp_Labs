#include <iostream>
#include <optional>
#include <array>
#include <cassert>

struct Book
{
    std::string_view title;
};

struct BookShelf
{
    std::array<std::optional<Book>, 5> slots; // слоты 0 и 3 хранят книги, а остальные пусты
};

bool shelve_book(BookShelf *shelf, size_t index, Book book)
{
    assert(shelf != nullptr);
    if (index >= shelf->slots.size())
    {
        return false;
    }
    if (shelf->slots[index].has_value())
    {
        return false;
    }

    shelf->slots[index] = book;
    return true;
}

bool take_book(BookShelf &shelf, size_t index)
{
    if (index >= shelf.slots.size())
    {
        return false;
    }
    if (!shelf.slots[index].has_value())
    {
        return false;
    }
    shelf.slots[index].reset();
    return true;
}

int empty_count(const BookShelf &shelf)
{
    int count{0};
    for (const auto &slot : shelf.slots)
    {
        if (!slot.has_value())
            count++;
    }
    return count;
}

int main()
{
    BookShelf bookshelf{};
    shelve_book(&bookshelf, 2, Book {.title = "Atlas"});
    take_book(bookshelf, 0);
    int freeSlots = empty_count(bookshelf);
}