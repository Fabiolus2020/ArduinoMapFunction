int Pot = A3;
int LedRed = 3; //PWM pin Arduino offer PIN 3,5,6,9,10,11 only)
int PotState = 0;
int UserSelection;

void ClearScreen() {
  for (int counter = 1; counter <= 15; counter++ ) {
    Serial.println(" ");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  //Main menu
step1:
 
  //Make sure the LED is off when starting the program.
  digitalWrite(LedRed, LOW);

  Serial.println("*********************************************");
  Serial.println("  Tool to observe difference between using   ");
  Serial.println("  map() function and not using map()function ");
  Serial.println("  Author Fabiolus                            ");
  Serial.println("                                             ");
  Serial.println("                                             ");
  Serial.println(" CHOICES ARE:                                ");
  Serial.println("                                             ");
  Serial.println("1 for Example 1 POT and map() Function using 0,1023 0,255      ");
  Serial.println("2 for example 2 POT and NO map() Function"    );
  Serial.println("3 for Example 3 POT and map() Function using 0,1023 -255,255      ");
  Serial.println("                                             ");
  Serial.println("                                             ");
  Serial.println("                                             ");
  Serial.println("*********************************************");
  //wait for an input
  while (Serial.available() == 0); {}

  // variable Userselection now holds the input from the user. We capture intgeger using parseInt()
  UserSelection = Serial.parseInt();


  //We make a decision based on the end user input
  if (UserSelection == 1) {
    goto example1;

  }

  if (UserSelection == 2) {
    goto example2;

  }
  if (UserSelection == 3) {
    goto example3;
  }else {
    Serial.println("Invalid Input!");
    delay(3000);
    ClearScreen();
    goto step1;
    }

  //demo showing AnalogRead with MAP Function
example1:
  ClearScreen();
  Serial.println("*********************************************");
  Serial.println("                                             ");
  Serial.println("                                             ");
  Serial.println("    PRESS 5 TO GO BACK AT ANYTIME            ");
  Serial.println("                                             ");
  Serial.println("                                             ");
  Serial.println("*********************************************");




  Serial.println("Example 1 will start in 5 seconds");
  //this start the countdown before the sketch start
  for (int counter = 1; counter <= 5; counter++) {
    delay(1000);
    Serial.println(counter);

  }
  delay(3000);
  ClearScreen();


  //Sketch 1
  //do while are great to build interactive menu without interompting the loop
  do {

    //set pin mode
    pinMode(Pot, INPUT);
    pinMode(LedRed, OUTPUT);
    //read the pot value
    PotState = analogRead(Pot);

    //apply map function
    PotState = map(PotState, 0, 1023, 0, 255);

    //apply value of pot to the LED pin
    analogWrite(LedRed, PotState);
    Serial.print("Analog value of POT: ");
    Serial.println (PotState);

  }
  //repeat sketch until input from end user
  while (Serial.available() == 0);

  // variable Userselection now holds the input from the user. We capture intgeger using parseInt()
  UserSelection = Serial.parseInt();

  // }

  //We make a decision based on end user input.
  if (UserSelection == 5) {
    ClearScreen();
    goto step1;
  } else {
    Serial.println("Invalid Input!");
    delay(2000);
    goto example1;
  }

  //demo showing AnalogRead without MAP Function
example2:
  ClearScreen();
  Serial.println("*********************************************");
  Serial.println("                                             ");
  Serial.println("                                             ");
  Serial.println("    PRESS 5 TO GO BACK AT ANYTIME            ");
  Serial.println("                                             ");
  Serial.println("                                             ");
  Serial.println("*********************************************");




  Serial.println("Example 2 will start in 5 seconds");

  //this start the countdown before the sketch start
  for (int counter = 1; counter <= 5; counter++) {
    delay(1000);
    Serial.println(counter);

  }
  delay(3000);
  ClearScreen();


  //sketch 2
  //do while are great to build interactive menu without interompting the loop
  do {
    //set pin mode
    pinMode(Pot, INPUT);
    pinMode(LedRed, OUTPUT);

    //read value from pot
    PotState = analogRead(Pot);

    //disable map()
    //PotState = map(PotState, 0, 1023, 0, 255);

    //apply value of pot to the LED pin
    analogWrite(LedRed, PotState);
    Serial.print("Analog value of POT: ");
    Serial.println (PotState);

  }
  //repeat sketch until input from end user
  while (Serial.available() == 0);

  // variable Userselection now holds the input from the user. We capture intgeger using parseInt()
  UserSelection = Serial.parseInt();


  //we make a decision based on end user input
  if (UserSelection == 5) {
    ClearScreen();
    goto step1;
  } else {
    Serial.println("Invalid Input!");
    delay(2000);
    goto example2;
  }


example3:
  ClearScreen();
  Serial.println("*********************************************");
  Serial.println("                                             ");
  Serial.println("                                             ");
  Serial.println("    PRESS 5 TO GO BACK AT ANYTIME            ");
  Serial.println("                                             ");
  Serial.println("                                             ");
  Serial.println("*********************************************");




  Serial.println("Example 3 will start in 5 seconds");

  //this start the countdown before the sketch start
  for (int counter = 1; counter <= 5; counter++) {
    delay(1000);
    Serial.println(counter);

  }
  delay(3000);
  ClearScreen();


  //sketch 2
  //do while are great to build interactive menu without interompting the loop
  do {
    //set pin mode
    pinMode(Pot, INPUT);
    pinMode(LedRed, OUTPUT);

    //read value from pot
    PotState = analogRead(Pot);

    //using map function 
    PotState = map(PotState, 0, 1023, -255, 255);

    //apply value of pot to the LED pin
    analogWrite(LedRed, PotState);
    Serial.print("Analog value of POT: ");
    Serial.println (PotState);

  }
  //repeat sketch until input from end user
  while (Serial.available() == 0);

  // variable Userselection now holds the input from the user. We capture intgeger using parseInt()
  UserSelection = Serial.parseInt();


  //we make a decision based on end user input
  if (UserSelection == 5) {
    ClearScreen();
    goto step1;
  } else {
    Serial.println("Invalid Input!");
    delay(2000);
    goto example3;
  }



  delay(10);
  exit(0);
}
