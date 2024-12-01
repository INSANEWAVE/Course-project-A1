unsigned long next_time;
unsigned long second_next_time; // время очередного переключения первого светодиода
int timeout = 10;
int timeout2 = 1000; // половина периода мигания
int sensorPin = A0;   // Пин, к которому подключен фоторезистор
int sensorValue = 0;   // Переменная для хранения значения с фоторезистора
int counter = 0;
void setup() {
  Serial.begin(9600);   // Инициализация Serial для вывода данных на монитор
  next_time = millis() + timeout;
  second_next_time = millis() + timeout2; // вычисляем время следующего переключения
}

void loop() {
  int now_time = millis();                          
  sensorValue = analogRead(sensorPin);            
  float voltage = sensorValue * (5.0 / 1023.0);     
                 
    if( now_time >= next_time ){               
        next_time = now_time + timeout;
          if(voltage < 4){
    counter++;
  }       
         
         }
   if( now_time >= second_next_time ){               
        next_time = now_time + timeout;
          float RPM = counter/0.5;
          Serial.println(RPM);
          counter = 0;
         } 
        
}

