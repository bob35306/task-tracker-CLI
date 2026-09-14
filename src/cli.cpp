#include "../include/cli.h"

void cli::addTask(string desc){
    task temp;
    temp.id = getLastId("tasks.json") + 1;
    temp.description = desc;
    temp.status = "todo";
    temp.createdAt = getCurrentTime();
    temp.updatedAt = getCurrentTime();
    writeTaskToJson(temp, "tasks.json");
}

void cli::deleteTask(int id){
    try{
        vector<task> newTasks;
        tasks = parseJsonFile("tasks.json");
        bool check = 0;
        for(auto tasks : tasks){
            if(tasks.id != id) newTasks.push_back(tasks);
            else check = 1;
        }
        if(check == 0) throw IdNotFound();
        writeTasksToJson(newTasks);
    }
    catch(IdNotFound& ex){
        cout << ex.what() << endl;
    }
}

void cli::updateTask(int id, string desc){
    try{
        tasks = parseJsonFile("tasks.json");
        bool check = 0;
        for(auto& task : tasks){
            if(task.id == id){
                task.description = desc;
                check = 1;
            }
            break;
        }
        if(check == 0) throw IdNotFound();
        writeTasksToJson(tasks);
    }
    catch(IdNotFound& ex){
        cout << ex.what() << endl;
    }
    
}

void cli::markInProgress(int id){
    try{
        tasks = parseJsonFile("tasks.json");
        bool check = 0;
        for(auto& task : tasks){
            if(task.id == id){
                task.status = "in-progress";
                check = 1;
                break;
            }
        }
        if(check == 0) throw IdNotFound();
        writeTasksToJson(tasks);
    }
    catch(IdNotFound& ex){
        cout << ex.what() << endl;
    }
}

void cli::markDone(int id){
    try{
        tasks = parseJsonFile("tasks.json");
        bool check = 0;
        for(auto& task : tasks){
            if(task.id == id){
                task.status = "done";
                check = 1;
                break;
            }
        }
        if(check == 0) throw IdNotFound();
        writeTasksToJson(tasks);
    }
    catch(IdNotFound& ex){
        cout << ex.what() << endl;
    }
}

void cli::listTasks(string type){
    
    try{
        tasks = parseJsonFile("tasks.json");
        if(tasks.size() == 0) throw NoTaskFound();
        if(type == ""){
            for(auto task : tasks){
                cout << "--------------------------" << endl;
                cout << "ID: " << task.id << endl;
                cout << "Description: " << task.description << endl;
                cout << "Status: " << task.status << endl;
                cout << "CreatedAt: " << task.createdAt << endl;
                cout << "UpdatedAt: " << task.updatedAt << endl;
            }
        }
        else if(type == "done"){
            for(auto task : tasks){
                if(task.status == "done"){
                    cout << "--------------------------" << endl;
                    cout << "ID: " << task.id << endl;
                    cout << "Description: " << task.description << endl;
                    cout << "Status: " << task.status << endl;
                    cout << "CreatedAt: " << task.createdAt << endl;
                    cout << "UpdatedAt: " << task.updatedAt << endl;
                }
            }
        }
        else if(type == "todo"){
            for(auto task : tasks){
                if(task.status == "todo"){
                    cout << "--------------------------" << endl;
                    cout << "ID: " << task.id << endl;
                    cout << "Description: " << task.description << endl;
                    cout << "Status: " << task.status << endl;
                    cout << "CreatedAt: " << task.createdAt << endl;
                    cout << "UpdatedAt: " << task.updatedAt << endl;
                }
            }
        }
        else if(type == "in-progress"){
            for(auto task : tasks){
                if(task.status == "in-progress"){
                    cout << "--------------------------" << endl;
                    cout << "ID: " << task.id << endl;
                    cout << "Description: " << task.description << endl;
                    cout << "Status: " << task.status << endl;
                    cout << "CreatedAt: " << task.createdAt << endl;
                    cout << "UpdatedAt: " << task.updatedAt << endl;
                }
            }
        }
        else throw CommandNotFound();
    }
    catch(NoTaskFound& ex){
        cout << ex.what() << endl;
    }
    catch(CommandNotFound& ex){
        cout << ex.what() << endl;
    }
}