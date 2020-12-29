#include <iostream>
#include "Command.h"

Command::~Command() = default;

int Command::getCommandID(){
    return commandID;
}