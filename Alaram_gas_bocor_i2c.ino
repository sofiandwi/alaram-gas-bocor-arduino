#include <Wire.h>
#include <LiquidCrystal_I2C.h> // memasukan libleri modul lcd i2c

LiquidCrystal_I2C lcd(0x27,16,2);  //addres dari lcd i2c 0x27 dengan lcd 16 x 2
const int pinAsap = A0;                      //inisialisasi pin sensor mq-2
const int pinSpeker = 8;                     //inisialisasi pin buzer
const int ledRed = 13;                       //inisialisasi pin LED

void setup() {
lcd.init();                      // inisialisasi lcd 
lcd.init();
lcd.backlight();
lcd.setCursor(3,0);                          
pinMode (ledRed, OUTPUT);                    //menetapkan pin 13 sebagai output
}

void loop() {
//digunakan untuk membaca data dari pin yang dihubungkan ke sensor
int dataAnalog = digitalRead (pinAsap);

//program untuk mengirimkan informasi aman ke LCD
if (dataAnalog == HIGH) {
  lcd.setCursor (0,0);
  lcd.print ("Sensor Kebakaran");
  lcd.setCursor (0,1);
  lcd.print ("     AMAN...    ");
  noTone(pinSpeker);
  digitalWrite (ledRed, LOW);
}

//program untuk mengirimkan informasi bahaya ke LCD
else if (dataAnalog == LOW){
lcd.setCursor (0,0);
lcd.print (" Mendeteksi Ada ");
lcd.setCursor (0,1);
lcd.print ("BAHAYA KEBAKARAN");

//program untuk menyalakan sirine
  // matikan LED
  digitalWrite( ledRed, LOW );
  // mainkan nada di pin#8 dg. frekuensi 1000Hz selama 300 ms
  tone( pinSpeker, 1000 );
  delay( 300 );
  // nyalakan LED
  digitalWrite( ledRed, HIGH );
  // mainkan nada di pin#8 dg. frekuensi 1318Hz selama 300 ms
  tone( pinSpeker, 1318 );
  delay( 300 );
}

}
