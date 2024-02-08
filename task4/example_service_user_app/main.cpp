// #include <aidl/example/service/api/BnExampleService.h>
// #include <utils/Log.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <android/binder_manager.h>

// namespace esapinamespace = ::aidl::example::service::api;
// using esapinamespace::IExampleService;
// using namespace esapinamespace;

// ::std::shared_ptr<esapinamespace::IExampleService> serviceObj = nullptr;
// const char* serviceName = "example.service.api.IExampleService/default";


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
//
	//esapinamespace::ExampleType* example_type = new esapinamespace::ExampleType();

	// if (serviceObj != nullptr)
	// {
	// 	serviceObj->getValues(example_type);
	// 	int64_t retval = example_type->retval;
	// 	std::vector<int32_t> cert = example_type->cert;

	// 	ALOGW ("%s:%d: Got retval: %d", __FUNCTION__, __LINE__,retval);
	// 	for (unsigned int i = 0; i< cert.size(); i++)
	// 	{
	// 		ALOGW ("%s:%d: Got cert[%d]: %d", __FUNCTION__, __LINE__,i,cert[i]);
	// 	}
	// }

	return 1;
}