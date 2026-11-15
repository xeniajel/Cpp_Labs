// Комнаты библиотеки.
// В библиотеке 2 комнаты по 3 слота.
// Каждый слот либо хранит книгу, либо пуст.
// Положите «Атлас» в первый пустой слот комнаты 1.
#include <array>
#include <optional>
#include <string_view>
#include <span>

struct Book
{
    std::string_view name;
};

struct Room
{
    std::array<std::optional<Book>, 3> slots;
};

struct Library
{
    std::array<Room, 2> rooms;
};

bool put_book(Library &library, Book book, size_t roomIndex)
{
    if (roomIndex >= library.rooms.size())
    {
        return false;
    }
    std::span<std::optional<Book>> books{library.rooms[roomIndex].slots};

    for (auto &slot : books)
    {
        if (slot.has_value())
        {
            continue;
        }
        slot = book;
        return true;
    }
    return false;
}

int main()
{
    Library library{};

    Book atlas{"Атлас"};

    bool result = put_book(library, atlas, 0);
}