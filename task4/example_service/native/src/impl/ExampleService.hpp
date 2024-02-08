 
#ifndef EXAMPLE_SERVICE
#define EXAMPLE_SERVICE

#include <aidl/example/service/api/BnExampleService.h>

namespace esapinamespace = ::aidl::example::service::api;

namespace example {
namespace service {

class ExampleService
   : public ::aidl::example::service::api::BnExampleService
{
public:
   ExampleService();
   ~ExampleService();

   static ::std::shared_ptr<ExampleService> getInstance();

   // IExampleService AIDL interface callbacks
   // ::ndk::ScopedAStatus getCpuTemperature(float* _aidl_return);

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
   // ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) ;
   // ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) ;


   const std::string getServiceName(void)
   {
      return std::string() + descriptor + "/default";
   }

private:
   static ::std::shared_ptr<ExampleService> S_INSTANCE;

};

}
}


#endif  // EXAMPLE_SERVICE
