#ifndef CURSOR_UP_HPP
#define CURSOR_UP_HPP

#include "Command.hpp"

class CursorUp: public Command
{
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
};


#endif // CURSOR_UP_HPP
