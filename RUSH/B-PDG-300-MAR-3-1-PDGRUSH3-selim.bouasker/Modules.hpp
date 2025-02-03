/*
** EPITECH PROJECT, 2025
** RUSH 3
** File description:
** HPP
*/
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <ncurses.h>

#pragma once

namespace Krell1 {
    // Interface modules
    class Module {
        public:
            virtual ~Module() {}
            virtual void update() = 0;
            virtual std::string getData() const = 0;
    };

    // Interface affichages
    class Display {
        public:
            virtual ~Display() {}
            virtual void init() = 0;
            virtual void render(const std::vector<Module*>&) = 0;
    };
}

// -- HostnameModule ----------------------------------------------------------
class HostnameModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- OSModule ----------------------------------------------------------------
class OSModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- UserModule --------------------------------------------------------------
class UserModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- KernelModule ------------------------------------------------------------
class KernelModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- DateModule -------------------------------------------------------------- 
class DateModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- HourModule --------------------------------------------------------------
class HourModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- CPUModule ---------------------------------------------------------------
class CPUModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- RAMModule --------------------------------------------------------------
class RAMModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- NetworkModule ----------------------------------------------------------
class NetworkModule : public Krell1::Module {
    private:
        std::string data;
        std::string getIPAddress();
        std::string getInterfaceInfo();
        std::string getNetworkStats();
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- BatteryModule ----------------------------------------------------------
class BatteryModule : public Krell1::Module {
    private:
        std::string data;
        std::string formatTime(const std::string& minutes);
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- UptimeModule ------------------------------------------------------------
class UptimeModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- VolumeModule ------------------------------------------------------------
class VolumeModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- StorageModule -----------------------------------------------------------
class StorageModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- ProcessModule -----------------------------------------------------------
class ProcessModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};

// -- GPUModule ---------------------------------------------------------------
class GPUModule : public Krell1::Module {
    std::string data;
    public:
        void update() override;
        std::string getData() const override { return data; }
};
