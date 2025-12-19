const int captir1 =A2; 
const int captir2 =A3 ;
const int captir3 =A1; 
const int captir4 =A0 ;
int LED=13;

int c1_prime;
int c2_prime;
int c3_prime;
int c4_prime;

int c1;
int c2;
int c3;
int c4;

/*const int trigPin1 = A4;
const int echoPin1 =A5 ;

const int trigPin2 =A2 ;
const int echoPin2 =A3 ;

const int trigPin3= A0;
const int echoPin3 = A1;*/

const int in1=11;
const int in2=10;
const int in3=9;;
const int in4=6;

int v1, v2,v3,v4;

int seuil1;
int seuil2;
int seuil3;
int seuil4;
int k=0;

int state, previous,previous_state;

void setup() {
pinMode (captir1,INPUT);
pinMode (captir2,INPUT);
pinMode (captir3,INPUT); 
pinMode (captir4,INPUT); 

  pinMode (in1,OUTPUT);  
  pinMode (in2,OUTPUT);
  pinMode (in3,OUTPUT);
  pinMode (in4,OUTPUT);
  pinMode (LED, OUTPUT);
  Serial.begin(9600);

digitalWrite(LED,HIGH);
delay(3000);
int bl1=black(captir1);
int bl2=black(captir2);
int bl3=black(captir3);
int bl4=black(captir4);
digitalWrite(LED,LOW);
delay(2000);
  
digitalWrite(LED,HIGH);
delay(3000);
int wh1=white(captir1);
int wh2=white(captir2);
int wh3=white(captir3);
int wh4=white(captir4);
digitalWrite(LED,LOW);

 seuil1=(bl1+wh1)/2;
seuil2=(bl2+wh2)/2;
 seuil3=(bl3+wh3)/2;
 seuil4=(bl4+wh4)/2;
delay (3000);

forward();
delay(200);

if(k==6){
digitalWrite(LED,HIGH);}
else{
digitalWrite(LED,LOW);}

}
int convert(int captir, int seuil)
{
  if(captir>seuil)
  return 1;

  return 0;
}

int binaire (int c1, int c2, int c3, int c4)
{return c4*1000+c3*100+c2*10+c1;

}

void reverse()
{analogWrite(in1, 0);
analogWrite(in2, 200);
analogWrite(in3, 0);
analogWrite(in4, 200);
   
}

void stop()
{analogWrite(in1, 0);
analogWrite(in2, 0);
analogWrite(in3, 0);
analogWrite(in4, 0);   
}


void forward()
{analogWrite(in1, 200);
analogWrite(in2, 0);
analogWrite(in3, 155); //155
analogWrite(in4, 0);
}

void right()
{analogWrite(in1, 0);
analogWrite(in2, 0);
analogWrite(in3, 200);
analogWrite(in4, 0);
}

void left()
{analogWrite(in1, 200);
analogWrite(in2, 0);
analogWrite(in3, 0);
analogWrite(in4, 0);  

}

float black (int captir1) 
{
int s=0;  
for( int i=0;i<30 ; i++){
int val1=analogRead(captir1);
s=s+val1;
}
return( s/30);
}

float white ( int captir1){
int x=0;
for( int i=0;i<30 ; i++){
int val2=analogRead(captir1);
x=x+val2;
}
return( x/30);}



void loop() {


// c1 = analogRead(captir1);
// c2 = analogRead(captir2);
// c3 = analogRead(captir3);
// c4 = analogRead(captir4);

// v1=convert(c1,seuil1);
// v2=convert(c2,seuil2);
// v3=convert(c3,seuil3);
// v4=convert(c4,seuil4);

//int k = 1;
// int c1_prime = analogRead(captir1);
// int c2_prime = analogRead(captir2);
// int c3_prime = analogRead(captir3);
// int c4_prime = analogRead(captir4);
// for(int j=0; j<4;j++){
// c1 = analogRead(captir1);
// c2 = analogRead(captir2);
// c3 = analogRead(captir3);
// c4 = analogRead(captir4);

// if (c1!=c1_prime||c2!=c2_prime||c3!=c3_prime||c4!=c4_prime){
//   k=0;
// }

// }
int n = 1;
c1 = analogRead(captir1);
c2 = analogRead(captir2);
c3 = analogRead(captir3);
c4 = analogRead(captir4);

v1=convert(c1,seuil1);
v2=convert(c2,seuil2);
v3=convert(c3,seuil3);
v4=convert(c4,seuil4);
state = binaire(v1,v2,v3,v4);

for(int j=0; j<5;j++){
  
previous_state = state;
c1 = analogRead(captir1);
c2 = analogRead(captir2);
c3 = analogRead(captir3);
c4 = analogRead(captir4);

v1=convert(c1,seuil1);
v2=convert(c2,seuil2);
v3=convert(c3,seuil3);
v4=convert(c4,seuil4);

state = binaire(v1,v2,v3,v4);
if (state!=previous_state){
  n=0;
}
}

// state = binaire(v1,v2,v3,v4);

if (n ==1)
{
if((c1<seuil1) && (c2>seuil2) && (c3>seuil3) && (c4<seuil4)) 
{forward();}

if((c1>seuil1) && (c2<seuil2) && (c3<seuil3) && (c4<seuil4))
{right();}

if((c1>seuil1) && (c2 > seuil2) && (c3<seuil3) && (c4<seuil4))
{right();}

// if((c1>seuil1) && (c2 >seuil2) && (c3>seuil3) && (c4<seuil4))
// {right();}
// if(previous != state )
// k++;
// if(k!=6)
// right();
// else 
// left();
// }
if((c1 <seuil1) && (c2 <seuil2) && (c3 <seuil3) && (c4<seuil4))
{k++;
if((k==3) && (k==11) )
left();
}

if((c1 <seuil1) && (c2 <seuil2) && (c3<seuil3) && (c4>seuil4))
{left();}

if((c1 <seuil1) && (c2 <seuil2) && (c3 >seuil3) && (c4>seuil4))
{left();}

if((c1 <seuil1) && (c2 >seuil2) && (c3 >seuil3) && (c4>seuil4))
{
  if(previous != state )
k++;
// if(k!=6)
// right();
// else 
// left();
// }
  left();
  }
//4.5
if((c1 >seuil1) && (c2 >seuil2) && (c3 >seuil3) && (c4>seuil4) )
{ forward();}

if((c1 <seuil1) && (c2 <seuil2) && (c3 >seuil3) && (c4<seuil4))
{left();}

if((c1 <seuil1) && (c2 >seuil2) && (c3 <seuil3) && (c4<seuil4))
{right();}
//Serial.println(state);
Serial.println(k);

previous = state;
delay(1);
}
}