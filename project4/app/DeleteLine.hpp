#ifndef DELETE_LINE_HPP
#define DELETE_LINE_HPP

#include "Command.hpp"

class DeleteLine: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    int backup_line;
    int backup_column;

    std::string backup_text;
};


#endif // DELETE_LINE_HPP
