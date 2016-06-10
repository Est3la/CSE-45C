#include "CursorDown.hpp"

void CursorDown::execute(EditorModel& model)
{
    model.moveDown();
}

void CursorDown::undo(EditorModel& model)
{
    model.moveUp();
}
