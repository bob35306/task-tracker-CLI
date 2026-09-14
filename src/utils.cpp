#include "../include/utils.h"

//Writes a Task object to a JSON file.
void writeTaskToJson(task task, const string& fileName) {
    ifstream file(fileName);
    string jsonContent((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    size_t startPos = jsonContent.find_last_of('[') + 1;
    size_t endPos = jsonContent.find_last_of(']');

    string newTaskJson =
        "\n    {\n"
        "        \"id\": " + to_string(task.id) + ",\n"
        "        \"description\": \"" + task.description + "\",\n"
        "        \"status\": \"" + task.status + "\",\n"
        "        \"createdAt\": \"" + task.createdAt + "\",\n"
        "        \"updatedAt\": \"" + task.updatedAt + "\"\n"
        "    }\n";

    if (startPos != string::npos && endPos != string::npos) {
        jsonContent.insert(endPos, "," + newTaskJson);
    } else {
        jsonContent = "[" + newTaskJson + "]";
    }

    ofstream fileOut(fileName, ios::trunc);
    fileOut << jsonContent;
    fileOut.close();
}

void writeTasksToJson(vector<task> tasks){
    for(auto task : tasks){
        writeTaskToJson(task, "temp.json");
    }
    remove("tasks.json");
    rename("temp.json", fileName);
}

//Parses a JSON file and returns a vector of Task objects.
vector<task> parseJsonFile(const string& fileName) {
    vector<task> tasks;

    ifstream file(fileName);
    string jsonContent((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    size_t startPos = jsonContent.find('[') + 1;
    size_t endPos = jsonContent.find_last_of(']');

    if (startPos != string::npos && endPos != string::npos) {
        string tasksJson = jsonContent.substr(startPos, endPos - startPos);

        size_t taskStartPos = 0;
        size_t taskEndPos = tasksJson.find('}');

        while (taskEndPos != string::npos) {
            string taskJson = tasksJson.substr(taskStartPos, taskEndPos - taskStartPos + 1);

            task task;
            size_t idStartPos = taskJson.find("\"id\": ") + 6;
            size_t idEndPos = taskJson.find(',', idStartPos);
            task.id = stoi(taskJson.substr(idStartPos, idEndPos - idStartPos));

            size_t descStartPos = taskJson.find("\"description\": \"") + 16;
            size_t descEndPos = taskJson.find('\"', descStartPos);
            task.description = taskJson.substr(descStartPos, descEndPos - descStartPos);


            size_t statusStartPos = taskJson.find("\"status\": \"") + 11;
            size_t statusEndPos = taskJson.find('\"', statusStartPos);
            task.status = taskJson.substr(statusStartPos, statusEndPos - statusStartPos);

            size_t createdAtStartPos = taskJson.find("\"createdAt\": \"") + 14;
            size_t createdAtEndPos = taskJson.find('\"', createdAtStartPos);
            task.createdAt = taskJson.substr(createdAtStartPos, createdAtEndPos - createdAtStartPos);

            size_t updatedAtStartPos = taskJson.find("\"updatedAt\": \"") + 14;
            size_t updatedAtEndPos = taskJson.find('\"', updatedAtStartPos);
            task.updatedAt = taskJson.substr(updatedAtStartPos, updatedAtEndPos - updatedAtStartPos);

            tasks.push_back(task);

            taskStartPos = taskEndPos + 1;
            taskEndPos = tasksJson.find('}', taskStartPos);
        }
    }

    return tasks;
}

string getCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t nowTimeT = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&nowTimeT);

    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d %H:%M:%S");
    string currentTime = oss.str();
    return currentTime;
}

//Returns the last ID from a JSON file containing an array of tasks.
int getLastId(const string& fileName) {
    int maxId = 0;
    vector<task> tasks = parseJsonFile(fileName);
    for (const auto& task : tasks) {
        if (task.id > maxId) {
            maxId = task.id;
        } 
    }
    return maxId;
}