
package enviro_thermal_service.service.api;

interface IEnviroThermalService {
    
    float getValues();
    float getCpuTemperature();
    float getGpuTemperature();
    float getAmbientTemperature();
    float getAverageCpuTemperature();
    float getAverageGpuTemperature();
    float getAverageAmbientTemperature();
    float getMaxCpuTemperature();
    float getMaxGpuTemperature();
    float getMaxAmbientTemperature();

}
