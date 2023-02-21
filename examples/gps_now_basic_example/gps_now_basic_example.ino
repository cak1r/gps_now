#include <gps_now.h>
#include <TinyGPS.h>

//create a TinyGPS variable
TinyGPS gps;

void setup() {
  //start serial monitor
  Serial.begin(9600);
}

void loop() {
  
    gps_now_print(16,17,9600,gps,1000);         //gps_now_print(RX, TX, baudrate, TinyGPS gps, MS);  
                                                //Prints a serial monitor
                                                /*
                                                 *  !!! Don't forget to change 
                                                 *  the parameters according 
                                                 *  to the project
                                                 */
    
    
    
    
    gps_now_get(16,17,9600,gps,1000);           //gps_now_get(RX, TX, baudrate, TinyGPS gps, MS);
                                                // Returns a variable of type gps_now
}                                               //Prints a serial monitor
                                                /*
                                                 *  !!! Don't forget to change 
                                                 *  the parameters according 
                                                 *  to the project
                                                 */
                                                 
