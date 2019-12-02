//
// Created by vl_sys on 2019-12-03.
//

#include "LsJson.h"

void LsJson::getSystemName(string &json) {
    ptree name_root;
    name_root.put("type", "name");
    name_root.put("time", std::time(nullptr));
    name_root.put("system", this->name.GetSystemName());
    name_root.put("node", this->name.GetNodeName());
    name_root.put("release", this->name.GetRelease());
    name_root.put("version", this->name.Version());
    name_root.put("machine", this->name.Machine());

    stringstream s;
    boost::property_tree::write_json(s, name_root, false);

    json = s.str();
}

void LsJson::getProcs(string &json) {
    ptree proc_root, proc_list;
    proc_root.put("type", "process");
    proc_root.put("time", std::time(nullptr));
    ps.GetProcesses();
    auto plist = ps.GetData();
    for(auto p : plist)
    {
        ptree proc;
        proc.put("pid", p.GetPid());
        proc.put("ppid", p.GetPPid());
        proc.put("pgrp", p.GetGroup());
        proc.put("session", p.GetSession());
        proc.put("tty", p.GetTty());
        proc.put("state", p.GetState());
        proc.put("name", p.GetName());

        proc_list.push_back(make_pair("", proc));
    }

    proc_root.add_child("procs", proc_list);

    stringstream s;
    boost::property_tree::write_json(s, proc_root, false);

    json = s.str();
}

void LsJson::getCpus(string &json) {
    ptree cpu_root, cpu_list;
    cpu_root.put("type", "cpu");
    cpu_root.put("time", std::time(nullptr));

    cpu_root.put("load1", ss.GetLoads1());
    cpu_root.put("load5", ss.GetLoads5());
    cpu_root.put("load15", ss.GetLoads15());

    auto cpus = cs.GetProcessor();

    for(auto cpu : cpus)
    {
        ptree c;
        c.put("id", cpu.GetId());
        c.put("vendor", cpu.GetVendor());
        c.put("model", cpu.GetModel());
        c.put("hz", cpu.GetMhz());
        c.put("cache", cpu.GetCache());
        c.put("physics_id", cpu.GetPhysicsId());
        c.put("core_id", cpu.GetCoreId());
        c.put("cores", cpu.GetCpuCores());

        cpu_list.push_back(make_pair("", c));
    }

    cpu_root.add_child("cpus", cpu_list);

    stringstream s;
    boost::property_tree::write_json(s, cpu_root, false);

    json = s.str();
}

void LsJson::getMem(string &json) {
    ptree mem_root;

    mem_root.put("type", "mem");
    mem_root.put("time", std::time(nullptr));

    mem_root.put("total", ss.GetTotalRam());
    mem_root.put("free", ss.GetFreeRam());
    mem_root.put("shared", ss.GetSharedRam());
    mem_root.put("buffer", ss.GetBufferRam());
    mem_root.put("total_swap", ss.GetTotalSwapSize());
    mem_root.put("free_swap", ss.GetFreeSwapSize());
    mem_root.put("total_high_mem", ss.GetTotalHighMemSize());
    mem_root.put("available_high_mem", ss.GetAvailableHighMemSize());
    mem_root.put("mem_unit", ss.GetMemUnit());

    stringstream s;
    boost::property_tree::write_json(s, mem_root, false);

    json = s.str();
}
