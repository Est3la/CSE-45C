#include "InsertCharacter.hpp"

InsertCharacter::InsertCharacter(char c): c{c}
{}

void InsertCharacter::execute(EditorModel& model)
{
    model.insertChar(c);
}

void InsertCharacter::undo(EditorModel& model)
{
    model.backspace();
}
