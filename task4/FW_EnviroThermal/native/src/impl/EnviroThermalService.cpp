#include <aidl/android/hardware/temperatureDevice/BnTemperatureDevice.h>
#include <utils/Log.h>
#include <stdio.h>
#include <stdlib.h>
#include <android/binder_manager.h>

#include "EnviroThermalService.hpp"
#include <utils/Log.h>

namespace esapinamespaceH = ::aidl::android::hardware::temperatureDevice;
using esapinamespaceH::ITemperatureDevice;
using namespace esapinamespaceH;

::std::shared_ptr<esapinamespaceH::ITemperatureDevice> serviceObj = nullptr;
const char* serviceName = "android.hardware.temperatureDevice.ITemperatureDevice/default";

#ifdef LOG_TAG
   #undef LOG_TAG
#endif
#define LOG_TAG "enviro_thermal_service"

namespace enviro_thermal_service {
namespace service {

::std::shared_ptr<EnviroThermalService> EnviroThermalService::S_INSTANCE = NULL;

::std::shared_ptr<EnviroThermalService> EnviroThermalService::getInstance()
{
   if (S_INSTANCE == NULL)
   {
      S_INSTANCE = ndk::SharedRefBase::make<EnviroThermalService>();
   }
   return S_INSTANCE;
}

EnviroThermalService::EnviroThermalService(){}

EnviroThermalService::~EnviroThermalService(){}

void initServiceObj() 
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
}

::ndk::ScopedAStatus EnviroThermalService::getValues(float* _aidl_return)
{
   *_aidl_return = 1.0f;
   return ndk::ScopedAStatus::ok();
}

static float cpuTemperature;
::ndk::ScopedAStatus EnviroThermalService::getCpuTemperature(float* _aidl_return)
{
   
   initServiceObj();
   serviceObj->getCpuTemperatureHW(_aidl_return );
   cpuTemperature = *_aidl_return;

   return ndk::ScopedAStatus::ok(); 
}

static float gpuTemperature;
::ndk::ScopedAStatus EnviroThermalService::getGpuTemperature(float* _aidl_return)
{
   initServiceObj();
   serviceObj->getGpuTemperatureHW(_aidl_return );
   gpuTemperature = *_aidl_return;

   return ndk::ScopedAStatus::ok();
}

static float ambientTemperature;
::ndk::ScopedAStatus EnviroThermalService::getAmbientTemperature(float* _aidl_return)
{
   initServiceObj();
   serviceObj->getAmbientTemperatureHW(_aidl_return );
   ambientTemperature = *_aidl_return;

   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus EnviroThermalService::getAverageCpuTemperature(float* _aidl_return)
{
   static float count;
   static float averageCpuTemperature;
   ++count;

   averageCpuTemperature += (cpuTemperature - averageCpuTemperature) / count;

   *_aidl_return = averageCpuTemperature;

   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus EnviroThermalService::getAverageGpuTemperature(float* _aidl_return)
{
   static float count;
   static float averageGpuTemperature;
   ++count;

   averageGpuTemperature += (gpuTemperature - averageGpuTemperature) / count;

   *_aidl_return = averageGpuTemperature;

   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus EnviroThermalService::getAverageAmbientTemperature(float* _aidl_return)
{

   static float count;
   static float averageAmbientTemperature;
   ++count;

   averageAmbientTemperature += (ambientTemperature - averageAmbientTemperature) / count;

   *_aidl_return = averageAmbientTemperature;

   return ndk::ScopedAStatus::ok();
}

static float maxCpuTemperature = -999;
::ndk::ScopedAStatus EnviroThermalService::getMaxCpuTemperature(float* _aidl_return)
{
   if (cpuTemperature > maxCpuTemperature) {
         maxCpuTemperature = cpuTemperature;
   }

   *_aidl_return = maxCpuTemperature;
   return ndk::ScopedAStatus::ok();
}

static float maxGpuTemperature = -999;
::ndk::ScopedAStatus EnviroThermalService::getMaxGpuTemperature(float* _aidl_return)
{
   if (gpuTemperature > maxGpuTemperature) {
         maxGpuTemperature = gpuTemperature;
   }

   *_aidl_return = maxGpuTemperature;
   return ndk::ScopedAStatus::ok();
}

static float maxAmbientTemperature = -999;
::ndk::ScopedAStatus EnviroThermalService::getMaxAmbientTemperature(float* _aidl_return)
{
   if (ambientTemperature > maxAmbientTemperature) {
         maxAmbientTemperature = ambientTemperature;
   }

   *_aidl_return = maxAmbientTemperature;
   return ndk::ScopedAStatus::ok();
}


}
}

