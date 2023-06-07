Arduino Uygulama Adı: Kablosuz Hava Kalitesi İzleme Sistemi

Uygulama Açıklaması:
Bu Uygulamade, Arduino platformu kullanarak kablosuz bir hava kalitesi izleme sistemi oluşturulacaktır. Sistem, hava kalitesini algılamak için gaz sensörleri kullanacak ve sonuçları kullanıcıya kablosuz olarak iletecektir.

Donanım bileşenleri:
Arduino UNO veya Arduino Nano
MQ-serisi gaz sensörleri (örneğin MQ-2, MQ-7, MQ-135 gibi)
DHT11 veya DHT22 sıcaklık ve nem sensörü
NRF24L01 kablosuz iletişim modülü
LCD ekran (16x2 karakter)
Buzzer

Yazılım gereksinimleri:
Arduino IDE
RF24.h
Adafruit_BME280.h
LiquidCrystal_I2C.h

Uygulama İşlevselliği:
Gaz sensörleri aracılığıyla çevredeki hava kalitesini algılar.
Sıcaklık ve nem sensörü ile ortamın sıcaklık ve nem değerlerini ölçer.
LCD ekran üzerinde hava kalitesi, sıcaklık ve nem değerlerini görüntüler.
Belirli bir hava kalitesi eşiği aşıldığında, alarmı tetikleyerek kullanıcıyı uyarır (buzzer kullanarak).
Kablosuz iletişim modülü (NRF24L01) aracılığıyla verileri kablosuz olarak başka bir Arduino veya alıcı birimine iletebilir.
Alıcı birim, verileri kablosuz olarak alır ve bilgisayara veya başka bir ekrana aktarabilir.
Uygulama üzerinde düğmeler veya potansiyometre gibi ek bileşenler ekleyerek kontrol ve ayarlamalar yapılabilir.


BME280 sıcaklık ve nem sensörü ile MQ-serisi gaz sensörünü kullanarak hava kalitesi verilerini okur. LCD ekran üzerinde sıcaklık, nem ve hava kalitesi bilgilerini görüntüler. Ayrıca, gaz değeri belirli bir eşiği aştığında bir alarm tetikler (ALARM_PIN üzerinden bir buzzer veya LED kullanabilirsiniz).

Kodda "RF24.h", "Adafruit_BME280.h" ve "LiquidCrystal_I2C.h" kütüphaneleri kullanılmaktadır. Bu kütüphaneleri Arduino IDE'de Kütüphane Yöneticisi'nden indirmeniz gerekmektedir. Ayrıca, RF24 modülünün CE ve CSN pinlerine bağlı olduğu pin numaralarını uygun şekilde ayarlamalısınız.

Bu kodda verileri kablosuz olarak başka bir Arduino veya alıcı birime gönderiyoruz. Alıcı birimde de RF24 modülü kullanarak verileri alabilir ve ekrana veya başka bir cihaza aktarabilirsiniz.

Not: Kodu özelleştirmek ve projeye özgü gereksinimlere göre ayarlamak size kalmıştır. Sensörlerin ve RF24 modülünün doğru şekilde bağlandığından emin olun ve pin numaralarını projenize göre uygun şekilde değiştirin.

