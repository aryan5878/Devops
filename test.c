#include <iostream>

// Environment Sensor class
class EnvironmentSensor {
private:
    int season;
    float temperature;

public:
    EnvironmentSensor(int season, float temperature) {
        this->season = season;
        this->temperature = temperature;
    }

    // Getter methods
    int getSeason() {
        return season;
    }

    float getTemperature() {
        return temperature;
    }
};

// Water Heater class
class WaterHeater {
private:
    float currentTemperature;

public:
    // Setter method
    void setTemperature(float temperature) {
        currentTemperature = temperature;
    }

    // Getter method
    float getTemperature() {
        return currentTemperature;
    }
};

// Smart Geyser class
class SmartGeyser {
private:
    EnvironmentSensor sensor;
    WaterHeater heater;

public:
    SmartGeyser(EnvironmentSensor sensor) : sensor(sensor) {}

    void activateGeyser() {
        float currentTemperature = sensor.getTemperature();
        // Your logic to calculate required temperature based on season and current temperature
        float requiredTemperature = currentTemperature + 10; // Example logic
        heater.setTemperature(requiredTemperature);
    }

    // Getter method
    float getHeatingTemperature() {
        return heater.getTemperature();
    }
};

// Home Owner class
class HomeOwner {
public:
    void getOutOfBed(SmartGeyser& geyser) {
        geyser.activateGeyser();
    }
};

int main() {
    EnvironmentSensor sensor(1, 20.5); // Example values for season and temperature
    SmartGeyser geyser(sensor);
    HomeOwner owner;

    owner.getOutOfBed(geyser);
    std::cout << "Heating temperature: " << geyser.getHeatingTemperature() << std::endl;

    return 0;
}
