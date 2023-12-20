/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:12:46 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/20 18:03:22 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include<cmath>

int main(int argc, char  *argv[])
{   
    try
    {
        PmergeMe o;
        std::vector<std::pair<int, int> >vect;
        if(argc != 1)
            o.doMergeSort(argv);
        else
            throw std::invalid_argument("invalid arguments!");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
