 
#ifndef ENVIRO_THERMAL_SERVICE
#define ENVIRO_THERMAL_SERVICE

#include <aidl/enviro_thermal_service/service/api/BnEnviroThermalService.h>

namespace esapinamespace = ::aidl::enviro_thermal_service::service::api;

namespace enviro_thermal_service {
namespace service {

class EnviroThermalService
   : public ::aidl::enviro_thermal_service::service::api::BnEnviroThermalService
{
public:
   EnviroThermalService();
   ~EnviroThermalService();

   static ::std::shared_ptr<EnviroThermalService> getInstance();

   ::ndk::ScopedAStatus getValues(float* _aidl_return);

   ::ndk::ScopedAStatus getCpuTemperature(float* _aidl_return);
   ::ndk::ScopedAStatus getGpuTemperature(float* _aidl_return) ;
   ::ndk::ScopedAStatus getAmbientTemperature(float* _aidl_return) ;
   ::ndk::ScopedAStatus getAverageCpuTemperature(float* _aidl_return) ;
   ::ndk::ScopedAStatus getAverageGpuTemperature(float* _aidl_return) ;
   ::ndk::ScopedAStatus getAverageAmbientTemperature(float* _aidl_return) ;
   ::ndk::ScopedAStatus getMaxCpuTemperature(float* _aidl_return) ;
   ::ndk::ScopedAStatus getMaxGpuTemperature(float* _aidl_return) ;
   ::ndk::ScopedAStatus getMaxAmbientTemperature(float* _aidl_return) ;
  
   const std::string getServiceName(void)
   {
      return std::string() + descriptor + "/default";
   }

private:
   static ::std::shared_ptr<EnviroThermalService> S_INSTANCE;

};

}
}

#endif  // ENVIRO_THERMAL_SERVICE
