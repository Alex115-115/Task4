#include <aidl/android/hardware/temperatureDevice/BnTemperatureDevice.h>
#include <utils/Log.h>
#include <stdio.h>
#include <stdlib.h>
#include <android/binder_manager.h>

namespace esapinamespaceH = ::aidl::android::hardware::temperatureDevice;
using esapinamespaceH::ITemperatureDevice;
using namespace esapinamespaceH;

::std::shared_ptr<esapinamespaceH::ITemperatureDevice> serviceObj = nullptr;
const char* serviceName = "android.hardware.temperatureDevice.ITemperatureDevice/default";


int main (void)
{
	ALOGW("Starting.\n");
	serviceObj = esapinamespaceH::ITemperatureDevice::fromBinder(ndk::SpAIBinder(AServiceManager_checkService(serviceName)));
	if (serviceObj != nullptr)
	{
		ALOGW("%s:%d: Connect ITemperatureDevice2 API successful", __FUNCTION__, __LINE__);
	}
	else
	{
		ALOGW("%s:%d: Connect ITemperatureDevice2 API failed", __FUNCTION__, __LINE__);
		return 0;
	}

	return 1;
}
