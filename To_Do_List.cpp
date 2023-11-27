#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;

const int maxTasks = 10;

class Task {
public:
    string description;
    bool completed;
    Task() : completed(false) {}
};

class TodoList {
private:
    Task* tasks[maxTasks];
    int taskCount;

public:
    TodoList() : taskCount(0) {}

    void addTask(const string&);
    void viewTasks() const;
    void markTaskAsCompleted(int);
    void removeTask(int);
};

int main() {
    TodoList todoList;

    while (true) {
        cout << endl
             << "===== Todo List Menu =====" << endl
             << "1. Add Task" << endl
             << "2. View Tasks" << endl
             << "3. Mark Task as Completed" << endl
             << "4. Remove Task" << endl
             << "0. Exit" << endl
             << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1: {
            string description;
            cout << endl <<  "Enter task description: ";
            getline(cin, description);
            todoList.addTask(description);
            cout<<endl;
        } break;
        case 2:
        	cout<<endl;
            todoList.viewTasks();
            cout<<endl;
            break;
        case 3: {
            int taskId;
            cout << endl << "Enter task ID to mark as completed: ";
            cin >> taskId;
            todoList.markTaskAsCompleted(taskId);
            cout<<endl;
        } break;
        case 4: {
            int taskId;
            cout << endl << "Enter task ID to remove: ";
            cin >> taskId;
            todoList.removeTask(taskId);
            cout<<endl;
        } break;
        case 0:
            cout << endl << "Exiting the program. Goodbye!" << endl;
			getch();
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}

void TodoList::addTask(const string& description) {
    if (taskCount < maxTasks) {
        tasks[taskCount] = new Task(); // Allocate memory for the new task
        tasks[taskCount]->description = description;
        cout << "Task added successfully!\n";
        taskCount++;
    } else {
        cout << "Task list is full. Cannot add more tasks.\n";
    }
}

void TodoList::viewTasks() const {
    cout << "Tasks:" << endl
         << "-------------------------------------";
    for (int i = 0; i < taskCount; ++i) {
        cout << endl
             << "ID: " << i + 1 << endl
             << "Description: " << tasks[i]->description << endl
             << "Status: " <<(tasks[i]->completed ? "Completed" : "Pending") << endl;
    }
    cout << endl;
}

void TodoList::markTaskAsCompleted(int taskId) {
    if (taskId >= 1 && taskId <= taskCount) {
        tasks[taskId - 1]->completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task ID!" << endl;
    }
}

void TodoList::removeTask(int taskId) {
    if (taskId >= 1 && taskId <= taskCount) {
        delete tasks[taskId - 1]; // Free the memory allocated for the task
        for (int i = taskId - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task ID!" << endl;
    }
}
