/*
** EPITECH PROJECT, 2025
** RUSH 3
** File description:
** CPP
*/
#include "NcursesDisplay.hpp"

void NcursesDisplay::init()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    timeout(100);
    
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_RED, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_BLUE, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);
    }
}

void NcursesDisplay::render(const std::vector<Krell1::Module*>& modules)
{
    erase();
    int y = 0;
    for (auto module : modules) {
        std::istringstream dataStream(module->getData());
        std::string line;

        while (std::getline(dataStream, line)) {
            int color = 0;
            int attrs = A_NORMAL;
            
            if (line.find("Hostname:") != std::string::npos || line.find("User:") != std::string::npos) {
                color = 2;
                attrs = A_BOLD;
            } else if (line.find("CPU:") != std::string::npos || line.find("RAM:") != std::string::npos || line.find("Storage:") != std::string::npos) {
                size_t start = line.find("[");
                size_t end = line.find("]");
                if (start != std::string::npos && end != std::string::npos && end > start) {
                    std::string barContent = line.substr(start + 1, end - start - 1);
                    int barCount = std::count(barContent.begin(), barContent.end(), '|');
                    int totalBars = barContent.length();
                    float fillRatio = (totalBars > 0) ? (static_cast<float>(barCount) / totalBars) * 100 : 0;
                    if (fillRatio > 75) {
                        color = 4;
                        attrs = A_BOLD;
                    } else if (fillRatio > 20) {
                        color = 3;
                        attrs = A_BOLD;
                    } else {
                        color = 1;
                        attrs = A_BOLD;
                    }
                }
            } else if (line.find("===") != std::string::npos) {
                color = 5;
                attrs = A_BOLD | A_UNDERLINE;
            }

            if (has_colors()) attron(COLOR_PAIR(color));
            if (attrs != A_NORMAL) attron(attrs);

            mvprintw(y++, 0, "%s", line.c_str());

            if (attrs != A_NORMAL) attroff(attrs);
            if (has_colors()) attroff(COLOR_PAIR(color));
        }
    }
    refresh();
}
