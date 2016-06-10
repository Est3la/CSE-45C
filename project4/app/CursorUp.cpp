#include "CursorUp.hpp"

void CursorUp::execute(EditorModel& model)
{
    model.moveUp();
}

void CursorUp::undo(EditorModel& model)
{
    model.moveDown();
}
