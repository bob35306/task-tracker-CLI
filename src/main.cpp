#include "../include/cli.h"

int main(int argc, char* argv[]){
    try{
        cli taskTracker;
        if(argc < 2 || argc > 4) throw CommandNotFound();
        if(argc == 3){
            if(argv[1] == "delete"){
                taskTracker.deleteTask(stoi(argv[2]));
            }
            else if(argv[1] == "mark-in-progess"){
                taskTracker.markInProgess(stoi(argv[2]));
            }
            else if(argv[1] == "mark-done"){
                taskTracker.markDone(stoi(argv[2]));
            }
            else if(argv[1] == "list"){
                taskTracker.listTasks(argv[2]);
            }
            else throw CommandNotFound();
        }
        else if(argc == 2 && argv[1] == "list"){
            taskTracker.listTasks("");
        }
        else if(argc == 4 && argv[1] == "update"){
            taskTracker.updateTask(stoi(argv[2]), argv[3]);
        }
        else throw CommandNotFound();
    }
    catch(CommandNotFound& ex){
        cout << ex.what() << endl;
    }
}