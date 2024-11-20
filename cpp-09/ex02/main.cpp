/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:40:26 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/20 21:43:19 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"  // FordJohnsonAlgorithm sınıfını içeren başlık dosyasını dahil eder.
#include <ctime>  // Zaman ölçüm işlemleri için <ctime> kütüphanesini ekler.

int main(int ac, char *av[])
{
	clock_t timeVec;  // Vektör tabanlı sıralama süresini ölçmek için saat değişkeni.
	// clock_t timeDeq;  // Deque tabanlı sıralama süresini ölçmek için saat değişkeni.
	PmergeMe::PmergeVector pmVec;  // PmergeVector sınıfından bir nesne oluşturur.
	//PmergeMe::PmergeDeque pmDeq;  // PmergeDeque sınıfından bir nesne oluşturur.

	if (ac == 1)  // Eğer komut satırı argümanları yoksa (sadece program adı verilmişse).
	{
		// Kullanıcıya doğru kullanımı gösteren bir hata mesajı verir.
		std::cerr << "usage: " << av[0] << " ...numbers" << std::endl;
		return (1);  // Program hatalı çalıştıysa 1 döner.
	}

	try  // Hataların yakalanması için try-catch bloğu kullanılır.
	{
		// Vektör tabanlı sıralama işlemi süresini ölçer.
		timeVec = clock();  // Başlangıç zamanı.
		pmVec.applyMergeInsertSort(av);  // Vektör tabanlı sıralama işlemini çalıştırır.
		timeVec = clock() - timeVec;  // Geçen süreyi hesaplar.

		// // Deque tabanlı sıralama işlemi süresini ölçer.
		// timeDeq = clock();  // Başlangıç zamanı.
		// pmDeq.applyMergeInsertSort(av);  // Deque tabanlı sıralama işlemini çalıştırır.
		// timeDeq = clock() - timeDeq;  // Geçen süreyi hesaplar.

		// Sıralama öncesi diziyi yazdırır.
		std::cout << "Before: ";
		pmVec.printBefore();
		std::cout << std::endl;

		// Sıralama sonrası diziyi yazdırır.
		std::cout << "After: ";
		pmVec.printAfter();
		std::cout << std::endl;

		// Vektör tabanlı sıralama için geçen süreyi milisaniye cinsinden yazdırır.
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : "
		          << (float)timeVec * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;

		// // Deque tabanlı sıralama için geçen süreyi milisaniye cinsinden yazdırır.
		// std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : "
		//           << (float)timeDeq * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
	}
	catch (const std::exception &e)  // Özel bir durum (exception) meydana gelirse.
	{
		std::cerr << e.what() << '\n';  // Hata mesajını standart hata çıkışına yazdırır.
	}

	return 0;  // Program başarıyla çalıştıysa 0 döner.
}
