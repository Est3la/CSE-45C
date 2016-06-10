// EditorModel.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"

#include <iostream>

EditorModel::EditorModel()
    : cursor_line{1}, cursor_column{1}, data{""}, error_msg{""}
{
}


int EditorModel::cursorLine() const
{
    return cursor_line;
}


int EditorModel::cursorColumn() const
{
    return cursor_column;
}


int EditorModel::lineCount() const
{
    return data.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return data.at(lineNumber-1);
}


const std::string& EditorModel::currentErrorMessage() const
{
    return error_msg;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    error_msg = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    error_msg = "";
}

void EditorModel::moveUp()
{
    if (cursor_line > 1)
    {
        cursor_line -= 1;
        if (cursor_column > data.at(cursor_line-1).length()+1)
        {
            cursor_column = data.at(cursor_line-1).length()+1;
        }
    }
    else
    {
        throw EditorException("Top of file");
    }
}

void EditorModel::moveDown()
{
    if (cursor_line < lineCount())
    {
        cursor_line += 1;
        if (cursor_column > data.at(cursor_line-1).length()+1)
        {
            cursor_column = data.at(cursor_line-1).length()+1;
        }
    }
    else
    {
        throw EditorException("Bottom of file");
    }
}
void EditorModel::moveRight()
{
    if (cursor_column < data.at(cursor_line - 1).length()+1)
    {
        cursor_column += 1;
    }
    else if (cursor_line < lineCount())
    {
        cursor_column = 1;
        cursor_line += 1;
    }
    else
    {
        throw EditorException("End of file");
    }
}

void EditorModel::moveLeft()
{
    if (cursor_column > 1)
    {
        cursor_column -= 1;
    }
    else if (cursor_line > 1)
    {
        cursor_line -= 1;
        cursor_column = data.at(cursor_line-1).length()+1;
    }
    else
    {
        throw EditorException("Beginning of file");
    }
}

void EditorModel::moveHome()
{
    cursor_column = 1;
}

void EditorModel::moveEnd()
{
    cursor_column = data.at(cursor_line-1).length()+1;
}

void EditorModel::newLine()
{
    std::string temp = data.at(cursor_line-1).substr(cursor_column-1);
    data.at(cursor_line-1) = data.at(cursor_line-1).substr(0, cursor_column-1);
    data.insert(data.begin() + cursor_line, temp);

    cursor_line += 1;
    cursor_column = 1;
}

void EditorModel::backspace()
{
    if (cursor_column == 1 && cursor_line == 1)
    {
        throw EditorException("Beginning of file");
    }
    else if (cursor_column == 1)
    {
        cursor_column = data.at(cursor_line-2).length()+1;
        data.at(cursor_line-2) += data.at(cursor_line-1);
        data.erase(data.begin() + cursor_line - 1);
        cursor_line -= 1;
    }
    else
    {
        backup_char = data.at(cursor_line-1).at(cursor_column-2);
        
        data.at(cursor_line-1) = data.at(cursor_line-1).erase(cursor_column-2,1);
        cursor_column -= 1;
    }
}

void EditorModel::deleteLine()
{
    backup_text = data.at(cursor_line-1);

    if (lineCount() == 1)
    {
        data.push_back("");
        data.erase(data.begin() + cursor_line-1);
        cursor_line = 1;
        cursor_column = 1;
    }
    else
    {
        data.erase(data.begin() + cursor_line-1);
        if (cursor_line > 1)
        {
            cursor_line -= 1;
        }
        else
        {
            cursor_line = 1;
        }
        if (cursor_column > data.at(cursor_line-1).length()+1)
        {
            cursor_column = data.at(cursor_line-1).length()+1;
        }
    }
}

char EditorModel::getBackupChar()
{
    return backup_char;
}

std::string EditorModel::getBackupText()
{
    return backup_text;
}


void EditorModel::movePosition(int line, int column)
{
    cursor_line = line;
    cursor_column = column;
}


void EditorModel::insertChar(char c)
{
    data.at(cursor_line-1) = data.at(cursor_line-1).insert(cursor_column-1,1,c);
    cursor_column += 1;
}

void EditorModel::insertLine(std::string line)
{
    data.insert(data.begin() + cursor_line-1, line);
}
