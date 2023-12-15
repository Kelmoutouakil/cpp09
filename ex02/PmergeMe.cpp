/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:12:30 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/15 12:08:06 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
        

PmergeMe::PmergeMe()
{
    impair = 0;
    data = new element;
    data->nb = 0;
    data->index = 0;
    data->next = NULL;
}

int PmergeMe:: getImpair()const
{
    return (impair);
}
