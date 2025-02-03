/*
** EPITECH PROJECT, 2025
** RUSH 3
** File description:
** CPP
*/
#include "Modules.hpp"

// -- HostnameModule ----------------------------------------------------------
void HostnameModule::update()
{
    try {
        system("hostname > tmp/hostname_tmp.txt");
        std::ifstream file("tmp/hostname_tmp.txt");
        std::getline(file, data);
        data = "Hostname: " + data;
        file.close();
    } catch (const std::exception& e) {
        data = "Hostname: [Error Hostname]";
    }
}

// -- OSModule ----------------------------------------------------------------
void OSModule::update()
{
    try {
        system("sysctl -n kern.ostype > tmp/os_tmp.txt");
        std::ifstream file("tmp/os_tmp.txt");
        std::getline(file, data);
        data = "OS: " + data;
        file.close();
    } catch (const std::exception& e) {
        data = "OS: [Error OS]";
    }
}

// -- UserModule --------------------------------------------------------------
void UserModule::update()
{   
    try {
        system("whoami > tmp/user_tmp.txt");
        std::ifstream file("tmp/user_tmp.txt");
        std::getline(file, data);
        data = "User: " + data;
        file.close();
    } catch (const std::exception& e) {
        data = "User: [Error User]";
    }
}

// -- KernelModule ------------------------------------------------------------
void KernelModule::update()
{
    try {
        system("sysctl -n kern.osrelease > tmp/kernel_tmp.txt");
        std::ifstream file("tmp/kernel_tmp.txt");
        std::getline(file, data);
        data = "Kernel: " + data;
        file.close();
    } catch (const std::exception& e) {
        data = "Kernel: [Error Kernel]";
    }
}

// -- DateModule ----------------------------------------------------------
void DateModule::update()
{
    try {
        system("date > tmp/date_tmp.txt");
        std::ifstream file("tmp/date_tmp.txt");
        std::getline(file, data);
        data = "Date: " + data.substr(0, 16);
        file.close();
    } catch (const std::exception& e) {
        data = "Date: [Error Date]";
    }
    // diviser la date et lheure.
}

// -- HourModule ---------------------------------------------------------------
void HourModule::update()
{
    try {
        std::ifstream file("tmp/date_tmp.txt");
        std::getline(file, data);
        data = "Hour: " + data.substr(17, 25);
        file.close();
    } catch (const std::exception& e) {
        data = "Hour: [Error Hour]";
    }
}

// -- CPUModule ----------------------------------------------------------------
void CPUModule::update()
{
    try {
        system("ps -A -o %cpu | awk '{s+=$1} END {print s}' > tmp/cpu_tmp.txt");
        system("sysctl -n hw.ncpu >> tmp/cpu_tmp.txt");
        std::string line;
        std::ifstream file("tmp/cpu_tmp.txt");
        std::getline(file, line);
        float cpuFloat = std::stof(line);
        std::getline(file, line);
        float coreCpu = std::stof(line);
        int core = static_cast<int>(coreCpu);
        int cpu = static_cast<int>(cpuFloat / coreCpu);
        file.close();

        std::string bar = "[";
        for (int i = 0; i < cpu/10; i++)
            bar += "|";
        for (int i = 0; i < 10 - cpu/10; i++)
            bar += " ";
        bar += "]";

        data = "CPU: " + bar + " " + std::to_string(cpu) + "%" + " (" + std::to_string(core) + " coeurs)";
    } catch (const std::exception& e) {
        data = "CPU: [Error CPU]";
    }
}

// -- RAMModule ----------------------------------------------------------------
void RAMModule::update()
{
    try {
        system("sysctl hw.memsize > tmp/ram_tmp.txt");
        system("vm_stat | grep 'Pages active' >> tmp/ram_tmp.txt");
        std::ifstream file("tmp/ram_tmp.txt");
        std::string line;
        std::getline(file, line);
        int totalMemory = std::stoull(line.substr(12)) / (1024 * 1024);
        std::getline(file, line);
        int activePages = std::stoull(line.substr(14));
        int activeMemory = (activePages * 4096) / (1024 * 1024);
        file.close();

        std::string bar = "[";
        for (int i = 0; i < (activeMemory * 10) / totalMemory; i++)
            bar += "|";
        for (int i = (activeMemory * 10) / totalMemory; i < 10; i++)
            bar += " ";
        bar += "]";

        data = "RAM: " + bar + " " + std::to_string(activeMemory) + " MB / " + std::to_string(totalMemory) + " MB";
    } catch (const std::exception& e) {
        data = "RAM: [Error RAM]";
    }
}

// -- NetworkModule ------------------------------------------------------------
std::string NetworkModule::getIPAddress()
{
    std::string result;
    system("ifconfig | grep 'inet ' | grep -v '127.0.0.1' > tmp/network_ip_tmp.txt");
    std::ifstream file("tmp/network_ip_tmp.txt");
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find("inet ") + 5;
        size_t end = line.find(" ", pos);
        result += "IP: " + line.substr(pos, end - pos) + "\n";
    }
    file.close();
    return result;
}

std::string NetworkModule::getInterfaceInfo()
{
    std::string result;
    system("ifconfig | grep ': flags=' | cut -d: -f1 > tmp/network_if_tmp.txt");
    std::ifstream file("tmp/network_if_tmp.txt");
    std::string interface;
    while (std::getline(file, interface)) {
        std::string cmd = "ifconfig " + interface + " | grep 'status' > tmp/network_status_tmp.txt";
        system(cmd.c_str());
        std::ifstream statusFile("tmp/network_status_tmp.txt");
        std::string status;
        std::getline(statusFile, status);
        result += "Interface " + interface + ": " + (status.empty() ? "Active" : status) + "\n";
        statusFile.close();
    }
    file.close();
    return result;
}

