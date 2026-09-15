# task-tracker-CLI
Sample solution for Task Tracker from roadmap.sh

## Requirements

- C++ compiler with `g++`
- C++17 or later
- `make` is optional

## Project Structure

```text
TASK-TRACKER-CLI/
├── include/
│   ├── cli.h
│   ├── exception.h
│   └── utils.h
├── src/
│   ├── cli.cpp
│   ├── exception.cpp
│   ├── main.cpp
│   └── utils.cpp
├── Makefile
├── README.md
└── tasks.json
```
## How to run

Clone the repository and run the following command:

```bash
git clone https://github.com/bob35306/task-tracker-CLI
cd task-tracker-cli
```

Run the following command to build the project:
### Method 1: Build using Makefile

Check whether Make is available:

```bash
make --version
```

If the command displays the GNU Make version, build the project:

```bash
make
```

### Method 2: Build directly using g++

Use this method if `make` is not installed or cannot be used.


```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/cli.cpp src/exception.cpp src/utils.cpp -o task-cli.exe
```
```bash
# To add a task
task-cli add "Buy groceries"

# To update a task
task-cli update 1 "Buy groceries and cook dinner"

# To delete a task
task-cli delete 1

# To mark a task as in progress/done/todo
task-cli mark-in-progress 1
task-cli mark-done 1
task-cli mark-todo 1

# To list all tasks
task-cli list
task-cli list done
task-cli list todo
task-cli list in-progress
```