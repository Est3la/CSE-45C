#include "DeleteLine.hpp"

void DeleteLine::execute(EditorModel& model)
{
    backup_line = model.cursorLine();
    backup_column = model.cursorColumn();

    model.deleteLine();

    backup_text = model.getBackupText();
}

void DeleteLine::undo(EditorModel& model)
{
    model.movePosition(backup_line, backup_column);
    model.insertLine(backup_text);
}
