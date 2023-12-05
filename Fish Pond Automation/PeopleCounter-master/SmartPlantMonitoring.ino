// Include necessary libraries
#define BLYNK_PRINT Serial   
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>

// Define BLYNK_PRINT to use Serial for Blynk communication
#define BLYNK_PRINT Serial

// Include OneWire and DallasTemperature libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Define the digital pin for the OneWire bus
#define ONE_WIRE_BUS D2

// Create an instance of the OneWire and DallasTemperature objects
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Blynk authentication token
char auth[] ="----------------";

// WiFi credentials
char ssid[] = "-------";
char pass[] = "-------";

// Define the digital pin for the soil moisture sensor
#define sensorPin D3 

// Initialize variables to track sensor state
int sensorState = 0;
int lastState = 0;

// Define the DHT11 sensor pin and type
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Create a SimpleTimer object
SimpleTimer timer;

// Function to send humidity and temperature sensor data to Blynk
void sendSensor()
{
  // Read humidity and temperature from DHT sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if readings are valid
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  // Send humidity and temperature data to Blynk virtual pins
  Blynk.virtualWrite(V5, h); // V5 is for Humidity
  Blynk.virtualWrite(V6, t); // V6 is for Temperature
}

void setup()
{
  // Initialize Serial communication
  Serial.begin(9600);

  // Initialize Blynk communication with authentication and WiFi credentials
  Blynk.begin(auth, ssid, pass);

  // Set sensorPin as an input
  pinMode(sensorPin, INPUT);

  // Initialize DHT sensor
  dht.begin();

  // Set up timer to call sendSensor() function every 1000ms (1 second)
  timer.setInterval(1000L, sendSensor);

  // Initialize Serial communication again with a higher baud rate
  Serial.begin(115200);

  // Initialize Blynk communication again
  Blynk.begin(auth, ssid, pass);

  // Initialize the DallasTemperature sensors
  sensors.begin();
}

void sendTemps()
{
  // Read analog value from pin A0 (soil moisture sensor)
  sensor = analogRead(A0);

  // Request temperature readings from the DallasTemperature sensors
  sensors.requestTemperatures();

  // Get the temperature from the first sensor
  float temp = sensors.getTempCByIndex(0); 

  // Print temperature and sensor readings to Serial monitor
  Serial.println(temp);
  Serial.println(sensor);

  // Send temperature and sensor data to Blynk virtual pins
  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, sensor);

  // Delay to prevent rapid data updates
  delay(1000);
}

void loop()
{
  // Run Blynk communication
  Blynk.run();

  // Run timer events
  timer.run();

  // Call sendTemps() function to update temperature and sensor data
  sendTemps();
}