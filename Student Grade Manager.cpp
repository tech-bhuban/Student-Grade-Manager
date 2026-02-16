


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>

class Student {
public:
    std::string name;
    std::vector<int> grades;
    
    Student(std::string n) : name(n) {}
    
    void addGrade(int grade) {
        grades.push_back(grade);
    }
    
    double average() {
        if(grades.empty()) return 0.0;
        return std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
    }
    
    void display() {
        std::cout << std::left << std::setw(15) << name
                  << "Avg: " << std::fixed << std::setprecision(1) << average()
                  << " | Grades: ";
        for(int g : grades) std::cout << g << " ";
        std::cout << "\n";
    }
};

class GradeManager {
    std::vector<Student> students;
public:
    void addStudent(std::string name) {
        students.push_back(Student(name));
        std::cout << "Student added: " << name << "\n";
    }
    
    void addGrade(std::string name, int grade) {
        for(auto& student : students) {
            if(student.name == name) {
                student.addGrade(grade);
                std::cout << "Grade added for " << name << "\n";
                return;
            }
        }
        std::cout << "Student not found!\n";
    }
    
    void showAll() {
        std::cout << "\n=== Student Grades ===\n";
        for(auto& student : students) student.display();
    }
    
    void classAverage() {
        double total = 0;
        for(auto& student : students) total += student.average();
        std::cout << "Class average: " << total/students.size() << "\n";
    }
};

int main() {
    GradeManager mgr;
    mgr.addStudent("Alice");
    mgr.addStudent("Bob");
    mgr.addGrade("Alice", 85);
    mgr.addGrade("Alice", 92);
    mgr.addGrade("Bob", 78);
    mgr.showAll();
    mgr.classAverage();
    return 0;
}
