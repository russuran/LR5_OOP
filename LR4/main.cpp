#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>

class Person {
protected:
    std::string name;
    std::string gender;
    int age;
    double height;

public:
    Person(const std::string& name, const std::string& gender, int age, double height) {
        if (age < 0) throw std::invalid_argument("Возраст не может быть отрицательным.");
        if (height < 0) throw std::invalid_argument("Рост не может быть отрицательным.");
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->height = height;
    }

    virtual void info() const = 0;
    virtual ~Person() = default;
};

class Preschooler : public Person {
public:
    Preschooler(const std::string& name, const std::string& gender, int age, double height)
        : Person(name, gender, age, height) {}

    void info() const override {
        std::cout << "Дошкольник. Имя: " << name << ", Пол: " << gender
            << ", Возраст: " << age << ", Рост: " << height << " см." << std::endl;
    }
};

class Schoolboy : public Person {
private:
    double salary;

public:
    Schoolboy(const std::string& name, const std::string& gender, int age, double height, double salary)
        : Person(name, gender, age, height) {
        if (salary < 0) throw std::invalid_argument("Зарплата не может быть отрицательной.");
        this->salary = salary;
    }

    void info() const override {
        std::cout << "Школьник. Имя: " << name << ", Пол: " << gender
            << ", Возраст: " << age << ", Рост: " << height << " см., Зарплата: " << salary << " руб." << std::endl;
    }
};

class Student : public Person {
private:
    double salary;

public:
    Student(const std::string& name, const std::string& gender, int age, double height, double salary)
        : Person(name, gender, age, height) {
        if (salary < 0) throw std::invalid_argument("Зарплата не может быть отрицательной.");
        this->salary = salary;
    }

    void info() const override {
        std::cout << "Студент. Имя: " << name << ", Пол: " << gender
            << ", Возраст: " << age << ", Рост: " << height << " см., Зарплата: " << salary << " руб." << std::endl;
    }
};

class Worker : public Person {
private:
    double salary;

public:
    Worker(const std::string& name, const std::string& gender, int age, double height, double salary)
        : Person(name, gender, age, height) {
        if (salary < 0) throw std::invalid_argument("Зарплата не может быть отрицательной.");
        this->salary = salary;
    }

    void info() const override {
        std::cout << "Работающий. Имя: " << name << ", Пол: " << gender
            << ", Возраст: " << age << ", Рост: " << height << " см., Зарплата: " << salary << " руб." << std::endl;
    }
};

template <typename T>
class Array {
private:
    std::vector<T*> elements;

public:
    void add(T* element) {
        elements.push_back(element);
    }

    T* operator[](size_t index) {
        if (index < elements.size()) {
            return elements[index];
        }
        return nullptr;
    }

    size_t size() const {
        return elements.size();
    }

    ~Array() {
        for (auto element : elements) {
            delete element;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU");
    Array<Person> people;

    try {
        people.add(new Preschooler("Аня", "Девочка", 5, 110));
        people.add(new Schoolboy("Саша", "Мальчик", 12, 150, 500));
        people.add(new Student("Иван", "Мальчик", 20, 175, 1500));
        people.add(new Worker("Мария", "Девушка", 30, 165, 3000));

        for (size_t i = 0; i < people.size(); ++i) {
            Person* person = people[i];
            if (person) {
                person->info();
            }
        }

        people.add(new Preschooler("Коля", "Мальчик", -3, 100)); //пример отлавливание невалид данных

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
