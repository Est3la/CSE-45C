#ifndef CURSOR_LEFT_HPP
#define CURSOR_LEFT_HPP

#include "Command.hpp"

class CursorLeft: public Command
{
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
};



#endif // CURSOR_LEFT_HPP
