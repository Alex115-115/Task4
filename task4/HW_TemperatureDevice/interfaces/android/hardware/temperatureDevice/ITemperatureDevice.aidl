
package android.hardware.temperatureDevice;

@VintfStability
interface ITemperatureDevice {

    float getAmbientTemperatureHW();
    float getCpuTemperatureHW();
    float getGpuTemperatureHW();
    
}
