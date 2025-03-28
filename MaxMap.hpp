#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <vector>

float consultMax(const std::string& search_term, const std::map<std::string, std::vector<float>>& data) {
    //implement your function here
    float max;
    if (data.find(search_term) != data.end()) {
      max = data.at(search_term).at(0);
      for (size_t i = 0; i < data.at(search_term).size(); i++) {
        if (data.at(search_term).at(i) > max) {
          max = data.at(search_term).at(i);
        }
      }
    } else {
      max = -1.f;
      }
    return max;
}

std::map<std::string, float> returnMaxMap(const std::map<std::string, std::vector<float>>& in_map) {
    //implement your function here
    std::map<std::string, float> maxMap;
    for (auto iter = in_map.begin(); iter != in_map.end(); iter++) {
      float max = consultMax(iter->first, in_map);
      if (max != -1) {
        maxMap.emplace(iter->first, max);
        }
      else {
          maxMap.emplace(iter->first, -1.f);
          }
    }
    return maxMap;
}