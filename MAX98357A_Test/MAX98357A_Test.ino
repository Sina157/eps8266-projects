#define PIN_DIN   0   // D3
#define PIN_BCLK  4   // D2
#define PIN_LRC   5   // D1

void setup() {
  pinMode(PIN_DIN,  OUTPUT);
  pinMode(PIN_BCLK, OUTPUT);
  pinMode(PIN_LRC,  OUTPUT);
}

void loop() {
  // نویز سریع — دقیقاً مثل لحظه ریست
  for (int i = 0; i < 10000; i++) {
    GPIO_REG_WRITE(GPIO_OUT_W1TS_ADDRESS, (1 << PIN_DIN) | (1 << PIN_BCLK) | (1 << PIN_LRC));
    GPIO_REG_WRITE(GPIO_OUT_W1TC_ADDRESS, (1 << PIN_DIN) | (1 << PIN_BCLK) | (1 << PIN_LRC));
  }
}
