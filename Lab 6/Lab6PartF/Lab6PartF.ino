// EEC_Lab1_PartB_Output_Digital_Example
int LED_1 = 35; //Save the pin number associated with the LED
int LED_2 = 34;
int LED_3 = 32;
int LED_4 = 31;
unsigned long time1 = 0;
unsigned long time2 = 0;
float period;
int L = 100;
float Real[100];
float Imag[100];
float F[100];
float a[100];
float b;
float c = 2 * 3.14 / 100;
int HighestCell = 0;
float TopFreq;
float Voltage[100];
float DC = 0;
float sampFreq;

void setup()
{
  pinMode(LED_1, OUTPUT); //Set the pin connected to LED as Output
  pinMode(LED_2, OUTPUT); //Set the pin connected to LED as Output
  pinMode(LED_3, OUTPUT); //Set the pin connected to LED as Output
  pinMode(LED_4, OUTPUT); //Set the pin connected to LED as Output
  Serial.begin(115200);

}

void loop ()
{
  float BandSums[5] = {0, 0, 0, 0, 0};
  float *pBandSums;
  float TF = 0;
  pBandSums = &BandSums[0];

  // Defines the regions the bands operate in.  
  float Bands[4] = {500, 600, 700, 800};

  //Take the Fourier Transform
  TF=fft(Bands[0], Bands[1], Bands[2], Bands[3], pBandSums);
  float maxBand=0;
  float minBand=0;

if (TF < Bands[0])
    {
      BandSums[0]=255;
    }
if (TF < Bands[1]&TF > Bands[0])
    {
      BandSums[1]=255;
    }
if (TF < Bands[2]&TF > Bands[1])
    {
      BandSums[2]=255;
    }
if (TF < Bands[3]&TF > Bands[2])
    {
      BandSums[3]=255;
    }
    if (TF > Bands[3])
    {
      BandSums[4]=255;
    }
  analogWrite(LED_1,floor(BandSums[0]));
  analogWrite(LED_2,floor(BandSums[1]));
  analogWrite(LED_3,floor(BandSums[2]));
  analogWrite(LED_4,floor(BandSums[3]));

}

// splits the FFT into 5 limits.
//0-UpperLimit1
//UpperLimit1-UpperLimit2
//UpperLimit2-UpperLimit3
//UpperLimit3-UpperLimit4
//UpperLimit4-5000 Hz
float fft(float Band1, float Band2, float Band3, float Band4, float *p)
{
  int usdelay = 75;
  int poffset = 0;
  int BandOffset = 0;
  float Bands[5] = {Band1, Band2, Band3, Band4, 10000};
  //Initialize Variables!!

  //Read in Data
  time1 = micros();
  for (int i = 0; i < L; i++)
  {
    a[i] = analogRead(A3);
    delayMicroseconds(usdelay);
  }
  time2 = micros();
  period = (time2 - time1) / L;
  //Serial.println(period);
  sampFreq = (1 / period) * 1000000;
  //Serial.println(sampFreq);

  for (int j = 0; j < L; j++)
  {
    a[j] = map(a[j], 0, 1023, 0, 3300);
    Voltage[j] = a[j] / 1000;
    DC += Voltage[j];
  }
  DC = DC / L;
  for (int j = 0; j < L / 2; j++)
  {
    //Reset
    Real[j] = 0;
    Imag[j] = 0;
    b = c * j;
    for (int u = 0; u < L; u++)
    {
      Real[j] += (Voltage[u] - DC) * cos(b * u);
      Imag[j] += (Voltage[u] - DC) * (-1) * sin(b * u);
    }
    F[j] = sqrt(sq(Real[j]) + sq(Imag[j]));

    //Check if current frequency bin is highest
    if (F[j] >= F[HighestCell])
    {
      HighestCell = j;
    }
    if (100 * j < Bands[BandOffset])
    {
      *(p + poffset) = *(p + poffset) + F[j];
    }
    if (100 * j <= Bands[BandOffset])
    {
      poffset = poffset + 1;
      BandOffset = BandOffset + 1;
    }
  }
    if (HighestCell > L / 2)
    {
      TopFreq = sampFreq / L * (L - HighestCell);
    }
    if (HighestCell < L / 2)
    {
      TopFreq = sampFreq / L * (1 + HighestCell);
    }
Serial.println(TopFreq);
  return(TopFreq);

}
