#include "Backspace.hpp"

void Backspace::execute(EditorModel& model)
{
    backup_column = model.cursorColumn();

    model.backspace();
    
    if (backup_column > 1)
    {
        backup_char = model.getBackupChar();
    }
}

void Backspace::undo(EditorModel& model)
{
    if (backup_column == 1)
    {
        model.newLine();
    }
    else
    {
        model.insertChar(backup_char);
    }
}
