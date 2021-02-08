//created by Team !ABHIMANYU

#define ML1 6 
#define ML2 5
#define MR1 10
#define MR2 11

String  str;
float a,b;
int c=0,d=0;
int v=200, vl1=0,vl2=0,vr1=0,vr2=0;


void setup() {
  // put your setup code here, to run once:
pinMode(ML1, OUTPUT);
pinMode(ML2, OUTPUT);
pinMode(MR1, OUTPUT);
pinMode(MR2, OUTPUT);
Serial.begin(115200);

 delay(5000);
}

void loop() {

  a=0.00;  b=0.00;

   String str="";
 boolean StringReady = false;
 
 if(Serial.available()){
   str=Serial.readStringUntil('\n');
   StringReady= true;
  }
 
  if (StringReady){

  // exracting data
a=0; b=0; c=0; d=0;
   if(str[0]=='-')
{
c=1;
if(str[9]=='-')
{
    d=1;
    b= b*10+ str[10]-48;
    b= b*10 +str[12] -48;
    b= b*10 +str[13] -48;
    b= b*10 +str[14] -48;
    b= b*10 +str[15] -48;
    b= b*10 +str[16] -48;
}
else
{
d=2;
b= b*10 +str[9] -48;
    b= b*10+ str[11]-48;
    b= b*10 +str[12] -48;
    b= b*10 +str[13] -48;
    b= b*10 +str[14] -48;
    b= b*10 +str[15] -48;
}
for(int i=1;i<=7;i++)
{
    if(i!=2)
    {
        a= a*10 +str[i] -48;
    }
}
}
else
{
c=2;
if(str[8]=='-')
{
    d=1;
    b= b*10+ str[9]-48;
    b= b*10 +str[11] -48;
    b= b*10 +str[12] -48;
    b= b*10 +str[13] -48;
    b= b*10 +str[14] -48;
    b= b*10 +str[15] -48;
}
else
{
d=2;
b= b*10 +str[8] -48;
    b= b*10+ str[10]-48;
    b= b*10 +str[11] -48;
    b= b*10 +str[12] -48;
    b= b*10 +str[13] -48;
    b= b*10 +str[14] -48;
}
for(int i=0;i<=6;i++)
{
    if(i!=1)
    {
        a= a*10 +str[i] -48;
    }
}
}

   a= a/10000 ; b= b/10000;
   Serial.print(str);
   Serial.print("  ");
   Serial.print(a);
   Serial.print("  ");
   Serial.print(b);
   Serial.print("  ");
   Serial.print(c);
   Serial.print("  ");
   Serial.print(d);
   Serial.println("  ");


  // a is reading of x-axis
  // b is reading of y-axis
  // c is sign of x-axis
  // d is sign of y-axis
   
  // running the car

   // if a >=10 and a<=90 and c==2 -> forward
   // if a <=50 and a>=0 and c==1 -> backward
   // if b >=5 && d == 2 -> right
   // if b >=5 && d == 1 -> left


 if(a >=15 && c==2 && b>=5 && d == 2)  // right forward
 {
    
  vr1=0;
  vr2= 2*a+55-2*b;
  vl1=0;
  vl2= 2*a+55+2*b;
  
  if((2*a+55+2*b) > 255) {
    if(b<40) {vl2=255;  vr2= 200; }
    else {vl2=255;  vr2= 100; }
    }
  if((2*a+55-2*b) < 0) {   vr2=0;  vr1= 2*b-2*a-55;  }
  
  }

 else if(a >=15 && c==2 && b>=5 && d == 1)   // left forward
 {
    
  vr1=0;
  vr2= 2*a+55+2*b;
  vl1=0;
  vl2= 2*a+55-2*b;

  if((2*a+55+2*b) > 255) {  
    if(b<40) { vr2=255;  vl2= 200;}
    else { vr2=255;  vl2= 100;}
    }
  if((2*a+55-2*b) < 0) {   vl2=0;  vl1= 2*b-2*a-55;  }
  
  }

 else if(c==1 && b>=5 && d == 2)   // right backward
 {
    
  vr1= 2*a+50-2*b;
  vr2= 0;
  vl1= 2*a+50+2*b;
  vl2= 0;

  if((2*a+55+2*b) > 255) {
    if(b<40) { vl1=255;  vr1= 200; }
    else { vl1=255;  vr1= 100; }
    }
  if((2*a+50-2*b) < 0) {   vr2= 2*b-2*a-50; vr1= 0;   }
  
  }

 else if(  c==1 && b>=5 && d == 1)   // left backward
 {
    
  vr1= 2*a+50+2*b;
  vr2= 0;
  vl1= 2*a+50-2*b;
  vl2= 0;

  if((2*a+55+2*b) > 255) {   
    if(b<40) {vr1=255;  vl1= 200;}
    else {vr1=255;  vl1= 100;}
    }
  if((2*a+50-2*b) < 0) {   vl2= 2*b-2*a-50; vl1= 0;   }
  }

 else if(a >=15 && c==2 && b<=5)   // forward
 {
    
  vr1= 0;
  vr2= 2*a+55;
  vl1= 0;
  vl2= 2*a+55;
  
  }

 else if( c==1 && b<=5)   // backward
 {
    
  vr1= 2*a+50;
  vr2= 0;
  vl1= 2*a+50;
  vl2= 0;
  
  }

 else if(a <15 && c==2 && b>5 && d==1)   // left
 {
    
  vr1=0;
  vr2= 4*b;
  vl1= 4*b;
  vl2= 0;
  
  }

 else if(a <15 && c==2 && b>5 && d==2)   // right
 {
    
  vr1=4*b;
  vr2= 0;
  vl1= 0;
  vl2= 4*b;
  
  }

  else    // stop
  {
    
   vr1=0;
   vr2=0;
   vl1=0;
   vl2=0; 
    
  }
   


    Serial.print(vl1);
  Serial.print("     ");
  Serial.print(vl2);
  Serial.print("     ");
  Serial.print(vr1);
  Serial.print("     ");
  Serial.println(vr2);
Serial.println("  ");

  }

  
analogWrite(ML1, vl1);
analogWrite(ML2, vl2);
analogWrite(MR1, vr1);
analogWrite(MR2, vr2);
}
