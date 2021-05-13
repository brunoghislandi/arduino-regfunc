void pinState(int pin, int state){
  if(pin>=0 && pin<=7){
    if(state==0){
      DDRD &= ~(1<<pin);
    }else if(state==1){
      DDRD |=  (1<<pin);
    }
  }else if(pin>=8 && pin<=13){
    if(state==0){
      DDRB &= ~(1<<pin-8);
    }else if(state==1){
      DDRB |=  (1<<pin-8);      
    }
  }else if(pin>=14 && pin<=19){
    if(state==0){
      DDRC &= ~(1<<pin-14);
    }else if(state==1){
      DDRC |=  (1<<pin-14);   
    }}}

void pinWrite(int pin, int state){
  if(pin>=0 && pin<=7){
    if(state==0){
      PORTD &= ~(1<<pin);
    }else if(state==1){
      PORTD |= (1<<pin);     
    }
  }else if(pin>=8 && pin<=13){
    if(state==0){
      PORTB &= ~(1<<pin-8);
    }else if(state==1){
      PORTB |= (1<<pin-8);      
    }
  }else if(pin>=14 && pin<=19){
    if(state==0){
      PORTC &= ~(1<<pin-14);
    }else if(state==1){
      PORTC |=  (1<<pin-14);   
    }}}

bool pinRead(int pin){

  bool dataPin = 0;
  
    if(pin>=0 && pin<=7){
      dataPin = PIND & (1<<pin);
    return(dataPin);
      }
      else if(pin>=8 && pin<=13){
      dataPin = PINB & (1<<pin-8);
    return(dataPin);
      }
      else if(pin>=14 && pin<=19){
      dataPin = PINC & (1<<pin-14);
    return(dataPin);
  }}

/* Here you can create variables and
 choose the numbers to be controlled */

int EX1 = 1, EX2 = 2, EX3 = 3, 
    EX4 = 4, EX5 = 5, EX6 = 6;

void setup() {
pinState(EX1, LOW);
pinState(EX2, LOW);
pinState(EX3, LOW);
pinState(EX4, HIGH);
pinState(EX5, HIGH);
pinState(EX6, HIGH);
}

/*Here is just a basic example of 
 connecting outputs with buttons */

void loop() {
  bool x = pinRead(EX1);
  if(x==1){
    pinWrite(EX4,HIGH);
  }else{
    pinWrite(EX4,LOW);
  }

  bool y = pinRead(EX2);
  if(y==1){
    pinWrite(EX5,HIGH);
  }else{
    pinWrite(EX5,LOW);
  }

  bool z = pinRead(EX3);
  if(z==1){
    pinWrite(EX6,HIGH);
  }else{
    pinWrite(EX6,LOW);
  }
}