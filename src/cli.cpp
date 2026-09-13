#include "cli.h"

void cli::addTask(string desc){
    task temp;
    temp.id = getLastId(fileName) + 1;
    temp.description = desc;
    temp.status = "todo";
    temp.createdAt = getCurrentTime();
    temp.updatedAt = getCurrentTime();
    writeTaskToJson(temp, fileName);
}

void cli::deleteTask(int id){
    vector<task> newTasks;
    tasks = parseJsonFile(fileName);
    for(int i = 0; i < tasks.size(); i++){
        if(tasks[i].id != id) newTasks.push_back(tasks[i]);
    }
    writeTasksToJson(newTasks);
}