// InteractionProcessor.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    std::vector<Command*> undo;
    std::vector<Command*> redo;

    view.refresh();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            std::for_each(undo.begin(), undo.end(), [](Command* c) {delete c;});
            std::for_each(redo.begin(), redo.end(), [](Command* c) {delete c;});
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (!undo.empty())
            {
                undo.back()->undo(model);
                redo.push_back(undo.back());
                undo.pop_back();

                model.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (!redo.empty())
            {
                redo.back()->execute(model);
                undo.push_back(redo.back());
                redo.pop_back();

                model.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                
                undo.push_back(interaction.command());

                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            //delete command;
        }
    }
}

