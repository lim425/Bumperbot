// #define L298N_enB 11  // PWM
// #define L298N_in3 7  // Dir Motor B
// #define L298N_in4 8  // Dir Motor B

// #define right_encoder_phaseA 3  // Interrupt green
// #define right_encoder_phaseB 5  //yellow

// unsigned int right_encoder_counter = 0; // counts encoder ticks (pulses)
// String right_encoder_sign = "p";  // stores direction ("p" = positive, "n" = negative)
// double right_wheel_meas_vel = 0.0;    // rad/s

// double gear_reduction_ratio = 35.0; // 35:1 gearbox
// double tick_per_rotation = 11.0;  // 11 pulses per motor shaft revolution


// void setup() {

//   pinMode(L298N_enB, OUTPUT);
//   pinMode(L298N_in3, OUTPUT);
//   pinMode(L298N_in4, OUTPUT);
//   digitalWrite(L298N_in3, HIGH);
//   digitalWrite(L298N_in4, LOW);

//   Serial.begin(115200); 
//   pinMode(right_encoder_phaseB, INPUT);
//   attachInterrupt(digitalPinToInterrupt(right_encoder_phaseA), rightEncoderCallback, RISING);
// }

// void loop() {
//   right_wheel_meas_vel = (10 * right_encoder_counter * (60.0/(tick_per_rotation * gear_reduction_ratio))) * 0.10472;
//   String encoder_read = "r" + right_encoder_sign + String(right_wheel_meas_vel);
//   Serial.println(encoder_read);
//   right_encoder_counter = 0;
//   analogWrite(L298N_enB, 50);
//   delay(100);
// }


// void rightEncoderCallback()
// {
//   if(digitalRead(right_encoder_phaseB) == HIGH)
//   {
//     right_encoder_sign = "p";
//   }
//   else
//   {
//     right_encoder_sign = "n";
//   }
//   right_encoder_counter++;
// }

// ##########################################################################


#define L298N_enA 9  // PWM
#define L298N_in2 13  // Dir Motor A
#define L298N_in1 12  // Dir Motor A

#define left_encoder_phaseA 2  // Interrupt green
#define left_encoder_phaseB 4  //yellow

unsigned int left_encoder_counter = 0; // counts encoder ticks (pulses)
String left_encoder_sign = "p";  // stores direction ("p" = positive, "n" = negative)
double left_wheel_meas_vel = 0.0;    // rad/s

double gear_reduction_ratio = 35.0; // 35:1 gearbox
double tick_per_rotation = 11.0;  // 11 pulses per motor shaft revolution


void setup() {

  pinMode(L298N_enA, OUTPUT);
  pinMode(L298N_in1, OUTPUT);
  pinMode(L298N_in2, OUTPUT);
  digitalWrite(L298N_in1, HIGH);
  digitalWrite(L298N_in2, LOW);


  Serial.begin(115200);

  pinMode(left_encoder_phaseB, INPUT);
  attachInterrupt(digitalPinToInterrupt(left_encoder_phaseA), leftEncoderCallback, RISING);
}

void loop() {
  // 1 rpm = 0.10472 rad/s
  left_wheel_meas_vel = (10 * left_encoder_counter * (60.0/(tick_per_rotation * gear_reduction_ratio))) * 0.10472;
  String encoder_read = "l" + left_encoder_sign + String(left_wheel_meas_vel);
  Serial.println(encoder_read);
  left_encoder_counter = 0;
  analogWrite(L298N_enA, 0);
  delay(100);

}

void leftEncoderCallback()
{
  if(digitalRead(left_encoder_phaseB) == HIGH)
  {
    left_encoder_sign = "p";
  }
  else
  {
    left_encoder_sign = "n";
  }
  left_encoder_counter++;
}


