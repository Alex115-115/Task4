#include <aidl/android/hardware/temperatureDevice/BnTemperatureDevice.h>
#include <utils/Log.h>
#include <stdio.h>
#include <stdlib.h>
#include <android/binder_manager.h>

#include "ExampleService.hpp"
#include <utils/Log.h>

namespace esapinamespaceH = ::aidl::android::hardware::temperatureDevice;
using esapinamespaceH::ITemperatureDevice;
using namespace esapinamespaceH;

::std::shared_ptr<esapinamespaceH::ITemperatureDevice> serviceObj = nullptr;
const char* serviceName = "android.hardware.temperatureDevice.ITemperatureDevice/default";

#ifdef LOG_TAG
   #undef LOG_TAG
#endif
#define LOG_TAG "example_service"

namespace example {
namespace service {

::std::shared_ptr<ExampleService> ExampleService::S_INSTANCE = NULL;

::std::shared_ptr<ExampleService> ExampleService::getInstance()
{
   if (S_INSTANCE == NULL)
   {
      S_INSTANCE = ndk::SharedRefBase::make<ExampleService>();
   }
   return S_INSTANCE;
}

ExampleService::ExampleService()
{
   
}

ExampleService::~ExampleService()
{

}

::ndk::ScopedAStatus ExampleService::getValues(float* _aidl_return)
{
   *_aidl_return = 1.0f;
   return ndk::ScopedAStatus::ok();
}

static float cpuTemperature;
::ndk::ScopedAStatus ExampleService::getCpuTemperature(float* _aidl_return)
{
   serviceObj = esapinamespaceH::ITemperatureDevice::fromBinder(ndk::SpAIBinder(AServiceManager_checkService(serviceName)));
	if (serviceObj != nullptr)
	{
		ALOGW("%s:%d: Connect ITemperatureDevice API successful", __FUNCTION__, __LINE__);
	}
	else
	{
		ALOGW("%s:%d: Connect ITemperatureDevice API failed", __FUNCTION__, __LINE__);
	}

   serviceObj->getCpuTemperatureHW(_aidl_return );
   cpuTemperature = *_aidl_return;

   return ndk::ScopedAStatus::ok(); 
}

static float gpuTemperature;
::ndk::ScopedAStatus ExampleService::getGpuTemperature(float* _aidl_return)
{
   serviceObj = esapinamespaceH::ITemperatureDevice::fromBinder(ndk::SpAIBinder(AServiceManager_checkService(serviceName)));
	if (serviceObj != nullptr)
	{
		ALOGW("%s:%d: Connect ITemperatureDevice API successful", __FUNCTION__, __LINE__);
	}
	else
	{
		ALOGW("%s:%d: Connect ITemperatureDevice API failed", __FUNCTION__, __LINE__);
	}

   serviceObj->getGpuTemperatureHW(_aidl_return );
   gpuTemperature = *_aidl_return;

   return ndk::ScopedAStatus::ok();
}

static float ambientTemperature;
::ndk::ScopedAStatus ExampleService::getAmbientTemperature(float* _aidl_return)
{
   serviceObj = esapinamespaceH::ITemperatureDevice::fromBinder(ndk::SpAIBinder(AServiceManager_checkService(serviceName)));
	if (serviceObj != nullptr)
	{
		ALOGW("%s:%d: Connect ITemperatureDevice API successful", __FUNCTION__, __LINE__);
	}
	else
	{
		ALOGW("%s:%d: Connect ITemperatureDevice API failed", __FUNCTION__, __LINE__);
	}
   
   serviceObj->getAmbientTemperatureHW(_aidl_return );
   ambientTemperature = *_aidl_return;

   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ExampleService::getAverageCpuTemperature(float* _aidl_return)
{
   static float count;
   static float averageCpuTemperature;
   ++count;

   averageCpuTemperature += (cpuTemperature - averageCpuTemperature) / count;

   *_aidl_return = averageCpuTemperature;

   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ExampleService::getAverageGpuTemperature(float* _aidl_return)
{
   static float count;
   static float averageGpuTemperature;
   ++count;

   averageGpuTemperature += (gpuTemperature - averageGpuTemperature) / count;

   *_aidl_return = averageGpuTemperature;

   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus ExampleService::getAverageAmbientTemperature(float* _aidl_return)
{

   static float count;
   static float averageAmbientTemperature;
   ++count;

   averageAmbientTemperature += (ambientTemperature - averageAmbientTemperature) / count;

   *_aidl_return = averageAmbientTemperature;

   return ndk::ScopedAStatus::ok();
}

static float maxCpuTemperature = -999;
::ndk::ScopedAStatus ExampleService::getMaxCpuTemperature(float* _aidl_return)
{
   if (cpuTemperature > maxCpuTemperature) {
         maxCpuTemperature = cpuTemperature;
   }

   *_aidl_return = maxCpuTemperature;
   return ndk::ScopedAStatus::ok();
}

static float maxGpuTemperature = -999;
::ndk::ScopedAStatus ExampleService::getMaxGpuTemperature(float* _aidl_return)
{
   if (gpuTemperature > maxGpuTemperature) {
         maxGpuTemperature = gpuTemperature;
   }

   *_aidl_return = maxGpuTemperature;
   return ndk::ScopedAStatus::ok();
}

static float maxAmbientTemperature = -999;
::ndk::ScopedAStatus ExampleService::getMaxAmbientTemperature(float* _aidl_return)
{
   if (ambientTemperature > maxAmbientTemperature) {
         maxAmbientTemperature = ambientTemperature;
   }

   *_aidl_return = maxAmbientTemperature;
   return ndk::ScopedAStatus::ok();
}


}
}

