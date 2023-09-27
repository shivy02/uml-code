/**
 * @file ps7.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <boost/regex.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;

using boost::posix_time::ptime;
using boost::posix_time::time_duration;

int main(int argc, char* argv[]) {
    std::string fileName = argv[1];
    std::ifstream logFile(fileName.c_str());
    // logFile.open(fileName);
    std::ofstream rptFile(fileName + ".rpt", std::ostream::out);
    // rptFile.open(fileName + ".rpt");
    date d;
    ptime startT;
    std::string line;

    // to check if there are two startups back to back
    bool boot = false;
    int lineNum = 1, bootTime = 0;

    // declare regex that we are looking for
    boost::regex beginBoot(
        "([0-9]{4})-([0-9]{2})-([0-9]{2}) "
        "([0-9]{2}):([0-9]{2}):([0-9]{2}): "
        "\\(log.c.166\\) server started");
    boost::regex endBoot(
        "([0-9]{4})-([0-9]{2})-([0-9]{2}) "
        "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):"
        "INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080");


    if (logFile.is_open()) {
        while (std::getline(logFile, line)) {
            boost::smatch sm;
            if (regex_search(line, sm, beginBoot)) {
                date tempStartDate(stoi(sm[1]), stoi(sm[2]), stoi(sm[3]));
                d = tempStartDate;
                ptime tempStartTime(d, time_duration(stoi(sm[4]), stoi(sm[5]), stoi(sm[6])));
                startT = tempStartTime;
                if (boot) {
                    rptFile << "**** Incomplete boot ****\n" << std::endl;
                    boot = false;
                }
                rptFile << "==== Device boot ====\n"
                           << lineNum << "(" << fileName << "):"
                           << sm[1] << "-" << sm[2] << "-" << sm[3]
                           << " " << sm[4] << ":" << sm[5] << ":" << sm[6]
                           << " Boot Start" << std::endl;

                boot = true;
            }
            if (regex_match(line, sm, endBoot)) {
                date tempEndDate(stoi(sm[1]), stoi(sm[2]), stoi(sm[3]));
                ptime endT(tempEndDate, time_duration(stoi(sm[4]), stoi(sm[5]), stoi(sm[6])));
                rptFile << lineNum << "(" << fileName << "):"
                           << sm[1] << "-" << sm[2] << "-" << sm[3]
                           << " " << sm[4] << ":" << sm[5] << ":" << sm[6]
                           << " Boot Completed" << std::endl;

                time_duration timeD = endT - startT;
                bootTime = timeD.total_milliseconds();
                rptFile << "Boot Time: " << bootTime << "ms\n" << std::endl;
                boot = false;
            }
            lineNum++;
        }
    }
    rptFile.close();
    logFile.close();
    return 0;
}

