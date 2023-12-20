/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:11:33 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/20 15:46:47 by kelmouto         ###   ########.fr       */
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

typedef struct element
{
    int nb;
    std::vector<int>index;
     element()
     {
        
     }
    element(const element &obj)
    {
        nb = obj.nb;
        index = obj.index;
    }
    
    struct element *next;
    bool operator<(const element& other) const {
        return nb < other.nb;}
}element;

class PmergeMe
{
    private:
        element data;
        std::vector<element> myVector;
        std::vector<element>Store;
 
    public:
        void doMergePair(std::vector<element> v);
        void StoreVect(char **arr);
        PmergeMe();

    
};
#endif 