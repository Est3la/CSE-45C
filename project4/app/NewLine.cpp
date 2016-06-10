#include "NewLine.hpp"

void NewLine::execute(EditorModel& model)
{
    model.newLine();
}

void NewLine::undo(EditorModel& model)
{
    model.backspace();    
}
