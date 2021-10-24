
#include <IRremote.h>
#include "HID-Project.h" //https://github.com/NicoHood/HID

IRrecv irrecv(A2); // указываем пин, к которому подключен IR приемник
decode_results results;

void setup() {
   irrecv.enableIRIn();  // запускаем прием инфракрасного сигнала
  delay(1000);
  Serial.begin(9600);  
  pinMode(A2, INPUT); // пин A2 будет входом ИК

  Consumer.begin(); 
    
}

void loop() {


   if (irrecv.decode(&results)) // если данные пришли выполняем команды
   {
    Serial.println(results.value); // отправляем полученные данные на порт
  if(results.value == 16750695)
  { 
      Consumer.write(MEDIA_VOLUME_DOWN); 
      delay(50);

  }
  if(results.value == 16734375)
      Consumer.write(MEDIA_VOLUME_UP); 
      delay(50);

{
  
  }
irrecv.resume(); // принимаем следующий сигнал на ИК приемнике
 }


}
