#include "../include/exception.h"

const char* IdNotFound::what() const noexcept{
    return "ID NOT FOUND";
}

const char* NoTaskFound::what() const noexcept{
    return "NO TASK FOUND";
}

const char* CommandNotFound::what() const noexcept{
    return "COMMAND NOT FOUND\nList of commands:\nadd [description]\nupdate [id]\ndelete [id]\nmark-in-progress [id]\nmark-done [id]\nlist [done/todo/in-progress]";
}