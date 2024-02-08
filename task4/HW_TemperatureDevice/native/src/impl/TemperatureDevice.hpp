 
#ifndef TEMPERATURE_DEVICE_SERVICE
#define TEMPERATURE_DEVICE_SERVICE

#include <aidl/android/hardware/temperatureDevice/BnTemperatureDevice.h>

namespace esapinamespace = ::aidl::android::hardware::temperatureDevice;

namespace android {
namespace hardware {

class TemperatureDevice
   : public ::aidl::android::hardware::temperatureDevice::BnTemperatureDevice
{
public:
   TemperatureDevice();
   ~TemperatureDevice();

   static ::std::shared_ptr<TemperatureDevice> getInstance();

   ::ndk::ScopedAStatus getAmbientTemperatureHW(float* _aidl_return);
   ::ndk::ScopedAStatus getCpuTemperatureHW(float* _aidl_return);
   ::ndk::ScopedAStatus getGpuTemperatureHW(float* _aidl_return);


   const std::string getServiceName(void)
   {
      return std::string() + descriptor + "/default";
   }

private:
   static ::std::shared_ptr<TemperatureDevice> S_INSTANCE;

};

}
}


#endif  // TEMPERATURE_DEVICE_SERVICE
