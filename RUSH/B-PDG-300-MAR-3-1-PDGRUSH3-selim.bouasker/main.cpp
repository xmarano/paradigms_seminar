/*
** EPITECH PROJECT, 2025
** RUSH 3
** File description:
** CPP
*/
#include "Modules.hpp"
#include "NcursesDisplay.hpp"
#include <unordered_map>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [-ncurses | -sfml]" << std::endl;
        return 1;
    }

    if (std::string(argv[1]) == "-sfml") {
        system("cd SFML && ./sfmldisplay 2>/dev/null");
        return 0;
    }

    if (std::string(argv[1]) == "-ncurses") {
        std::vector<Krell1::Module*> modules;
        std::unordered_map<std::string, Krell1::Module*> availableModules = {
            {"hostname", new HostnameModule()},
            {"os", new OSModule()},
            {"user", new UserModule()},
            {"kernel", new KernelModule()},
            {"date", new DateModule()},
            {"hour", new HourModule()},
            {"cpu", new CPUModule()},
            {"ram", new RAMModule()},
            {"network", new NetworkModule()},
            {"battery", new BatteryModule()},
            {"uptime", new UptimeModule()},
            {"volume", new VolumeModule()},
            {"storage", new StorageModule()},
            {"process", new ProcessModule()},
            {"gpu", new GPUModule()}
        };

        NcursesDisplay display;
        display.init();

        modules.push_back(availableModules["hostname"]);
        modules.push_back(availableModules["os"]);
        modules.push_back(availableModules["user"]);
        modules.push_back(availableModules["kernel"]);
        modules.push_back(availableModules["date"]);
        modules.push_back(availableModules["hour"]);
        modules.push_back(availableModules["volume"]);
        modules.push_back(availableModules["cpu"]);
        modules.push_back(availableModules["ram"]);
        //modules.push_back(availableModules["network"]);
        modules.push_back(availableModules["storage"]);
        modules.push_back(availableModules["gpu"]);
        modules.push_back(availableModules["battery"]);
        //modules.push_back(availableModules["uptime"]);
        //modules.push_back(availableModules["process"]);

        while (true) {
            for (auto module : modules) module->update();
            display.render(modules);

            int c = getch();
            if (c == 'q') break;
            if (c == 'a') modules.push_back(availableModules["hostname"]);
            if (c == 'z') modules.push_back(availableModules["os"]);
            if (c == 'e') modules.push_back(availableModules["user"]);
            if (c == 'r') modules.push_back(availableModules["kernel"]);
            if (c == 't') modules.push_back(availableModules["date"]);
            if (c == 'y') modules.push_back(availableModules["hour"]);
            if (c == 'u') modules.push_back(availableModules["cpu"]);
            if (c == 'i') modules.push_back(availableModules["ram"]);
            if (c == 'o') modules.push_back(availableModules["network"]);
            if (c == 'p') modules.push_back(availableModules["battery"]);
            if (c == 'd') modules.push_back(availableModules["uptime"]);
            if (c == 'f') modules.push_back(availableModules["volume"]);
            if (c == 'g') modules.push_back(availableModules["storage"]);
            if (c == 'h') modules.push_back(availableModules["process"]);
            if (c == 'j') modules.push_back(availableModules["gpu"]);

            if (c == 's') { system("cd SFML && ./sfmldisplay 2>/dev/null"); }
            if (c == 127 && !modules.empty()) modules.pop_back();
        }

        endwin();
        for (auto& pair : availableModules) delete pair.second;
    } else {
        std::cerr << "Usage: " << argv[0] << " [-ncurses | -sfml]" << std::endl;
        return 1;
    }
    return 0;
}
