# task-tracker-CLI
Sample solution for Task Tracker from roadmap.sh

## How to run

Clone the repository and run the following command:

```bash
git clone https://github.com/bob35306/task-tracker-CLI
cd task-tracker-cli
```

Run the following command to build the project:

```bash
make

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