std::string NetworkModule::getNetworkStats()
{
    std::string result;
    system("netstat -I en0 -b | tail -n 1 > tmp/network_stats_tmp.txt");
    std::ifstream file("tmp/network_stats_tmp.txt");
    std::string stats;
    if (std::getline(file, stats)) {
        std::stringstream ss(stats);
        std::string in, out;
        ss >> in >> out;
        result += "Traffic In: " + in + " bytes\n";
        result += "Traffic Out: " + out + " bytes\n";
    }
    file.close();
    return result;
}

void NetworkModule::update()
{
    try {
        data = "=== Network Information ===\n";
        data += getIPAddress();
        data += getInterfaceInfo();
        data += getNetworkStats();
    } catch (const std::exception& e) {
        data = "Network: [Error Network]";
    }
}

// -- BatteryModule ----------------------------------------------------------
std::string BatteryModule::formatTime(const std::string& minutes)
{
    try {
        int mins = std::stoi(minutes);
        int hours = mins / 60;
        mins = mins % 60;
        std::stringstream ss;
        ss << hours << "h " << mins << "m";
        return ss.str();
    } catch (const std::exception& e) {
        return "Battery: [Error Battery]";
    }
}

void BatteryModule::update()
{
    try {
        data = "=== Battery Information ===\n";

        system("pmset -g batt | grep -Eo \"\\d+%\" > tmp/battery_percent_tmp.txt");
        std::ifstream percentFile("tmp/battery_percent_tmp.txt");
        std::string percentage;
        if (std::getline(percentFile, percentage)) {
            data += "Charge: " + percentage + "\n";
        }
        percentFile.close();

        system("pmset -g batt | grep \"Battery Power\"|wc -l > tmp/battery_state_tmp.txt");
        std::ifstream stateFile("tmp/battery_state_tmp.txt");
        std::string state;
        if (std::getline(stateFile, state)) {
            bool onBattery = (state[0] == '1');
            data += "Status: " + std::string(onBattery ? "On Battery" : "AC Power") + "\n";
        }
        stateFile.close();

        system("pmset -g batt | grep -Eo \"\\d+:\\d+\" > tmp/battery_time_tmp.txt");
        std::ifstream timeFile("tmp/battery_time_tmp.txt");
        std::string timeRemaining;
        if (std::getline(timeFile, timeRemaining)) {
            data += "Time Remaining: " + timeRemaining + "\n";
        }
        timeFile.close();
    } catch (const std::exception& e) {
        data = "Battery: [Error Battery]";
    }
}

// -- UptimeModule ------------------------------------------------------------
void UptimeModule::update()
{
    try {
        system("uptime > tmp/uptime_tmp.txt");
        std::ifstream file("tmp/uptime_tmp.txt");
        std::getline(file, data);
        data = "Uptime: " + data.substr(10, 7);
        file.close();
    } catch (const std::exception& e) {
        data = "Uptime: [Error Uptime]";
    }
}

// -- VolumeModule ------------------------------------------------------------
void VolumeModule::update()
{
    try {
        system("osascript -e \"output volume of (get volume settings)\" > tmp/volume_tmp.txt");
        std::ifstream file("tmp/volume_tmp.txt");
        std::getline(file, data);
        data = "Volume: " + data + "%";
        file.close();
    } catch (const std::exception& e) {
        data = "Volume: [Error Volume]";
    }
}

// -- StorageModule -----------------------------------------------------------
void StorageModule::update()
{
    try {
        system("df -h | grep \"/System/Volumes/Data\" > tmp/storage_tmp.txt");
        std::ifstream file("tmp/storage_tmp.txt");
        std::string line;
        std::getline(file, line);
        file.close();

        std::istringstream iss(line);
        std::string fs, size, used, avail, percent, mounted;
        iss >> fs >> size >> used >> avail >> percent >> mounted;

        int totalStorage = std::stoi(size.substr(0, size.size() - 2));
        int usedStorage = std::stoi(used.substr(0, used.size() - 2));
        int usagePercent = (usedStorage * 100) / totalStorage;

        std::string bar = "[";
        for (int i = 0; i < usagePercent / 10; i++) bar += "|";
        for (int i = 0; i < 10 - usagePercent / 10; i++) bar += " ";
        bar += "]";

        data = "Storage: " + bar + " " + std::to_string(usedStorage) + "GiB / " +
               std::to_string(totalStorage) + "GiB (" + std::to_string(usagePercent) + "%)";
    }
    catch (const std::exception& e) {
        data = "Storage: [Error Storage]";
    }
}

// -- ProcessModule -----------------------------------------------------------
void ProcessModule::update()
{
    try {
        system("ps -Ao pid,pcpu,comm | sort -k2 -nr | head -3 > tmp/process_cpu_tmp.txt");

        std::ifstream file("tmp/process_cpu_tmp.txt");
        std::string line;
        data = "=== Processes Information ===\n";
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string pid, cpu, command;
            iss >> pid >> cpu;
            std::getline(iss, command);
            data += "PID: " + pid + " | CPU: " + cpu + "% | " + command + "\n";
        }
        file.close();
    }
    catch (const std::exception& e) {
        data = "Processes: [Error Process]";
    }
}

// -- GPUModule ---------------------------------------------------------------
void GPUModule::update()
{
    try {
        system("system_profiler SPDisplaysDataType | grep \"Chipset Model\" -A 6 > tmp/gpu_tmp.txt");
        std::ifstream file("tmp/gpu_tmp.txt");
        std::getline(file, data);
        data = "GPU: " + data.substr(20);
        file.close();
    } catch (const std::exception& e) {
        data = "GPU: [Error GPU]";
    }
}
