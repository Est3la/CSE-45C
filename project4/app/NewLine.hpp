#ifndef NEW_LINE_HPP
#define NEW_LINE_HPP

#include "Command.hpp"

class NewLine: public Command
{
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
};


#endif // NEW_LINE_HPP
