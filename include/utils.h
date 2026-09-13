#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <string.h>
#include <ctime>
#include <chrono>
#include <vector>
#include <iomanip>
#include <fstream>
#include "cli.h"
using namespace std;


void writeTaskToJson(struct task task, const string& fileName);
void writeTasksToJson(vector<task> tasks);
vector<task> parseJsonFile(const string& fileName);
int getLastId(const string& fileName);
string getCurrentTime();

#endif