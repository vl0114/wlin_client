//
// Created by vl_sys on 2019-11-29.
//

#include "Linuxstatus.h"

LinuxStats::SystemName::SystemName() {
    memset(&system_names, 0, sizeof(struct utsname));
    int r = uname(&system_names);
    if(r < 0)
    {
        //throw
    }
}

std::string LinuxStats::SystemName::GetSystemName() {
    return std::string(system_names.sysname);
}

std::string LinuxStats::SystemName::GetNodeName() {
    return std::string(system_names.nodename);
}

std::string LinuxStats::SystemName::GetRelease() {
    return std::string(system_names.release);
}

std::string LinuxStats::SystemName::Version() {
    return std::string(system_names.version);
}

std::string LinuxStats::SystemName::Machine() {
    return std::string(system_names.machine);
}

void LinuxStats::ProcessStatus::GetProcesses() {
    processes.clear();

    for(auto &p : std::filesystem::directory_iterator("/proc"))
    {
        if(!p.is_directory())
            continue;

        int pid = atoi(basename(p.path().string().c_str()));
        if(!pid)
            continue;
        processes.emplace_back(Process(pid));
    }
}

std::vector<LinuxStats::Process> LinuxStats::ProcessStatus::GetData() {
    return processes;
}

void LinuxStats::Process::GetStatus(pid_t id) {
    std::string path("/proc/");
    path.append(std::to_string(id));
    path.append("/stat");
    std::ifstream proc(path);

    if(!proc.good())
        return;
    is_ok = true;
    proc >> pid >> name >> state >> ppid >> pgrp >> session >> tty;
}

void LinuxStats::Process::KillThis() {
    kill(pid, SIGKILL);
}

int LinuxStats::Process::GetPid() {
    return pid;
}
int LinuxStats::Process::GetPPid()
{
    return ppid;
}
int LinuxStats::Process::GetGroup()
{
    return pgrp;
}
int LinuxStats::Process::GetSession()
{
    return session;
}
int LinuxStats::Process::GetTty()
{
    return tty;
}
char LinuxStats::Process::GetState()
{
    return state;
}

std::string LinuxStats::Process::GetName() {
    return name;
}

void LinuxStats::Process::SendSignal(int sig) {
    kill(pid, sig);
}

bool LinuxStats::Process::IsOk() {
    return is_ok;
}

LinuxStats::SysStatus::SysStatus() {
    sysinfo(&info);
}

ulong LinuxStats::SysStatus::GetLoads1() {
    return info.loads[0];
}

ulong LinuxStats::SysStatus::GetLoads5() {
    return info.loads[1];
}

ulong LinuxStats::SysStatus::GetLoads15() {
    return info.loads[2];
}

ulong LinuxStats::SysStatus::GetTotalRam() {
    return info.totalram;
}

ulong LinuxStats::SysStatus::GetFreeRam() {
    return info.freeram;
}

ulong LinuxStats::SysStatus::GetSharedRam() {
    return info.sharedram;
}

ulong LinuxStats::SysStatus::GetBufferRam() {
    return info.bufferram;
}

ulong LinuxStats::SysStatus::GetTotalSwapSize() {
    return info.totalswap;
}

ulong LinuxStats::SysStatus::GetTotalHighMemSize() {
    return info.totalhigh;
}

ulong LinuxStats::SysStatus::GetFreeSwapSize() {
    return info.freeswap;
}

ulong LinuxStats::SysStatus::GetAvailableHighMemSize() {
    return info.freehigh;
}

ulong LinuxStats::SysStatus::GetMemUnit() {
    return info.mem_unit;
}

ulong LinuxStats::SysStatus::GetUptime() {
    return info.uptime;
}

ushort LinuxStats::SysStatus::GetProcs() {
    return info.procs;
}

LinuxStats::CpuProcessor::CpuProcessor(std::stringstream &info) {

    info.ignore(500, ':');
    info >> id;
    info.ignore(500, ':');
    info >> vendor;
    info.ignore(500, ':');
    info.ignore(500, ':');
    info.ignore(500, ':');
    std::getline(info, model);
    info.ignore(500, ':');
    info.ignore(500, ':');
    info.ignore(500, ':');
    info >> mhz;
    info.ignore(500, ':');
    info >> cache;
    info.ignore(500, ':');
    info >> physics_id;
    info.ignore(500, ':');
    info.ignore(500, ':');
    info >> core_id;
    info.ignore(500, ':');
    info >> cpu_cores;
}

int LinuxStats::CpuProcessor::GetId() {
    return id;
}

const std::string & LinuxStats::CpuProcessor::GetVendor() {
    return vendor;
}

const std::string &LinuxStats::CpuProcessor::GetModel() {
    return model;
}

double LinuxStats::CpuProcessor::GetMhz() {
    return mhz;
}

uint LinuxStats::CpuProcessor::GetCache() {
    return cache;
}

int LinuxStats::CpuProcessor::GetPhysicsId() {
    return physics_id;
}

int LinuxStats::CpuProcessor::GetCoreId() {
    return core_id;
}

int LinuxStats::CpuProcessor::GetCpuCores() {
    return cpu_cores;
}


LinuxStats::CpuStatus::CpuStatus() {
    std::ifstream cs("/proc/cpuinfo");
    std::stringstream ss;
    std::string temp;

    while(!cs.eof()) {
        ss.str("");

        for (int i = 0; i < 25; i++) {
            std::getline(cs, temp);
            //std::cout << i << ": " << temp << '\n';
            ss << temp << '\n';

        }
        cs.get();cs.get();
        processor.emplace_back(CpuProcessor(ss));
    }
}

const std::vector<LinuxStats::CpuProcessor> &LinuxStats::CpuStatus::GetProcessor() {
    return processor;
}
