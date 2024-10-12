# Three major design patterns with real-life coding examples in C++

1. **Singleton Pattern:** The Singleton Pattern ensures that a class has only one instance and provides a global point of access to it.
2. **Observer Pattern:** The Observer Pattern defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.
3. **Factory Pattern:** The Factory Pattern defines an interface for creating an object, but lets subclasses alter the type of objects that will be created.

- **Singleton Pattern**<br>
Real-life Example: Database Connection Pool: Ensures only one instance of the connection pool is created to manage database connections.

`DatabaseConnectionPool.h`
```cpp
#pragma once

#include <iostream>

class DatabaseConnectionPool {
public:
    // Public method to get the single instance of the class
    static DatabaseConnectionPool* getInstance() {
        if (instance == nullptr) {
            instance = new DatabaseConnectionPool();
        }
        return instance;
    }

    void getConnection() {
        std::cout << "Returning a database connection" << std::endl;
    }

private:
    // Private constructor to prevent instantiation
    DatabaseConnectionPool() {
        std::cout << "DatabaseConnectionPool Created" << std::endl;
    }

    // Delete copy constructor and assignment operator to prevent copying
    DatabaseConnectionPool(const DatabaseConnectionPool&) = delete;
    DatabaseConnectionPool& operator=(const DatabaseConnectionPool&) = delete;

    // Static member to hold the single instance of the class
    static DatabaseConnectionPool* instance;
};
```

`DatabaseConnectionPool.cpp`
```cpp
// Initialize the static member
#include "DatabaseConnectionPool.h"

DatabaseConnectionPool* DatabaseConnectionPool::instance = nullptr;
```

// Usage main file
```cpp
int main() {
    DatabaseConnectionPool* pool = DatabaseConnectionPool::getInstance();
    pool->getConnection();
    return 0;
}
```

- **Observer Pattern** <br>

Real-life Example: Weather Monitoring System: When the weather station updates the weather data, all the display elements (observers) are updated.
```cpp
#include <iostream>
#include <vector>
#include <memory>

class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

class WeatherData {
private:
    std::vector<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    void registerObserver(Observer* o) {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) {
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notifyObservers() {
        for (auto observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void measurementsChanged() {
        notifyObservers();
    }

    void setMeasurements(float temperature, float humidity, float pressure) {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }
};

class CurrentConditionsDisplay : public Observer {
private:
    float temperature;
    float humidity;

public:
    void update(float temperature, float humidity, float pressure) override {
        this->temperature = temperature;
        this->humidity = humidity;
        display();
    }

    void display() {
        std::cout << "Current conditions: " << temperature << "F degrees and " << humidity << "% humidity" << std::endl;
    }
};

// Usage
int main() {
    WeatherData weatherData;
    CurrentConditionsDisplay currentDisplay;

    weatherData.registerObserver(&currentDisplay);
    weatherData.setMeasurements(80, 65, 30.4f);

    return 0;
}
```
- **Factory Pattern** <br>
Real-life Example: Notification System: Depending on the type of notification (SMS, Email, Push), the factory can create the appropriate object.
```cpp
#include <iostream>
#include <memory>

class Notification {
public:
    virtual void notifyUser() = 0;
};

class SMSNotification : public Notification {
public:
    void notifyUser() override {
        std::cout << "Sending an SMS notification" << std::endl;
    }
};

class EmailNotification : public Notification {
public:
    void notifyUser() override {
        std::cout << "Sending an Email notification" << std::endl;
    }
};

class PushNotification : public Notification {
public:
    void notifyUser() override {
        std::cout << "Sending a Push notification" << std::endl;
    }
};

class NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification(const std::string& type) {
        if (type == "SMS") {
            return std::make_unique<SMSNotification>();
        } else if (type == "EMAIL") {
            return std::make_unique<EmailNotification>();
        } else if (type == "PUSH") {
            return std::make_unique<PushNotification>();
        } else {
            throw std::invalid_argument("Unknown notification type " + type);
        }
    }
};

// Usage
int main() {
    NotificationFactory factory;
    
    auto notification = factory.createNotification("EMAIL");
    notification->notifyUser();
    
    return 0;
}
```
