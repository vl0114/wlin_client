//
// Created by vl_sys on 2019-11-29.
//
// require standard c++17
// at least g++-8 or clang++-8
//
//

#ifndef SERVERSOCKETINFO_LINUXSTATUS_H
#define SERVERSOCKETINFO_LINUXSTATUS_H

#include <sys/utsname.h>
#include <string>
#include <exception>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <csignal>
#include <iostream>
#include <fstream>
#include <climits>
#include <filesystem>
#include <sys/sysinfo.h>
#include <sstream>


namespace LinuxStats {
    class SystemName {
    private:
        struct utsname system_names;

    public:

        SystemName();

        std::string GetSystemName();
        std::string GetNodeName();
        std::string GetRelease();
        std::string Version();
        std::string Machine();
    };


    class Process{
    private:
        pid_t pid = -1, ppid = -1, pgrp = -1, session = -1, tty = -1;

        char state = -1;

        bool is_ok = false;

        std::string name;

    public:
        Process() = default;
        explicit Process(pid_t pid) {
            GetStatus(pid);
        }

        void GetStatus(pid_t pid);
        void KillThis();
        int GetPid();
        int GetPPid();
        int GetGroup();
        int GetSession();
        int GetTty();
        char GetState();
        std::string GetName();
        void SendSignal(int sig);
        bool IsOk();
    };

    class ProcessStatus{
    private:
        std::vector<Process> processes;

    public:
        ProcessStatus()
        {
            GetProcesses();
        }
        void GetProcesses();

        std::vector<Process> GetData();
    };

    class NetworkStatus
    {

    };

    class CpuProcessor
    {
    public:
        CpuProcessor() = default;
        explicit CpuProcessor(std::stringstream &info);
        int GetId();

        const std::string & GetVendor();

        const std::string &GetModel();

        double GetMhz();

        uint GetCache();

        int GetPhysicsId();

        int GetCoreId();

        int GetCpuCores();

    private:
        int id = -1;
        std::string vendor;
        std::string model;
        double mhz = -1;
        uint cache = 0;
        int physics_id = -1;
        int core_id = -1;
        int cpu_cores = -1;
    };

    class CpuStatus
    {
    private:
        std::vector<CpuProcessor> processor;
    public:
        CpuStatus();

        const std::vector<CpuProcessor> &GetProcessor();
    };

    class SysStatus
    {
    private:
        struct sysinfo info;

    public:
        SysStatus();
        ulong GetLoads1();
        ulong GetLoads5();
        ulong GetLoads15();
        ulong GetTotalRam();
        ulong GetFreeRam();
        ulong GetSharedRam();
        ulong GetBufferRam();
        ulong GetTotalSwapSize();
        ulong GetFreeSwapSize();
        ulong GetTotalHighMemSize();
        ulong GetAvailableHighMemSize();
        ulong GetMemUnit();
        ulong GetUptime();
        ushort GetProcs();
    };
}

#endif //SERVERSOCKETINFO_LINUXSTATUS_H
