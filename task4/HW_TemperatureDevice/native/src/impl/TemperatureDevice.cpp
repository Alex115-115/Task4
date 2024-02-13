
#include "TemperatureDevice.hpp"
#include <utils/Log.h>

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>

#include <TemperatureMonitor.hpp>

#ifdef LOG_TAG
   #undef LOG_TAG
#endif
#define LOG_TAG "temperatureDevice_service"

namespace android {
namespace hardware {

struct TemperatureData {
   float ambient;
   float cpu;
   float gpu;
};

TemperatureData temperatureData;

::std::shared_ptr<TemperatureDevice> TemperatureDevice::S_INSTANCE = NULL;

::std::shared_ptr<TemperatureDevice> TemperatureDevice::getInstance()
{
   if (S_INSTANCE == NULL)
   {
      S_INSTANCE = ndk::SharedRefBase::make<TemperatureDevice>();
   }
   return S_INSTANCE;
}

TemperatureDevice::TemperatureDevice(){}

TemperatureDevice::~TemperatureDevice(){}

::ndk::ScopedAStatus TemperatureDevice::getAmbientTemperatureHW(float* _aidl_return)
{
  
   *_aidl_return = TemperatureMonitor::Ambient();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus TemperatureDevice::getCpuTemperatureHW(float* _aidl_return)
{
   *_aidl_return = TemperatureMonitor::Cpu();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus TemperatureDevice::getGpuTemperatureHW(float* _aidl_return)
{
   *_aidl_return = TemperatureMonitor::Gpu();
   return ndk::ScopedAStatus::ok();
}

}
}
