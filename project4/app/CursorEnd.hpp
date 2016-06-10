#ifndef CURSOR_END_HPP
#define CURSOR_END_HPP

#include "Command.hpp"

class CursorEnd: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    int backup_line;
    int backup_column;
};


#endif // CURSOR_END_HPP
