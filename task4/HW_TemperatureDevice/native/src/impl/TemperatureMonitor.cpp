#include <TemperatureMonitor.hpp>

  
size_t TemperatureMonitor::counter = 0;
int TemperatureMonitor::count1 = 0;
int TemperatureMonitor::count2 = 0;
int TemperatureMonitor::count3 = 0;
  
float TemperatureMonitor::IAmbient() 
{
    if(count1 >= 1)
    {
        count1 = 0;
        count2 = 0;
        count3 = 0;
    }

    if((count1 < 1) && (count2 < 1) && (count3 < 1))
    {
    UpdateTemperatureData();
    }
    count1++;

    
    return ambient; 
}
float TemperatureMonitor::ICpu() 
{
    if(count2 >= 1)
    {
        count1 = 0;
        count2 = 0;
        count3 = 0;
    }

    if((count1 < 1) && (count2 < 1) && (count3 < 1)) 
    {
        UpdateTemperatureData();
    }
    count2++;

    return cpu; 
}
float TemperatureMonitor::IGpu()  
{
    if(count3 >= 1)
    {
        count1 = 0;
        count2 = 0;
        count3 = 0;
    }

    if((count1 < 1) && (count2 < 1) && (count3 < 1)) 
    {
        UpdateTemperatureData();
    }
    count3++;

    return gpu; 
}

int32_t TemperatureMonitor::UpdateTemperatureData() {

    if (!file.is_open()) {
        file.open(file_path_);
        if (!file.is_open()) {
        ALOGW("Error: File Open\n");
        return -1; 
        }
        std::getline(file, line); 
    }

    file.seekg(0, std::ios::beg);
    std::getline(file, line); 

    for (size_t i = 0; i < counter; ++i) {
        std::getline(file, line);
    }


    if (!getline(file, line)) {
        file.clear(); 
        counter = 0; 
        return 1;
    }

    
    std::istringstream ss(line);
    std::string token;

    if (std::getline(ss, token, ',')) ambient = std::stof(token);
    if (std::getline(ss, token, ',')) cpu = std::stof(token);
    if (std::getline(ss, token, ',')) gpu = std::stof(token);
    

    ++counter; 

    return 0; 
}

