/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Score
*/

#include "Score.hpp"

arcade::Score::Score()
{
    std::ifstream file("score.txt");

    if (file.is_open()) {
        std::string line;
        bool firstLineProcessed = false;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name;
            int value;
            if (iss >> name >> value)
                _score.insert(std::pair<int, std::string>(value, name));
            else if (!firstLineProcessed)
                throw Error("First line of score file does not contain a valid score");
            firstLineProcessed = true;
        }
        file.close();
    } else {
        throw Error("Failed to open score file");
    }
}

void arcade::Score::initScore(IDisplayModule& graphical)
{
    const std::vector<float> size = {800, 600};
    float pos = 0;
    constexpr float inc = 50.0f;
    std::vector<std::pair<int, std::string>> scoreVector(_score.begin(), _score.end());
    std::sort(scoreVector.begin(), scoreVector.end(), std::greater<std::pair<int, std::string>>());
    arcade::Text scoreBoard("ScoreBoard", {280, 140 + pos}, {60});
    int rank = 1;
    Color color = {};

    for (size_t i = 0; i < scoreVector.size(); i++) {
        const std::string name = scoreVector[i].second;
        const int value = scoreVector[i].first;
        arcade::Text text(name + " - " + std::to_string(value), {350, 280 + pos}, {25});
        graphical.drawText(text);
        pos += inc;
        if (i < scoreVector.size() - 1 && value != scoreVector[i + 1].first) {
            if (rank == 1)
                color = {255, 215, 0, 255};
            if (rank == 2)
                color = {192, 192, 192, 255};
            if (rank == 3)
                color = {205, 127, 50, 255};
            arcade::Text rankText("#" + std::to_string(rank), {300, 280 + pos - inc}, {25}, color);
            graphical.drawText(rankText);
            rank++;
        }
    }
    if (rank == 1)
        color = {255, 215, 0, 255};
    if (rank == 2)
        color = {192, 192, 192, 255};
    if (rank == 3)
        color = {205, 127, 50, 255};
    arcade::Text rankText("#" + std::to_string(rank), {300, 280 + pos - inc}, {25}, color);
    graphical.drawText(rankText);
    graphical.drawText(scoreBoard);
}

void arcade::Score::drawScore(IDisplayModule &graphical)
{
    arcade::Event keys = none;

    while (keys != enter) {
		while (graphical.pollEvent(keys))
			keys = graphical.useEvent();
        graphical.clear();
        graphical.drawBack();
        initScore(graphical);
        graphical.display();
    }
}
