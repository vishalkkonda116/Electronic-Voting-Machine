int p,q,r,s;
 int W[500];
#include <LiquidCrystal.h>
#include <Keypad.h>


LiquidCrystal lcd( 12, 11, 5, 4, 3, 2);
const byte ROWS = 4; // Four rows

  const byte COLS = 3; // three columns

  

  char keys[ROWS][COLS] = 

  {

   
  {'1','2','3'},

   
  {'4','5','6'},

   
  {'7','8','9'},

   
  {'*','0','#'}

  };

  

  byte rowPins[ROWS] = { 10, 9, 8, 7};

  

  byte colPins[COLS] = { A5, A4, A3 }; 

  

  Keypad kpd = Keypad( makeKeymap(keys), rowPins,
  colPins, ROWS, COLS );
    int reverse(int n){
int rev=0,rem,k=n;
     while(n != 0) {
      
    rem = n % 10;
    rev = rev * 10 + rem;
    n=n/10;
  }
  lcd.clear();
 // *lcd.print(rev);
if(k<10)
return rev*100;
else if (k<100)
return rev*10;
else
  return rev;
  }
void setup() {
 
  for(int j=0;j<500;j++)
  {
    W[j]=0;
  }

  pinMode(6, OUTPUT);
  digitalWrite(6,LOW);
  
  lcd.begin(16, 2);

  
 
   
  lcd.clear();
  lcd.print("Press 1 to vote");
  lcd.setCursor(5, 1);
  lcd.print("for BJP");
  delay(2000);
  lcd.clear();
  lcd.print("Press 2 to vote");
  lcd.setCursor(2, 1);
  lcd.print("for Congress");
  delay(2000);
  lcd.clear();
  lcd.print("Press 3 to vote");
  lcd.setCursor(5, 1);
  lcd.print("for TRS");
  delay(2000);
  lcd.clear();
  lcd.print("Press 4 to vote");
  lcd.setCursor(5, 1);
  lcd.print("for TDP");
  delay(2000);

p=q=r=s=0;
}
void loop() {
  lcd.clear();
   int P,U=0,K=0;
  lcd.print("ENTER USER ID");
  delay(2000);
  lcd.clear();
  for(int i=0;i<3;){
    P=kpd.getKey();
  while(P!=NO_KEY){
     lcd.setCursor(i, 1);
    
     P=P-48;
     U=U*10+P;
      if (P==-13||P==-7)
     U=501;
     lcd.print(P);
     i++;
     break;
  }}
  delay(1000);
  lcd.clear();
  lcd.print("ENTER PASSWORD");
  delay(2000);
  lcd.clear();
  for(int i=0;i<3;){
    P=kpd.getKey();
  if(P!=NO_KEY){
     lcd.setCursor(i, 1);
     
      P=P-48;
     K=K*10+P;
     lcd.print("*");
     i++;
  }}
   delay(2000);
   K=reverse(K);
   if (K!=U||W[U]==1||U>500)
   {if(U>500)
    lcd.print(" invalid User ID  ");
    else if(K!=U)
     {lcd.print("Wrong Password");
     // lcd.print(K);
      }
     else
      {lcd.print(" Vote already ");
      lcd.setCursor(3, 1);
      lcd.print("Casted");}
    delay(2000);
   }
   else
    {
       
    lcd.print("cast your vote");
    delay(2000);
  lcd.clear();
  
 
  while(1){
     char v=kpd.getKey();
  if(v!=NO_KEY){
    W[U]=1;
    delay(1000);
  switch (v){
   case 49:
   p++;
    lcd.clear();
   lcd.print("Vote casted for"); 
      lcd.setCursor(5,1);
    lcd.print("BJP");
     digitalWrite(6,HIGH);
    delay(1000);
     digitalWrite(6,LOW);
    break;
    case 50:
    q++;
     lcd.clear();
    lcd.print("Vote casted for"); 
      lcd.setCursor(5,1);
    lcd.print("CNG");
     digitalWrite(6,HIGH);
    delay(1000);
     digitalWrite(6,LOW);
    break;
    case 51:
    r++;
     lcd.clear();
    lcd.print("Vote casted for");
    lcd.setCursor(5,1);
    lcd.print("TRS");
     digitalWrite(6,HIGH);
    delay(1000);
     digitalWrite(6,LOW);
    break;
    case 52:
    s++;
     lcd.clear();
    lcd.print("Vote casted for"); 
      lcd.setCursor(5,1);
    lcd.print("TDP");
     digitalWrite(6,HIGH);
    delay(1000);
     digitalWrite(6,LOW);
    break;
    case 53:
    { lcd.clear();
   lcd.print("BJP CNG TRS TDP");
    
    lcd.setCursor(1, 1);
    lcd.print(p);
      lcd.setCursor(5, 1);
    lcd.print(q);
      lcd.setCursor(9, 1);
    lcd.print(r);
     lcd.setCursor(13, 1);
    lcd.print(s);
     delay(2000);
     
    if(p>=q&&p>=r&&p>=s)
    {lcd.clear();
      if(p==q&&p==r&&p==s)
       lcd.print("ALL Won");
      else if(p==q&&p==r)
       lcd.print("BJP,CNG,TRS Won");
       else if(p==s&&p==r)
       lcd.print("BJP,TDP,TRS Won");
       else if(p==q&&p==s)
       lcd.print("BJP,CNG,TDP Won");
     else if(p==q)
        lcd.print("BJP and CNG Won");
    else if(p==r)
       lcd.print("BJP and TRS Won");
      else if(p==s)
       lcd.print("BJP and TDP Won");
      else
     lcd.print("BJP Won");}
    else if(q>=r&&q>=s)
    {
    lcd.clear();
       if(s==q&q==r)
       lcd.print("TDP,CNG,TRS Won");
      else if(q==r)
       lcd.print("CNG and TRS Won");
        else if(q==s)
       lcd.print("CNG and TDP Won");
          
        else
      lcd.print("CNG Won");}
     else if(r>=s)
     {lcd.clear();
         if(r==s)
       lcd.print("TRS and TDP Won");
           else
      lcd.print("TRS Won");}
     else 
     {lcd.clear();
      lcd.print("TDP Won");}
     delay(5000);
    }
  }
   break;
  }
 }
 
}}