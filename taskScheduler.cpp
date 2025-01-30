#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Task {
public:
    string taskName;
    string dueDate;

    Task(string name, string date) : taskName(name), dueDate(date) {}

    void displayTask() {
        cout << "Task: " << taskName << " | Due Date: " << dueDate << endl;
    }
};

class TaskScheduler {
private:
    vector<Task> tasks;

public:
    void addTask(string name, string date) {
        tasks.push_back(Task(name, date));
        cout << "Task added successfully!" << endl;
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks available!" << endl;
            return;
        }
        for (auto& task : tasks) {
            task.displayTask();
        }
    }

    void deleteTask(string name) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->taskName == name) {
                tasks.erase(it);
                cout << "Task deleted successfully!" << endl;
                return;
            }
        }
        cout << "Task not found!" << endl;
    }

    void editTask(string oldName, string newName, string newDate) {
        for (auto& task : tasks) {
            if (task.taskName == oldName) {
                task.taskName = newName;
                task.dueDate = newDate;
                cout << "Task updated successfully!" << endl;
                return;
            }
        }
        cout << "Task not found!" << endl;
    }
};

int main() {
    TaskScheduler scheduler;
    int choice;
    string taskName, dueDate;

    do {
        cout << "\nTask Scheduler\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Edit Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter task name: ";
            getline(cin, taskName);
            cout << "Enter due date: ";
            getline(cin, dueDate);
            scheduler.addTask(taskName, dueDate);
            break;
        case 2:
            scheduler.displayTasks();
            break;
        case 3:
            cout << "Enter the task name to edit: ";
            getline(cin, taskName);
            cout << "Enter new task name: ";
            getline(cin, dueDate);
            cout << "Enter new due date: ";
            getline(cin, dueDate);
            scheduler.editTask(taskName, taskName, dueDate);
            break;
        case 4:
            cout << "Enter task name to delete: ";
            getline(cin, taskName);
            scheduler.deleteTask(taskName);
            break;
        case 5:
            cout << "Exiting Task Scheduler.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
