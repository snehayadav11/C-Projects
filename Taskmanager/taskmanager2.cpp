# include <iostream>
using namespace std;
# include <vector>
# include <string>

struct Task {
    string description;
    bool completed;
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask;
        newTask.description = description;
        newTask.completed = false;
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void listTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }

    void markTaskComplete(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as complete: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    do {
        cout << "\nTask Manager Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. List Tasks" << endl;
        cout << "3. Mark Task as Complete" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    cin.ignore(); // Clear the input buffer
                    string description;
                    cout << "Enter task description: ";
                    getline(cin, description);
                    taskManager.addTask(description);
                }
                break;

            case 2:
                taskManager.listTasks();
                break;

            case 3:
                {
                    int index;
                    cout << "Enter task index to mark as complete: ";
                    cin >> index;
                    taskManager.markTaskComplete(index);
                }
                break;

            case 4:
                cout << "Exiting Task Manager." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}