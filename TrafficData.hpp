#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, int> loadTrafficData(const std::string& filename) {
  //implement your function here!
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "-1" << std::endl;
  }
  std::map<std::string, int> trafficData;
  std::string line;
  while (std::getline(file, line)) {
    std::string airport_code = line.substr(line[0], line.find(','));
    int numPassengers = stoi(line.substr(line.find(',') + 1, line.size()));
    trafficData[airport_code] = numPassengers;
  }
  return trafficData;
}

void updateTrafficData(const std::string& filename, std::map<std::string, int>& dataMap) {
    //implement your function here!
    auto trafficData = loadTrafficData(filename);
    for (auto iter = trafficData.begin(); iter != trafficData.end(); iter++) {
      dataMap[iter->first] = iter->second;
    }
}