# LinkedListQuestion
typedef struct polinom
{ int katsayi;
int us;
struct polinom *sonraki;
} Polinomlar;

Yukarıdaki yapıdaki iki polinomu polinom1.txt ve polinom2.txt dosyalarından okuyarak
toplayan ve toplam sonucunu polinom3.txt dosyasına yazan bir programı istediğiniz bir programlama
dilini kullanarak gerçekleştiriniz. Polinom toplama işlemi aşağıdaki formatta olup, tek yönlü bağlı liste
yapısı kullanılarak tanımlanmıştır. Buna göre:

a) Aşağıdaki formattaki “polinom1.txt” ve “polinom2.txt” dosyalarından sırasıyla okuyacağınız
polinom ve üs katsayılarını kullanarak sırası ile Polinomlar *p1 ve Polinomlar *p2 türünden 2
adet tek yönlü bağlı liste oluşturunuz. (30 P)

b) a-seçeneğinde oluşturduğunuz *p1 ve *p2 polinomlarının toplanma işlemini gerçekleştirilecek
ve toplam sonucunu tutacak *p3 bağlı listesini geriye gönderecek Polinom_Topla()
fonksiyonunu yazınız. (50 P) Polinom toplama fonksiyonu şablonu:
Polinomlar * Polinom_Topla(Polinomlar * p1, Polinomlar * p2) {}
şeklindedir.

c) Toplamam sonucunu yine aynı formatta “polinom3.txt” dosyasına yazınız. (20 P)
