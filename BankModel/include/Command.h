#pragma once

class Command {
protected:
    int commandID;
public:
    virtual ~Command() = default;
    virtual void run() const = 0;
    virtual void undo() const = 0;
    
    int getCommandID();
};