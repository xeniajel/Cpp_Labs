// Класс. В комнате 2 ряда по 3 парты.
// Каждая парта либо хранит ученика, либо пуста.
// Посчитайте пустые парты. Посадите новичка за первую пустую парту.
#include <optional>
#include <array>

struct Student
{
};

struct Desk
{
    std::optional<Student> seat;
};

struct Row
{
    std::array<Desk, 3> row;
};

struct ClassRoom
{
    std::array<Row, 2> room;
};

int count_empty_desks(ClassRoom &classroom)
{
    int emptyDesks{};
    for (const auto &row : classroom.room)
    {
        for (const auto &desk : row.row)
        {
            if (!desk.seat.has_value())
            {
                emptyDesks++;
            }
        }
    }
    return emptyDesks;
}

bool seat_newStudent(ClassRoom &classroom)
{
    for (size_t i{}; i < classroom.room.size(); i++)
    {
        for (size_t j{}; j < classroom.room[i].row.size(); j++)
        {
            if (!classroom.room[i].row[j].seat.has_value())
            {
                classroom.room[i].row[j].seat = Student{};
                return true;
            }
        }
    }
    return false;
}
