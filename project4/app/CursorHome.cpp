#include "CursorHome.hpp"

void CursorHome::execute(EditorModel& model)
{
    backup_line = model.cursorLine();
    backup_column = model.cursorColumn();
    
    model.moveHome();
}

void CursorHome::undo(EditorModel& model)
{
    model.movePosition(backup_line, backup_column);
}
