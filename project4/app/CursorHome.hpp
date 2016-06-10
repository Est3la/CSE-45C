#ifndef CURSOR_HOME_HPP
#define CURSOR_HOME_HPP

#include "Command.hpp"

class CursorHome: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    int backup_line;
    int backup_column;
};


#endif // CURSOR_HOME_HPP
