const int pin = 0;
const int vcc = 5;
const float midlevel = vcc/2.0;
const float quantlevel = 1024.0;

int indx = 0;
float block[320] = {0.0};
int t = 0;
int t_old = 0;
String sblock;


void setup() {
  Serial.begin(115200);
  
}

void loop() {
  t = micros();
  if((t - t_old) >= 62){
    block[indx] = ((analogRead(pin)/quantlevel)*vcc - midlevel); //Convert signal to valid sound signal
    t_old = t;
    indx++;
  }
  if(indx >= 320){
    for(int i=0; i<320; i++){
      //sblock += block[i];
      //sblock += ", ";
      Serial.print(block[i]);
      Serial.print(", ");
    }
    Serial.println();
    sblock = "";
    indx = 0;
  }
}

