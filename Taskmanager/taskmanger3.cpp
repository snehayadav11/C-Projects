# include <iostream>
using namespace std;
# include <vector>
# include <string>
# include <fstream>
# include <sstream>

struct Task {
    string description;
    bool completed;

    Task(const string& desc, bool comp = false) : description(desc), completed(comp) {}
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask(description);
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

    void saveTasksToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const Task& task : tasks) {
                outFile << task.completed << " " << task.description << endl;
            }
            outFile.close();
            cout << "Tasks saved to " << filename << endl;
        } else {
            cout << "Unable to open the file for saving tasks." << endl;
        }
    }

    void loadTasksFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            tasks.clear(); // Clear existing tasks

            string line;
            while (getline(inFile, line)) {
                istringstream iss(line);
                bool completed;
                string description;

                if (iss >> completed >> ws && getline(iss, description)) {
                    tasks.push_back(Task(description, completed));
                }
            }

            inFile.close();
            cout << "Tasks loaded from " << filename << endl;
        } else {
            cout << "Unable to open the file for loading tasks." << endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    // Load tasks from a file (if available)
    taskManager.loadTasksFromFile("tasks.txt");

    do {
        cout << "\nTask Manager Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. List Tasks" << endl;
        cout << "3. Mark Task as Complete" << endl;
        cout << "4. Save Tasks to File" << endl;
        cout << "5. Exit" << endl;
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
                taskManager.saveTasksToFile("tasks.txt");
                break;

            case 5:
                cout << "Exiting Task Manager." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}