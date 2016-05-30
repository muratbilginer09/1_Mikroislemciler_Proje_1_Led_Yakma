#include <16F84A.h>           //kullanacaðmýz mikrodenetleyici yazýyoruz
                              // çift slash dan sonra yazacaðýmýz açýklama satýrlarýný program okumaz 
#fuses nowdt                  //sigorta ayarlarý...ilerki konularda bize lazým olacak

#use fast_io(a)               // a portunu kullanacaðýmýzý belirttik
#use fast_io(b)               // b portunu kullanacaðýmýzý belirtitk

#use delay(crystal=20000000)  // kullancaðýmýz kristalin 1 saniyede üreteceði kare dalga sayýsý

void main() 
{
   set_tris_a(0xff);          // a portunun tamamý giriþ
   set_tris_b(0x00);          // b portunun tamamý çýkýþ
   
   output_b(0x00);            // baþlangýçta b portunu sýfýrlýyoruz

   while(TRUE)                // programýn iþleneceði sonsuz döngü
   {
      if(input(pin_a0))       // A0 pinine sinyal geldiðinde iþlenecek kýsým
      {
         for(int i=1; i<=3; i++) // 3 tekrar
         {
         output_high(pin_b0);    // B0 pinine yüksek sinyal yani 5V gönder
         delay_ms(500);          // 500 milisaniye bekleme süresi
         output_low(pin_b0);     // B0 pinine düþük sinyal yani 0V gönder
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
