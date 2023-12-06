
#define RED 7
#define GREEN 4
#define BLUE 5
#define CONTROL A2

#define flash_type 11
#define BASE_SINE_PERIOD_HZ 100
#define SCALAR 255
#define MAX_DEG_FOR_SINE_CALC 360
#define NUM_LEDS 3
#define SPEED_DIVIDER 100


double pct[3] = { 0, 0, 0 };
const String labels[3] = { "red ", "green ", "blue " };
String output = "";
String base_stuff = "base_val: ";
int num_steps = 360;
float sine_val = 0.0;
float rad = 0.0;
float sine_base = 0.0;
double pw_val = 0;
float control_signal = 0;
int pins[3] = { RED, GREEN, BLUE };
float power;
int i, j;
int ZERO = 0;
float converter = (PI / 180);
bool custom_speed = false;
const double step = PI / (MAX_DEG_FOR_SINE_CALC * (max(1,SPEED_DIVIDER)));


void setup() {
  Serial.begin(9600);
  Serial.println();
  // put your setup code here, to run once:
  for (i = 0; i < NUM_LEDS; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], true);
  }


  pinMode(CONTROL, INPUT);
  pinMode(flash_type, INPUT_PULLUP);
  ZERO = analogRead(CONTROL);
  attachInterrupt(digitalPinToInterrupt(flash_type), change_speed_type, CHANGE);
}

void loop() {

  for (double i = PI; i >= 0; i = i - step) {
    rad = i;

    control_signal = ((float)analogRead(CONTROL) / (float)ZERO) / 2;

    //rad = control_signal * 360 * converter / 2;

    rad = i;
    //Serial.println(custom_speed);

    output = "";
    for (int j = 0; j <= 2; j++) {
      power = pow(2, j);
      sine_base = abs(sin(rad * power));
      sine_val = (sine_base == 0) ? sine_base : abs(sine_base);
      pct[j] = sine_val * 100;
      pw_val = sine_val * 255;
      //output =  output + " power:" + String(power) + " " + String(pw_val);
      analogWrite(pins[j], pw_val);
    }
   // output = "Base: " + String(rad) + " " + output;
   // Serial.println(output);
  }
}

void change_speed_type() {
  custom_speed = !custom_speed;
  Serial.println("clicked");
}