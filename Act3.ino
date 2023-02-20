// Declaring Global Constants
const byte LED_PIN = 13;
const byte METER_PIN = A4;
int timeComp;

void setup()
{
    // Setting pinMode
    pinMode(LED_PIN, OUTPUT);
    pinMode(METER_PIN, INPUT);
    Serial.begin(9600);
    startTimer();
}

void loop()
{
    // Reading values
    double val = analogRead(METER_PIN);
    val = val / 1000;

    // Calculationg Waiting Time
    timeComp = (16000000 / (1024 * val)) - 1;
    delay(500);
}

void startTimer()
{

    // Disabling the timer
    noInterrupts();

    // Initialising Timer
    TCCR1A = 0;
    TCCR1B = 0;

    TCNT1 = timeComp;
    TCCR1B |= (1 << CS12);

    // Enable timer interrupt
    TIMSK1 |= (1 << OCIE1A);
    interrupts();
}

// Interrupt service: Comparison
ISR(TIMER1_COMPA_vect)
{
    TCNT1 = timeComp;

    // LED State Changes
    digitalWrite(LED_PIN, digitalRead(LED_PIN) ^ 1);
}

const byte LED_PIN = 13;
const byte METER_PIN = A4;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(METER_PIN, INPUT);

    Serial.begin(9600);

    startTimer();
}

void loop()
{
}

void startTimer()
{
    noInterrupts();

    interrupts();
}

ISR(TIMER1_COMPA_vect)
{
    digitalWrite(LED_PIN, digitalRead(LED_PIN) ^ 1);
}
