const int redPin = 4;    // Red channel
const int greenPin = 0;  // Green channel
const int bluePin = 1;   // Blue channel

// Current color values
int currentRed = 0;
int currentGreen = 0;
int currentBlue = 0;

// Predefined maximum brightness
int MAX_BRIGHT = 64;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, 0);

  testChannels();
}

void loop() {
  IDAHO();
  ColorFade(2, 5);
  Morse();
  Breathe(2);
  Sparkle(3);
  ColorPyramid(1);
}

void ColorFade(int numLoops, int fadeTime)
{
  fadeTime *= 1000;
  for(int i = 0; i < numLoops; i++)
  {
    fadeToColor(MAX_BRIGHT, 0, 0, fadeTime);
    fadeToColor(0, MAX_BRIGHT, 0, fadeTime);
    fadeToColor(0, 0, MAX_BRIGHT, fadeTime);
  }

  fadeToColor(0, 0, 0, fadeTime);

  delay(2000);
}

void ColorPyramid(int fadeTime)
{
  fadeTime *= 1000;
  
  fadeToColor(MAX_BRIGHT, 0, 0, fadeTime);
  fadeToColor(MAX_BRIGHT, MAX_BRIGHT, 0, fadeTime);
  fadeToColor(MAX_BRIGHT, MAX_BRIGHT, MAX_BRIGHT, fadeTime);
  fadeToColor(0, MAX_BRIGHT, MAX_BRIGHT, fadeTime);
  fadeToColor(0, 0, MAX_BRIGHT, fadeTime);
  fadeToColor(0, 0, 0, fadeTime);

  delay(2000);
}

