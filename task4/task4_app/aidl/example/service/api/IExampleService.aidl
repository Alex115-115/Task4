
package example.service.api;

interface IExampleService {
    
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
