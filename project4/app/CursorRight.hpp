#ifndef CURSOR_RIGHT_HPP
#define CURSOR_RIGHT_HPP

#include "Command.hpp"

class CursorRight: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
};



#endif // CURSOR_RIGHT_HPP
