#define SET_HOUR_PIN 3
#define SET_MINUTE_PIN 2
#define HOUR_DDR DDRC
#define HOUR_PORT PORTC
#define MINUTE_DDR DDRB
#define MINUTE_PORT PORTB

unsigned long previousMillis = 0;

/**
 * Increment hour
 *
 * @author Gustavo Franco
 * @since  2011-05-06
 */
void incrementHour() {
    if (HOUR_PORT >= 23) {
        HOUR_PORT = 0;
    } else {
        HOUR_PORT++;
    }
}

/**
 * Increment minute
 *
 * @author Gustavo Franco
 * @since  2011-05-06
 */
void incrementMinute() {
    if (MINUTE_PORT >= 59) {
        MINUTE_PORT = 0;
    } else {
        MINUTE_PORT++;
    }
}

/**
 * Setup method
 *
 * @author Gustavo Franco
 * @since  2011-05-06
 */
void setup() {
    HOUR_DDR    = B00011111;
    MINUTE_DDR  = B00111111;

    attachInterrupt(0, incrementHour, LOW);
    attachInterrupt(1, incrementMinute, LOW);
}

/**
 * Main method
 *
 * @author Gustavo Franco
 * @since  2011-05-06
 */
void loop() {
    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis >= 60000) {
        previousMillis = currentMillis;

        if (MINUTE_PORT >= 59) {
            MINUTE_PORT = 0;

            if (HOUR_PORT >= 23) {
                HOUR_PORT = 0;
            } else {
                HOUR_PORT++;
            }
        } else {
            MINUTE_PORT++;
        }
    }
}

