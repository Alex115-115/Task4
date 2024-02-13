package com.example.task4

import android.os.Bundle
import android.os.Handler
import android.os.IBinder
import android.os.Looper
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import enviro_thermal_service.service.api.IEnviroThermalService

class MainActivity : AppCompatActivity() {

  private lateinit var handler: Handler
  private lateinit var serviceInterface: IEnviroThermalService

  override fun onCreate(savedInstanceState: Bundle?) 
  {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.main)

    handler = Handler(Looper.getMainLooper())


    val serviceManagerClass = Class.forName("android.os.ServiceManager")
    val getServiceMethod = serviceManagerClass.getMethod("getService", String::class.java)
    val binder = getServiceMethod.invoke(null, "enviro_thermal_service.service.api.IEnviroThermalService/default") as IBinder
    serviceInterface = IEnviroThermalService.Stub.asInterface(binder)

    handler.postDelayed(object : Runnable 
    {
      override fun run() 
      {
          updateStatistics()
          handler.postDelayed(this, 1000)
      }
    }, 1000)
  }


  private fun updateStatistics() 
  {
    try 
    {
      val cpuTemperature = serviceInterface.getCpuTemperature()
      findViewById<TextView>(R.id.cpuTemperatureText).text = "CPU Temperature: $cpuTemperature"

      val gpuTemperature = serviceInterface.getGpuTemperature()
      findViewById<TextView>(R.id.gpuTemperatureText).text = "GPU Temperature: $gpuTemperature"

      val ambientTemperature = serviceInterface.getAmbientTemperature()
      findViewById<TextView>(R.id.ambientTemperatureText).text = "Ambient Temperature: $ambientTemperature"

      val averageCpuTemperature = serviceInterface.getAverageCpuTemperature()
      findViewById<TextView>(R.id.averageCpuTemperatureText).text = "Average CPU Temperature: $averageCpuTemperature"

      val averageGpuTemperature = serviceInterface.getAverageGpuTemperature()
      findViewById<TextView>(R.id.averageGpuTemperatureText).text = "Average GPU Temperature: $averageGpuTemperature"

      val averageAmbientTemperature = serviceInterface.getAverageAmbientTemperature()
      findViewById<TextView>(R.id.averageAmbientTemperatureText).text = "Average Ambient Temperature: $averageAmbientTemperature"

      val maxCpuTemperature = serviceInterface.getMaxCpuTemperature()
      findViewById<TextView>(R.id.maxCpuTemperatureText).text = "Max CPU Temperature: $maxCpuTemperature"

      val maxGpuTemperature = serviceInterface.getMaxGpuTemperature()
      findViewById<TextView>(R.id.maxGpuTemperatureText).text = "Max GPU Temperature: $maxGpuTemperature"

      val maxAmbientTemperature = serviceInterface.getMaxAmbientTemperature()
      findViewById<TextView>(R.id.maxAmbientTemperatureText).text = "Max Ambient Temperature: $maxAmbientTemperature"

    } catch (e: Exception) 
    {
      e.printStackTrace()
    }
  }
  

  override fun onDestroy() 
  {
      super.onDestroy()
      handler.removeCallbacksAndMessages(null)
  }
}
