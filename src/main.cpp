#include "../include/cli.h"
struct CommandLineArgs {
    string command;
    vector<string> args;
};

CommandLineArgs parseCommandLineArgs(int argc, char* argv[]);

int main(int argc, char* argv[]){
    try{
        cli taskTracker;
        if(argc < 2 || argc > 4) throw CommandNotFound();
        CommandLineArgs args  = parseCommandLineArgs(argc, argv);
        if(argc == 3){
            if(args.command == "add"){
                taskTracker.addTask(args.args[0]);
            }
            else if(args.command == "delete"){
                taskTracker.deleteTask(stoi(args.args[0]));
            }
            else if(args.command == "mark-in-progress"){
                taskTracker.markInProgress(stoi(args.args[0]));
            }
            else if(args.command == "mark-done"){
                taskTracker.markDone(stoi(args.args[0]));
            }
            else if(args.command == "list"){
                taskTracker.listTasks(args.args[0]);
            }
            else throw CommandNotFound();
        }
        else if(argc == 2 && args.command == "list"){
            taskTracker.listTasks("");
        }
        else if(argc == 4 && args.command == "update"){
            taskTracker.updateTask(stoi(args.args[0]), args.args[1]);
        }
        else throw CommandNotFound();
    }
    catch(CommandNotFound& ex){
        cout << ex.what() << endl;
    }
}

CommandLineArgs parseCommandLineArgs(int argc, char* argv[]) {
    CommandLineArgs args;
    if (argc > 1) {
        args.command = argv[1];
        for (int i = 2; i < argc; i++) {
            args.args.push_back(argv[i]);
        }
    }
    return args;
}