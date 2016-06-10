#ifndef INSERT_CHARACTER_HPP
#define INSERT_CHARACTER_HPP

#include "Command.hpp"

class InsertCharacter: public Command
{
public:
    InsertCharacter(char c);
    
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    char c;
};


#endif // INSERT_CHARACTER_HPP
