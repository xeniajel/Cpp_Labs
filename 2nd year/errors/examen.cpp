
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

struct Student
{
    std::array<int, 5> completedSubjects{};
    int completedCount{};
    bool isRegistered{};
};

struct Exam
{
    int id{};
    std::array<int, 3> requiredSubjects{};
    int requiredCount{};
    int availableSeats{};
};

enum class ExamError
{
    None,
    MissingSubject,
    NoSeats,
    AlreadyRegistered
};

void registerStudent(Student &student, Exam &exam,
                     std::vector<ExamError> &errors)
{
    errors.clear();

    if (student.isRegistered)
    {
        errors.push_back(ExamError::AlreadyRegistered);
    }

    for (size_t i{}; i < exam.requiredCount; i++)
    {
        bool completed{};

        for (size_t j{}; j < student.completedCount; j++)
        {
            if (exam.requiredSubjects[i] == student.completedSubjects[j])
            {
                completed = true;
                break;
            }
        }

        if (!completed)
        {
            errors.push_back(ExamError::MissingSubject);
        }
    }

    if (exam.availableSeats <= 0)
    {
        errors.push_back(ExamError::NoSeats);
    }

    if (errors.empty())
    {
        student.isRegistered = true;
        exam.availableSeats--;
    }
}

int main()
{
    Student student{
        std::array<int, 5>{101, 102, 103},
        3,
        false};

    Exam exam{
        10,
        std::array<int, 3>{101, 102, 104},
        3,
        2};

    std::vector<ExamError> errors;

    {
        registerStudent(student, exam, errors);

        assert(errors.size() == 1);
        assert(errors[0] == ExamError::MissingSubject);
        assert(student.isRegistered == false);
        assert(exam.availableSeats == 2);

        std::cout << "missing subject" << std::endl;
    }

    {
        student.completedSubjects[2] = 104;

        registerStudent(student, exam, errors);

        assert(errors.empty());
        assert(student.isRegistered == true);
        assert(exam.availableSeats == 1);

        std::cout << "registration successful" << std::endl;
    }
    {
        registerStudent(student, exam, errors);

        assert(errors.size() == 1);
        assert(errors[0] == ExamError::AlreadyRegistered);
        assert(exam.availableSeats == 1);

        std::cout << "already registered" << std::endl;
    }

    {
        Student anotherStudent{
            std::array<int, 5>{101, 102, 104},
            3,
            false};

        exam.availableSeats = 0;

        registerStudent(anotherStudent, exam, errors);

        assert(errors.size() == 1);
        assert(errors[0] == ExamError::NoSeats);
        assert(anotherStudent.isRegistered == false);
        assert(exam.availableSeats == 0);

        std::cout << "no seats available" << std::endl;
    }
}
