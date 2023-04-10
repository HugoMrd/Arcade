/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Name
*/

#include "Name.hpp"

arcade::Name::Name()
{
    _namePlayer.clear();
    _input = "";
}

void arcade::Name::printName(arcade::Event keys)
{
	if (keys == backspace)
		_namePlayer = _namePlayer.substr(0, _namePlayer.size() - 1);
	else if (_namePlayer.size() < SIZENAME) {
		_input = keys + '`';
		if (_input.c_str()[0] >= '`' && _input.c_str()[0] <= 'z')
			_namePlayer += _input;
	}
}

int arcade::Name::createName(arcade::IDisplayModule &graphical)
{
    arcade::Event keys = {};
    arcade::Text title("Arcade", {300, 80}, {80});
    arcade::Text name("Enter your name: ", {150, 300}, {42});
    arcade::Text namePlayer("", {400, 300}, {42});

    while (keys != Event::escape) {
        while (graphical.pollEvent(keys)) {
            keys = graphical.useEvent();
            if (keys == enter)
                return (0);
            printName(keys);
        }
        namePlayer.setText(_namePlayer);
        graphical.clear();
        graphical.drawBack();
        graphical.drawText(title);
        graphical.drawText(name);
        graphical.drawText(namePlayer);
        namePlayer.setColor({0, 244, 244, 244});
        graphical.display();
    }
    return (0);
}

void arcade::Name::writeScore(void)
{
    std::fstream inputFile("score.txt", std::ios::in);
    std::multimap<int, std::string> existingScores;

    if (inputFile.is_open()) {
        int score;
        std::string name;
        while (inputFile >> name >> score)
            existingScores.insert({score, name});
        inputFile.close();
    }
    if (_namePlayer.empty())
        _namePlayer = "New_player";
    existingScores.insert({_score, _namePlayer});
    while (existingScores.size() > 3)
        existingScores.erase(existingScores.begin());
    std::fstream outputFile("score.txt", std::ios::out | std::ios::trunc);
    if (outputFile.is_open()) {
        for (auto it = existingScores.crbegin(); it != existingScores.crend(); ++it) {
            outputFile << it->second << " " << it->first << std::endl;
            std::cout << it->first << " " << it->second << std::endl;
        }
        outputFile.close();
    }
}

void arcade::Name::setScore(int score)
{
    _score = score;
}
