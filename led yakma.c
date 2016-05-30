#include <16F84A.h>           //kullanaca�m�z mikrodenetleyici yaz�yoruz
                              // �ift slash dan sonra yazaca��m�z a��klama sat�rlar�n� program okumaz 
#fuses nowdt                  //sigorta ayarlar�...ilerki konularda bize laz�m olacak

#use fast_io(a)               // a portunu kullanaca��m�z� belirttik
#use fast_io(b)               // b portunu kullanaca��m�z� belirtitk

#use delay(crystal=20000000)  // kullanca��m�z kristalin 1 saniyede �retece�i kare dalga say�s�

void main() 
{
   set_tris_a(0xff);          // a portunun tamam� giri�
   set_tris_b(0x00);          // b portunun tamam� ��k��
   
   output_b(0x00);            // ba�lang��ta b portunu s�f�rl�yoruz

   while(TRUE)                // program�n i�lenece�i sonsuz d�ng�
   {
      if(input(pin_a0))       // A0 pinine sinyal geldi�inde i�lenecek k�s�m
      {
         for(int i=1; i<=3; i++) // 3 tekrar
         {
         output_high(pin_b0);    // B0 pinine y�ksek sinyal yani 5V g�nder
         delay_ms(500);          // 500 milisaniye bekleme s�resi
         output_low(pin_b0);     // B0 pinine d���k sinyal yani 0V g�nder
         delay_ms(500);
         }
      }
      
      if(input(pin_a1))
      {
         for(int i=0; i<3; i++)
         {
         output_high(pin_b1);
         delay_ms(150);
         output_low(pin_b1);
         delay_ms(150);
         }
      }
      
      if(input(pin_a2))
      {
         for(int i=0; i<3; i++)
         {
         output_high(pin_b0);
         delay_ms(150);
         output_low(pin_b0);
         
         output_high(pin_b1);
         delay_ms(150);
         output_low(pin_b1);
         
         output_high(pin_b2);
         delay_ms(150);
         output_low(pin_b2);
         }
      }
   }

}
