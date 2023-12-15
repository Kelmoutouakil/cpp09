/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:11:33 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/15 13:53:03 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <stdexcept> 
#include<iostream>
#include<utility>
#include<exception>
#include <algorithm>
#include<stack>
#include<vector>
struct element{
    int nb;
    int index;
    struct element *next;
};
class PmergeMe
{
    private:
        element *data;
        std::vector<element> myVector;
        std::vector<element>Store;
        int impair;
    public:
        void doMergePair(std::vector<element>& v);
        void StoreVect(char **arr);
        PmergeMe();
        int getImpair()const;
    
};

#endif 