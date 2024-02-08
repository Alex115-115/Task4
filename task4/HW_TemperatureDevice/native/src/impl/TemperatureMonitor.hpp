#ifndef TEMPERATURE_MONITOR
#define TEMPERATURE_MONITOR

#include <utils/Log.h>

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>


class TemperatureMonitor {
private:
   float ambient = 8;
   float cpu;
   float gpu;

   std::string file_path_ = "/vendor/etc/temperature.csv";
   std::ifstream file;
   std::string line;

   static size_t counter;
   static int count1;
   static int count2;
   static int count3;

   float IAmbient();
   float ICpu();
   float IGpu();

   int32_t UpdateTemperatureData();


public:
   static TemperatureMonitor& Get()
   {
      static TemperatureMonitor instance;
      return instance;
   }
   
   static float Ambient() { return Get().IAmbient(); }
   static float Cpu() { return Get().ICpu(); }
   static float Gpu() { return Get().IGpu(); }

};

#endif  // TEMPERATURE_MONITOR
