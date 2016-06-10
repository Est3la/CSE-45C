// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "Command.hpp"
#include "Interaction.hpp"

#include "CursorUp.hpp"
#include "CursorDown.hpp"
#include "CursorLeft.hpp"
#include "CursorRight.hpp"
#include "CursorHome.hpp"
#include "CursorEnd.hpp"
#include "NewLine.hpp"
#include "Backspace.hpp"
#include "DeleteLine.hpp"

#include "InsertCharacter.hpp"

// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'I':
            {
                Command* pUpCursor = new CursorUp;
                return Interaction::command(pUpCursor);
            }
            case 'K':
            {
                Command* pDownCursor = new CursorDown;
                return Interaction::command(pDownCursor);
            }
            case 'U':
            {
                Command* pLeftCursor = new CursorLeft;
                return Interaction::command(pLeftCursor);
            }
            case 'O':
            {
                Command* pRightCursor = new CursorRight;
                return Interaction::command(pRightCursor);
            }
            case 'Y':
            {
                Command* pHomeCursor = new CursorHome;
                return Interaction::command(pHomeCursor);
            }
            case 'P':
            {
                Command* pEndCursor = new CursorEnd;
                return Interaction::command(pEndCursor);
            }
            case 'J':
            {
                Command* pNewLine = new NewLine;
                return Interaction::command(pNewLine);
            }
            case 'M':
            {
                Command* pNewLine = new NewLine;
                return Interaction::command(pNewLine);
            }
            case 'H':
            {
                Command* pBackspace = new Backspace;
                return Interaction::command(pBackspace);
            }
            case 'D':
            {
                Command* pDeleteLine = new DeleteLine;
                return Interaction::command(pDeleteLine);
            }
            case 'Z':
            {
                return Interaction::undo();            
            }
            case 'A':
            {
                return Interaction::redo();
            }
            case 'X':
                return Interaction::quit();
            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            Command* pInsertChar = new InsertCharacter(keypress.code());
            return Interaction::command(pInsertChar); 
        }
    }
}

