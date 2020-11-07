float liczba1;
float liczba2;
char znak;
float wynik;
bool wyslanoWiadomosc = false;

void setup(){
  Serial.begin(9600);
}

void loop(){

if (!wyslanoWiadomosc){
  Serial.println("Prosze podac dzialanie");
  wyslanoWiadomosc = true;
}
  while(Serial.available()>0){

    liczba1=Serial.parseInt();
    znak=Serial.read();
    liczba2=Serial.parseInt();

    dzialanie();

  }
}

void dzialanie(){

  switch (znak){

    case '+' :
    wynik = liczba1 + liczba2;
    Serial.println("Wynik = ");
    Serial.println(wynik);
    break;

    case '-' :
    wynik = liczba1 - liczba2;
    Serial.println("Wynik = ");
    Serial.println(wynik);
    break;

    case '/' :
    if (liczba2 == 0){
      Serial.println("Nie mozna dzielic przez 0 !");
      break;
    }else
    wynik = liczba1 / liczba2;
    Serial.println("Wynik = ");
    Serial.println(wynik);
    break;

    case '*' :
    wynik = liczba1 * liczba2;
    Serial.println("Wynik = ");
    Serial.println(wynik);
    break;
     
  }
  wyslanoWiadomosc = false;
}
