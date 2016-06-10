#include "CursorEnd.hpp"

void CursorEnd::execute(EditorModel& model)
{
    backup_line = model.cursorLine();
    backup_column = model.cursorColumn();
    
    model.moveEnd();
}

void CursorEnd::undo(EditorModel& model)
{
    model.movePosition(backup_line, backup_column);
}
