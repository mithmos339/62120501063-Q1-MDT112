void setup(){
    Serial.begin(9600);
    pinMode(2,INPUT_PULLUP);   //LED Pin 3,4,5,6,7,9,10,11,12,13
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);    
    tone(8,200,500);
    delay(250);
    tone(8,400,100);
}

int c = 0;  //count
int l = 3;  //light
int t = 100;  //time

void loop(){
    for (l = 3;l <= 13;l++)
    {
        if(l == 8)
        {
            digitalWrite(l,0);
            continue;
        }
        digitalWrite(l,1);
        while (digitalRead(2)==0)
        {   
            delay(200);
            if (digitalRead(2)==1)
            {               
                c++;
                tone(8,400,100);        
                Serial.println("Faster X 2 (Current Speed : X" + String(pow(2,c)) + ")");  //Current Speed : X(2^n)                              
                t = t/2;
            }
        }     
        delay(t);
        digitalWrite(l,0);               
    }
    for (l = 13 ; l >= 3 ; l--)
    {
        if(l == 8)
        {
            digitalWrite(l,0);
            continue;
        }
        digitalWrite(l, 1);
        while (digitalRead(2)==0)
        {   
            delay(200);
            if (digitalRead(2)==1)
            {               
                c++;
                tone(8,400,100);        
                Serial.println("Faster X 2 (Current Speed : X" + String(pow(2, c)) + ")");   //Current Speed : X(2^n)                             
                t = t/2;
            }
        }     
        delay(t);
        digitalWrite(l, 0);         
    }
}    
