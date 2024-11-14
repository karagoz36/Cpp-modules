# Algoritma Karşılaştırması: Insertion Sort, Merge Sort ve Ford-Johnson Merge-Insertion Sort

Bu README dosyasında Insertion Sort, Merge Sort ve Ford-Johnson Merge-Insertion Sort algoritmalarını farklı kriterlere göre karşılaştıran bir tablo bulunmaktadır. Bu algoritmaların zaman karmaşıklığı, bellek kullanımı ve avantaj/dezavantajlarını aşağıdaki tablodan inceleyebilirsiniz.

| **Özellik**                 | **Insertion Sort**       | **Merge Sort**                   | **Ford-Johnson Merge-Insertion Sort**            |
|-----------------------------|--------------------------|----------------------------------|--------------------------------------------------|
| **Zaman Karmaşıklığı (Ortalama)** | O(n²)                  | O(n log n)                       | O(n log n - n)                                   |
| **Zaman Karmaşıklığı (En Kötü)** | O(n²)                  | O(n log n)                       | O(n log n - n)                                   |
| **Ek Bellek Kullanımı**     | O(1)                     | O(n)                             | O(n)                                             |
| **Algoritma Tipi**          | Sıralı Ekleme            | Böl ve Birleştir (Rekürsif)      | Böl ve Birleştir + Ekleme (Rekürsif)             |
| **En İyi Kullanım Durumu**  | Küçük veya kısmen sıralı diziler | Büyük diziler veya genel sıralama | Rastgele sıralı ve büyük diziler                 |
| **Stabilite**               | Evet                     | Evet                             | Evet                                             |
| **Karşılaştırma Sayısı**    | Yüksek (O(n²))           | Orta (O(n log n))                | Düşük (özellikle en kötü durum dizilerde)        |
| **Avantajları**             | Basit ve küçük veri kümelerinde hızlı | Büyük dizilerde verimli          | Karşılaştırma sayısını azaltır                   |
| **Dezavantajları**          | Büyük dizilerde yavaş    | Ek bellek kullanımı              | Kompleks yapısı nedeniyle daha karmaşık ve yavaş |

### Açıklamalar:
- **Insertion Sort**: Basit ve küçük veri kümeleri için oldukça etkili, ancak karmaşıklığı **O(n²)** olduğu için büyük veri kümelerinde yavaş çalışır.
- **Merge Sort**: Büyük dizilerde çok verimlidir ve karmaşıklığı **O(n log n)**'dir. Ancak ek bellek kullanımı gerektirir.
- **Ford-Johnson Merge-Insertion Sort**: **O(n log n - n)** teorik karmaşıklığı ile diğer sıralama algoritmalarına göre karşılaştırma sayısını azaltır. Bu özellik, özellikle çok büyük ve rastgele sıralanmış dizilerde önemlidir. Ancak karmaşıklığı nedeniyle uygulanması daha zordur ve pratikte Merge Sort’tan daha hızlı olmayabilir.

Bu tablo, algoritmaların belirli durumlarda nasıl performans gösterebileceğine dair genel bir bakış sağlar.