void Morse()
{
  int dotTime = 500;
  int dashTime = 1500;
  
  // I -> ..
  SetColor(0, MAX_BRIGHT, MAX_BRIGHT);
  delay(dotTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  SetColor(0, MAX_BRIGHT, MAX_BRIGHT);
  delay(dotTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  delay(dotTime);

  // D -> -..
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(dashTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(dotTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(dotTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  delay(dotTime);

  // A -> .-
  SetColor(MAX_BRIGHT, 0, MAX_BRIGHT);
  delay(dotTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  SetColor(MAX_BRIGHT, 0, MAX_BRIGHT);
  delay(dashTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  delay(dotTime);

  // H -> ....
  SetColor(0, 0, MAX_BRIGHT);
  delay(dotTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  SetColor(0, 0, MAX_BRIGHT);
  delay(dotTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  SetColor(0, 0, MAX_BRIGHT);
  delay(dotTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  SetColor(0, 0, MAX_BRIGHT);
  delay(dotTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  delay(dotTime);

  // O -> ---
  SetColor(0, MAX_BRIGHT, 0);
  delay(dashTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  SetColor(0, MAX_BRIGHT, 0);
  delay(dashTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  SetColor(0, MAX_BRIGHT, 0);
  delay(dashTime);
  SetColor(0, 0, 0);
  delay(dotTime);

  delay(2000);
}

void Sparkle(int duration) {
  duration *= 1000;
  while (duration > 0) {
    switch (random(7)) {  // 7 options for the switch
      case 0: // Red
        fadeToColor(MAX_BRIGHT, 0, 0, 100);
        break;
      case 1: // Green
        fadeToColor(0, MAX_BRIGHT, 0, 100);
        break;
      case 2: // Blue
        fadeToColor(0, 0, MAX_BRIGHT, 100);
        break;
      case 3: // Yellow (Red + Green)
        fadeToColor(MAX_BRIGHT, MAX_BRIGHT, 0, 100);
        break;
      case 4: // Cyan (Green + Blue)
        fadeToColor(0, MAX_BRIGHT, MAX_BRIGHT, 100);
        break;
      case 5: // Magenta (Red + Blue)
        fadeToColor(MAX_BRIGHT, 0, MAX_BRIGHT, 100);
        break;
      case 6: // White (Red + Green + Blue)
        fadeToColor(MAX_BRIGHT, MAX_BRIGHT, MAX_BRIGHT, 100);
        break;
    }
    delay(100);
    duration -= 100;
  }

  fadeToColor(0, 0, 0, 1000);  // Fade to black
  delay(2000);
}


void Breathe(int fadeTime)
{
  fadeTime *= 1000;
  // RED
  fadeToColor(MAX_BRIGHT, 0, 0, fadeTime);
  fadeToColor(0, 0, 0, fadeTime);

   // GREEN
  fadeToColor(0, MAX_BRIGHT, 0, fadeTime);
  fadeToColor(0, 0, 0, fadeTime);

  // BLUE
  fadeToColor(0, 0, MAX_BRIGHT, fadeTime);
  fadeToColor(0, 0, 0, fadeTime);

  delay(2000);
}

void IDAHO()
{
  int tempo = 145;
  int quarterNote = 60000/tempo;
  int eigthNote = quarterNote / 2;
  int sixteenth = eigthNote / 2;

  // I
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(quarterNote);
  fadeToZero(quarterNote);

  // D
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(quarterNote);
  fadeToZero(quarterNote);

  // A
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(eigthNote);
  fadeToZero(eigthNote);

  // H
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(eigthNote);
  fadeToZero(eigthNote);

  // O
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(eigthNote);
  fadeToZero(eigthNote);

  delay(quarterNote);

  // IDAHO
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  fadeToZero(eigthNote);

  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  fadeToZero(eigthNote);

  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  fadeToZero(eigthNote);

  delay(eigthNote);

  // IDAHO
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  fadeToZero(eigthNote);

  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  fadeToZero(eigthNote);

  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  fadeToZero(eigthNote);

  delay(eigthNote);
  
  // GO
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(eigthNote);
  fadeToZero(eigthNote);

  
  // GO
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(eigthNote);
  fadeToZero(eigthNote);

  
  // GO
  SetColor(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(eigthNote);
  fadeToZero(eigthNote);

  // Post effect delay
  delay(2000);
}

void fadeToZero(int duration)
{
  fadeToColor(0, 0, 0, duration);
}

// Function to fade RGB LED from current color to a new color
void fadeToColor(int targetRed, int targetGreen, int targetBlue, int duration) {
  const int fadeStep = 1;  // Increment/decrement step size
  
  // Calculate the total number of steps required
  int redSteps = abs(targetRed - currentRed);
  int greenSteps = abs(targetGreen - currentGreen);
  int blueSteps = abs(targetBlue - currentBlue);
  int totalSteps = max(max(redSteps, greenSteps), blueSteps);

  // Calculate delay per step to match the desired duration
  int fadeDelay = totalSteps > 0 ? duration / totalSteps : 0;

  while (currentRed != targetRed || currentGreen != targetGreen || currentBlue != targetBlue) {
    // Adjust red
    if (currentRed < targetRed) currentRed += fadeStep;
    else if (currentRed > targetRed) currentRed -= fadeStep;

    // Adjust green
    if (currentGreen < targetGreen) currentGreen += fadeStep;
    else if (currentGreen > targetGreen) currentGreen -= fadeStep;

    // Adjust blue
    if (currentBlue < targetBlue) currentBlue += fadeStep;
    else if (currentBlue > targetBlue) currentBlue -= fadeStep;

    // Write new values, scaled to MAX_BRIGHT
    analogWrite(redPin, constrain(currentRed, 0, MAX_BRIGHT));
    analogWrite(greenPin, constrain(currentGreen, 0, MAX_BRIGHT));
    analogWrite(bluePin, constrain(currentBlue, 0, MAX_BRIGHT));
    
    delay(fadeDelay);
  }
}


void SetColor(int r, int g, int b)
{
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);

  currentRed = r;
  currentGreen = g;
  currentBlue = b;
}

void testChannels() {
  analogWrite(redPin, 255);
  delay(1000);

  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  delay(1000);

  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  delay(1000);

  analogWrite(bluePin, 0);
  delay(1000);
}
