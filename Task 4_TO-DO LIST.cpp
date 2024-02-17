#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

  
    Task(string desc) : description(desc), completed(false) {}
};

void addTask(vector<Task>& taskList) {
    string description;
    cout << "Enter the description of the task: ";
    cin.ignore(); 
    getline(cin, description);
    taskList.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& taskList) {
    cout << "Tasks in the to-do list:" << endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". ";
        cout << (taskList[i].completed ? "[X] " : "[ ] "); 
        cout << taskList[i].description << endl;
    }
}

void markCompleted(vector<Task>& taskList) {
    int index;
    cout << "Enter the index of the task you want to mark as completed: ";
    cin >> index;
    if (index < 1 || index > static_cast<int>(taskList.size())) {
        cout << "Invalid index! Please enter a valid index." << endl;
        return;
    }
    taskList[index - 1].completed = true;
    cout << "Task marked as completed!" << endl;
}

void removeTask(vector<Task>& taskList) {
    int index;
    cout << "Enter the index of the task you want to remove: ";
    cin >> index;
    if (index < 1 || index > static_cast<int>(taskList.size())) {
        cout << "Invalid index! Please enter a valid index." << endl;
        return;
    }
    taskList.erase(taskList.begin() + index - 1);
    cout << "Task removed successfully!" << endl;
}

int main() {
    vector<Task> taskList; 

    cout << "Welcome to the Unique To-Do List Manager!" << endl;

    int choice;
    do {
        cout << "\nMenu:\n"
            << "1. Add Task\n"
            << "2. View Tasks\n"
            << "3. Mark Task as Completed\n"
            << "4. Remove Task\n"
            << "5. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(taskList);
                break;
            case 2:
                viewTasks(taskList);
                break;
            case 3:
                markCompleted(taskList);
                break;
            case 4:
                removeTask(taskList);
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
