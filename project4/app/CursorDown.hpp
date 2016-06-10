#ifndef CURSOR_DOWN_HPP
#define CURSOR_DOWN_HPP

#include "Command.hpp"

class CursorDown: public Command
{
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
};


#endif // CURSOR_DOWN_HPP
