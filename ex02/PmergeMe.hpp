/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:11:33 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/14 12:30:36 by kelmouto         ###   ########.fr       */
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
class PmergeMe
{
    private:
        std::vector<int> myVector;
        std::vector<int>tmp;
        int impair;
    public:
        std::vector<std::pair<int, int> > doMergePair();
        void StoreVect(char **arr);
        PmergeMe();
        int getImpair()const;
    
};

#endif 