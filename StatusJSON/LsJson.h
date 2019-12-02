//
// Created by vl_sys on 2019-12-03.
//
// 리눅스의 상태를 json으로 만듭니다.
//

#ifndef SERVERSOCKETINFO_LSJSON_H
#define SERVERSOCKETINFO_LSJSON_H

#include "../LinuxStatus/Linuxstatus.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace LinuxStats;
using boost::property_tree::ptree;
using namespace std;

class LsJson {
private:
    SystemName name;
    ProcessStatus ps;
    CpuStatus cs;
    SysStatus ss;

public:
    void getSystemName(string & json);
    void getProcs(string & json);
    void getCpus(string & json);
    void getMem(string & json);
};


#endif //SERVERSOCKETINFO_LSJSON_H
