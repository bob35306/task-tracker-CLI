#ifndef CLI_H
#define CLI_H
#include <iostream>
#include <vector>
#include <string>
#include "utils.h"
using namespace std;

struct task{
    int id;
    string description;
    string status;
    string createdAt;
    string updatedAt;
};

const string fileName = "tasks.json";

class cli{
private:
    vector<task> tasks;
public:
    void addTask(string desc);
    void updateTask(int id, string desc);
    void deleteTask(int id);
    void markInProgess(int id);
    void markDone(int id);
    void listTasks(int type); // 1 : all, 2 : done, 3 : todo, 4 : in-progress
};

#endif
