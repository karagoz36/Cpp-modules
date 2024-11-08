| Feature                  | `std::vector`                             | `std::list`                                 | `std::map`                                          | `std::stack`                              |
|--------------------------|-------------------------------------------|---------------------------------------------|-----------------------------------------------------|-------------------------------------------|
| **Data Storage**         | Contiguous, array-like                   | Dispersed, doubly linked list               | Key-value pairs stored in order                     | Elements added on top of the stack        |
| **Random Access**        | Yes, `O(1)`                              | No, `O(n)`                                  | No, only key-based access `O(log n)`               | No, only the top element is accessible    |
| **Insertion (End)**      | `O(1)`                                   | `O(1)`                                      | `O(log n)`                                          | `O(1)`                                   |
| **Insertion (Middle)**   | `O(n)`                                   | `O(1)`                                      | `O(log n)`                                          | -                                         |
| **Deletion (Middle/Specific)** | `O(n)`                           | `O(1)`                                      | `O(log n)`                                          | Only from the top `O(1)`                 |
| **Memory Usage**         | Low, contiguous block                    | Higher, uses pointers                       | Medium, allocated according to tree structure       | Low, only elements in the stack           |
| **Cache Efficiency**     | High                                     | Low                                         | Medium                                              | High                                     |
| **Ordering**             | Stored in insertion order                | Stored in insertion order                   | Automatically ordered by key                        | None                                      |
| **Best Use Cases**       | Array-like structures, random access     | Frequent insertions/deletions               | Key-value pairs, fast lookup requirements           | LIFO (Last In First Out) operations       |



| Özellik                | `std::vector`                               | `std::list`                                 | `std::map`                                          | `std::stack`                              |
|------------------------|---------------------------------------------|---------------------------------------------|-----------------------------------------------------|-------------------------------------------|
| **Veri Saklama**       | Ardışık, dizi yapısında                     | Dağınık, çift yönlü bağlı liste             | Anahtar-değer çiftleri olarak sıralı                 | Yığının üstüne eklenen elemanlar          |
| **Rastgele Erişim**    | Evet, `O(1)`                                | Hayır, `O(n)`                               | Hayır, yalnızca anahtar ile erişim `O(log n)`       | Hayır, yalnızca en üst eleman erişilebilir |
| **Ekleme (Sonuna)**    | `O(1)`                                      | `O(1)`                                      | `O(log n)`                                          | `O(1)`                                   |
| **Ekleme (Ortaya)**    | `O(n)`                                      | `O(1)`                                      | `O(log n)`                                          | -                                         |
| **Silme (Orta/Belirli)** | `O(n)`                                    | `O(1)`                                      | `O(log n)`                                          | Yalnızca en üstten `O(1)`                 |
| **Bellek Kullanımı**   | Az, ardışık blok                            | Fazla, işaretçiler kullanılır               | Orta, ağaç yapısına göre tahsis                      | Az, yalnızca yığındaki elemanlar          |
| **Önbellek Verimliliği** | Yüksek                                    | Düşük                                       | Orta                                                | Yüksek                                    |
| **Sıralama**           | Elemanlar eklenme sırasına göre             | Eklenme sırasına göre                       | Anahtar değerine göre otomatik sıralı                | Yok                                       |
| **En İyi Kullanım Durumları** | Dizi benzeri yapılar, rastgele erişim | Çok ekleme/silme yapılan durumlar           | Anahtar-değer çiftleri, hızlı arama gereksinimleri   | LIFO (Son Giren İlk Çıkar) işlemleri      |
