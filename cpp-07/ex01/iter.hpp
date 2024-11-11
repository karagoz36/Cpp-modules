/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:58:58 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/11/07 16:17:58 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>

void iter(T* arr, int len, void (*f)(T&)) {
	for (int i = 0; i < len; i++) {
		f(arr[i]);
	}
}