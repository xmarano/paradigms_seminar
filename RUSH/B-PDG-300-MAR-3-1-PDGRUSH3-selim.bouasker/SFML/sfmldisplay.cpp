/*
** EPITECH PROJECT, 2025
** RUSH 3
** File description:
** CPP
*/
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>

std::string getCommandOutput(const std::string &command)
{
    std::string result;
    std::system((command + " > output.txt").c_str());
    std::ifstream file("output.txt");
    if (file) {
        std::getline(file, result);
        file.close();
    }
    return result;
}

std::vector<std::pair<std::string, std::string >> getSystemInfo()
{
    std::vector<std::pair<std::string, std::string >> info;
    info.push_back({"Hostname", getCommandOutput("hostname")});
    info.push_back({"OS", getCommandOutput("uname -s")});
    info.push_back({"User", getCommandOutput("whoami")});
    info.push_back({"Kernel", getCommandOutput("uname -r")});
    info.push_back({"Date/Time", getCommandOutput("date '+%Y-%m-%d %H:%M:%S'")});
    info.push_back({"CPU Usage", getCommandOutput("top -l 1 -n 0 | grep 'CPU usage' | awk '{print $3}'")});
    info.push_back({"IP Address", getCommandOutput("ipconfig getifaddr en0")});
    info.push_back({"Disk Usage", getCommandOutput("df -h / | tail -1 | awk '{print $5}'")});
    return info;
}

float parsePercentage(const std::string &str)
{
    try {
        return std::stof(str.substr(0, str.size() - 1));
    } catch (...) {
        return 0.0f;
    }
}

std::string getCurrentTimeString()
{
    std::time_t now = std::time(nullptr);
    std::tm *ltm = std::localtime(&now);
    char buffer[9];
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", ltm);
    return std::string(buffer);
}

void updateBar(sf::RectangleShape &bar, float percentage)
{
    bar.setSize(sf::Vector2f(2 * percentage, 20));
    if (percentage < 50)
        bar.setFillColor(sf::Color::Green);
    else if (percentage < 80)
        bar.setFillColor(sf::Color::Yellow);
    else
        bar.setFillColor(sf::Color::Red);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "System Monitor");
    window.setFramerateLimit(2);

    sf::Font font;
    if (!font.loadFromFile("test.ttf")) {
        std::cerr << "Erreur : chargement de la police" << std::endl;
        return EXIT_FAILURE;
    }

    sf::RectangleShape background(sf::Vector2f(800, 700));
    background.setFillColor(sf::Color(40, 40, 40));

    sf::Text title("System Monitor", font, 30);
    title.setFillColor(sf::Color::White);
    title.setPosition(20, 10);

    sf::Text clockText("", font, 24);
    clockText.setFillColor(sf::Color::Yellow);
    clockText.setPosition(600, 10);

    struct InfoPanel {
        sf::RectangleShape panel;
        sf::Text text;
    };

    std::vector<InfoPanel> panels;
    auto info = getSystemInfo();
    float panelWidth = 760.f;
    float panelHeight = 50.f;
    float panelMargin = 15.f;
    float startY = 60.f;

    for (size_t i = 0; i < info.size(); i++) {
        InfoPanel ip;
        ip.panel.setSize(sf::Vector2f(panelWidth, panelHeight));
        ip.panel.setFillColor(sf::Color(50, 50, 50, 230));
        ip.panel.setOutlineThickness(2);
        ip.panel.setOutlineColor(sf::Color(150, 150, 255));
        ip.panel.setPosition(20, startY + i * (panelHeight + panelMargin));

        ip.text.setFont(font);
        ip.text.setCharacterSize(22);
        ip.text.setFillColor(sf::Color::White);
        ip.text.setString(info[i].first + ": " + info[i].second);
        ip.text.setPosition(ip.panel.getPosition().x + 15, ip.panel.getPosition().y + 5);

        panels.push_back(ip);
    }

    // Barre CPU
    sf::RectangleShape cpuBarBackground(sf::Vector2f(200, 20));
    cpuBarBackground.setFillColor(sf::Color(70, 70, 70));
    cpuBarBackground.setPosition(500, startY + 5 * (panelHeight + panelMargin));

    sf::RectangleShape cpuBar(sf::Vector2f(0, 20));
    cpuBar.setPosition(cpuBarBackground.getPosition());

    // Barre Disque
    sf::RectangleShape diskBarBackground(sf::Vector2f(200, 20));
    diskBarBackground.setFillColor(sf::Color(70, 70, 70));
    diskBarBackground.setPosition(500, startY + 7 * (panelHeight + panelMargin));

    sf::RectangleShape diskBar(sf::Vector2f(0, 20));
    diskBar.setPosition(diskBarBackground.getPosition());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
                window.close();
        }

        auto updatedInfo = getSystemInfo();
        for (size_t i = 0; i < panels.size(); i++)
            panels[i].text.setString(updatedInfo[i].first + ": " + updatedInfo[i].second);

        clockText.setString(getCurrentTimeString());

        float cpuUsage = parsePercentage(updatedInfo[5].second);
        float diskUsage = parsePercentage(updatedInfo[7].second);

        updateBar(cpuBar, cpuUsage);
        updateBar(diskBar, diskUsage);

        window.clear();
        window.draw(background);
        window.draw(title);
        window.draw(clockText);

        for (auto &p : panels)
            window.draw(p.panel), window.draw(p.text);

        window.draw(cpuBarBackground);
        window.draw(cpuBar);
        window.draw(diskBarBackground);
        window.draw(diskBar);

        window.display();
    }

    return 0;
}
